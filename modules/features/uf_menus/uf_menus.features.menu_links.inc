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

  // Exported menu link: user-menu_all-projects:projects
  $menu_links['user-menu_all-projects:projects'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'projects',
    'router_path' => 'projects',
    'link_title' => 'All Projects',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'user-menu_all-projects:projects',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: user-menu_all-teams:teams
  $menu_links['user-menu_all-teams:teams'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'teams',
    'router_path' => 'teams',
    'link_title' => 'All Teams',
    'options' => array(
      'attributes' => array(
        'title' => 'View all the teams!',
      ),
      'identifier' => 'user-menu_all-teams:teams',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
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
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: user-menu_create-a-project:node/add/project-profile
  $menu_links['user-menu_create-a-project:node/add/project-profile'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'node/add/project-profile',
    'router_path' => 'node/add',
    'link_title' => 'Create A Project',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'user-menu_create-a-project:node/add/project-profile',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 4,
    'customized' => 1,
  );
  // Exported menu link: user-menu_create-a-team:node/add/team-profile
  $menu_links['user-menu_create-a-team:node/add/team-profile'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'node/add/team-profile',
    'router_path' => 'node/add',
    'link_title' => 'Create A Team',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'user-menu_create-a-team:node/add/team-profile',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 2,
    'customized' => 1,
  );
  // Exported menu link: user-menu_log-out:user/logout
  $menu_links['user-menu_log-out:user/logout'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Log out',
    'options' => array(
      'identifier' => 'user-menu_log-out:user/logout',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 10,
    'customized' => 0,
  );
  // Exported menu link: user-menu_timeline:projects-timeline
  $menu_links['user-menu_timeline:projects-timeline'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'projects-timeline',
    'router_path' => 'projects-timeline',
    'link_title' => 'Timeline',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'user-menu_timeline:projects-timeline',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: user-menu_user-account:user
  $menu_links['user-menu_user-account:user'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'User account',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'user-menu_user-account:user',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('All Projects');
  t('All Teams');
  t('All Users');
  t('Create A Project');
  t('Create A Team');
  t('Log out');
  t('Timeline');
  t('User account');


  return $menu_links;
}
