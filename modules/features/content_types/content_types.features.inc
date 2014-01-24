<?php
/**
 * @file
 * content_types.features.inc
 */

/**
 * Implements hook_node_info().
 */
function content_types_node_info() {
  $items = array(
    'user_profiles' => array(
      'name' => t('User Profiles'),
      'base' => 'node_content',
      'description' => t('Profiles of users'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => t('A name. Preferably yours. '),
    ),
  );
  return $items;
}
