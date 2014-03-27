<?php

/**
 * @file Acquia Cloud API commands
 */

/**
 * Implementation of hook_drush_command().
 */
function acapi_drush_command() {
  // All Acquia Cloud API commands accept a common set of options which are
  // centrally defined. Retrieve them with acapi_get_option().
  $options = acapi_common_options();

  // Most of the commands below use drush_acapi_ac_generic_callback, which
  // translates their 'method', 'resource', and 'arguments' properties into
  // the appropriate API call, executes it, and displays the result.

  //////////////////////////////////////////////////////////////////////
  // Login
  //////////////////////////////////////////////////////////////////////
  $items['ac-api-login'] = array(
    'description' => 'Store Acquia Cloud API credentials and configuration information.',
    'arguments' => array(
    ),
    'options' => $options + array(
      'reset' => 'Discard any existing stored values from a previous call. Without this option, new values will be merged with existing values.',
    ),
  );

  //////////////////////////////////////////////////////////////////////
  // Sites and environments
  //////////////////////////////////////////////////////////////////////
  $items['ac-site-list'] = array(
    'description' => 'List all sites available to the current user.',
    'arguments' => array(
    ),
    'method' => 'GET',
    'resource' => '/sites',
    'callback' => 'drush_acapi_ac_generic_callback',
    'options' => $options,
  );
  $items['ac-site-info'] = array(
    'description' => 'Show information about a site.',
    'arguments' => array(
    ),
    'method' => 'GET',
    'resource' => '/sites/:realm::site',
    'callback' => 'drush_acapi_ac_generic_callback',
    'options' => $options,
  );
  $items['ac-environment-list'] = array(
    'description' => "List a site's environments.",
    'arguments' => array(
    ),
    'method' => 'GET',
    'resource' => '/sites/:realm::site/envs',
    'callback' => 'drush_acapi_ac_generic_callback',
    'options' => $options,
  );
  $items['ac-environment-info'] = array(
    'description' => "Show information about a site environment.",
    'arguments' => array(
    ),
    'method' => 'GET',
    'resource' => '/sites/:realm::site/envs/:env',
    'callback' => 'drush_acapi_ac_generic_callback',
    'options' => $options,
  );
  $items['ac-environment-install'] = array(
    'description' => "Install a Drupal distribution from a pre-selected list, URL, or Drush Makefile.",
    'arguments' => array(
      'type' => 'Type of distro source: distro_url or make_url.',
      'source' => 'A URL to a distro or URL to a Drush make file.',
    ),
    'method' => 'POST',
    'resource' => '/sites/:realm::site/envs/:env/install/:type',
    'params' => array('source'),
    'callback' => 'drush_acapi_ac_generic_callback',
    'options' => $options,
  );
  $items['ac-environment-livedev'] = array(
    'description' => "Configure Live Development on a site environment.",
    'arguments' => array(
      'action' => 'Action to take.  \'enable\' or \'disable\' live development.',
      'discard' => 'When action is \'disable\', set to 1 to discard uncommitted changes.',
    ),
    'method' => 'POST',
    'resource' => '/sites/:realm::site/envs/:env/livedev/:action',
    'params' => array('discard'),
    'callback' => 'drush_acapi_ac_generic_callback',
    'options' => $options,
  );

  //////////////////////////////////////////////////////////////////////
  // Servers
  //////////////////////////////////////////////////////////////////////
  $items['ac-server-list'] = array(
    'description' => "List servers for a site and environment.",
    'arguments' => array(
    ),
    'method' => 'GET',
    'resource' => '/sites/:realm::site/envs/:env/servers',
    'callback' => 'drush_acapi_ac_generic_callback',
    'options' => $options,
  );
  $items['ac-server-info'] = array(
    'description' => "Show information about a server.",
    'arguments' => array(
      'server' => 'Server name.',
    ),
    'method' => 'GET',
    'resource' => '/sites/:realm::site/envs/:env/servers/:server',
    'callback' => 'drush_acapi_ac_generic_callback',
    'options' => $options,
  );
  $items['ac-server-php-procs'] = array(
    'description' => "Calculate the php max procs value based on possible memory limits and apc shm settings.",
    'arguments' => array(
      'server' => 'Server name.',
      'memory_limits' => 'Memory limits.',
      'apc_shm' => 'APC shm settings.'
    ),
    'method' => 'GET',
    'resource' => '/sites/:realm::site/envs/:env/servers/:server/php-procs',
    'params_array' => array(
      'memory_limits',
      'apc_shm',
    ),
    'callback' => 'drush_acapi_ac_generic_callback',
    'options' => $options,
  );

  //////////////////////////////////////////////////////////////////////
  // Databases
  //////////////////////////////////////////////////////////////////////
  $items['ac-database-list'] = array(
    'description' => "List a site's databases.",
    'arguments' => array(
    ),
    'method' => 'GET',
    'resource' => '/sites/:realm::site/dbs',
    'callback' => 'drush_acapi_ac_generic_callback',
    'options' => $options,
  );
  $items['ac-database-info'] = array(
    'description' => "Show information about a site database.",
    'arguments' => array(
      'db' => 'Database name.',
    ),
    'method' => 'GET',
    'resource' => '/sites/:realm::site/dbs/:db',
    'callback' => 'drush_acapi_ac_generic_callback',
    'options' => $options,
  );
  $items['ac-database-add'] = array(
    'description' => 'Add a database.',
    'arguments' => array(
      'db' => 'The database.',
    ),
    'method' => 'POST',
    'resource' => '/sites/:realm::site/dbs',
    'body_fields' => array('db'),
    'callback' => 'drush_acapi_ac_generic_callback',
    'options' => $options,
  );
  $items['ac-database-delete'] = array(
    'description' => 'Delete a database.',
    'arguments' => array(
      'db' => 'The database.',
    ),
    'default_params' => array(
      'backup' => 1,
    ),
    'method' => 'DELETE',
    'resource' => '/sites/:realm::site/dbs/:db',
    'callback' => 'drush_acapi_ac_generic_callback',
    'options' => $options + array('no-backup' =>
      array(
        'description' => 'Do not make a final backup of each instance of this database before deleting it.',
        'param' => 'backup',
        'value' => 0,
      ))
  );
  $items['ac-database-instance-list'] = array(
    'description' => "List a site environment's database instances.",
    'arguments' => array(
    ),
    'method' => 'GET',
    'resource' => '/sites/:realm::site/envs/:env/dbs',
    'callback' => 'drush_acapi_ac_generic_callback',
    'options' => $options,
  );
  $items['ac-database-instance-info'] = array(
    'description' => "Show information about a site environment's database instance.",
    'arguments' => array(
      'db' => 'Database name.',
    ),
    'method' => 'GET',
    'resource' => '/sites/:realm::site/envs/:env/dbs/:db',
    'callback' => 'drush_acapi_ac_generic_callback',
    'options' => $options,
  );
  $items['ac-database-instance-backup-list'] = array(
    'description' => "List a site environment's database instance backups.",
    'arguments' => array(
      'db' => 'Database name.',
    ),
    'method' => 'GET',
    'resource' => '/sites/:realm::site/envs/:env/dbs/:db/backups',
    'callback' => 'drush_acapi_ac_generic_callback',
    'options' => $options,
  );
  $items['ac-database-instance-backup-info'] = array(
    'description' => "Show information about a site environment's database instance backup.",
    'arguments' => array(
      'db' => 'Database name.',
      'backup' => 'Backup id.',
    ),
    'method' => 'GET',
    'resource' => '/sites/:realm::site/envs/:env/dbs/:db/backups/:backup',
    'callback' => 'drush_acapi_ac_generic_callback',
    'options' => $options,
  );
  $items['ac-database-instance-backup-download'] = array(
    'description' => "Download a site environment database instance backup.",
    'arguments' => array(
      'db' => 'Database name.',
      'backup' => 'Backup id.',
    ),
    'method' => 'GET',
    'resource' => '/sites/:realm::site/envs/:env/dbs/:db/backups/:backup/download',
    'callback' => 'drush_acapi_ac_database_backup_download',
    'options' => array('result-file' =>
      array(
        'description' => 'Save to a file; specify the full path in which to store the backup. If not provided, the backup is sent the standard output.',
        'example-value' => '/path/to/file',
      )) + $options,
  );
  $items['ac-database-instance-backup'] = array(
    'description' => 'Create a database instance backup.',
    'arguments' => array(
      'db' => 'The database.',
    ),
    'method' => 'POST',
    'resource' => '/sites/:realm::site/envs/:env/dbs/:db/backups',
    'callback' => 'drush_acapi_ac_generic_callback',
    'options' => $options,
  );
  $items['ac-database-instance-backup-restore'] = array(
    'description' => 'Restore a database instance backup.',
    'arguments' => array(
      'db' => 'The database.',
      'backupid' => 'The backup id.',
    ),
    'method' => 'POST',
    'resource' => '/sites/:realm::site/envs/:env/dbs/:db/backups/:backupid/restore',
    'callback' => 'drush_acapi_ac_generic_callback',
    'options' => $options,
  );
  $items['ac-database-instance-backup-delete'] = array(
    'description' => 'Delete a database instance backup.',
    'arguments' => array(
      'db' => 'The database.',
      'backupid' => 'The backup id.',
    ),
    'method' => 'DELETE',
    'resource' => '/sites/:realm::site/envs/:env/dbs/:db/backups/:backupid',
    'callback' => 'drush_acapi_ac_generic_callback',
    'options' => $options,
  );

  //////////////////////////////////////////////////////////////////////
  // Tasks
  //////////////////////////////////////////////////////////////////////
  // API resource /sites/:realm::site/tasks returns an array of task records,
  // unlike other list resources which return a list of ids, so we need a
  // non-standard callback. We'd have to make N API calls to implement this the
  // way other data types work, which I think shows that the returning a list of
  // records is better.
  $items['ac-task-list'] = array(
    'description' => "List a site's tasks.",
    'arguments' => array(
    ),
    'options' => array (
      'state' => array (
        'description' => 'The task state to retrieve. If not specified, retrieve all tasks for the site.',
        'example-value' => 'done',
      )) + $options,
  );

  $items['ac-task-info'] = array(
    'description' => "Show information about a site task.",
    'arguments' => array(
      'task' => 'The task id.',
    ),
    'method' => 'GET',
    'resource' => '/sites/:realm::site/tasks/:task',
    'callback' => 'drush_acapi_ac_generic_callback',
    'options' => $options,
  );

  //////////////////////////////////////////////////////////////////////
  // Workflow
  //////////////////////////////////////////////////////////////////////
  $items['ac-code-deploy'] = array(
    'description' => 'Deploy code from one site environment to another.',
    'arguments' => array(
      'target' => 'The target environment.',
    ),
    'method' => 'POST',
    'resource' => '/sites/:realm::site/code-deploy/:env/:target',
    'callback' => 'drush_acapi_ac_generic_callback',
    'options' => $options,
  );
  $items['ac-code-path-deploy'] = array(
    'description' => 'Deploy a specific branch or tag in an environment.',
    'arguments' => array(
      'path' => 'The branch or tag to deploy.',
    ),
    'method' => 'POST',
    'resource' => '/sites/:realm::site/envs/:env/code-deploy',
    'params' => array('path'),
    'callback' => 'drush_acapi_ac_generic_callback',
    'options' => $options,
  );
  $items['ac-database-copy'] = array(
    'description' => 'Copy a database from one site environment to another.',
    'arguments' => array(
      'db' => 'The database.',
      'target' => 'The target environment.',
    ),
    'method' => 'POST',
    'resource' => '/sites/:realm::site/dbs/:db/db-copy/:env/:target',
    'callback' => 'drush_acapi_ac_generic_callback',
    'options' => $options,
  );
  $items['ac-files-copy'] = array(
    'description' => 'Copy user-uploaded files from one site environment to another.',
    'arguments' => array(
      'target' => 'The target environment.',
    ),
    'method' => 'POST',
    'resource' => '/sites/:realm::site/files-copy/:env/:target',
    'callback' => 'drush_acapi_ac_generic_callback',
    'options' => $options,
  );
  $items['ac-domain-move'] = array(
    'description' => 'Move a domain from one site environment to another.',
    'arguments' => array(
      'target' => 'The target environment.',
      'domains' => 'Comma separated list of domains, or * for all.',
    ),
    'method' => 'POST',
    'resource' => '/sites/:realm::site/domain-move/:env/:target',
    'body_fields_array' => array('domains'),
    'callback' => 'drush_acapi_ac_generic_callback',
    'options' => $options,
  );

  //////////////////////////////////////////////////////////////////////
  // SSH keys
  //////////////////////////////////////////////////////////////////////
  $items['ac-sshkey-list'] = array(
    'description' => "List a site's SSH keys.",
    'arguments' => array(
    ),
    'method' => 'GET',
    'resource' => '/sites/:realm::site/sshkeys',
    'callback' => 'drush_acapi_ac_generic_callback',
    'options' => $options,
  );
  $items['ac-sshkey-info'] = array(
    'description' => "Show information about a site SSH key.",
    'arguments' => array(
      'sshkeyid' => 'SSH key id.',
    ),
    'method' => 'GET',
    'resource' => '/sites/:realm::site/sshkeys/:sshkeyid',
    'callback' => 'drush_acapi_ac_generic_callback',
    'options' => $options,
  );
  $items['ac-sshkey-add'] = array(
    'description' => 'Add an SSH key to a site.',
    'arguments' => array(
      'ssh_pub_key' => 'File containing the SSH public key.',
      'nickname' => 'The SSH key nickname.',
    ),
    'method' => 'POST',
    'resource' => '/sites/:realm::site/sshkeys',
    'params' => array('nickname'),
    'body_fields_path' => array('ssh_pub_key'),
    'callback' => 'drush_acapi_ac_generic_callback',
    'options' => $options,
  );
  $items['ac-sshkey-delete'] = array(
    'description' => 'Delete an SSH key from a site.',
    'arguments' => array(
      'sshkeyid' => 'The SSH key id to delete.',
    ),
    'method' => 'DELETE',
    'resource' => '/sites/:realm::site/sshkeys/:sshkeyid',
    'callback' => 'drush_acapi_ac_generic_callback',
    'options' => $options,
  );

  //////////////////////////////////////////////////////////////////////
  // SVN users
  //////////////////////////////////////////////////////////////////////
  $items['ac-svnuser-list'] = array(
    'description' => "List a site's SVN users.",
    'arguments' => array(
    ),
    'method' => 'GET',
    'resource' => '/sites/:realm::site/svnusers',
    'callback' => 'drush_acapi_ac_generic_callback',
    'options' => $options,
  );
  $items['ac-svnuser-info'] = array(
    'description' => "Show information about a site SVN user.",
    'arguments' => array(
      'svnuserid' => 'SVN user id.',
    ),
    'method' => 'GET',
    'resource' => '/sites/:realm::site/svnusers/:svnuserid',
    'callback' => 'drush_acapi_ac_generic_callback',
    'options' => $options,
  );
  $items['ac-svnuser-add'] = array(
    'description' => 'Add an SVN user to a site.',
    'arguments' => array(
      'username' => 'SVN username.',
      'password' => 'SVN password.',
    ),
    'method' => 'POST',
    'resource' => '/sites/:realm::site/svnusers/:username',
    'body_fields' => array('password'),
    'callback' => 'drush_acapi_ac_generic_callback',
    'options' => $options,
  );
  $items['ac-svnuser-delete'] = array(
    'description' => 'Delete an SVN user from a site.',
    'arguments' => array(
      'svnuserid' => 'The SVN user id to delete.',
    ),
    'method' => 'DELETE',
    'resource' => '/sites/:realm::site/svnusers/:svnuserid',
    'callback' => 'drush_acapi_ac_generic_callback',
    'options' => $options,
  );

  //////////////////////////////////////////////////////////////////////
  // Domains
  //////////////////////////////////////////////////////////////////////
  $items['ac-domain-list'] = array(
    'description' => "List a site's domains.",
    'arguments' => array(
    ),
    'method' => 'GET',
    'resource' => '/sites/:realm::site/envs/:env/domains',
    'callback' => 'drush_acapi_ac_generic_callback',
    'options' => $options,
  );
  $items['ac-domain-info'] = array(
    'description' => "Show information about a site domain.",
    'arguments' => array(
      'domain' => 'Domain name.',
    ),
    'method' => 'GET',
    'resource' => '/sites/:realm::site/envs/:env/domains/:domain',
    'callback' => 'drush_acapi_ac_generic_callback',
    'options' => $options,
  );
  $items['ac-domain-add'] = array(
    'description' => "Add a domain name to an environment.",
    'arguments' => array(
      'domain' => 'Domain name.',
    ),
    'method' => 'POST',
    'resource' => '/sites/:realm::site/envs/:env/domains/:domain',
    'callback' => 'drush_acapi_ac_generic_callback',
    'options' => $options,
  );
  $items['ac-domain-delete'] = array(
    'description' => "Delete a domain name from an environment.",
    'arguments' => array(
      'domain' => 'Domain name.',
    ),
    'method' => 'DELETE',
    'resource' => '/sites/:realm::site/envs/:env/domains/:domain',
    'callback' => 'drush_acapi_ac_generic_callback',
    'options' => $options,
  );
  $items['ac-domain-purge'] = array(
    'description' => "Purge a domain from the Varnish cache.",
    'arguments' => array(
      'domain' => 'Domain name.',
    ),
    'method' => 'DELETE',
    'resource' => '/sites/:realm::site/envs/:env/domains/:domain/cache',
    'callback' => 'drush_acapi_ac_generic_callback',
    'options' => $options,
  );

  foreach ($items as $command => $item) {
    $items[$command]['orig_options'] = $item['options'];
    if (DRUSH_VERSION < 5) {
      // Make our command structure work with previous versions of drush while
      // still supporting the way we handle arguments, options, and defaults.
      $items[$command]['argument-description'] = $item['arguments'];
      foreach ($item['options'] as $option => $info) {
        $items[$command]['options'][$option] = $info['description'];
      }
    }
    else {
      $items[$command]['handle-remote-commands'] = TRUE;
    }

    $items[$command]['bootstrap'] = DRUSH_BOOTSTRAP_DRUSH;
    $items[$command]['required-arguments'] = TRUE;
  }

  return $items;
}

