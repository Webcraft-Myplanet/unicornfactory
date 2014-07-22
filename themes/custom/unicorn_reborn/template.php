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

      $vars['title'] = $vars['node']->title;


      $vars['date'] = date('F jS, Y', $vars['created']);

      $vars['description'] = $vars['node']->field_description['und'][0]['value'];

      $vars['status'] = $vars['node']->field_status_progress['und'][0]['value'];
     break;

    case 'kicklow' :

      $all_related_bounties = unicorn_reborn_get_related_bounties($vars['nid']);

          //Make a list of all bounties
      if (!empty($all_related_bounties)){
        $vars['bounties'] = unicorn_reborn_format_bounties($all_related_bounties);
      }

      // Make the date more readable.
      // $vars['date_update'] = date('F jS, Y', $vars['date_update']);
      $vars['date'] = date('F jS, Y', $vars['created']);

      $vars['name'] = $vars['node']->name;

      $vars['comments'] = $vars['node']->comment;
      if (!empty($vars['node']->body)){
      $vars['proj_desc'] = $vars['node']->body['und'][0]['value'];
      }
      // Make a "Project Type" variable.
      $vars['project_type'] = $vars['field_type'][0]['value'];

      // Make a logo variable.
      // $image_url = image_style_url('thumbnail', $vars['field_kl_logo'][0]['uri']);
      // $vars['project_logo'] = '<img src="' . $image_url . '" />';

      // Make rendered list of resource list.
      $vars['resources'] = unicorn_reborn_render_resource_list($vars['field_resources']);
      $vars['tasks'] = unicorn_reborn_render_tasks($vars['field_tasks']);
      $vars['total_task_count'] =count($vars['node']->field_tasks['und']);
      $vars['updates'] = unicorn_reborn_render_updates($vars['field_updates']);
      $vars['contribs'] = unicorn_reborn_list_contributors($vars['field_bounty']);
      // loop for contributors(bounty owners)

     break;

     case 'comment':
  }
}

/**
 * Get's related bounties, from kicklow nodes.
 *
 * Using a kicklow $nid variable, we use a EntityFieldQuery
 * to get all related bounty nodes.
 *
 * @param $nid
 *   Integer - The node ID of the kicklow to search within.
 *
 * @return
 *   Array - Array of loaded node objects.
 */
function unicorn_reborn_get_related_bounties($nid) {
  // Query DB to get all bounties.
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'bounty')
  ->fieldCondition('field_kicklow', 'nid', $nid);
  $result = $query->execute();

  // Check for results, and return loaded nodes.
  if (!empty($result)) {
    $all_related_bounties = node_load_multiple(array_keys($result['node']));
    return $all_related_bounties;
  }
}

function unicorn_reborn_format_bounties($all_related_bounties){
  $bounties = array();
// if (!empty($all_related_bounties)){
  foreach($all_related_bounties as $bounty) {
    $result = array();
    $status = $bounty->field_status_progress['und'][0]['value'];
    $result['status'] = $status;
    $result['title'] = $bounty->title;
    $result['date'] = date('F jS, Y', $bounty->created);

    $result['description'] = $bounty->field_description['und'][0]['value'];
    $result['node_id'] = $bounty->nid;
    if (!empty($bounty->field_bounty_owner['und'][0]['uid'])) {
      $result['owner_id'] = $bounty->field_bounty_owner['und'][0]['uid'];
      $owner = user_load($result['owner_id']);
      if (!empty($owner->picture->uri)) {
        $result['owner_img'] = image_style_url('thumbnail', $owner->picture->uri);
      }
    }
    else {
      $result['owner_id'] = NULL;
      $result['owner_img'] = NULL;
    }
    $bounties[$status][] = $result;
  }
  return $bounties;

}
/**
 * Render a resource list from a field_collection field.
 */
function unicorn_reborn_render_resource_list($resources) {
  // Create output var.
  $output = '';

  if (!empty($resources)){
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
  }//if
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
    if (!empty($field_collection[$update_id]->field_update_description['und'])){
      $body_update = $field_collection[$update_id]->field_update_description['und'][0]['value'];
    }
    else {
      $body_update = '';
    }
    $date_update = $field_collection[$update_id]->field_update_date['und'][0]['value'];
    $date_nice = date('F jS, Y',strtotime($date_update));

    // Format data.
    $output .= '<div class="update">'.'<h4>'.$date_nice.'</h4><p>'.$body_update.'</p></div>';
    // $output .= $date_update;
  }
  return $output;
}
function unicorn_reborn_list_contributors($contribs) {
  // Create output var.
  $output = '';


  foreach($contribs as $contrib) {
    $uf_user = $contrib['node']->field_bounty_owner['und'][0]['uid'];
    $user = user_load($uf_user);
    $uf_username = $user->name;
    if (!empty($user->picture->uri)) {
      $uf_userimg = image_style_url('thumbnail', $user->picture->uri);
    }
    else{
      $uf_userimg = drupal_get_path('theme', 'unicorn_reborn') . '/logo.png';
    }
    $output .= '<div class="ufContrib">';
    $output .= '<h4>'.$uf_username.'</h4>';
    $output .= '<img src="' . $uf_userimg . '">';
    $output .= '</div>';
  }
  return $output;
}

function unicorn_reborn_preprocess_comment(&$vars){
  $vars['comment_date'] = date('F jS, Y - h:ia',$vars['comment']->created);
  }

  /**
 * Gets task count for Kicklow
 *
 * @param $tasks
 *  loads field_tasks associated with kicklow from preprocess node
 *
 * @return $tasks_completed_count
 *  $tasks_completed_count is the number of completed tasks
 */

function unicorn_reborn_render_tasks($tasks) {
  // Create output var.
    $task_completed_count = 0;
    // loop through tasks to get task id
    foreach($tasks as $task) {
      // Get field collection ID.
      $task_id = $task['value'];
      // Load field collection.
      $field_collections = entity_load('field_collection_item', array($task_id));
      // Loop through field collection array to find status.
        foreach ($field_collections as $field_collection) {
          $status = $field_collection->field_tasks_status['und'][0]['value'];
          //0 represents incomplete, 1 represents complete.
          if($status == 1){
            $task_completed_count++;
          }
        }

    }
    return $task_completed_count;
}
