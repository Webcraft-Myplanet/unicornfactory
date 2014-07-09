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
   case 'bounty' :
      $vars['test'] = "Here's some content!!";

     break;

    case 'kicklow' :

      // Make the date more readable.
      $vars['date'] = date('F jS, Y', $vars['created']);
      // $vars['date_update'] = date('F jS, Y', $vars['date_update']);

      $vars['name'] = $vars['node']->name;

      $vars['proj_desc'] = $vars['node']->body['und'][0]['value'];

      // Make a "Project Type" variable.
      $vars['project_type'] = $vars['field_type'][0]['value'];

      // Make a logo variable.
      $image_url = image_style_url('thumbnail', $vars['field_kl_logo'][0]['uri']);
      $vars['project_logo'] = '<img src="' . $image_url . '" />';

      // Make rendered list of resource list.
      $vars['resources'] = unicorn_reborn_render_resource_list($vars['field_resources']);
      $vars['updates'] = unicorn_reborn_render_updates($vars['field_updates']);
     break;
  }
}

/**
 * Render a resource list from a field_collection field.
 */
function unicorn_reborn_render_resource_list($resources) {
  // Create output var.
  $output = '';

  foreach($resources as $resource) {
    // Get field collection ID.
    $resource_id = $resource['value'];
    // Load field collection.
    $field_collection = entity_load('field_collection_item', array($resource_id));

    // Get data to display.
    $title = $field_collection[$resource_id]->field_resource_url['und'][0]['title'];
    $url = $field_collection[$resource_id]->field_resource_url['und'][0]['url'];

    // Format data.
    $output .= '<h3>' . $title . '</h3>';
    $output .= '<a href="' . $url . '">' . $url . '</a>';
  }

  return $output;
}

function unicorn_reborn_render_updates($updates) {
  // Create output var.
  $output = '';

  foreach($updates as $update) {
    // Get field collection ID.
    $update_id = $update['value'];
    // Load field collection.
    $field_collection = entity_load('field_collection_item', array($update_id));

    // Get data to display.
    $body_update = $field_collection[$update_id]->field_update_description['und'][0]['value'];
    $date_update = $field_collection[$update_id]->field_update_date['und'][0]['value'];
    $date_nice = date('F jS, Y',strtotime($date_update));

    // Format data.
    $output .= '<div class="update">'.'<h4>'.$date_nice.'</h4><p>'.$body_update.'</p></div>';
    // $output .= $date_update;
  }
  return $output;
}
