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

  // Exported image style: medium_cool.
  $styles['medium_cool'] = array(
    'name' => 'medium_cool',
    'label' => 'medium_cool',
    'effects' => array(
      5 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 80,
          'height' => 80,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: smaller_cool.
  $styles['smaller_cool'] = array(
    'name' => 'smaller_cool',
    'label' => 'smaller_cool',
    'effects' => array(
      6 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 50,
          'height' => 50,
        ),
        'weight' => 2,
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
