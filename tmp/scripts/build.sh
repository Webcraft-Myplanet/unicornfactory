#!/bin/bash

# USAGE
# Run this script as given.
#
# $ bash build.sh [ path/to/project.make ] [ path/to/build/project ]
#
# (Default paths are for Vagrant VM.)

# Bail if non-zero exit code
set -e

PROJECT=unicornfactory

# Get absolute paths from relative
realpath() {
  [[ $1 = /* ]] && echo "$1" || echo "$PWD/${1#./}"
}

# Set from args
BUILD_FILE=`realpath "$1"`
BUILD_DEST=`realpath "$2"`

# Assume vagrant VM defaults if neither ENV variables nor args set
if [ -z "$BUILD_FILE" ]; then
  BUILD_FILE="/vagrant/data/make/${PROJECT}/build-${PROJECT}.local.make"
fi

if [ -z "$BUILD_DEST" ]; then
  BUILD_DEST="/mnt/www/html/${PROJECT}"
fi

# Drush make the site structure
drush make ${BUILD_FILE} ${BUILD_DEST} \
  --working-copy \
  --prepare-install \
  --no-gitinfofile \
  --yes

chmod u+w ${BUILD_DEST}/sites/default/settings.php

echo "Appending settings.php snippets..."
for f in ${BUILD_DEST}/profiles/${PROJECT}/tmp/snippets/*.settings.php
do
  # Concatenate newline and snippet, then append to settings.php
  echo "" | cat - $f | tee -a ${BUILD_DEST}/sites/default/settings.php > /dev/null
done

chmod u-w ${BUILD_DEST}/sites/default/settings.php

# Add snippet that allows basic auth through settings.php
tee -a ${BUILD_DEST}/.htaccess << 'EOH'

# Required for user/password authentication on development environments.
RewriteEngine on
RewriteRule .* - [E=REMOTE_USER:%{HTTP:Authorization},L]
EOH
