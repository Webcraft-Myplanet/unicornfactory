<?php
/**
 * @file
 * content_types.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function content_types_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create skill content'.
  $permissions['create skill content'] = array(
    'name' => 'create skill content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'use PHP for title patterns'.
  $permissions['use PHP for title patterns'] = array(
    'name' => 'use PHP for title patterns',
    'roles' => array(),
    'module' => 'auto_nodetitle',
  );

  return $permissions;
}
