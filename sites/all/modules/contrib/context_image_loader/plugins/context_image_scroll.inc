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
class context_image_scroll extends context_reaction {

  public $search_scope;

  /**
   * Constructor method.
   */
  public function __construct($plugin, $info) {
    parent::__construct($plugin, $info);

    $this->title = t('Image Load on Scroll');
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

    $form['#prefix'] = '<div id="lazyload-form-wrapper">';
    $form['#suffix'] = '</div>';

    $form['lazload-header'] = array(
      '#markup' => '<h1>Image Load on Scroll</h1>',
    );

    $form['dom_img_scroll'] = array(
      '#type' => 'fieldset',
      '#collapsible' => FALSE,
      '#collapsed' => FALSE,
    );
    $form['dom_img_scroll']['instructions'] = array(
      '#markup' => "Image scrolling would allow you to replace existing images with a lighter version of webp format. It would check if the webp version of the image exists and if so, it would replace.",
    );
    $form['dom_img_scroll']['enable_scrolling'] = array(
      '#type' => 'checkbox',
      '#title' => t('Enable image scrolling for this context?'),
      '#default_value' => isset($values['dom_img_scroll']['enable_scrolling']) ? $values['dom_img_scroll']['enable_scrolling'] : 0,
    );

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
          print_r($lazyload_settings);
            $conf['context_image_loader']['enable_scrolling'] = $lazyload_settings['enable_scrolling'];
        }
      }
    }
  }

}
