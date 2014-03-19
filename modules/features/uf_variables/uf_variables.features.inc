<?php
/**
 * @file
 * uf_variables.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uf_variables_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_themekey_features_rule_chain().
 */
function uf_variables_themekey_features_rule_chain() {
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
      'module' => 'uf_variables',
    ),
    'string' => '"drupal:path = admin/% >>> seven"',
    'childs' => array(),
  ),
);

return $rules;
}
