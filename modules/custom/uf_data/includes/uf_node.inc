<?php

/**
 * @file
 * Services callbacks.
 */

/**
 * Returns a form array based on form_id.
 *
 * @param $form_id
 *   The form_id of the form to retrieve.
 * @param $nid
 *   The nid of the node to edit.
 * @return
 *   The form array.
 */
function _uf_node_retrieve($form_id, $nid) {
  // Load node form pages.
  module_load_include('inc', 'node', 'node.pages');

  // Load node so we can add it to the form.
  $node = node_load($nid);

  // Load the form.
  $form_state = array();
  $form_state['build_info']['args'] = array($node);
  drupal_build_form($form_id, $form_state);
  $values = $form_state['values'];
  unset($values['form_build_id']);
  unset($values['form_token']);

  // Modify the data structure based on $form_id.
  _uf_node_format_values_retrieval($form_id, $values);

  return $values;
}


/**
 * Format values array for retrieval.
 */
function _uf_node_format_values_retrieval($form_id, &$values) {
  switch ($form_id) {

    case 'project_profile_node_form':

    // Catch an empty ['value']['date'] array for start date
    if (is_array($values['field_start_date']['und'][0]['value']) && isset($values['field_start_date']['und'][0]['value']['date'])) {
      unset($values['field_start_date']['und'][0]['value']['date']);
    }

    // Catch an empty ['value']['date'] array for end date
    if (is_array($values['field_start_date']['und'][0]['value2']) && isset($values['field_start_date']['und'][0]['value2']['date'])) {
      unset($values['field_start_date']['und'][0]['value2']['date']);
    }

    // Modify start time.
    // Ensure that the value is not empty before trying to blindly throw it into strtotime()
    if (!empty($values['field_start_date']['und'][0]['value'])) {
      $start_time = strtotime($values['field_start_date']['und'][0]['value']);
      $start_time = date('M j, Y', $start_time);
      $values['field_start_date']['und'][0]['value'] = array('date' => $start_time);
    } else {
      $values['field_start_date']['und'][0]['value'] = array('date' => 'Today');
    }

    // Modify end time.
    // Ensure that the value is not empty before trying to blindly throw it into strtotime()
    if (!empty($values['field_start_date']['und'][0]['value2']) && $values['field_start_date']['und'][0]['show_todate'] == 1) {
      $end_time = strtotime($values['field_start_date']['und'][0]['value2']);
      $end_time = date('M j, Y', $end_time);
      if ($start_time !== $end_time) {
        $values['field_start_date']['und'][0]['value2'] = array('date' => $end_time);
      } else {
        $values['field_start_date']['und'][0]['value2'] = array('date' => 'Ongoing');
      }
    } else {
      $values['field_start_date']['und'][0]['value2'] = array('date' => 'Ongoing');
    }

    // Create img tag for avatar.
    $config = array(
                    "style_name" => "thumbnail",
                    "path" => $values['field_avatar']['und'][0]['uri'],
                    "height" => $values['field_avatar']['und'][0]['height'],
                    "width" => $values['field_avatar']['und'][0]['width'],
                    );
    $values['field_avatar']['und'][0]['html'] = theme_image_style($config);

    // Turn skills CSV list into an array.
    if (!empty($values['field_skills']['und'])) {
      // Explode values in array.
      $values['field_skills']['und'] = explode(', ', $values['field_skills']['und']);
    }

    // Add list of people to the project.
    $values['related_users'] = _uf_node_get_related('user', 'field_working_on', $values['nid']);

    // Add list of teams to the project.
    $values['related_teams'] = _uf_node_get_related('team', 'field_working_on', $values['nid']);

    break;
    case 'team_profile_node_form':

      // Create img tag for avatar.
      if ($values['field_avatar']['und'][0]['display']) {
        $config = array(
                        "style_name" => "thumbnail",
                        "path" => $values['field_avatar']['und'][0]['uri'],
                        "height" => $values['field_avatar']['und'][0]['height'],
                        "width" => $values['field_avatar']['und'][0]['width'],
                        "alt" => $values['name'],
                        );
        $values['field_avatar']['und'][0]['html'] = theme_image_style($config);
      } else {
        $values['field_avatar'] = array('und' => array(0 => array(
          'html' => '<img src="/profiles/skeletor/themes/custom/unicorn/images/default-profile-pic.png" alt="'.$values['name'].'" width="100" />',
        )));
      }

      // Add a list of people to the team
      $values['related_users'] = _uf_node_get_related('user', 'field_member_of', $values['nid']);

      // Now build a skills composite from all the individual users
      $composite = array();
      foreach ($values['related_users'] as $user) {
        foreach ($user['skills'] as $skill) {
          if (isset($composite[$skill['name']])) {
            $composite[$skill['name']]['current'] += $skill['current'];
            $composite[$skill['name']]['desired'] += $skill['desired'];
            $composite[$skill['name']]['count']++;
          } else {
            $composite[$skill['name']] = array(
              'current' => $skill['current'],
              'desired' => $skill['desired'],
              'count' => 1,
            );
          }
        }
      }

      // Now put it into an Angular readable format
      $values['skills_composite'] = array();
      foreach ($composite as $skillName => $skillValues) {
        $values['skills_composite'][] = array(
          'name' => $skillName,
          'current' => ($skillValues['current'] / $skillValues['count']),
          'desired' => ($skillValues['desired'] / $skillValues['count']),
          'count' => $skillValues['count'],
        );
      }

      // Add a list of projects to the team
      $val = Array();
      foreach ($values['field_working_on']['und'] as $pid) {
        $v = Array();
        $project = node_load($pid);
        if (isset($project->field_avatar['und'])) {
          $config = array(
                          "style_name" => "medium",
                          "path" => $project->field_avatar['und'][0]['uri'],
                          "height" => $project->field_avatar['und'][0]['height'],
                          "width" => $project->field_avatar['und'][0]['width'],
                          );
          $v['avatar'] = theme_image_style($config);
        } else {
          $v['avatar'] = '<img src="/profiles/skeletor/themes/custom/unicorn/images/default-profile-pic.png" alt="'.$project->title.'" width="100" />';
        }
        $v['name'] = $project->title;
        $v['nid'] = $project->nid;
        $val[] = $v;
      }
      $values['related_projects'] = $val;

    break;
  }
}

