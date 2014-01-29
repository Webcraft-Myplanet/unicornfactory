<?php
/**
 * @file
 * Enables modules and site configuration for install profile.
 */

/**
 * Implements hook_form_FORM_ID_alter() for install_configure_form().
 *
 * Allows the profile to alter the site configuration form.
 */
function skeletor_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = $_SERVER['SERVER_NAME'];
}

/*
 * Implements hook_install_postinstall()
 *
 * Allows us to set the site_name after it has been overridden
 */
function skeletor_install_postinstall() {
  // Set some variables.
  variable_set('site_name', 'Unicorn Factory');
  //variable_get('other_var', 123);

  // Do other things.
  /*$things = array(
    'setting' => 'value',
  ); */
}