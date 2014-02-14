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
 * @return
 *   The form array.
 */
function _uf_edit_retrieve($form_id) {
  return drupal_get_form($form_id);
}

/**
 * Creates a new form submission based on submitted values.
 *
 * Note that this function uses drupal_form_submit() to create new submissions,
 * which may require very specific formatting. The full implications of this
 * are beyond the scope of this comment block. The Googles are your friend.
 *
 * @param $form_id
 *   The form_id we're submitting.
 * @param $form_values
 *   Array representing the form values.
 * @return
 *   An associative array contained the returned object.
 */
function _uf_edit_submit($form_id, $form_values) {

  // Prepare form state
  $form_state = array();
  $form_state['submitted'] = true;
  $form_state['values'] = $form_values;

  // Submit form programmatically.
  form_execute_handlers('submit', $form, $form_state);

  if ($errors = form_get_errors()) {
    return services_error(implode(" ", $errors), 406, array('form_errors' => $errors));
  }

  return $form_state;
}
