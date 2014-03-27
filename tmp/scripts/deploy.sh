#!/bin/bash
#
## README
#
# This script assumes that there will be a WORKSPACE directory with the install
# profile repo previously cloned as a contained folder called `profile/`, which
# has the desired branch checked out. You may get to this point like so:
#
#     $ git clone -b BRANCH http://github.com/USERNAME/PROJECT.git profile
#
# It expects to be passed an absolute path to this directory as the $WORKSPACE
# environment variable..
#
## USAGE:
#
#     $ WORKSPACE=/path/to/workspace bash deploy.sh
#
# The script will run build.sh and deploy the build to the development
# (integration) environment on devcloud. It assumes your SSH keys have access
# to the Acquia repo.
#

set -e

PROJECT=unicornfactory
BRANCH=develop

# Get commit message from install profile repo
COMMIT_MSG=`git --git-dir=$WORKSPACE/profile/.git log --oneline --max-count=1`

# Execute site build script
rerun 2ndlevel:build --build-file profile/build-${PROJECT}.make --destination build --project ${PROJECT}

git clone --branch ${BRANCH} ${PROJECT}@svn-1745.prod.hosting.acquia.com:${PROJECT}.git $WORKSPACE/acquia
cd $WORKSPACE/acquia
git rm -r --force --quiet docroot

# rsync build/ dir into acquia repo docroot/
# (excluding files according to patterns in file, accessible to developers.)
rsync --archive --exclude-from=$WORKSPACE/profile/tmp/scripts/docroot-exclude.txt $WORKSPACE/build/ $WORKSPACE/acquia/docroot/
git add --force docroot/

# Sanity check to see what was commited.
git status

# If nothing staged, `git diff --cached` exits with 0
# and so deploy script exits (no error)
if [ "$(git diff --quiet --exit-code --cached; echo $?)" -eq 0 ]; then
  echo 'DEPLOY SCRIPT: No changes staged, and so exiting gracefully...'
  exit 0
fi

# Script only gets here if something to commit.
# VVVVVV

git commit --message="Profile repo commit $COMMIT_MSG"

# TODO: Remove hardcoded branch?
git push origin ${BRANCH}

# Back up database before running remote drush commands on it.
# We request a backup with the Acquia CLI, and then use the
# task ID to poll for it to be 'done' before moving on.
# We provide output for the logs, and a cap of 10 API calls.
ACAPI_USER=d9b69484-7cf1-11e1-9eb5-12313928d5b8
ACAPI_PASS=Pau6uy8d9J3YBqxk3h7cWUqZYehOwRan1r/MafvsXGBU9FKNB1LUGcf9Tub0PHf3TGUPH74W1NYw
drush @unicornfactory.dev ac-api-login \
  --alias-path=${WORKSPACE}/profile/tmp/scripts \
  --username=${ACAPI_USER} \
  --password=${ACAPI_PASS}

TASK_ID=`drush @${PROJECT}.dev ac-database-backup ${PROJECT} --alias-path=${WORKSPACE}/profile/tmp/scripts | awk '{ print $2 }'`

poll_count=0
while [[ "`drush @${PROJECT}.dev ac-task-info $TASK_ID --alias-path=${WORKSPACE}/profile/tmp/scripts | grep -E '^ state' | awk '{ print $NF }'`" != "done" ]]
do
  poll_count=`expr $poll_count + 1`
  echo "API polls: $poll_count"
  if [[ "$poll_count" -gt 10 ]]; then
    exit
  fi
  sleep 1
done

# Use drush alias in repo so accessible to developers
drush @${PROJECT}.dev --alias-path=$WORKSPACE/profile/tmp/scripts --yes updatedb
drush @${PROJECT}.dev --alias-path=$WORKSPACE/profile/tmp/scripts --yes fra
drush @${PROJECT}.dev --alias-path=$WORKSPACE/profile/tmp/scripts --yes cc all
