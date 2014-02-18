<?php
/**
 * @file
 * uf_content_types.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function uf_content_types_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: user-menu_all-users:users
  $menu_links['user-menu_all-users:users'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'users',
    'router_path' => 'users',
    'link_title' => 'All Users',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'user-menu_all-users:users',
    ),
    'module' => 'menu',
    'hidden' => 1,
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
