<?php

/**
 * @file
 * The Context reaction plugin to add asset files.
 *
 * Contextually add asset files to any page on your site.
 */

/**
 * Expose themes as context reactions.
 */
class context_image_swap extends context_reaction {

  public $search_scope;

  /**
   * Constructor method.
   */
  public function __construct($plugin, $info) {
    parent::__construct($plugin, $info);

    $this->title = t('Image Swap ( Webp )');
  }

  /**
   * Editor form.
   */
  public function editor_form($context) {
    $form = $this->options_form($context);
    return $form;
  }

  /**
   * Submit handler for editor form.
   */
  public function editor_form_submit($context, $values) {
    //$_SESSION['context_form_element_count'] = '';
    return $values;
  }

  /**
   * Image Lazyoader config form.
   *
   * Form to select images to lazyload.
   */
  public function options_form($context) {

    $values = $this->fetch_from_context($context);

    $form['#tree'] = TRUE;
    $form['#attached']['js'][] = drupal_get_path('module', 'context_image_loader') . '/context_image_loader_admin.js';
    $form['#attached']['css'][] = drupal_get_path('module', 'context_image_loader') . '/context_image_loader_admin.css';

    $form['#prefix'] = '<div id="webpswap-form-wrapper">';
    $form['#suffix'] = '</div>';

    $form['lazload-header'] = array(
      '#markup' => '<h1>Settings for Webp Image Swapping</h1>',
    );

    $form['dom_img_swap'] = array(
      '#type' => 'fieldset',
      '#collapsible' => FALSE,
      '#collapsed' => FALSE,
    );
    $form['dom_img_swap']['instructions'] = array(
      '#markup' => "Image swapping would allow you to replace existing images with a lighter version of webp format. It would check if the webp version of the image exists and if so, it would replace.",
    );
    $form['dom_img_swap']['enable_swapping'] = array(
      '#type' => 'checkbox',
      '#title' => t('Enable image swapping for this context?'),
      '#description' =>t('This will allow browser to render webp images ( if available ) when supported.'),
      '#default_value' => isset($values['dom_img_swap']['enable_swapping']) ? $values['dom_img_swap']['enable_swapping'] : 0,
    );
    $form['dom_img_swap']['image_swapping_exclude'] = array(
      '#type' => 'textarea',
      '#title' => t('Exclude Images'),
      '#description' =>t('Add image names which need to be excluded.'),
      '#default_value' => $values['dom_img_swap']['image_swapping_exclude'],
    );
    if(function_exists('imagewebp')) {
      $form['dom_img_swap']['image_swapping_runtime'] = array(
        '#type' => 'checkbox',
        '#title' => t('Generate webp image on the fly?'),
        '#description' =>t('This will to create webp images on the fly if not available. It may have performance effect. You can try bulk image conversion in settings page.'),
        '#default_value' => isset($values['dom_img_swap']['image_swapping_runtime']) ? $values['dom_img_swap']['image_swapping_runtime'] : 0,
      );
    }
    return $form;
  }

  /**
   * Filters deselected files from the listing.
   *
   * Reduces unnecessary conflicts when exporting to Features.
   */
  public function options_form_submit($values) {
    foreach (array_keys($values) as $key) {
      $values[$key] = array_filter($values[$key]);
    }
    return $values;
  }

  /**
   * Implementation of the built-in context plugin class execution.
   */
  public function execute() {
    global $conf;
    $contexts = context_active_contexts();

    foreach ($contexts as $key => $value) {
      if (!empty($value->reactions[$this->plugin])) {
        foreach ($value->reactions[$this->plugin] as $lazyload_settings) {
          $conf['context_image_loader']['enable_swapping'] = $lazyload_settings['enable_swapping'];
          $conf['context_image_loader']['image_swapping_exclude'] = $lazyload_settings['image_swapping_exclude'];
          $conf['context_image_loader']['image_swapping_runtime'] = (isset($lazyload_settings['image_swapping_runtime']))?$lazyload_settings['image_swapping_runtime']:0;
        }
      }
    }
  }

}