/**
 * Get the users related to a particular content type.
 *
 * @param $field_name
 *   The field name we're trying to find a relationship from.
 * @param $type
 *   The type of entity that we want back.
 * @param $entity_id
 *   The entity_id we're looking to find a relationship for.
 * @return
 *   An array of trimmed objects, based on type.
 */
function _uf_node_get_related($type, $field_name = NULL, $entity_id = NULL) {
  // Build our vars based on type.
  switch ($type) {
    case 'user':
    $options = array(
                     'base_table' => 'users',
                     'id_name' => 'uid',
                     'entity_type' => 'user',
                     );
    break;
    case 'team':
    $options = array(
                     'base_table' => 'node',
                     'id_name' => 'nid',
                     'entity_type' => 'node',
                     );
    break;
    case 'project':
    $options = array(
                     'base_table' => 'node',
                     'id_name' => 'nid',
                     'entity_type' => 'node',
                     );
    break;
  }

  // Setup select SQL.
  $query = db_select($options['base_table'], 'e')
  ->fields('e', array($options['id_name']));

  // Perform join and conditions only if entity_id isn't empty
  if (!empty($entity_id) && !empty($field_name)) {
    // Add our join.
    $query->join('field_data_' . $field_name, 'f', 'e.' . $options['id_name'] . ' = f.entity_id');

    // Add conditions
    $query->condition('f.entity_type', $options['entity_type'])
          ->condition('f.' . $field_name .  '_nid', $entity_id);
  }

  // Get the results.
  $results = $query->execute()
  ->fetchAllAssoc($options['id_name']);

  // Create array of objects.
  $return = array();
  if (is_array($results)) {
    foreach(array_filter($results) as $result) {
      // Setup blank array and user object.
      $values = array();

      switch ($type) {
        case 'user':
          // Prevent an empty result set from being loaded
        if (empty($result->uid)) {
          break;
        }
        $user = user_load($result->uid);

          // Create viewable avatar and values that will make our object.
        if (!empty($user->picture->uri)) {
          $config = array(
                          "style_name" => "medium",
                          "path" => $user->picture->uri,
                          "height" => NULL,
                          "width" => NULL,
                          "alt" => $user->name,
                          );
          $values['avatar'] = theme_image_style($config);
        } else {
          $values['avatar'] = '<img src="/profiles/skeletor/themes/custom/unicorn/images/default-profile-pic.png" alt="'.$user->name.'" width="100" />';
        }
        $values['name'] = $user->name;
        $values['uid'] = $user->uid;
        // Create array of skills.
        $skills = array();
        if (!empty($user->field_user_skill['und'])) {
          foreach ($user->field_user_skill['und'] as $skill) {
            // If it's not an array... move on.
            if (!is_array($skill)) {
              continue;
            }

            // Build values.
            $fc = entity_load('field_collection_item', array($skill['value']));
            $t = taxonomy_term_load($fc[$skill['value']]->field_skill['und'][0]['tid']);
            $v['name'] = $t->name;
            $v['current'] = $fc[$skill['value']]->field_user_skill_current_rating['und'][0]['value'];
            if (!empty($fc[$skill['value']]->field_user_skill_desired_rating['und'][0]['value'])) {
              $v['desired'] = $fc[$skill['value']]->field_user_skill_desired_rating['und'][0]['value'];
            } else {
              $v['desired'] = $v['current'];
            }

            $skills[] = $v;
          }
        }
        $values['skills'] = $skills;
        // Add our object to the array of user objects
        $return[] = $values;
        break;
        case 'team':
          // Prevent an empty result set from being loaded
        if (empty($result->nid)) {
          break;
        }
        $node = node_load($result->nid);

        // Create viewable avatar and values that will make our object.
        if (isset($node->field_avatar['und'])) {
          $config = array(
                          "style_name" => "medium",
                          "path" => $node->field_avatar['und'][0]['uri'],
                          "height" => $node->field_avatar['und'][0]['height'],
                          "width" => $node->field_avatar['und'][0]['width'],
                          );
          $values['avatar'] = theme_image_style($config);
        } else {
          $values['avatar'] = '<img src="/profiles/skeletor/themes/custom/unicorn/images/default-profile-pic.png" alt="'.$node->title.'" width="100" />';
        }
        $values['name'] = $node->title;
        $values['nid'] = $node->nid;
          // Add our object to the array of node objects
        $return[] = $values;
        break;
      }
    }
  }

  return $return;
}
