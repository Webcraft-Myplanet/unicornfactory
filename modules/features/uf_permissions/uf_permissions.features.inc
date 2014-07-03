<?php
/**
 * @file
 * uf_permissions.features.inc
 */

/**
 * Implements hook_themekey_features_rule_chain().
 */
function uf_permissions_themekey_features_rule_chain() {
if (!defined('THEMEKEY_PAGECACHE_UNSUPPORTED')) {
    define('THEMEKEY_PAGECACHE_UNSUPPORTED', 0);
    define('THEMEKEY_PAGECACHE_SUPPORTED', 1);
    define('THEMEKEY_PAGECACHE_TIMEBASED', 2);
  }
$rules = array(
  0 => array(
    'rule' => array(
      'property' => 'drupal:path',
      'operator' => '=',
      'value' => 'admin/%',
      'theme' => 'seven',
      'enabled' => 1,
      'wildcards' => array(),
      'module' => 'uf_permissions',
    ),
    'string' => '"drupal:path = admin/% >>> seven"',
    'childs' => array(),
  ),
);

return $rules;
}
