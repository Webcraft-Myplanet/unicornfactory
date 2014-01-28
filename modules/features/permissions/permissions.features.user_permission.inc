<?php
/**
 * @file
 * permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function permissions_user_default_permissions() {
  $permissions = array();
  // Exported permission: 'create team_profile content'.
  $permissions['create team_profile content'] = array(
    'name' => 'create team_profile content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
        'module' => 'node',
  );

  // Exported permission: 'create user_profiles content'.
  $permissions['create user_profiles content'] = array(
    'name' => 'create user_profiles content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
