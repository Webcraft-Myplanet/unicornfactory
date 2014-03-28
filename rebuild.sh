#!/bin/bash
# This is a quick rebuild script that doesn't do all the things that
# the full build script does.
#
## ## README ##
#
# This file is only meant to be used after switching branches.
#
# It backs up all the projects that were previously downloaded from the make
# file and then downloads again, in case something is new, removed or updated.
#
# The purpose of the backup is to make sure that we don't kill the user's dev
# environment in cases of a failed drush_make build or accidental running
# of the script.

DIRS="modules/contrib themes/contrib libraries/contrib"
for d in $DIRS; do
  rm -Rf "$d.bak.tar.gz"
  mv $d "$d.bak"
  tar cvzf "$d.bak.tar.gz" "$d.bak"
  rm -Rf "$d.bak"
done
drush make --yes --working-copy --no-core --contrib-destination=. drupal-org.make

# Copy default.settings.php and append snippets again.
chmod u+w ../../sites/default
rm -f ../../sites/default/settings.bak.php
mv ../../sites/default/settings.php ../../sites/default/settings.bak.php
cp ../../sites/default/default.settings.php ../../sites/default/settings.php
chmod 666 ../../sites/default/settings.php

echo "Appending settings.php snippets..."
for f in tmp/snippets/settings.php/*.settings.php
do
  # Concatenate newline and snippet, then append to settings.php
  echo "" | cat - $f | tee -a ../../sites/default/settings.php > /dev/null
done

echo "Prepending .htaccess snippets at the start of file."
for f in tmp/snippets/htaccess/*.before.htaccess
do
  # Prepend a snippet and a new line to the existing .htaccess file
  echo "" | cat $f - | cat - ../../.htaccess > htaccess.tmp && mv htaccess.tmp ../../.htaccess
done

echo "Appending .htaccess snippets at the end of file..."
for f in tmp/snippets/htaccess/*.after.htaccess
do
  # Concatenate newline and snippet, then append to the existing .htaccess file
  echo "" | cat - $f | tee -a ../../.htaccess > /dev/null
done

echo "Copy files into docroot..."
# Copy files into docroot
cp -r tmp/copy_to_docroot/. ../../

chmod 444 ../../sites/default/settings.php
drush cc all