function acapi_drush_help($section) {
  switch ($section) {
    case 'drush:ac-api-login':
      $file = '$HOME/.acquia/cloudapi.conf';
      return dt("Store Acquia Cloud API credentials and endpoint information.

This command stores default email, key, and optionally endpoint values for future Acquia Cloud API commands in @file. File location can be altered with the ac-config option on all Acquia Cloud commands.", array('@file' => $file));
  }
}

/**
 * Returns site specific acapi config file.
 */
function drush_acapi_get_config($site) {
  $acp = drush_get_option('acapi-conf-path', FALSE);
  return !empty($acp) ? $acp . "/$site.acapi.drushrc.php" : _drush_config_file('home.drush', "$site.acapi");
}


/**
 * Login. Store default options in ~/.drush/$site.acapi.drushrc.php for use by
 * future calls.
 */
function drush_acapi_ac_api_login() {
  $acapi_options = drush_get_option('acapi', array());
  $defaults = acapi_common_options();
  $file = drush_get_option('ac-config', $defaults['ac-config']['default_value']);

  // Preserve existing defaults by loading them unless the user said not to.
  $reset = drush_get_option('reset', FALSE);
  if (! $reset) {
    drush_load_config_file('home.user', $file);
  }

  // Collect specified values for each option, prompting if appropriate.
  foreach ($defaults as $k => $info) {
    if (in_array($k, array('email', 'key', 'endpoint'))){
      $default = isset($acapi_options[$k]) ? $acapi_options[$k] : $info['default_value'];
      $option = drush_get_option($k, $default);
      if (empty($option) && !empty($info['prompt'])) {
        $option = call_user_func_array('drush_prompt', $info['prompt']);
      }
      // Only save non-default values so we can update the defaults without pain.
      if ($option != $info['default_value']) {
        $acapi_options[$k] = $option;
      }
    }
  }

  $dt_args = array('@file' => $file);
  $verbose = drush_get_option('verbose', FALSE);
  $simulate = drush_get_option('simulate', FALSE);
  if ($verbose || $simulate) {
    drush_log(dt('Storing Acquia Cloud API defaults in @file.', $dt_args), 'ok');
  }
  if ($verbose) {
    drush_print($output);
  }
  if (! $simulate) {
    $output = "<?php
// WARNING! This file was created by drush ac-api-login. Changes to this
// file will be lost if you run ac-api-login again.

";
    foreach ($acapi_options as $option => $value) {
        $output .= "\$options['acapi']['$option'] = '$value';\n";
    }
    if (file_put_contents($file, $output) === FALSE) {
      return drush_set_error('ACAPI_CANNOT_WRITE_LOGIN', dt('Cannot write to Acquia Cloud API defaults file @file.', $dt_args));
    }
  }
}

//////////////////////////////////////////////////////////////////////
// Custom callbacks
//////////////////////////////////////////////////////////////////////

/**
 * List a site's tasks. See the command definition for why this function is
 * different.
 */
function drush_acapi_ac_database_backup_download($db, $backupid) {
  $command = drush_get_context('command');
  list($site, $env) = acapi_get_site();
  $simulate = drush_get_option('simulate', FALSE);
  $result_file = drush_get_option('result-file', '');
  // Similar to drush_sql_build_dump_command(). If the user has set
  // $options['result-file'] = TRUE, then we will generate an SQL dump file in
  // an automatically-generated backup directory based on site and env values.
  if ($result_file === TRUE) {
    // User did not pass a specific value for --result-file. Make one.
    $backup = drush_include_engine('version_control', 'backup');
    $backup_dir = $backup->prepare_backup_dir($site . '.' . $env);
    if (empty($backup_dir)) {
      $backup_dir = "/tmp";
    }
    $result_file = $backup_dir . '/' . $db . '-' . $backupid .'.sql.gz';
  }
  if ($result_file == '') {
    $fp = STDOUT;
  }
  else {
    $fp = fopen($result_file, 'w');
    if ($fp == NULL) {
      return drush_set_error('ACAPI_ENOENT', dt('Cannot write to result file @result_file.', array('@name' => $result_file)));
    }
  }

  $api_args = acapi_get_site_args() + array(
    ':db' => $db,
    ':backup' => $backupid,
  );
  list($status, $result) = acapi_call(
    $command['method'],
    $command['resource'],
    $api_args,
    array(),
    array(),
    array('result_stream' => $fp, 'redirect' => 1, 'display' => FALSE)
  );
}

/**
 * List a site's tasks. See the command definition for why this function is
 * different.
 */
function drush_acapi_ac_task_list() {
  $api_args = acapi_get_site_args();
  $format = acapi_get_option('format');
  $state = drush_get_option('state', NULL);
  $params = array();
  if (isset($state)) {
    $params['state'] = $state;
  }

  list($status, $result) = acapi_call(
    'GET',
    '/sites/:realm::site/tasks',
    $api_args,
    $params,
    array(),
    array('display' => !empty($format))
  );

  $simulate = drush_get_option('simulate', FALSE);
  if ($simulate) {
    return;
  }

  if (empty($format)) {
    $display = array();
    foreach ($result as $id => $task) {
      $display[$task->id] = $task->description;
    }
    drush_print_table(drush_key_value_to_array_table($display));
  }
}

//////////////////////////////////////////////////////////////////////
// Utility functions
//////////////////////////////////////////////////////////////////////

/**
 * Define common options for Acquia Cloud API commands, and their defaults.
 */
function acapi_common_options() {
  $options = array(
    'username' => array(
      'description' => 'Acquia Cloud API username',
      'default_value' => '',
      'example-value' => 'username',
    ),
    'password' => array(
      'description' => 'Acquia Cloud API password',
      'default_value' => '',
      'example-value' => 'password',
    ),
    'email' => array(
      'description' => 'Acquia Cloud API email',
      'default_value' => '',
      'prompt' => array('Email', NULL, TRUE, FALSE),
      'example-value' => 'example@acquia.com',
    ),
    'key' => array(
      'description' => 'Acquia Cloud API key',
      'default_value' => '',
      'prompt' => array('Key', NULL, TRUE, TRUE),
      'example-value' => 'apikey',
    ),
    'acapi-conf-path' => array(
      'description' => 'Acquia Cloud API config files location. If not specified config will be loaded from $HOME/.drush',
      'default_value' => '',
      'example-value' => '/home/user/acapi-site-configs',
    ),
    'ac-config' => array(
      'description' => 'Acquia Cloud API user config file location. If not specified config will be loaded from $HOME',
      'default_value' => drush_server_home() . '/.acquia/cloudapi.conf',
      'example-value' => drush_server_home() . '/.acquia/cloudapi-site-specific.conf',
    ),
    'endpoint' => array(
      'description' => 'Acquia Cloud API endpoint URL.',
      'default_value' => 'https://cloudapi.acquia.com/v1',
      'example-value' => 'https://cloudapi.acquia.com/v1',
    ),
    'cainfo' => array(
      'description' => 'Path to a file containing the SSL certificates needed to verify the ac-api-endpoint.',
      'default_value' => dirname(__FILE__) . '/cloudapi.acquia.com.pem',
      'example-value' => 'cloudapi.acquia.com.pem',
    ),
    'format' => array(
      'description' => 'Format to output the object. Use "print_r" for print_r, "export" for var_export, and "json" for JSON. If not provided, the output is printed in a human-readable format.',
      'default_value' => '',
      'example-value' => 'json',
    ),
  );
  return $options;
}

/**
 * Retrieve an Acquia Cloud API default option.
 *
 * @param $name
 *   An ac-api option name.
 * @return
 *   The option value from the command line, or stashed per-site option, or
 *   the default from acapi_common_options().
 */
function acapi_get_option($name) {
  list($site) = acapi_get_site();

  $options = acapi_common_options();
  if (!isset($options[$name])) {
    return drush_set_error('ACAPI_UNKNOWN_OPTION', dt('Unknown ac-api option @name.', array('@name' => $name)));
  }

  $value = drush_get_option($name, NULL);
  if (isset($value)) {
    return $value;
  }

  drush_load_config_file('home.user', drush_get_option('ac-config', $options['ac-config']['default_value']));
  $acapi_options = drush_get_option('acapi', array(), 'home.user');
  if (isset($acapi_options[$name])) {
    return $acapi_options[$name];
  }

  drush_load_config_file('home.drush', drush_acapi_get_config($site));
  $acapi_options = drush_get_option('acapi', array());
  if (isset($acapi_options[$site][$name])) {
    return $acapi_options[$site][$name];
  }

  if (!empty($options[$name]['default_value'])) {
    return $options[$name]['default_value'];
  }

  return;
}

/**
 * A generic callback for API commands. The command must have:
 *
 * 'method': $method for acapi_call().
 * 'resource': $resource for acapi_call(). API resource argument names can
 * include any argument name from the command's arguments in addition to :site
 * and :env which are taken from the site alias.
 *
 * The command calls acapi_call() with arguments for the specified method,
 * resource, and arguments, calling the API and displaying the results.
 */
function drush_acapi_ac_generic_callback() {
  $command = drush_get_context('command');
  $api_args = acapi_get_site_args();
  $params = array();
  $body = array();

  if (isset($command['default_params'])) {
    $params += $command['default_params'];
  }

  foreach ($command['argument-description'] as $k => $desc) {
    if (isset($command['params']) && array_search($k, $command['params']) !== FALSE) {
      $params[$k] = array_shift($command['arguments']);
    }
    elseif (isset($command['params_array']) && array_search($k, $command['params_array']) !== FALSE) {
      $params[$k] = explode(',', array_shift($command['arguments']));
    }
    elseif (isset($command['body_fields']) && array_search($k, $command['body_fields']) !== FALSE) {
      $body[$k] = array_shift($command['arguments']);
    }
    elseif (isset($command['body_fields_array']) && array_search($k, $command['body_fields_array']) !== FALSE) {
      $body[$k] = explode(',', array_shift($command['arguments']));
    }
    elseif (isset($command['body_fields_path']) && array_search($k, $command['body_fields_path']) !== FALSE) {
      $path = array_shift($command['arguments']);
      $body[$k] = file_get_contents($path);
      if ($body[$k] === FALSE) {
        drush_set_error('ACAPI_ENOENT', dt('Cannot read @arg path @path.', array('@arg' => $k, '@path' => $path)));
        return;
      }
    }
    else {
      $api_args[":$k"] = array_shift($command['arguments']);
    }
  }

  foreach ($command['orig_options'] as $option => $info) {
    if (!empty($info['param'])) {
      if (drush_get_option($option, FALSE)) {
        $params[$info['param']] = $info['value'];
      }
    }
  }

  return acapi_call($command['method'], $command['resource'], $api_args, $params, $body);
}

/**
 * Return the Acquia Cloud site information specified via the site
 * alias.
 *
 * @return
 *   An array of three elements, site name, environment and realm unless the
 *   alias file pre-dates the addition of realm.
 */
function acapi_get_site() {
  return array_values(acapi_get_site_args());
}

/**
 * Get arguments aboud the Acquia Cloud site ready to be used for replacement
 * in a URI.
 *
 * Calls drush_set_error if the site alias options are not found.
 *
 * @return array
 *   An associative array containing :site, :env and :realm (if not BC) or an
 *   empty array if site alias option not found.
 */
function acapi_get_site_args() {
  // Use the presence of ac-site to imply namespaced options, else BC.
  // @todo - Remove backwards compatibility someday.
  $site = drush_get_option('ac-site');
  if ($site) {
    $params = array(
      ':site' => $site,
      ':env' => drush_get_option('ac-env'),
      ':realm' => drush_get_option('ac-realm'),
    );
  }
  else {
    $params = array(
      ':site' => drush_get_option('site'),
      ':env' => drush_get_option('env'),
    );
  }

  $missing = array_intersect($params, array(NULL));
  if ($missing) {
    $missing = str_replace(':', 'ac-', implode(', ', array_keys($missing)));
    $error = dt(
      'Alias file is missing Acquia Cloud information: !missing',
      array('!missing' => $missing)
    );
    drush_set_error('ACAPI_SITE_REQUIRED', $error);
    return array();
  }

  return $params;
}

/**
 * Call an Acquia Cloud API resource.
 *
 * @param $method
 *   The HTTP method; e.g. GET.
 * @param $resource
 *   The API function to call; e.g. /sites/:realm::site.
 * @param $args = array()
 *   An array of argument values for the resource; e.g: array(':site' =>
 *   'mysite').
 * @params $params = array()
 *   An array of query parameters to append to the URL.
 * @params $body = array()
 *   An array of parameters to include in the POST body in JSON format.
 * @params $options = array()
 *   An array of options:
 *   - display (TRUE): whether to output the result to stdout
 *   - result_stream: open stream to which to write the response body
 *   - redirect: the maximum number of redirects to allow
 */
function acapi_call($method, $resource, $args, $params = array(), $body = array(), $options = array()) {
  $default_options = array(
    'display' => TRUE,
  );
  $options = array_merge($default_options, $options);

  $debug = drush_get_option('debug', FALSE);
  $verbose = drush_get_option('verbose', FALSE);
  $simulate = drush_get_option('simulate', FALSE);
  $format = acapi_get_option('format');

  // Maintain backwards compatibility with alias files created before ac-realm.
  // @todo - Remove this BC someday.
  if (!isset($args[':realm']) && strpos($resource, '/sites/:realm:') === 0) {
    $resource = str_replace('/sites/:realm:', '/sites/', $resource);
  }

  // Build the API call URL.
  $url = acapi_get_option('endpoint');
  $url .= acapi_dt($resource, $args);
  $url .= '.json';

  foreach ($params as $k => $v) {
    if (is_array($v)) {
      unset($params[$k]);
      foreach ($v as $key => $val) {
        $params["$k-$key"] = "$k%5B%5D=" . urlencode($val);
      }
    }
    else {
      $params[$k] = "$k=" . urlencode($v);
    }
  }

  $url .= '?' . implode('&', $params);

  $creds = acapi_get_creds();
  if (!$creds) {
    return FALSE;
  }

  // Build the body.
  $json_body = json_encode($body);

  $display = "curl -X $method '$url'";
  if ($debug) {
    $display .= " ($creds)";
  }
  if ($debug || $verbose || $simulate) {
    drush_print($display, 0, STDERR);
    if (!empty($body)) {
      drush_print("  $json_body", 0, STDERR);
    }
  }

  if ($simulate) {
    return;
  }

  $headers = array();
  $ch = curl_init($url);
  // Basic request settings
  curl_setopt($ch, CURLOPT_CUSTOMREQUEST, $method);
  curl_setopt($ch, CURLOPT_USERAGENT, basename(__FILE__));
  if (!empty($options['result_stream'])) {
    curl_setopt($ch, CURLOPT_FILE, $options['result_stream']);
  }
  else {
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, TRUE);
  }
  // User authentication
  curl_setopt($ch, CURLOPT_HTTPAUTH, TRUE);
  curl_setopt($ch, CURLOPT_USERPWD, $creds);
  // SSL
  curl_setopt($ch, CURLOPT_SSL_VERIFYHOST, 2);
  curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, preg_match('@^https:@', acapi_get_option('endpoint')));
  curl_setopt($ch, CURLOPT_CAINFO, acapi_get_option('cainfo'));
  // Redirects
  if (!empty($options['redirect'])) {
    curl_setopt($ch, CURLOPT_FOLLOWLOCATION, TRUE);
    curl_setopt($ch, CURLOPT_MAXREDIRS, $options['redirect']+1);
  }
  /* Body
     We need to set a Content-Length header even on empty POST requests, or the webserver
     will throw a 411 Length Required.
  */
   
  curl_setopt($ch, CURLOPT_POSTFIELDS, $json_body);
  $headers[] = 'Content-Type: application/json;charset=utf-8';
  $headers[] = 'Content-Length: ' . strlen($json_body);
  // Headers
  if (!empty($headers)) {
    curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);
  }
  // Debugging
  curl_setopt($ch, CURLOPT_VERBOSE, $debug);
  // Go
  $content = curl_exec($ch);
  if (curl_errno($ch) > 0) {
    return drush_set_error('ACAPI_CURL_ERROR', dt('Error accessing API: @err', array('@err' => curl_error($ch))));
  }

  $result = json_decode($content);
  $status = curl_getinfo($ch, CURLINFO_HTTP_CODE);
  curl_close($ch);

  if (!empty($format)) {
    drush_print(drush_format($result, NULL, $format));
  }
  else if ($options['display']) {
    if (is_array($result)) {
      foreach ($result as $item) {
        if (! is_scalar($item)) {
          drush_print_table(drush_key_value_to_array_table(acapi_convert_values($item)));
        }
        else {
          drush_print($item);
        }
      }
    }
    else {
      if ($method == 'POST') {
        // All POST actions return a task. Display something helpful.
        drush_log(dt('Task @taskid started.', array('@taskid' => $result->id)), 'ok');
      }
      else {
        drush_print_table(drush_key_value_to_array_table(acapi_convert_values($result)));
      }
    }
  }

  if ($status != 200) {
    return drush_set_error('ACAPI_HTTP_STATUS_' . $status, dt('API status code @status', array('@status' => $status)));
  }

  return array($status, $result);
}

