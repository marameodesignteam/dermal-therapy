<?php
/**
 * @file
 * res_fav_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function res_fav_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
