<?php

/**
 * @file
 * Services callbacks.
 */

/**
 * Format values array for submission.
 *
 * @param $field_ids
 *   String, seperated by comma of field ids to get.
 */
function _uf_field_retrieve($field_ids = '') {
  $field_ids = explode(',', $field_ids);
  $options = array();

  foreach (array_filter($field_ids) as $field_id) {
    $options[$field_id] = _uf_field_get_options($field_id);
  }

  return $options;
}

/**
 * Find options for particular fields.
 *
 * @param $field_id
 *   The field_id to get options for.
 */
function _uf_field_get_options($field_id) {
  $field = field_info_field($field_id);
  $options = array();

  switch ($field['type']) {
    case 'taxonomy_term_reference':
    $options = array_values(taxonomy_allowed_values($field));
    break;
    case 'node_reference':
    // For each node referenced, let's build a pretty array for JS to use.
    foreach (node_reference_options_list($field) as $nid => $title) {
      // Reset the "row" array.
      $row = array();
      $node = node_load($nid);

      // Build a pretty array of "row"s.
      $row['value'] = $nid;
      $row['text'] = $node->title;
      $row['logo'] = uf_edit_build_thumbnail((object) $node->field_avatar['und'][0]);

      // Add our newly build "row" to our list of options.
      $options[$nid] = $row;
    }
    break;
  }

  return $options;
}
