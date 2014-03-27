#!/bin/bash

PROJECT=skeletor
ACQUIA_NAME=unicornfactory
ENV=prod
BRANCH=develop
GIT_REFERENCE_DIR=~jenkins/jobs/deploy-dev/$PROJECT.reference.git
REPO="${ACQUIA_NAME}@svn-3.devcloud.hosting.acquia.com:${ACQUIA_NAME}.git"

cd $WORKSPACE/profile

# Go into maintenance mode?
#drush @$PROJECT.$ENV vset maintenance_mode 1 \
#  --alias-path=tmp/scripts \
#  --yes

# Create git tag for commit and push
cd $WORKSPACE
git clone $REPO $WORKSPACE/acquia \
  --reference=$GIT_REFERENCE_DIR \
  --branch=$BRANCH
cd acquia/
GIT_TAG="$(date +'%Y-%m-%d')-build-$BUILD_NUMBER"
# Find the Acquia commit by parsing the log for the profile repo commit.
ACQUIA_GIT_COMMIT=`git log --format=oneline | grep --max-count=1 $(echo $GIT_COMMIT | cut --characters=1-7) | awk '{ print $1 }'`
git tag $GIT_TAG $ACQUIA_GIT_COMMIT
git push --tags

# Store currently deployed commit
# https://cloudapi.acquia.com/#GET__sites__site_envs__env-instance_route
PREV_DEPLOYED_REF="$(drush @$ACQUIA_NAME.$ENV ac-environment-info \
  --include=${WORKSPACE}/profile/tmp/scripts/drush \
  --config=${WORKSPACE}/profile/tmp/scripts/drush/${ACQUIA_NAME}.acapi.drushrc.php \
  --alias-path=${WORKSPACE}/profile/tmp/scripts/drush \
  | grep -e '^ vcs_path' | awk '{ print $3 }')"
echo $PREV_DEPLOYED_REF

# Back up database before running remote drush commands on it.
# We request a backup with the Acquia CLI, and then use the
# task ID to poll for it to be 'done' before moving on.
# We provide output for the logs, and a cap of 10 API calls.

echo "Backup task initiated..."
BACKUP_TASK_ID="$(drush @${ACQUIA_NAME}.$ENV ac-database-backup ${ACQUIA_NAME} \
  --include=${WORKSPACE}/profile/tmp/scripts/drush \
  --config=${WORKSPACE}/profile/tmp/scripts/drush/${ACQUIA_NAME}.acapi.drushrc.php \
  --alias-path=${WORKSPACE}/profile/tmp/scripts/drush \
  2>&1 | awk '{ print $2 }')"

echo "Waiting for task to complete..."
poll_count=0
while [[ "$(drush @${ACQUIA_NAME}.$ENV ac-task-info $BACKUP_TASK_ID \
  --include=${WORKSPACE}/profile/tmp/scripts/drush \
  --config=${WORKSPACE}/profile/tmp/scripts/drush/${ACQUIA_NAME}.acapi.drushrc.php \
  --alias-path=${WORKSPACE}/profile/tmp/scripts/drush 2>&1 \
  | grep -E '^ state' | awk '{ print $NF }')" != "done" ]]
do
  poll_count=`expr $poll_count + 1`
  echo "API polls: $poll_count"
  if [[ "$poll_count" -gt 10 ]]; then
    echo "ERROR: Timed out while waiting for Acquia task completion."
    exit 1
  fi
  sleep 2
done

# Deploy tag on appropriate env
# https://cloudapi.acquia.com/#POST__sites__site_envs__env_code_deploy-instance_route

echo "Code deploy task initiatiated..."
DEPLOY_TASK_ID="$(drush @$ACQUIA_NAME.$ENV ac-code-path-deploy tags/$GIT_TAG \
  --include=${WORKSPACE}/profile/tmp/scripts/drush \
  --config=${WORKSPACE}/profile/tmp/scripts/drush/${ACQUIA_NAME}.acapi.drushrc.php \
  --alias-path=${WORKSPACE}/profile/tmp/scripts/drush \
  2>&1 | awk '{ print $2 }')"

echo "Waiting for task to complete..."
poll_count=0
while [[ "$(drush @${ACQUIA_NAME}.$ENV ac-task-info $DEPLOY_TASK_ID \
  --include=${WORKSPACE}/profile/tmp/scripts/drush \
  --config=${WORKSPACE}/profile/tmp/scripts/drush/${ACQUIA_NAME}.acapi.drushrc.php \
  --alias-path=${WORKSPACE}/profile/tmp/scripts/drush 2>&1 \
  | grep -E '^ state' | awk '{ print $NF }')" != "done" ]]
do
  poll_count=`expr $poll_count + 1`
  echo "API polls: $poll_count"
  if [[ "$poll_count" -gt 10 ]]; then
    echo "ERROR: Timed out while waiting for Acquia task completion."
    exit 1
  fi
  sleep 2
done

# Run remote drush commands
drush @${ACQUIA_NAME}.$ENV --alias-path=${WORKSPACE}/profile/tmp/scripts/drush --yes updatedb
# Force reversion since sometimes its skipped when feature incorrectly assumes no changes.
drush @${ACQUIA_NAME}.$ENV --alias-path=${WORKSPACE}/profile/tmp/scripts/drush --yes features-revert-all --force
drush @${ACQUIA_NAME}.$ENV --alias-path=${WORKSPACE}/profile/tmp/scripts/drush --yes cache-clear all
# List feature statuses to audit whether reversions happened correctly.
drush @${ACQUIA_NAME}.$ENV --alias-path=${WORKSPACE}/profile/tmp/scripts/drush --yes features-list

# Rollback to initial commit if anything goes wrong
# https://cloudapi.acquia.com/#POST__sites__site_envs__env_dbs__db_backups__backup_restore-instance_route
# https://github.com/acquia/cloud-hooks/tree/master/samples/rollback_demo
