<?php
/**
 * @file
 * content_types.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function content_types_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: user-menu_all-users:user-list
  $menu_links['user-menu_all-users:user-list'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user-list',
    'router_path' => 'user-list',
    'link_title' => 'All Users',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'user-menu_all-users:user-list',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('All Users');


  return $menu_links;
}
