<?php

/**
 * @file
 * inc file for context image loader admin activity.
 */

/**
 * Menu Callback.
 *
 * Builds the admin settings for image swapping.
 */

function context_image_swap_admin() {
  $output = array();
  $output['auto'] = drupal_get_form('context_image_auto_swap');
  $output['upload'] = drupal_get_form('context_image_swap_upload');
  return $output;
}

/**
 * Webp Image auto generation Admin Form.
 *
 * Builds the admin config form for autotamted webp image generation.
 */
function context_image_auto_swap() {
  // Do not show the form if GD for webp not enabled.
  if(!function_exists('imagewebp')) {
    $form['context_image_swapping_alert'] = array(
    '#type' => 'item',
    '#markup' => '<div class="context-image-loader-admin-form-warning">Automated webp image creation needs GD library installed with webp support. Your server does not seems to have that. Please configure it accordingly. <br/><b>You can still use image swapping feature</b> by generating images offline and following the instruction given below.</div>',
    );
    return $form;
  }

  $form['#attached']['css'][] = drupal_get_path('module', 'context_image_loader') . '/context_image_loader_admin.css';

  $form['context_image_swapping_generation'] = [
    '#type' => 'fieldset',
    '#name' =>'Generate webp images',
    '#title' =>'Generate webp images',
  ];

  $form['context_image_swapping_generation']['context_image_webp_label'] = array(
    '#markup' => '<p>You need to have webp images to get image swapping feature working. There are 2 ways of doing it,
     <ul>
     <li>Create them manually and store them it in a subfolder named "webp" for each of the folders containing images you need to swap. (<i> i.e. for any folder "abc", relevant webp images should be kept at "abc/webp"</i></li>
     <li>Use below form to start image generation process automatically. It will find images from the path you choose. It can scan for sub folders too. For each folders, it will generate webp version and store in a subfolder named "webp".</li>
     <li>If you have too many images ( more than thousand ), we would recommend you to work folder by folder or use the drush command.</li>
     <li>Please note, it only works for images of extentions <i>jpg, jpeg, and png</i>.</li>
     </ul></p>',
  );

  $form['context_image_swapping_generation']['context_path_to_scan_images'] = array(
    '#type' => 'textfield',
    '#title' => 'Enter the path to scan for images.',
    '#required' => TRUE,
    '#description' => t('It can be like a valid path like /sites/default/files/ or public://'),
  );

  if(variable_get('context_image_path_scanned', '')) {
    $form['context_image_swapping_generation']['context_image_path_scanned'] = array(
      '#markup' => '<div>Path scanned previously,<br/>'.str_replace(',', '<br/>', variable_get('context_image_path_scanned', '')).'</div>',
    );
  }

  $form['context_image_swapping_generation']['context_scan_sub_folders'] = array(
    '#type' => 'checkbox',
    '#title' => 'Scan the sub folders as well?',
  );

  $form['btn_generate'] = [
    '#type' => 'submit',
    '#value' => 'Generate Webp Images',
  ];

  return $form;
}

/**
 * Image swapping admin form validate handler.
 */
function context_image_auto_swap_validate($form, &$form_state) {
  $path_to_scan = $form_state['values']['context_path_to_scan_images'];
  $actual_path_to_scan = _get_actual_path($path_to_scan);
  if(!$actual_path_to_scan || !file_exists($actual_path_to_scan)) {
    form_set_error('context_image_path_scanned', t('Path seems invalid. Try a valid one.'));
    return FALSE;
  }
  return TRUE;
}

/**
 * Image swapping admin form submit handler.
 */
function context_image_auto_swap_submit($form, &$form_state) {
  $scan_sub_folders = $form_state['values']['context_scan_sub_folders'];
  $path_to_scan = $form_state['values']['context_path_to_scan_images'];
  if(variable_get('context_image_path_scanned', '')) {
    $old_path = variable_get('context_image_path_scanned', '');
    variable_set('context_image_path_scanned', $old_path.",".$path_to_scan);
  }
  _batch_to_convert_webp_images($path_to_scan, $scan_sub_folders);
}


/**
 * Webp image manual upload admin form.
 *
 * Builds the admin config form for manually uploading webp images.
 */
function context_image_swap_upload() {
  // Do not show the form if GD for webp is enabled.
  if(function_exists('imagewebp')) {
    return [];
  }
  $form['context_image_swapping_upload'] = [
    '#type' => 'fieldset',
    '#name' =>'Upload webp images',
    '#title' =>'Upload webp images',
  ];

  $form['context_image_swapping_upload']['context_image_webp_upload_label'] = array(
    '#markup' => '<p>Please use the below form to upload the images using the below process,
     <ul>
     <li>You can upload single of multiple files.</li>
     <li>To upload multiple files, please zip the image files in a single zipped folder.</li>
     <li>Enter the exact location. DO NOT add the "webp" folder as it will be automatically created in the path provided if already does not exists.</li>
     </ul></p>',
  );

  $form['context_image_swapping_upload']['image_swap_upload_path'] = array(
    '#type' => 'textfield',
    '#title' => 'Enter the path to upload.',
    '#required' => TRUE,
    '#description' => t('Enter folder name after /sites/default/files/'),
  );

  $form['context_image_swapping_upload']['upload_image'] = array(
    '#type' => 'managed_file',
    '#title' => 'Webp image files',
    '#default_value' => '',
    '#required' => TRUE,
    '#description' => t('Allowed extension : .zip,.webp'),
    '#upload_location' => 'public://images/',
    '#upload_validators' => array(
      'file_validate_extensions' => array('txt zip'),
      // Pass the maximum file size in bytes
      'file_validate_size' => array(MAX_FILE_SIZE*1024*1024),
    ),
  );
  $form['submit'] = array('#type' => 'submit', '#value' => t('Save Images'), '#attributes' => ['class'=>['btn_track_order']]);
  $form['#submit'] = ['_upload_save_image_files'];

  return $form;
}

/**
 * Menu Callback.
 *
 * Builds the image lazy loading settings page.
 */
function context_image_loader_admin() {

  $form['lazy_load_admin_header'] = array(
    '#markup' => '<h2>Default settings for image lazyload</h2>',
  );

  $form['context_lazy_load_default_delay'] = array(
    '#type' => 'textfield',
    '#title' => 'Default Image load delay time',
    '#default_value' => variable_get('context_lazy_load_default_delay', 0),
    '#description' => t('Delay Time in milli-seconds to load the images'),
  );

  $form['context_lazy_load_default_loader'] = array(
    '#type' => 'managed_file',
    '#title' => 'Default loader image',
    '#default_value' => variable_get('context_lazy_load_default_loader', ''),
    '#required' => TRUE,
    '#upload_location' => 'public://',
  );

  $form['context_lazy_load_div_min_height'] = array(
    '#type' => 'textfield',
    '#title' => 'Loader Div Minimum Height',
    '#default_value' => variable_get('context_lazy_load_div_min_height', 50),
    '#description' => t('Mimimum height required to display loader properly. Put the numeric value only, will be converted to px.'),
  );

  $form['context_lazy_load_div_min_width'] = array(
    '#type' => 'textfield',
    '#title' => 'Loader Div Minimum Width',
    '#default_value' => variable_get('context_lazy_load_div_min_width', 50),
    '#description' => t('Mimimum width required to display loader properly. Put the numeric value only, will be converted to px.'),
  );

  $form['context_lazy_load_enable_cache'] = array(
    '#type' => 'checkbox',
    '#title' => 'Enable caching?',
    '#description' => t('Cache the ouput, for a faster delivery. Enabling it will require cache clearance for all content changes.'),
    '#default_value' => variable_get('context_lazy_load_enable_cache', 0),
  );

  $form['context_lazy_load_cache_exclude'] = array(
    '#type' => 'textarea',
    '#title' => t('Pages to exclude from caching'),
    '#description' => t('Enter the path you want to exclude from caching'),
    '#default_value' => variable_get('context_lazy_load_cache_exclude', ''),
  );

  $form['#submit'] = ['_save_loader_image'];

  return system_settings_form($form);
}
