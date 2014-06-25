<?php
/**
 * @file
 * uf_content_types.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uf_content_types_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function uf_content_types_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function uf_content_types_node_info() {
  $items = array(
    'planets_info' => array(
      'name' => t('Planets Info'),
      'base' => 'node_content',
      'description' => t('Description for planet skill rating.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'project_profile' => array(
      'name' => t('Project Profile'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Project Name'),
      'help' => '',
    ),
    'team_profile' => array(
      'name' => t('Team Profile'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Team Name'),
      'help' => '',
    ),
  );
  return $items;
}
