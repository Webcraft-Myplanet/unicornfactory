<?php
/**
 * @file
 * uf_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function uf_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'views',
  );

  // Exported permission: 'access backup and migrate'.
  $permissions['access backup and migrate'] = array(
    'name' => 'access backup and migrate',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'access backup files'.
  $permissions['access backup files'] = array(
    'name' => 'access backup files',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'Administrator1' => 'Administrator1',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access custom config'.
  $permissions['access custom config'] = array(
    'name' => 'access custom config',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'custom_config',
  );

  // Exported permission: 'access devel information'.
  $permissions['access devel information'] = array(
    'name' => 'access devel information',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'system',
  );

  // Exported permission: 'admin custom config'.
  $permissions['admin custom config'] = array(
    'name' => 'admin custom config',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'custom_config',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer advanced pane settings'.
  $permissions['administer advanced pane settings'] = array(
    'name' => 'administer advanced pane settings',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer backup and migrate'.
  $permissions['administer backup and migrate'] = array(
    'name' => 'administer backup and migrate',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'block',
  );

  // Exported permission: 'administer ckeditor'.
  $permissions['administer ckeditor'] = array(
    'name' => 'administer ckeditor',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'ckeditor',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer empty page callbacks'.
  $permissions['administer empty page callbacks'] = array(
    'name' => 'administer empty page callbacks',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'empty_page',
  );

  // Exported permission: 'administer features'.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'features',
  );

  // Exported permission: 'administer field collections'.
  $permissions['administer field collections'] = array(
    'name' => 'administer field collections',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'field_collection',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'image',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer page manager'.
  $permissions['administer page manager'] = array(
    'name' => 'administer page manager',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: 'administer pane access'.
  $permissions['administer pane access'] = array(
    'name' => 'administer pane access',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels layouts'.
  $permissions['administer panels layouts'] = array(
    'name' => 'administer panels layouts',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels styles'.
  $permissions['administer panels styles'] = array(
    'name' => 'administer panels styles',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer pathauto'.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer services'.
  $permissions['administer services'] = array(
    'name' => 'administer services',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'services',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer theme assignments'.
  $permissions['administer theme assignments'] = array(
    'name' => 'administer theme assignments',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'themekey',
  );

  // Exported permission: 'administer themekey settings'.
  $permissions['administer themekey settings'] = array(
    'name' => 'administer themekey settings',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'themekey',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'path',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer uuid'.
  $permissions['administer uuid'] = array(
    'name' => 'administer uuid',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'uuid',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'views',
  );

  // Exported permission: 'assign node themes'.
  $permissions['assign node themes'] = array(
    'name' => 'assign node themes',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'themekey_ui',
  );

  // Exported permission: 'assign path alias themes'.
  $permissions['assign path alias themes'] = array(
    'name' => 'assign path alias themes',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'themekey_ui',
  );

  // Exported permission: 'assign theme to own nodes'.
  $permissions['assign theme to own nodes'] = array(
    'name' => 'assign theme to own nodes',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'themekey_ui',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'system',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'node',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'user',
  );

  // Exported permission: 'change layouts in place editing'.
  $permissions['change layouts in place editing'] = array(
    'name' => 'change layouts in place editing',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'user',
  );

  // Exported permission: 'create bounty content'.
  $permissions['create bounty content'] = array(
    'name' => 'create bounty content',
    'roles' => array(
      'Administrator1' => 'Administrator1',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create kicklow content'.
  $permissions['create kicklow content'] = array(
    'name' => 'create kicklow content',
    'roles' => array(
      'Administrator1' => 'Administrator1',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create planets_info content'.
  $permissions['create planets_info content'] = array(
    'name' => 'create planets_info content',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create project_profile content'.
  $permissions['create project_profile content'] = array(
    'name' => 'create project_profile content',
    'roles' => array(
      'Administrator1' => 'Administrator1',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create team_profile content'.
  $permissions['create team_profile content'] = array(
    'name' => 'create team_profile content',
    'roles' => array(
      'Administrator1' => 'Administrator1',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'path',
  );

  // Exported permission: 'customize ckeditor'.
  $permissions['customize ckeditor'] = array(
    'name' => 'customize ckeditor',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'ckeditor',
  );

  // Exported permission: 'delete any bounty content'.
  $permissions['delete any bounty content'] = array(
    'name' => 'delete any bounty content',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any kicklow content'.
  $permissions['delete any kicklow content'] = array(
    'name' => 'delete any kicklow content',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any planets_info content'.
  $permissions['delete any planets_info content'] = array(
    'name' => 'delete any planets_info content',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any project_profile content'.
  $permissions['delete any project_profile content'] = array(
    'name' => 'delete any project_profile content',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any team_profile content'.
  $permissions['delete any team_profile content'] = array(
    'name' => 'delete any team_profile content',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete backup files'.
  $permissions['delete backup files'] = array(
    'name' => 'delete backup files',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'delete own bounty content'.
  $permissions['delete own bounty content'] = array(
    'name' => 'delete own bounty content',
    'roles' => array(
      'Administrator1' => 'Administrator1',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own kicklow content'.
  $permissions['delete own kicklow content'] = array(
    'name' => 'delete own kicklow content',
    'roles' => array(
      'Administrator1' => 'Administrator1',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own planets_info content'.
  $permissions['delete own planets_info content'] = array(
    'name' => 'delete own planets_info content',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own project_profile content'.
  $permissions['delete own project_profile content'] = array(
    'name' => 'delete own project_profile content',
    'roles' => array(
      'Administrator1' => 'Administrator1',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own team_profile content'.
  $permissions['delete own team_profile content'] = array(
    'name' => 'delete own team_profile content',
    'roles' => array(
      'Administrator1' => 'Administrator1',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'Administrator1' => 'Administrator1',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in project_status'.
  $permissions['delete terms in project_status'] = array(
    'name' => 'delete terms in project_status',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in skill'.
  $permissions['delete terms in skill'] = array(
    'name' => 'delete terms in skill',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'display drupal links'.
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'edit any bounty content'.
  $permissions['edit any bounty content'] = array(
    'name' => 'edit any bounty content',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any kicklow content'.
  $permissions['edit any kicklow content'] = array(
    'name' => 'edit any kicklow content',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any planets_info content'.
  $permissions['edit any planets_info content'] = array(
    'name' => 'edit any planets_info content',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any project_profile content'.
  $permissions['edit any project_profile content'] = array(
    'name' => 'edit any project_profile content',
    'roles' => array(
      'Administrator1' => 'Administrator1',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any team_profile content'.
  $permissions['edit any team_profile content'] = array(
    'name' => 'edit any team_profile content',
    'roles' => array(
      'Administrator1' => 'Administrator1',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own bounty content'.
  $permissions['edit own bounty content'] = array(
    'name' => 'edit own bounty content',
    'roles' => array(
      'Administrator1' => 'Administrator1',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own kicklow content'.
  $permissions['edit own kicklow content'] = array(
    'name' => 'edit own kicklow content',
    'roles' => array(
      'Administrator1' => 'Administrator1',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own planets_info content'.
  $permissions['edit own planets_info content'] = array(
    'name' => 'edit own planets_info content',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own project_profile content'.
  $permissions['edit own project_profile content'] = array(
    'name' => 'edit own project_profile content',
    'roles' => array(
      'Administrator1' => 'Administrator1',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own team_profile content'.
  $permissions['edit own team_profile content'] = array(
    'name' => 'edit own team_profile content',
    'roles' => array(
      'Administrator1' => 'Administrator1',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in project_status'.
  $permissions['edit terms in project_status'] = array(
    'name' => 'edit terms in project_status',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in skill'.
  $permissions['edit terms in skill'] = array(
    'name' => 'edit terms in skill',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'execute php code'.
  $permissions['execute php code'] = array(
    'name' => 'execute php code',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'flush caches'.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'generate features'.
  $permissions['generate features'] = array(
    'name' => 'generate features',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'features',
  );

  // Exported permission: 'get a system variable'.
  $permissions['get a system variable'] = array(
    'name' => 'get a system variable',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'services',
  );

  // Exported permission: 'get any binary files'.
  $permissions['get any binary files'] = array(
    'name' => 'get any binary files',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'services',
  );

  // Exported permission: 'get own binary files'.
  $permissions['get own binary files'] = array(
    'name' => 'get own binary files',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'services',
  );

  // Exported permission: 'manage features'.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'features',
  );

  // Exported permission: 'notify of path changes'.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'perform backup'.
  $permissions['perform backup'] = array(
    'name' => 'perform backup',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'perform unlimited index queries'.
  $permissions['perform unlimited index queries'] = array(
    'name' => 'perform unlimited index queries',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'services',
  );

  // Exported permission: 'restore from backup'.
  $permissions['restore from backup'] = array(
    'name' => 'restore from backup',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'Administrator1' => 'Administrator1',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'save file information'.
  $permissions['save file information'] = array(
    'name' => 'save file information',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'services',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'user',
  );

  // Exported permission: 'set a system variable'.
  $permissions['set a system variable'] = array(
    'name' => 'set a system variable',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'services',
  );

  // Exported permission: 'switch users'.
  $permissions['switch users'] = array(
    'name' => 'switch users',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'use ipe with page manager'.
  $permissions['use ipe with page manager'] = array(
    'name' => 'use ipe with page manager',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use page manager'.
  $permissions['use page manager'] = array(
    'name' => 'use page manager',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: 'use panels caching features'.
  $permissions['use panels caching features'] = array(
    'name' => 'use panels caching features',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels dashboard'.
  $permissions['use panels dashboard'] = array(
    'name' => 'use panels dashboard',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels in place editing'.
  $permissions['use panels in place editing'] = array(
    'name' => 'use panels in place editing',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels locks'.
  $permissions['use panels locks'] = array(
    'name' => 'use panels locks',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format taras_html'.
  $permissions['use text format taras_html'] = array(
    'name' => 'use text format taras_html',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'Administrator1' => 'Administrator1',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view pane admin links'.
  $permissions['view pane admin links'] = array(
    'name' => 'view pane admin links',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'Administrator1' => 'Administrator1',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'Administrator1' => 'Administrator1',
    ),
    'module' => 'system',
  );

  return $permissions;
}
