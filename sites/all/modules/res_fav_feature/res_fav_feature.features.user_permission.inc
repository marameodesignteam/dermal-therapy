<?php
/**
 * @file
 * res_fav_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function res_fav_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer responsive favicons'.
  $permissions['administer responsive favicons'] = array(
    'name' => 'administer responsive favicons',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'responsive_favicons',
  );

  return $permissions;
}
