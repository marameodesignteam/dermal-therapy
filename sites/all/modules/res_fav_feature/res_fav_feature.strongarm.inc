<?php
/**
 * @file
 * res_fav_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function res_fav_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'responsive_favicons_path';
  $strongarm->value = 'favicons';
  $export['responsive_favicons_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'responsive_favicons_remove_default';
  $strongarm->value = 1;
  $export['responsive_favicons_remove_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'responsive_favicons_tags';
  $strongarm->value = array(
    0 => '<link rel="apple-touch-icon" sizes="180x180" href="/apple-touch-icon.png">',
    1 => '<link rel="icon" type="image/png" sizes="32x32" href="/favicon-32x32.png">',
    2 => '<link rel="icon" type="image/png" sizes="16x16" href="/favicon-16x16.png">',
    3 => '<link rel="manifest" href="/site.webmanifest">',
    4 => '<link rel="mask-icon" href="/safari-pinned-tab.svg" color="#5bbad5">',
    5 => '<meta name="msapplication-TileColor" content="#da532c">',
    6 => '<meta name="theme-color" content="#ffffff">',
  );
  $export['responsive_favicons_tags'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'responsive_favicons_upload';
  $strongarm->value = '';
  $export['responsive_favicons_upload'] = $strongarm;

  return $export;
}
