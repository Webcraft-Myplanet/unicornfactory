<?php
/**
 * @file
 * uf_menus.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function uf_menus_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: user-menu_people:users
  $menu_links['user-menu_people:users'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'users',
    'router_path' => 'users',
    'link_title' => 'People',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'user-menu_people:users',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 3,
    'customized' => 1,
  );
  // Exported menu link: user-menu_projects:projects
  $menu_links['user-menu_projects:projects'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'projects',
    'router_path' => 'projects',
    'link_title' => 'Projects',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'user-menu_projects:projects',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 1,
    'customized' => 1,
  );
  // Exported menu link: user-menu_teams:teams
  $menu_links['user-menu_teams:teams'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'teams',
    'router_path' => 'teams',
    'link_title' => 'Teams',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'user-menu_teams:teams',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 2,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('People');
  t('Projects');
  t('Teams');


  return $menu_links;
}
