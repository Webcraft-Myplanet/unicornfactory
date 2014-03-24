<?php
/**
 * @file
 * uf_content_types.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function uf_content_types_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['system-main'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'main',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'unicorn' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'unicorn',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['user-login'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'login',
    'module' => 'user',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(
      'anonymous user' => 1,
    ),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'unicorn' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'unicorn',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  return $export;
}
