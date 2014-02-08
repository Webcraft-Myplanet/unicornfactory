<?php
/**
 * @file
 * content_types.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function uf_content_types_taxonomy_default_vocabularies() {
  return array(
    'project_status' => array(
      'name' => 'Project Status',
      'machine_name' => 'project_status',
      'description' => 'Project specific status',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'skill' => array(
      'name' => 'Skill',
      'machine_name' => 'skill',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
