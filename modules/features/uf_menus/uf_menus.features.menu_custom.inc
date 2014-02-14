<?php
/**
 * @file
 * uf_menus.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function uf_menus_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-editing-menu.
  $menus['menu-editing-menu'] = array(
    'menu_name' => 'menu-editing-menu',
    'title' => 'Editing Menu',
    'description' => 'User editing options--profile, creation of teams/projects, etc. ',
  );
  // Exported menu: user-menu.
  $menus['user-menu'] = array(
    'menu_name' => 'user-menu',
    'title' => 'User menu',
    'description' => 'The <em>User</em> menu contains links related to the user\'s account, as well as the \'Log out\' link.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Editing Menu');
  t('The <em>User</em> menu contains links related to the user\'s account, as well as the \'Log out\' link.');
  t('User editing options--profile, creation of teams/projects, etc. ');
  t('User menu');


  return $menus;
}
