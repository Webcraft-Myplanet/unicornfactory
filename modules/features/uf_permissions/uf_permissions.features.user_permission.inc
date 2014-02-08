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

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create project_profile content'.
  $permissions['create project_profile content'] = array(
    'name' => 'create project_profile content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create team_profile content'.
  $permissions['create team_profile content'] = array(
    'name' => 'create team_profile content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any project_profile content'.
  $permissions['delete any project_profile content'] = array(
    'name' => 'delete any project_profile content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any team_profile content'.
  $permissions['delete any team_profile content'] = array(
    'name' => 'delete any team_profile content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own project_profile content'.
  $permissions['delete own project_profile content'] = array(
    'name' => 'delete own project_profile content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own team_profile content'.
  $permissions['delete own team_profile content'] = array(
    'name' => 'delete own team_profile content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any project_profile content'.
  $permissions['edit any project_profile content'] = array(
    'name' => 'edit any project_profile content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any team_profile content'.
  $permissions['edit any team_profile content'] = array(
    'name' => 'edit any team_profile content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own project_profile content'.
  $permissions['edit own project_profile content'] = array(
    'name' => 'edit own project_profile content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own team_profile content'.
  $permissions['edit own team_profile content'] = array(
    'name' => 'edit own team_profile content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
