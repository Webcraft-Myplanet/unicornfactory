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
dsm($vars);

  switch($vars['type']) {
   case 'bounty' :

      $vars['title'] = $vars['node']->title;


      $vars['date'] = date('F jS, Y', $vars['created']);

      $vars['description'] = $vars['node']->field_description['und'][0]['value'];

      $vars['status'] = $vars['node']->field_status_progress['und'][0]['value'];
     break;

    case 'kicklow' :


    unicorn_reborn_get_related_bounties($vars['nid']);

    dsm('vars');
    dsm($vars);
      // Make the date more readable.
      $vars['date'] = date('F jS, Y', $vars['created']);

      // Make a "Project Type" variable.
      $vars['project_type'] = $vars['field_type'][0]['value'];

      // Make a logo variable.
      $image_url = image_style_url('thumbnail', $vars['field_kl_logo'][0]['uri']);
      $vars['project_logo'] = '<img src="' . $image_url . '" />';

      // Make rendered list of resource list.
      $vars['resources'] = unicorn_reborn_render_resource_list($vars['field_resources']);

     break;
  }
}

function unicorn_reborn_get_related_bounties($nid) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'bounty')
  ->fieldCondition('field_kicklow', 'nid', $nid);

  $result = $query->execute();

  $bounty_info = node_load_multiple(array_keys($result['node']));

  dsm('bounty_info');
  dsm($bounty_info);

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
