<?php

/**
 * @file
 * template.php
 */

/**
 * Implements hook_preprocess_block().
 */
function unicorn_preprocess_block(&$vars) {
  // Check for our blocks, and add proper ng-controller directives.
  switch ($vars['block']->delta) {
    case 'uf_projects_list':
      $vars['attributes_array']['ng-controller'] = 'ProjectsCtrl';
      break;
    default:
      break;
  }
}

/**
 * Implements hook_preprocess_page().
 */
function unicorn_preprocess_html(&$vars) {
  // Add the ng-app directive to the body tag.
  $vars['attributes_array']['ng-app'] = 'ufApp';
}
