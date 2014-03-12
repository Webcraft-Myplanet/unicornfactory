<?php
/**
 * @file
 * feedback.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function uf_feedback_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access site-wide contact form'.
  $permissions['access site-wide contact form'] = array(
    'name' => 'access site-wide contact form',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'contact',
  );

  // Exported permission: 'access user contact forms'.
  $permissions['access user contact forms'] = array(
    'name' => 'access user contact forms',
    'roles' => array(),
    'module' => 'contact',
  );

  // Exported permission: 'administer contact forms'.
  $permissions['administer contact forms'] = array(
    'name' => 'administer contact forms',
    'roles' => array(),
    'module' => 'contact',
  );

  // Exported permission: 'administer feedback simple'.
  $permissions['administer feedback simple'] = array(
    'name' => 'administer feedback simple',
    'roles' => array(),
    'module' => 'feedback_simple',
  );

  return $permissions;
}
