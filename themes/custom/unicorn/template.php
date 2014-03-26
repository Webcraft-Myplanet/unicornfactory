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
  drupal_add_css('http://netdna.bootstrapcdn.com/font-awesome/4.0.3/css/font-awesome.css', array('type' => 'external'));
}

function unicorn_preprocess_page(&$vars) {
  if (empty($vars['content_column_class'])) {
    $vars['content_column_class'] = ' class="col-xs-offset-1 col-xs-10"';
  }
}

function unicorn_preprocess_user_profile(&$vars) {
  $vars['content_column_class'] = ' class="col-xs-12"';
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

/**
 * Implements hook_preprocess_page().
 */
function unicorn_get_avatar() {

// Creating dynamic avatar for menu.

  global $user;
  $user = user_load ($user->uid);
  if(!empty($user->picture)) {
    $image = theme_image_style(
      array(
        'style_name' => 'thumbnail',
        'path' => $user->picture->uri,
        'alt' => 'Your avatar/profile',
        'attributes' => array(
          'class' => 'avatar'

          ),
        'height' => 65,
        'width' => NULL,
        )
      );
  }
  else{
    $image = '<img class="avatar" src="/profiles/skeletor/themes/custom/unicorn/images/default-profile-pic.png" alt="Your avatar/profile" height="65" />';
  }

  return $image;
}


/**
 * Overrides theme_menu_link().
 *
 * We're using this to add the user's avatar to a link.
 */
function unicorn_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    // Prevent dropdown functions from being added to management menu so it
    // does not affect the navbar module.
    if (($element['#original_link']['menu_name'] == 'management') && (module_exists('navbar'))) {
      $sub_menu = drupal_render($element['#below']);
    }
    elseif ((!empty($element['#original_link']['depth'])) && ($element['#original_link']['depth'] == 1)) {
      // Add our own wrapper.
      unset($element['#below']['#theme_wrappers']);
      $sub_menu = '<ul class="dropdown-menu">' . drupal_render($element['#below']) . '</ul>';
      // Generate as standard dropdown.

      // Attach the user's avatar to their link.
      if ($element['#title'] == 'My Account') {
        $element['#title'] = '<span class="user-picture">'.unicorn_get_avatar().'</span>' ;
      }
      $element['#title'] .= ' <span class="caret"></span>';
      $element['#attributes']['class'][] = 'dropdown';
      $element['#localized_options']['html'] = TRUE;

      // Set dropdown trigger element to # to prevent inadvertant page loading
      // when a submenu link is clicked.
      $element['#localized_options']['attributes']['data-target'] = '#';
      $element['#localized_options']['attributes']['class'][] = 'dropdown-toggle';
      $element['#localized_options']['attributes']['data-toggle'] = 'dropdown';
    }
  }
  // On primary navigation menu, class 'active' is not set on active menu item.
  // @see https://drupal.org/node/1896674
  if (($element['#href'] == $_GET['q'] || ($element['#href'] == '<front>' && drupal_is_front_page())) && (empty($element['#localized_options']['language']))) {
    $element['#attributes']['class'][] = 'active';
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}
