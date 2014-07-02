<?php
/**
 * @file
 * uf_content_types.features.ckeditor_profile.inc
 */

/**
 * Implements hook_ckeditor_profile_defaults().
 */
function uf_content_types_ckeditor_profile_defaults() {
  $data = array(
    'CKEditor Global Profile' => array(
      'name' => 'CKEditor Global Profile',
      'settings' => array(
        'ckeditor_path' => '//cdn.ckeditor.com/4.4.0/full-all',
      ),
      'input_formats' => array(),
    ),
  );
  return $data;
}
