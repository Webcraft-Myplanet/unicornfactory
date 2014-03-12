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

    // Add slogan, if any.
    if (!empty($user->field_slogan['und'][0]['value'])) {
      $row['slogan'] = $user->field_slogan['und'][0]['value'];
    }

    // Add profile image, if any.
    if (!empty($user->picture->uri)) {
      $config = array(
                      "style_name" => "thumbnail",
                      "path" => $user->picture->uri,
                      "height" => 100,
                      "width" => 100,
                      );
      $row['picture'] = theme_image_style($config);
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
    $values['picture']->html = uf_edit_build_thumbnail($values['picture']);
  }

  // Create array of skills.
  $skills = array();
  if (!empty($values['field_user_skill']['und'])) {
    foreach ($values['field_user_skill']['und'] as $skill) {
      // If it's not an array... move on.
      if (!is_array($skill)) {
        continue;
      }

      // Build values.
      $v = Array();
      $v['name'] = $skill['field_skill']['und'];
      $v['current'] = (int) $skill['field_user_skill_current_rating']['und'][0]['value'];
      $v['desired'] = (int) $skill['field_user_skill_desired_rating']['und'][0]['value'];

      $skills[] = $v;
    }
  }
  $values['skills'] = $skills;

  // Create list of projects.
  $projects = array();
  if (!empty($user->field_working_on['und'])) {
    foreach ($user->field_working_on['und'] as $pid) {
      $projects[] = $pid['nid'];
    }
  }
  $values['myProjects'] = $projects;

  // Create list of teams.
  $teams = array();
  if (!empty($user->field_member_of['und'])) {
    foreach ($user->field_member_of['und'] as $tid) {
      $teams[] = $tid['nid'];
    }
  }
  $values['myTeams'] = $teams;
}

/**
 * Creates a new form submission based on submitted values.
 *
 * Note that this function uses drupal_form_submit() to create new submissions,
 * which may require very specific formatting. The full implications of this
 * are beyond the scope of this comment block. The Googles are your friend.
 *
 * @param $uid
 *   The uid of the user to edit.
 * @param $values
 *   Array representing the form values.
 * @return
 *   An associative array contained the returned object.
 */
function _uf_user_submit($uid, $values) {
  // Load user form pages.
  module_load_include('inc', 'user', 'user.pages');

  // Load user so we can add it to the form.
  $user = user_load($uid);

  // Modify the values structure based on $form_id.
  _uf_user_format_values_submission('user_profile_form', $values);

  // Load the form.
  $form_state = array();
  $form_state['values'] = $values;
  $form_state['values']['op'] = t('Save');
  $form_state['build_info']['args'] = array($user);
  drupal_form_submit('user_profile_form', $form_state, $user);

  // Submit form programmatically.
  if ($errors = form_get_errors()) {
    return services_error(implode(" ", $errors), 406, array('form_errors' => $errors));
  }

  return drupal_get_messages();
}

/**
 * Format values array for submission.
 */
function _uf_user_format_values_submission($form_id, &$values) {
  // We don't need to assign roles in the inline edit - take out so Drupal doesn't complain
  unset($values['roles']);

  // If these values are set, Drupal will try to call deleting functions for the avatar
  unset($values['picture_delete']);
  unset($values['picture_upload']);

  // Put the skills back into the array.
  if (!empty($values['skills'])) {
    // Reset the skills array.
    $values['field_user_skill']['und'] = array();
    foreach ($values['skills'] as $skill) {

      // Build values array.
      $row = array();
      $row['field_skill']['und'] = $skill['name'];
      $row['field_user_skill_current_rating']['und'][0]['value'] = $skill['current'];
      $row['field_user_skill_desired_rating']['und'][0]['value'] = $skill['desired'];

      // Add it to the row.
      $values['field_user_skill']['und'][] = $row;
    }
  }

  // Update "changed".
  $values['changed'] = time();
}
