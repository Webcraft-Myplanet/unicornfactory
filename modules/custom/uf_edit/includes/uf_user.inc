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
function _uf_user_retrieve($uid) {
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
 * Format values array for retrieval.
 */
function _uf_user_format_values_retrieval($form_id, &$values, $user) {
  // Create img tag for avatar.
  if (!empty($values['picture'])) {
    $config = array(
                    "style_name" => "thumbnail",
                    "path" => $values['picture']->uri,
                    "height" => 100,
                    "width" => 100,
                    );

    $values['picture']->html = theme_image_style($config);
  }

  // Create list of projects.
  $projects = Array();
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
  $teams = Array();
  if (!empty($user->field_member_of['und'])) {
    foreach ($user->field_member_of['und'] as $tid) {
      $v = Array();
      $team = node_load($tid['nid']);
      $config = array(
                      "style_name" => "medium",
                      "path" => $team->field_avatar['und'][0]['uri'],
                      "height" => $team->field_avatar['und'][0]['height'],
                      "width" => $team->field_avatar['und'][0]['width']
                      );
      $v['avatar'] = theme_image_style($config);
      $v['name'] = $team->title;
      $v['nid'] = $team->nid;
      $teams[] = $v;
    }
  }
  $values['related_teams'] = $teams;
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
  _uf_edit_format_values_submission('user_profile_form', $values);

  // Load the form.
  $form_state = array();
  $form_state['values'] = $values;
  $form_state['values']['op'] = t('Save');
  $form_state['build_info']['args'] = array($user);
  drupal_form_submit('user_profile_form', $form_state, $user);

  // Submit form programmatically.
  // user_form_submit($form, $form_state);
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
  // Same thing applies to avatar
  unset($values['field_avatar']);
  // If these values are set, Drupal will try to call deleting functions for the avatar
  unset($values['picture_delete']);
  unset($values['picture_upload']);

  // Update "changed".
  $values['changed'] = time();
}
