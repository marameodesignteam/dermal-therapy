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
class context_image_lazyload extends context_reaction {

  public $search_scope;

  /**
   * Constructor method.
   */
  public function __construct($plugin, $info) {
    parent::__construct($plugin, $info);
    $this->title = t('Image Lazyload');
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
    $_SESSION['context_form_element_count'] = '';
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

    $form['#prefix'] = '<div id="lazyload-form-wrapper">';
    $form['#suffix'] = '</div>';

    $form['lazload-header'] = array(
      '#markup' => '<h1>Settings for Image Lazy Load</h1>',
    );

    $form['dom_elements'] = array(
      '#type' => 'fieldset',
      '#title' => 'Lazy Load Scope',
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );

    $form['dom_elements']['instructions'] = array(
      '#markup' => "<div class='context_image_loader_instruction'><strong>Scope for lazy loading in this context :</strong><br/>
      <ul>
      <li><strong>Complete Page : </strong> Grabs all images within html>body.</li>
      <li><strong>Specific Containers : </strong> Grabs images of the specific containers as selected.</li>
      </ul>
      <strong>Rules for selector :</strong>
      <ul>
      <li>Allowed containers :<strong> Div, Span, P, Table, Tr, Td, Ul, li.</strong></li>
      <li>Each container may have only one filter. Allowed filters are : <strong>class, name, id.</strong></li>
      <li>Filters must be enclosed with square brackets [ ]. <strong> Example use : div[class=classname], span[id=id].</strong></li>
      <li>Nesting can be used only with seperator '>'. <strong>Example use : div[class=classname]>span[id=id]>div.</strong></li>
      <li>Element count ( Nth element ) can be used for multiple elements with same attributes. <strong>Example use : div[class=classname,N]. It must be used for the last element in the selector.</strong></li>
      <li>Don't use spaces.</li>
      <li>Container or the image should have a height/width defined to keep the layout intact while using a loader image.</li>
      <li><strong>Putting 0 and negative values in Delay Time field will stop lazy loading.</strong></li>
      <li><strong>Alternate image</strong> can be used to replace any existing high-res image with low-res image for a lazy load. If you upload <strong>alternate image</strong> for any block, it will be shown instead of the loader image.</li>
      <li>For <strong>Inline Background images</strong>, it will be replaced by any <strong>alternate image</strong> if uploaded, else it will be placed blank.</li>
      </ul>
      </div>",
    );

    $form['dom_elements']['element_type'] = array(
      '#type' => 'radios',
      '#options' => [1 => 'Complete page', 2 => 'Specific Containers'],
      '#title' => t('Select the scope for lazy loading'),
      '#default_value' => isset($values['dom_elements']['element_type']) ? $values['dom_elements']['element_type'] : 1,
    );   

    $form['dom_elements']['custom_elementset'] = array(
      '#type' => 'fieldset',
      '#title' => t('Specific Containers'),
      '#description' => t('Select specific containers within a page to be scanned for images'),
      '#prefix' => '<div id="custom-element-wrapper">',
      '#suffix' => '</div>',
    );

    if (isset($context->reactions['plugins']['lazy_load']['custom_elementset']['element_count'])) {
      $elem_count = $form_state['values']['reactions']['plugins']['lazy_load']['custom_elementset']['element_count'];
    }
    else {

      $elem_count = isset($values['dom_elements']['custom_elementset']['element_count'])?$values['dom_elements']['custom_elementset']['element_count']:0;
    }

    $form['dom_elements']['custom_elementset']['element_count'] = array(
      '#type' => 'select',
      '#title' => 'Number of containers to be used',
      '#prefix' => '<div id="element-count-wrapper">',
      '#suffix' => '</div>',
      '#options' => range(1, 10),
      '#default_value' => $elem_count,
      '#submit' => array('submit_callback'),
      '#ajax' => array(
        'callback' => 'elements_add_more',
        'method' => 'replace',
        'effect' => 'fade',
        'wrapper' => 'custom-element-wrapper',
      ),
    );

    for ($i = 1; $i <= $elem_count + 1; $i++) {
      $form['dom_elements']['custom_elementset']['element_wrapper_' . $i] = array(
        '#type' => 'fieldset',
        '#title' => t('Container') . " $i",
        '#prefix' => '<div id="custom-element-subwrapper">',
        '#suffix' => '</div>',
      );
      $form['dom_elements']['custom_elementset']['element_wrapper_' . $i]['element_selector_' . $i] = array(
        '#type' => 'textfield',
        '#title' => 'DOM Selector',
        '#description' => t('Enter the selector for the container to be scanned for images'),
        '#size' => 22,
        '#default_value' => $values['dom_elements']['custom_elementset']['element_wrapper_' . $i]['element_selector_' . $i],
      );
      $form['dom_elements']['custom_elementset']['element_wrapper_' . $i]['element_loadtime_' . $i] = array(
        '#type' => 'textfield',
        '#title' => 'Image Load Delay Time',
        '#description' => t('Delay Time in milli-seconds to load the images'),
        '#size' => 22,
        '#default_value' => $values['dom_elements']['custom_elementset']['element_wrapper_' . $i]['element_loadtime_' . $i],
      );
      $form['dom_elements']['custom_elementset']['element_wrapper_' . $i]['use_loader_' . $i] = array(
        '#type' => 'checkbox',
        '#title' => 'Show loader image.',
        '#description' => t('Select if you want to show the default loader image, else blank div will be shown until the image is loaded.'),
        '#default_value' => $values['dom_elements']['custom_elementset']['element_wrapper_' . $i]['use_loader_' . $i],
      );
      $form['dom_elements']['custom_elementset']['element_wrapper_' . $i]['set_on_scroll_' . $i] = array(
        '#type' => 'checkbox',
        '#title' => t('Load only when in viewport.'),
        '#description' => t('Select if you want to load images first time only when it is in viewport. This can immensely help reducing initial page size and unnecessary image loading.'),
        '#default_value' => $values['dom_elements']['custom_elementset']['element_wrapper_' . $i]['set_on_scroll_' . $i],
      );
      $form['dom_elements']['custom_elementset']['element_wrapper_' . $i]['bg_image_' . $i] = array(
        '#type' => 'checkbox',
        '#title' => 'Is it a Inline Background image?',
        '#description' => t('Check if you want to lazy load a background image.'),
        '#default_value' => $values['dom_elements']['custom_elementset']['element_wrapper_' . $i]['bg_image_' . $i],
      );
      $form['dom_elements']['custom_elementset']['element_wrapper_' . $i]['trans_image_' . $i] = array(
        '#type' => 'checkbox',
        '#title' => 'Render resized transparent image?',
        '#description' => t('It tries to render a resized transparent image of actual image size displayed in the page while showing the loader. This feature may be helpful in some scenarios to keep loader in place and avoid layout distortion. Use only when necessary.'),
        '#default_value' => $values['dom_elements']['custom_elementset']['element_wrapper_' . $i]['trans_image_' . $i],
      );
      
      $form['dom_elements']['custom_elementset']['element_wrapper_' . $i]['alternate_image_' . $i] = array(
        '#type' => 'managed_file',
        '#title' => 'Alternate image',
        '#default_value' => $values['dom_elements']['custom_elementset']['element_wrapper_' . $i]['alternate_image_' . $i],
        '#description' => t('It can be used for replacing current image with alternate (low-res) image during lazy-load.'),
        '#upload_location' => 'public://',
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
    global $user;
    foreach (array_keys($values) as $key) {
      $values[$key] = array_filter($values[$key]);
    }
    //save alternate image if needed
    if ($values['dom_elements']['element_type'] == 2) {
      for($i=0; $i<=$values['dom_elements']['custom_elementset']['element_count']; $i++){
        if($values['dom_elements']['custom_elementset']['element_wrapper_'.($i+1)]['alternate_image_'.($i+1)]) {

          $file = file_load($values['dom_elements']['custom_elementset']['element_wrapper_'.($i+1)]['alternate_image_'.($i+1)]);
          if($file) {
            // Change status to permanent.
            $file->status = FILE_STATUS_PERMANENT;
            // Save.
            file_save($file);
            file_usage_add($file, 'context_image_loader', 'user', $user->uid);
          }
        }
      }
    }

    return $values;
  }

  /**
   * Implementation of the built-in context plugin class execution.
   */
  public function execute() {
    global $conf;
    $contexts = context_active_contexts();
    foreach ($contexts as $value) {
      if (!empty($value->reactions[$this->plugin])) {
        foreach ($value->reactions[$this->plugin] as $lazyload_settings) {          
          if ($lazyload_settings['element_type'] == 1) {
            $conf['context_image_loader']['image_lazyload'][] = 'content';
          }
          else {
            $lazyload_settings['custom_elementset']['context_name'] = $value->name;
            $conf['context_image_loader']['image_lazyload'][] = $lazyload_settings['custom_elementset'];
          }

        }
      }
    }
  }

}
