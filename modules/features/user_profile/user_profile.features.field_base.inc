<?php
/**
 * @file
 * user_profile.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function user_profile_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_user_team'
  $field_bases['field_user_team'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_user_team',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'project_profile' => 0,
        'team_profile' => 'team_profile',
      ),
      'view' => array(
        'args' => array(),
        'display_name' => '',
        'view_name' => '',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
  );

  return $field_bases;
}
