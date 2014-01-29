<?php
/**
 * @file
 * content_types.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function content_types_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function content_types_node_info() {
  $items = array(
    'skill' => array(
      'name' => t('Skill'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
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
    'user_profiles' => array(
      'name' => t('User Profile'),
      'base' => 'node_content',
      'description' => t('Profiles of users'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => t('A name. Preferably yours. '),
    ),
  );
  return $items;
}
