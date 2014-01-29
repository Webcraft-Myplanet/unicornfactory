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

  // Exported menu link: user-menu_create-my-profile:node/add/user-profiles
  $menu_links['user-menu_create-my-profile:node/add/user-profiles'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'node/add/user-profiles',
    'router_path' => 'node/add/user-profiles',
    'link_title' => 'Create My Profile',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'user-menu_create-my-profile:node/add/user-profiles',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
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
    'weight' => -47,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Create My Profile');
  t('Create Team Profile');


  return $menu_links;
}
