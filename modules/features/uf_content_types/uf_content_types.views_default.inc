<?php
/**
 * @file
 * uf_content_types.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function uf_content_types_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'user_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'User List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'User List';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_avatar']['id'] = 'field_avatar';
  $handler->display->display_options['fields']['field_avatar']['table'] = 'field_data_field_avatar';
  $handler->display->display_options['fields']['field_avatar']['field'] = 'field_avatar';
  $handler->display->display_options['fields']['field_avatar']['label'] = 'picture';
  $handler->display->display_options['fields']['field_avatar']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_avatar']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['label'] = 'email';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = 'nid';
  /* Field: Field: Slogan */
  $handler->display->display_options['fields']['field_slogan']['id'] = 'field_slogan';
  $handler->display->display_options['fields']['field_slogan']['table'] = 'field_data_field_slogan';
  $handler->display->display_options['fields']['field_slogan']['field'] = 'field_slogan';
  $handler->display->display_options['fields']['field_slogan']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_slogan']['type'] = 'text_plain';
  /* Field: User: User Skill */
  $handler->display->display_options['fields']['field_user_skill']['id'] = 'field_user_skill';
  $handler->display->display_options['fields']['field_user_skill']['table'] = 'field_data_field_user_skill';
  $handler->display->display_options['fields']['field_user_skill']['field'] = 'field_user_skill';
  $handler->display->display_options['fields']['field_user_skill']['label'] = 'skills';
  $handler->display->display_options['fields']['field_user_skill']['settings'] = array(
    'edit' => 'Edit',
    'delete' => 'Delete',
    'add' => 'Add',
    'description' => 1,
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_user_skill']['delta_offset'] = '0';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'user-list';

  /* Display: Services */
  $handler = $view->new_display('services', 'Services', 'services_1');
  $handler->display->display_options['path'] = 'user-list';
  $export['user_list'] = $view;

  return $export;
}
