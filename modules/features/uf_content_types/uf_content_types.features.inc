<?php
/**
 * @file
 * uf_content_types.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uf_content_types_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function uf_content_types_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function uf_content_types_image_default_styles() {
  $styles = array();

  // Exported image style: cool.
  $styles['cool'] = array(
    'name' => 'cool',
    'label' => 'Cool',
    'effects' => array(
      1 => array(
        'label' => 'Manual crop',
        'help' => 'Crop a freely user-selected area.',
        'effect callback' => 'manualcrop_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'manualcrop_crop_form',
        'summary theme' => 'manualcrop_crop_summary',
        'module' => 'manualcrop',
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => 200,
          'height' => 100,
          'keepproportions' => 1,
          'style_name' => 'cool',
        ),
        'weight' => 0,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function uf_content_types_node_info() {
  $items = array(
    'bounty' => array(
      'name' => t('Bounty'),
      'base' => 'node_content',
      'description' => t('Bounty content type'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'kicklow' => array(
      'name' => t('Kicklow'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'planets_info' => array(
      'name' => t('Planets Info'),
      'base' => 'node_content',
      'description' => t('Description for planet skill rating.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'project_profile' => array(
      'name' => t('Project Profile'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Project Name'),
      'help' => '',
    ),
    'team_profile' => array(
      'name' => t('Team Profile'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Team Name'),
      'help' => '',
    ),
  );
  return $items;
}
