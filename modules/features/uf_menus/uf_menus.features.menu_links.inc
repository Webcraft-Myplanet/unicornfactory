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

  // Exported menu link: menu-editing-menu_create-project:node/add/project-profile
  $menu_links['menu-editing-menu_create-project:node/add/project-profile'] = array(
    'menu_name' => 'menu-editing-menu',
    'link_path' => 'node/add/project-profile',
    'router_path' => 'node/add',
    'link_title' => 'Create Project',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-editing-menu_create-project:node/add/project-profile',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 3,
    'customized' => 1,
  );
  // Exported menu link: menu-editing-menu_create-team:node/add/team-profile
  $menu_links['menu-editing-menu_create-team:node/add/team-profile'] = array(
    'menu_name' => 'menu-editing-menu',
    'link_path' => 'node/add/team-profile',
    'router_path' => 'node/add',
    'link_title' => 'Create Team',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-editing-menu_create-team:node/add/team-profile',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 1,
    'customized' => 1,
  );
  // Exported menu link: menu-editing-menu_edit-profile:user
  $menu_links['menu-editing-menu_edit-profile:user'] = array(
    'menu_name' => 'menu-editing-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'Edit Profile',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-editing-menu_edit-profile:user',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-editing-menu_log-out:user/logout
  $menu_links['menu-editing-menu_log-out:user/logout'] = array(
    'menu_name' => 'menu-editing-menu',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Log Out',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-editing-menu_log-out:user/logout',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 4,
    'customized' => 1,
  );
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
  t('Create Project');
  t('Create Team');
  t('Edit Profile');
  t('Log Out');
  t('People');
  t('Projects');
  t('Teams');


  return $menu_links;
}
