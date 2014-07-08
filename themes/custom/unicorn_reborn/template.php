<?php

/**
 * Implements hook_preprocess_html().
 */
function unicorn_reborn_preprocess_html(&$vars) {
  // Device scale
  $meta_device_scale = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'viewport',
      'content' =>  'width=device-width, initial-scale=1',
    )
  );

  drupal_add_html_head($meta_device_scale, 'meta_device_scale');
}

/**
 * Implements hook_preprocess_node().
 */
function unicorn_reborn_preprocess_node(&$vars) {
  switch($vars['type']) {
    case 'kicklow' :
dsm($vars);
      // Make the date more readable.
      $vars['date'] = date('F jS, Y', $vars['created']);

      // Make a "Project Type" variable.
      $vars['project_type'] = $vars['field_type'][0]['value'];

      // Make a logo variable.
      $image_url = image_style_url('thumbnail', $vars['field_kl_logo'][0]['uri']);
      $vars['project_logo'] = '<img src="' . $image_url . '" />';
      break;
  }
}
