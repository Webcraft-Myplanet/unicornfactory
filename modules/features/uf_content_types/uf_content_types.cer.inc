<?php
/**
 * @file
 * uf_content_types.cer.inc
 */

/**
 * Implements hook_cer_default_presets().
 */
function uf_content_types_cer_default_presets() {
  $export = array();

  $preset = new CerPreset();
  $preset->disabled = FALSE; /* Edit this to true to make a default preset disabled initially */
  $preset->a = 'node:kicklow:field_bounty';
  $preset->b = 'node:bounty:field_kicklow';
  $preset->bidirectional = TRUE;
  $preset->weight = 0;
  $export['570cc94cc4759cd07f5dd6d93ca9deb5'] = $preset;

  return $export;
}