/**
 * Return Acquia Cloud API credentials as username:password, or log an error
 * if they are unavailable.
 */
function acapi_get_creds() {

  if (file_exists(acapi_get_option('ac-config'))){
    $user = acapi_get_option('email');
    $pass = acapi_get_option('key');
  }
  else{
    $user = acapi_get_option('username');
    $pass = acapi_get_option('password');
  }
  if (empty($user)) {
    return drush_set_error('ACAPI_CREDS_MISSING', dt('Email and api key required; specify --email/--key or run drush ac-api-login'));
  }
  return "$user:$pass";
}

/**
 * Convert NULL, array and object values to appropriate string representations
 * so they are printed correctly.
 */
function acapi_convert_values($arr) {
  foreach ($arr as $k => $v) {
    if (!isset($v)) {
      $arr->{$k} = '';
    }
    elseif (is_array($v) || is_object($v)) {
      $arr->{$k} = '...';
    }
  }
  return (array) $arr;
}

/**
 * dt() wrapper that URL-encodes all substituted parameters that begin with
 * a colon (':').
 */
function acapi_dt($string, $args = array()) {
  foreach ($args as $k => $v) {
    if ($k[0] == ':') {
      $args[$k] = urlencode($v);
    }
  }
  return dt($string, $args);
}
