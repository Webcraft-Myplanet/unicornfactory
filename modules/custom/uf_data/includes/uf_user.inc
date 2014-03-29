<?php

/**
 * @file
 * Services callbacks.
 */

/**
 * Returns an array of form values based on uid.
 *
 * @param $uid
 *   The uid of the node to edit.
 * @return
 *   The form values array.
 */
function _uf_user_retrieve($uid = NULL) {
  // If it's not numeric, let's assume they wanted ALL the users.
  if (!is_numeric($uid)) {
    return _uf_user_retrieve_all();
  }

  // Load user form pages.
  module_load_include('inc', 'user', 'user.pages');

  // Load user so we can add it to the form.
  $user = user_load($uid);

  // Load the form.
  $form_id = 'user_profile_form';
  $form_state = array();
  $form_state['build_info']['args'] = array($user);
  drupal_build_form($form_id, $form_state);

  // Get the values.
  $values = $form_state['values'];
  unset($values['form_build_id']);
  unset($values['form_token']);

  // Modify the data structure based on $form_id.
  _uf_user_format_values_retrieval($form_id, $values, $user);

  return $values;
}

/**
 * Returns an array of user objects.
 *
 * @return
 *   The array of users.
 */
function _uf_user_retrieve_all() {
  // Load all user entities.
  $users = entity_load('user');

  // Remove anonymous.
  unset($users[0]);

  // Start putting together our results array.
  $results = array();
  foreach ($users as $uid => $user) {
    $row = array();

    // Create output data.
    $row['uid'] = $uid;
    $row['name'] = $user->name;
    $row['email'] = $user->mail;

    // Add slogan, if any.
    if (!empty($user->field_slogan['und'][0]['value'])) {
      $row['slogan'] = $user->field_slogan['und'][0]['value'];
    }

    // Add profile image, if any.
    if (!empty($user->picture->uri)) {
      $config = array(
                      "style_name" => "thumbnail",
                      "path" => $user->picture->uri,
                      "alt" => $user->name,
                      "height" => 100,
                      "width" => NULL,
                      );
      $row['picture'] = theme_image_style($config);
    } else {
      $row['picture'] = '<img src="/profiles/unicornfactory/themes/custom/unicorn/images/default-profile-pic.png" alt="'.$user->name.'" height="100" />';
    }

    // Add to our results array.
    $results[] = $row;
  }

  return $results;
}

/**
 * Format values array for retrieval.
 */
function _uf_user_format_values_retrieval($form_id, &$values, $user) {
  // Create img tag for avatar.
  if (!empty($values['picture'])) {
    $config = array(
                    "style_name" => "thumbnail",
                    "path" => $values['picture']->uri,
                    "height" => 100,
                    "width" => NULL,
                    );

    $values['picture']->html = theme_image_style($config);
  } else {
    $values['picture'] = new stdClass();
    $values['picture']->html = '<img src="/profiles/unicornfactory/themes/custom/unicorn/images/default-profile-pic.png" alt="'.$user->name.'" height="100" />';
  }

  // Create array of skills.
  $skills = array();
  if (!empty($values['field_user_skill']['und'])) {
    foreach ($values['field_user_skill']['und'] as $skill) {
      // If it's not an array or there is no skill... move on.
      if (!is_array($skill) || empty($skill['field_skill']['und'])) {
        continue;
      }

      // Build values.
      $v = Array();
      $v['name'] = $skill['field_skill']['und'];
      if (is_array($skill['field_user_skill_current_rating']['und']) && isset($skill['field_user_skill_current_rating']['und'][0])) {
        $v['current'] = (int) $skill['field_user_skill_current_rating']['und'][0];
      } else {
        $v['current'] = 0;
      }
      if (is_array($skill['field_user_skill_desired_rating']['und']) && isset($skill['field_user_skill_desired_rating']['und'][0])) {
        $v['desired'] = (int) $skill['field_user_skill_desired_rating']['und'][0];
      } else {
        $v['desired'] = $v['current'];
      }

      $skills[] = $v;
    }
  }
  $values['skills'] = $skills;

  // Create list of projects.
  $projects = array();
  if (!empty($user->field_working_on['und'])) {
    foreach ($user->field_working_on['und'] as $pid) {
      $v = Array();
      $project = node_load($pid['nid']);
      $config = array(
                      "style_name" => "medium",
                      "path" => $project->field_avatar['und'][0]['uri'],
                      "height" => $project->field_avatar['und'][0]['height'],
                      "width" => $project->field_avatar['und'][0]['width']
                      );
      $v['avatar'] = theme_image_style($config);
      $v['name'] = $project->title;
      $v['nid'] = $project->nid;
      $projects[] = $v;
    }
  }
  $values['related_projects'] = $projects;

  // Create list of teams.
  $teams = array();
  if (!empty($user->field_member_of['und'])) {
    foreach ($user->field_member_of['und'] as $tid) {
      $v = Array();
      $team = node_load($tid['nid']);
      if (isset($team->field_avatar['und'])) {
        $config = array(
                        "style_name" => "medium",
                        "path" => $team->field_avatar['und'][0]['uri'],
                        "height" => $team->field_avatar['und'][0]['height'],
                        "width" => $team->field_avatar['und'][0]['width'],
                        "alt" => $team->title,
                        );
        $v['avatar'] = theme_image_style($config);
      } else {
        $v['avatar'] = '<img src="/profiles/unicornfactory/themes/custom/unicorn/images/default-profile-pic.png" alt="'.$team->title.'" width="100" />';
      }
      $v['name'] = $team->title;
      $v['nid'] = $team->nid;
      $teams[] = $v;
    }
  }
  $values['related_teams'] = $teams;
}
