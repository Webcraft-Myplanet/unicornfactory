Unicorn Factory Install Profile
===========================

This is the D7 install profile for the Unicorn Factory project, which
was built to help facilitate our individual metamorphosis’ into Unicorns.

It is based on the [install profile for the skeletor project](https://github.com/myplanetdigital/drupal-skeletor), to set up an
appropriate layout for a build-based development strategy, striving
toward continuous delivery and great good.

Requirements
------
* PHP 5.3+
* MySQL 5+
* drush command line tool

Installation
------

From a fresh D7 install, place a file named `settings.local.php` inside of `/sites/default` with the following content:
  <?php
  $databases = array (
    'default' => 
    array (
      'default' => 
      array (
        'database' => 'wow-imdb',
        'username' => 'wow-imdb',
        'password' => 'wow-imdb',
        'host' => 'localhost',
        'port' => '8889',
        'driver' => 'mysql',
        'prefix' => '',
      ),
    ),
  );

  $conf['gauth_login_client_id'] = '280058925066-7041r56djibva392p9030frmrqc2gftm.apps.googleusercontent.com';
  $conf['gauth_login_client_secret'] = 'WrXGloHGS4EkPYnOextYKr2o';
  $conf['gauth_login_developer_key'] = 'AIzaSyCJQPJinqfjRMdfUor2JnGdQqYyJU8pGO4';

1. Place this folder inside of `/profiles`
2. Create a file `settings.local.php` in `/sites/default/settings.local.php` with the following content:
3. cd to the folder and run `./rebuild.sh`
3. Install your database for the first time using `drush si skeletor`
4. Run `./druf` to re-install site on the database with desired default values

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
