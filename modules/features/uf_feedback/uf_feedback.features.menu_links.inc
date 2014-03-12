<?php
/**
 * @file
 * feedback.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function uf_feedback_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_feedback-simple:admin/appearance/feedback-simple
  $menu_links['management_feedback-simple:admin/appearance/feedback-simple'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/appearance/feedback-simple',
    'router_path' => 'admin/appearance/feedback-simple',
    'link_title' => 'Feedback Simple',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure the Feedback Simple tab.',
      ),
      'identifier' => 'management_feedback-simple:admin/appearance/feedback-simple',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_appearance:admin/appearance',
  );
  // Exported menu link: management_modal-forms:admin/config/development/modal_forms
  $menu_links['management_modal-forms:admin/config/development/modal_forms'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/development/modal_forms',
    'router_path' => 'admin/config/development/modal_forms',
    'link_title' => 'Modal forms',
    'options' => array(
      'attributes' => array(
        'title' => 'Adjust Modal forms settings.',
      ),
      'identifier' => 'management_modal-forms:admin/config/development/modal_forms',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_development:admin/config/development',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Feedback Simple');
  t('Modal forms');


  return $menu_links;
}
