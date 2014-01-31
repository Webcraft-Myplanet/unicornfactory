<?php
/**
 * @file
 * content_types.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function content_types_taxonomy_default_vocabularies() {
  return array(
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
