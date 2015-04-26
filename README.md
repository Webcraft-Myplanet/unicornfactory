UPDATE: As of April 26, 2015 - please note that the post-commit hook that kicks off Jenkins no longer will function as expected.  The Jenkins environment was deprovisioned and removed due to lack of use.

Unicorn Factory Install Profile
===========================

This is the D7 install profile for the Unicorn Factory project, which
was built to help facilitate our individual metamorphosis’ into Unicorns.

It is based on the [install profile for the unicornfactory project](https://github.com/myplanetdigital/drupal-unicornfactory), to set up an
appropriate layout for a build-based development strategy, striving
toward continuous delivery and great good.

Requirements
------
* PHP 5.3+
* MySQL 5+
* drush command line tool

Installation
------

From a fresh D7 install, place a file named `settings.local.php` inside of `/sites/default` with the following content. Customize for your localmachine setup, IE mysql default port is 3306. You may set the database, username and password to whatever you like:
    
    <?php

    $databases = array (
      'default' =>
      array (
        'default' =>
        array (
          'database' => 'uf_database',
          'username' => 'uf_username',
          'password' => 'uf_password',
          'host' => 'localhost',
          'port' => '8889',
          'driver' => 'mysql',
          'prefix' => '',
        ),
      ),
    );

    $conf['gauth_login_client_id'] = '';
    $conf['gauth_login_client_secret'] = '';
    $conf['gauth_login_developer_key'] = '';

1. Create a database that matches the credentials in the above `$databases` settings.
2. `git clone` this repository inside of `/profiles`
3. Create a file `settings.local.php` in `/sites/default/settings.local.php` with the following content:
4. cd to the folder and run `./rebuild.sh`
5. Run `drush si unicornfactory -y --account-pass="admin"` from profiles folder

Usage
------

The administration login to the website is:

    Username: admin
    Password: admin

Layout
------

We will be attempting to follow the drush make guidelines laid out for
packaging distributions on drupal.org:

http://drupal.org/node/1476014

The rationale being that when we layout our projects according to these
guidelines, we don't need to document as much, and we will also know how
to package our own distribution for drupal.org in the future.

Here's the additional suggested folder structure for the install profile:

    +-modules/
    | +-contrib/  (gitignored - all contrib modules should go here via makefile)
    | +-custom/   (custom modules for the site)
    | +-features/ (all feature modules)
    +-themes/
    | +-contrib/  (gitignored - any contrib themes should go here via makefile)
    | +-custom/   (custom themes for the site)
    +-libraries/  (gitignored - any libraries should go here via makefile)
    +-tmp/        (for things that don't fit in standard install profile structure)
      +-conf/
      +-docs/     (project-specific docs)
      +-patches/
      +-scripts/  (any scripts related to project)
      +-snippets/ (settings.php and htaccess snippets)
      | +-htaccess/
      | +-settings.php/
      +-tests/

* If you'd like any code to be appended to `settings.php`, simply add a
snippet as `tmp/snippets/settings.php/mysnippetname.settings.php`. These
snippets will be appended in alphabetical order during the build script.
This is my modification.
