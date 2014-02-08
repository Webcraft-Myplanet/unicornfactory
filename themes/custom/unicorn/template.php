<?php

/**
 * @file
 * template.php
 */

/**
 * Implements hook_preprocess_page().
 */
function unicorn_preprocess_html(&$vars) {
  // Add the ng-app directive to the body tag.
  $vars['attributes_array']['ng-app'] = 'ufApp';
}

/**
 * Returns HTML for a date element formatted as a single date.
 */
function unicorn_date_display_single($variables) {
  $date = $variables['date'];
  $timezone = $variables['timezone'];
  $attributes = $variables['attributes'];

  // Wrap the result with the attributes.
  $output = $date . $timezone;

  if ($variables['add_microdata']) {
    $output .= '<meta' . drupal_attributes($variables['microdata']['value']['#attributes']) . '/>';
  }

  return $output;
}
