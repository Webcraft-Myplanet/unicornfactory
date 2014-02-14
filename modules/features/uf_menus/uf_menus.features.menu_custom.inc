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
  // Exported menu: menu-user-menu2.
  $menus['menu-user-menu2'] = array(
    'menu_name' => 'menu-user-menu2',
    'title' => 'User Menu2',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Editing Menu');
  t('User Menu2');
  t('User editing options--profile, creation of teams/projects, etc. ');


  return $menus;
}
