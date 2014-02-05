<?php
/**
 * @file
 * uf_views.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function uf_views_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: user-menu_projects:projects
  $menu_links['user-menu_projects:projects'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'projects',
    'router_path' => 'projects',
    'link_title' => 'Projects',
    'options' => array(
      'identifier' => 'user-menu_projects:projects',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Projects');


  return $menu_links;
}
