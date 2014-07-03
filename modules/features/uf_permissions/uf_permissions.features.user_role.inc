<?php
/**
 * @file
 * uf_permissions.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function uf_permissions_user_default_roles() {
  $roles = array();

  // Exported role: Administrator1.
  $roles['Administrator1'] = array(
    'name' => 'Administrator1',
    'weight' => 2,
  );

  return $roles;
}
