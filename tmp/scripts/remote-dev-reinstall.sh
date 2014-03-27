#!/bin/sh

set -e

: ${WORKSPACE:?"Need to set WORKSPACE"}
: ${PROJECT:?"Need to set PROJECT"}

drush @$PROJECT.dev site-install $PROJECT \
  --alias-path="$WORKSPACE/profile/tmp/scripts" \
  --account-pass="Champ&Hose_legend7repair" \
  --verbose \
  --yes \
