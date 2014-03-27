#!/bin/sh

set -e

PROJECT=skeletor
ACQUIA_NAME=unicornfactory
ACAPI_USER=503e1095-ff56-49a4-d5c8-460fb24de041
ACAPI_PASS=DOVESPpDyImofQKAnOD1id2jTzLLTOzeFLXkXtaigkiA5q+TpEcbRaYU+S4ABO4RskXk4RxqdVYW

# Config how automated commits from Jenkins will show up in git log.
git config --global user.email "${PROJECT}@myplanetdigital.com"
git config --global user.name "Jenkins - Unicorn Factory"

# Turn on colored output (helpful for console log)
git config --global color.ui auto

mkdir -p ~/.ssh
echo -e "Host *\n  StrictHostKeyChecking no" > ~/.ssh/config

# Set up for rerun
export PATH=$PATH:${WORKSPACE}/profile/tmp/scripts/rerun/core
export RERUN_MODULES=${WORKSPACE}/profile/tmp/scripts/rerun/custom_modules
export RERUN_COLOR=true

# Error out if expected files don't exist.
requiredFiles=(
  "$WORKSPACE/profile/tmp/scripts/drush/$ACQUIA_NAME.acapi.drushrc.php"
  "$WORKSPACE/profile/tmp/scripts/drush/$ACQUIA_NAME.aliases.drushrc.php"
  "$WORKSPACE/profile/tmp/scripts/drush/cloudapi.acquia.com.pem"
  "$WORKSPACE/profile/tmp/scripts/drush/acapi.drush.inc"
)
for i in "${requiredFiles[@]}"; do
  printf "Checking for file: $i..."
  [ -f $i ] || exit 1
  echo " Success!"
done

#FIX THIS SOON AS IT IS UGLY
ACQUIA_SUBSCRIPTION=$ACQUIA_NAME rerun 2ndlevel:deploy \
  --project ${PROJECT} \
  --repo ${ACQUIA_NAME}@svn-3.devcloud.hosting.acquia.com:${ACQUIA_NAME}.git \
  --acapi-user $ACAPI_USER \
  --apapi-pass $ACAPI_PASS

# Not sure which one to use... kept this here in case we actually needed it.
#  --repo ${ACQUIA_NAME}@svn-3.devcloud.hosting.acquia.com:${ACQUIA_NAME}.git \
#  --acapi-user 503e1095-ff56-49a4-d5c8-460fb24de041 \
#  --apapi-pass DOVESPpDyImofQKAnOD1id2jTzLLTOzeFLXkXtaigkiA5q+TpEcbRaYU+S4ABO4RskXk4RxqdVYW
