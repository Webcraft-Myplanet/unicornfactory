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

  // Exported menu link: user-menu_create-team-profile:node/add/team-profile
  $menu_links['user-menu_create-team-profile:node/add/team-profile'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'node/add/team-profile',
    'router_path' => 'node/add/team-profile',
    'link_title' => 'Create Team Profile',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'user-menu_create-team-profile:node/add/team-profile',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: user-menu_view-all-teams:teams
  $menu_links['user-menu_view-all-teams:teams'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'teams',
    'router_path' => 'teams',
    'link_title' => 'View all teams',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'user-menu_view-all-teams:teams',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Create Team Profile');
  t('View all teams');


  return $menu_links;
}
