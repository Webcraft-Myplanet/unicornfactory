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

  // Exported permission: 'create user_profiles content'.
  $permissions['create user_profiles content'] = array(
    'name' => 'create user_profiles content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
