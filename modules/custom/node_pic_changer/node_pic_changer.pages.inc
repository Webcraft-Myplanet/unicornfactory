<?php
/**
 * @file
 * Pages and forms constructors and handlers
 */
function node_pic_changer_ajax($nid) {
  global $user; // Is this needed? I haven't tried testing after removing this

  ctools_include('modal');
  ctools_include('ajax');

  // Load node form pages
  module_load_include('inc', 'node', 'node.pages');

  $node = node_load($nid);

  $form_state = array(
    'nid'   => $nid,
    'title' => t("Update this image"),
    'ajax'  => TRUE // this should never get called from outside of ajax
  );

  $output = ctools_modal_form_wrapper('node_pic_changer_form', $form_state);
  if ($form_state['executed']) {
    // remove the confirmation messages that will have been set by user.module, or they will be displayed
    // on the next page load, confusing the user.
    unset($_SESSION['messages']['status']);

    $commands = array();
    $commands[] = ctools_modal_command_dismiss(t('Picture changed'));
    $commands[] = array('command' => 'pic_updated', 'argument' => node_pic_picture_src($nid));

    print ajax_render($commands);
    exit;
  }

  print ajax_render($output);
  exit;
}

function node_pic_picture_src($nid) {
  $node = node_load($nid);
  if (!$node) {
    return '1';
  }

  $filepath = $node->field_avatar['und'][0]['uri'];
  if (!$filepath) {
    return '2';
  }

  $image_html = '';
  if (module_exists('image') && file_valid_uri($filepath) && $style = 'thumbnail') {
    $image_html = theme('image_style', array('style_name' => 'thumbnail', 'path' => $filepath));
  }
  else {
    $image_html = theme('image', array('path' => $filepath, 'alt' => $alt, 'title' => $alt));
  }

  $match = array();
  if (preg_match("/src=[\"'](.*?)[\"']/", $image_html, $match)) {
    return $match[1];
  }

  return "";
}

function node_pic_changer_form($form, &$form_state) {
  global $user;
  /*if (!$form_state['uid'] || $user->uid != $form_state['uid']) {
    return array();
  }*/

  // Load node form pages
  module_load_include('inc', 'node', 'node.pages');

  // Get node
  $node = node_load($form_state['nid']);

  /* Get the default node form so we can reuse the validation
   * and submit stuff, then remove everything except the field_avatar field
   */
  $form = node_form($form, $form_state, $node);

  // grab the picture field (which may have been nested if field_group is installed)
  $fpic = node_pic_changer_picture_field($form);

  if (!$fpic) {
    // no picture field here
    watchdog('node_pic_changer', 'Error finding picture field in the node.', WATCHDOG_ERROR);
    return array();
  }

  // unset all the unneeded stuff
  foreach ($form as $k => $v) {
    // internal keys
    if (substr($k, 0, 1) === '#') {
      continue;
    }

    // keep the various buttons
    if ($k === 'actions') {
      // Remove the delete button so the node itself can't be deleted
      if (isset($form['actions']['delete'])) {
        unset($form['actions']['delete']);
      }
      continue;
    }

    // other important fields
    if (substr($k, 0, 4) === 'form') {
      continue;
    }

    // Node forms need to know what type the node is
    if ($k === 'type') {
      continue;
    }

    unset($form[$k]);
  }

  // add the pic field back
  $form['field_avatar'] = $fpic;

  // Ensure that just the node_form_validate function is being called
  $form['#validate'] = array('node_form_validate');

  return $form;
}

/**
 * Retrieve the picture field
 *
 * @param $element
 *
 * @return
 * An array describing the picture field
 */
function node_pic_changer_picture_field($element) {
  foreach ($element as $k => $v) {
    if ($k === 'field_avatar' && is_array($v)) {
      return $element[$k];
    }

    if (is_array($element[$k])) {
      $test = node_pic_changer_picture_field($element[$k]);
      if ($test) {
        return $test;
      }
    }
  }

  return NULL;
}
