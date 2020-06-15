<?php
/**
 * @file
 * flexitol_content.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function flexitol_content_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|article|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'article';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h2',
        'class' => '',
        'ft' => array(),
      ),
    ),
  );
  $export['node|article|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|article|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'article';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|article|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|article|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'article';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|article|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|conditions|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'conditions';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|conditions|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|conditions|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'conditions';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'node_link' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|conditions|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|homepage_featured_content|widget';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'homepage_featured_content';
  $ds_fieldsetting->view_mode = 'widget';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'field_hfc_hover_text' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field-name-field-hfc-hover-text',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['node|homepage_featured_content|widget'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|homepage_slide|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'homepage_slide';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'field_slide_image' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|homepage_slide|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|page|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'page';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|page|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|product|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'product';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'beauty_review_data_clone_' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:10:{s:5:"label";s:6:"hidden";s:9:"formatter";s:10:"bhfivestar";s:11:"delta_limit";i:0;s:12:"delta_offset";s:1:"0";s:14:"delta_reversed";b:0;s:18:"formatter_settings";a:0:{}s:7:"context";s:25:"argument_entity_id:node_1";s:14:"override_title";i:0;s:19:"override_title_text";s:0:"";s:22:"override_title_heading";s:2:"h2";}s:4:"type";s:12:"entity_field";s:7:"subtype";s:29:"node:field_beauty_review_data";}',
        'load_terms' => 0,
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'bh-rating  hidden-md',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'product_slideshow' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'product-gallery',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'subtitle_clone_' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:10:{s:5:"label";s:6:"hidden";s:9:"formatter";s:12:"text_default";s:11:"delta_limit";i:0;s:12:"delta_offset";s:1:"0";s:14:"delta_reversed";b:0;s:18:"formatter_settings";a:0:{}s:7:"context";s:25:"argument_entity_id:node_1";s:14:"override_title";i:0;s:19:"override_title_text";s:0:"";s:22:"override_title_heading";s:2:"h2";}s:4:"type";s:12:"entity_field";s:7:"subtype";s:27:"node:field_product_subtitle";}',
        'load_terms' => 0,
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'hidden-md',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'subtitle_information_clone_' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:10:{s:5:"label";s:6:"hidden";s:9:"formatter";s:12:"text_default";s:11:"delta_limit";s:1:"0";s:12:"delta_offset";s:1:"0";s:14:"delta_reversed";i:0;s:18:"formatter_settings";a:0:{}s:7:"context";s:25:"argument_entity_id:node_1";s:14:"override_title";i:0;s:19:"override_title_text";s:0:"";s:22:"override_title_heading";s:2:"h2";}s:4:"type";s:12:"entity_field";s:7:"subtype";s:31:"node:field_subtitle_information";}',
        'load_terms' => 0,
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'subtitle-info hidden-md',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'title_clone_' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:8:{s:4:"link";i:0;s:6:"markup";s:2:"h1";s:2:"id";s:0:"";s:5:"class";s:9:"hidden-md";s:7:"context";s:25:"argument_entity_id:node_1";s:14:"override_title";i:0;s:19:"override_title_text";s:0:"";s:22:"override_title_heading";s:2:"h2";}s:4:"type";s:10:"node_title";s:7:"subtype";s:10:"node_title";}',
        'load_terms' => 0,
        'ft' => array(
          'func' => 'theme_ds_field_expert',
        ),
      ),
    ),
    'where_to_buy_button' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'write_a_review_url_clone_' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:10:{s:5:"label";s:6:"hidden";s:9:"formatter";s:12:"link_default";s:11:"delta_limit";i:0;s:12:"delta_offset";s:1:"0";s:14:"delta_reversed";b:0;s:18:"formatter_settings";a:0:{}s:7:"context";s:25:"argument_entity_id:node_1";s:14:"override_title";i:0;s:19:"override_title_text";s:0:"";s:22:"override_title_heading";s:2:"h2";}s:4:"type";s:12:"entity_field";s:7:"subtype";s:29:"node:field_write_a_review_url";}',
        'load_terms' => 0,
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'write-review hidden-md',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'title' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h1',
        'class' => 'visible-md',
        'ft' => array(
          'func' => 'theme_ds_field_expert',
        ),
      ),
    ),
    'field_product_subtitle' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'visible-md field-name-field-product-subtitle',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_product_related_product' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'related-products',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'ul',
          'fis-cl' => 'row',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'li',
          'fi-cl' => 'col-sm-6 col-lg-3',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_beauty_review_data' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'bh-rating visible-md-inlineflex',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_write_a_review_url' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'write-review visible-md-inlineflex',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_subtitle_information' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'subtitle-info visible-md-flex',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['node|product|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|product|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'product';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h2',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'node_link' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link text' => 'Learn more',
        'wrapper' => '',
        'class' => 'btn btn-default',
        'ft' => array(),
      ),
    ),
  );
  $export['node|product|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|product|widget';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'product';
  $ds_fieldsetting->view_mode = 'widget';
  $ds_fieldsetting->settings = array(
    'node_link' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link text' => 'Read more',
        'wrapper' => '',
        'class' => 'btn btn-primary',
        'ft' => array(),
      ),
    ),
  );
  $export['node|product|widget'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|review|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'review';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h2',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'field_review_city' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-col' => TRUE,
          'suffix' => ', ',
        ),
      ),
    ),
    'field_review_country' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
        ),
      ),
    ),
  );
  $export['node|review|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|review|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'review';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'node_link' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|review|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|review|widget';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'review';
  $ds_fieldsetting->view_mode = 'widget';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|review|widget'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|webform|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'webform';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'comments' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|webform|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|webform|widget';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'webform';
  $ds_fieldsetting->view_mode = 'widget';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|webform|widget'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'taxonomy_term|conditions|full';
  $ds_fieldsetting->entity_type = 'taxonomy_term';
  $ds_fieldsetting->bundle = 'conditions';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'inline',
      'format' => 'default',
    ),
    'more_link' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['taxonomy_term|conditions|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'taxonomy_term|conditions|widget';
  $ds_fieldsetting->entity_type = 'taxonomy_term';
  $ds_fieldsetting->bundle = 'conditions';
  $ds_fieldsetting->view_mode = 'widget';
  $ds_fieldsetting->settings = array(
    'more_link' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['taxonomy_term|conditions|widget'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'taxonomy_term|product_category|full';
  $ds_fieldsetting->entity_type = 'taxonomy_term';
  $ds_fieldsetting->bundle = 'product_category';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['taxonomy_term|product_category|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function flexitol_content_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'conditions_menu_block';
  $ds_field->label = 'Conditions Menu';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|conditions_menu-block',
    'block_render' => '2',
  );
  $export['conditions_menu_block'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'where_to_buy_button';
  $ds_field->label = 'Where to buy button';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'product|*';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
$crt_path = current_path();
$path = ($crt_path == \'node/1331\' || $crt_path == \'node/1332\' || $crt_path == \'node/1333\') ? \'https://littlebodies.com.au/\' : \'/where-buy\';
?>
<p><a class="btn btn-danger" href="<?php echo $path; ?>">Where to buy</a></p>',
      'format' => 'php_code',
    ),
    'use_token' => 0,
  );
  $export['where_to_buy_button'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function flexitol_content_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_clinical_study|default';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_clinical_study';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'group_clinical_studies_accordion',
        1 => 'group_clinical_studies_item',
        2 => 'field_clinical_study_title',
        3 => 'field_clinical_study_images',
        4 => 'field_clinical_study_description',
      ),
    ),
    'fields' => array(
      'group_clinical_studies_accordion' => 'central',
      'group_clinical_studies_item' => 'central',
      'field_clinical_study_title' => 'central',
      'field_clinical_study_images' => 'central',
      'field_clinical_study_description' => 'central',
    ),
    'classes' => array(),
    'wrappers' => array(
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['field_collection_item|field_clinical_study|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'title',
        1 => 'field_image',
        2 => 'body',
        3 => 'field_video',
      ),
    ),
    'fields' => array(
      'title' => 'central',
      'field_image' => 'central',
      'body' => 'central',
      'field_video' => 'central',
    ),
    'classes' => array(),
    'wrappers' => array(
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|article|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'title',
        1 => 'field_image',
        2 => 'body',
        3 => 'field_video',
      ),
    ),
    'fields' => array(
      'title' => 'central',
      'field_image' => 'central',
      'body' => 'central',
      'field_video' => 'central',
    ),
    'classes' => array(),
    'wrappers' => array(
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'hide_page_title' => '0',
    'page_option_title' => '',
  );
  $export['node|article|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'title',
        1 => 'field_image',
        2 => 'body',
        3 => 'field_video',
      ),
    ),
    'fields' => array(
      'title' => 'central',
      'field_image' => 'central',
      'body' => 'central',
      'field_video' => 'central',
    ),
    'classes' => array(),
    'wrappers' => array(
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|article|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|conditions|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'conditions';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'bootstrap_3_9';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_conditions_main_blurb',
        1 => 'field_conditions_body',
        2 => 'field_page_background_image',
      ),
    ),
    'fields' => array(
      'field_conditions_main_blurb' => 'left',
      'field_conditions_body' => 'left',
      'field_page_background_image' => 'left',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|conditions|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|conditions|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'conditions';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'field_conditions_body',
      ),
      'banner_conditions' => array(
        1 => 'title',
        2 => 'field_conditions_main_blurb',
      ),
    ),
    'fields' => array(
      'field_conditions_body' => 'central',
      'title' => 'banner_conditions',
      'field_conditions_main_blurb' => 'banner_conditions',
    ),
    'classes' => array(),
    'wrappers' => array(
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'hide_page_title' => '0',
    'page_option_title' => '',
  );
  $export['node|conditions|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|conditions|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'conditions';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'title',
        1 => 'field_conditions_main_blurb',
        2 => 'node_link',
      ),
    ),
    'fields' => array(
      'title' => 'central',
      'field_conditions_main_blurb' => 'central',
      'node_link' => 'central',
    ),
    'classes' => array(),
    'wrappers' => array(
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|conditions|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|homepage_featured_content|widget';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'homepage_featured_content';
  $ds_layout->view_mode = 'widget';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_hfc_image',
        2 => 'group_hover',
        3 => 'field_hfc_hover_title',
        4 => 'field_hfc_hover_text',
        5 => 'field_hfc_link',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_hfc_image' => 'ds_content',
      'group_hover' => 'ds_content',
      'field_hfc_hover_title' => 'ds_content',
      'field_hfc_hover_text' => 'ds_content',
      'field_hfc_link' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|homepage_featured_content|widget'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|homepage_slide|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'homepage_slide';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'field_slide_image',
      ),
    ),
    'fields' => array(
      'field_slide_image' => 'central',
    ),
    'classes' => array(),
    'wrappers' => array(
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|homepage_slide|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|page|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'page';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'title',
        1 => 'body',
      ),
    ),
    'fields' => array(
      'title' => 'central',
      'body' => 'central',
    ),
    'classes' => array(),
    'wrappers' => array(
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|page|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|product|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'product';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'bootstrap_5_7';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'title_clone_',
        3 => 'beauty_review_data_clone_',
        4 => 'group_dt_clone',
        5 => 'write_a_review_url_clone_',
        8 => 'subtitle_clone_',
        9 => 'subtitle_information_clone_',
        11 => 'product_slideshow',
      ),
      'right' => array(
        1 => 'field_amcal_',
        2 => 'field_chemist_warehouse',
        6 => 'field_product_information',
        7 => 'field_product_directions',
        10 => 'field_product_ingredients',
        12 => 'field_product_research',
        13 => 'group_onlineresellers',
        14 => 'field_clinical_study',
        15 => 'title',
        16 => 'group_buyonline_group',
        17 => 'field_product_subtitle',
        18 => 'field_beauty_review_data',
        19 => 'where_to_buy_button',
        20 => 'group_dt',
        21 => 'field_write_a_review_url',
        22 => 'field_subtitle_information',
        23 => 'group_buttons',
        24 => 'group_info',
        26 => 'group_information',
        27 => 'group_directions',
        28 => 'group_ingredients',
        29 => 'group_research',
      ),
      'related' => array(
        25 => 'field_product_related_product',
      ),
    ),
    'fields' => array(
      'title_clone_' => 'left',
      'field_amcal_' => 'right',
      'field_chemist_warehouse' => 'right',
      'beauty_review_data_clone_' => 'left',
      'group_dt_clone' => 'left',
      'write_a_review_url_clone_' => 'left',
      'field_product_information' => 'right',
      'field_product_directions' => 'right',
      'subtitle_clone_' => 'left',
      'subtitle_information_clone_' => 'left',
      'field_product_ingredients' => 'right',
      'product_slideshow' => 'left',
      'field_product_research' => 'right',
      'group_onlineresellers' => 'right',
      'field_clinical_study' => 'right',
      'title' => 'right',
      'group_buyonline_group' => 'right',
      'field_product_subtitle' => 'right',
      'field_beauty_review_data' => 'right',
      'where_to_buy_button' => 'right',
      'group_dt' => 'right',
      'field_write_a_review_url' => 'right',
      'field_subtitle_information' => 'right',
      'group_buttons' => 'right',
      'group_info' => 'right',
      'field_product_related_product' => 'related',
      'group_information' => 'right',
      'group_directions' => 'right',
      'group_ingredients' => 'right',
      'group_research' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
    'hide_page_title' => '1',
    'page_option_title' => '',
  );
  $export['node|product|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|product|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'product';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_product_image',
        1 => 'title',
        2 => 'node_link',
      ),
    ),
    'fields' => array(
      'field_product_image' => 'ds_content',
      'title' => 'ds_content',
      'node_link' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|product|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|product|widget';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'product';
  $ds_layout->view_mode = 'widget';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'field_product_image',
        1 => 'node_link',
      ),
    ),
    'fields' => array(
      'field_product_image' => 'central',
      'node_link' => 'central',
    ),
    'classes' => array(),
    'wrappers' => array(
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|product|widget'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|review|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'review';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'title',
        1 => 'field_review_product',
        2 => 'field_review_body',
        3 => 'field_review_city',
        4 => 'field_review_country',
      ),
    ),
    'fields' => array(
      'title' => 'central',
      'field_review_product' => 'central',
      'field_review_body' => 'central',
      'field_review_city' => 'central',
      'field_review_country' => 'central',
    ),
    'classes' => array(),
    'wrappers' => array(
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|review|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|review|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'review';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_review_body',
        1 => 'node_link',
      ),
    ),
    'fields' => array(
      'field_review_body' => 'ds_content',
      'node_link' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|review|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|review|widget';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'review';
  $ds_layout->view_mode = 'widget';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_transform_container',
        1 => 'group_default',
        2 => 'title',
        3 => 'group_hover',
        4 => 'field_review_city',
        5 => 'field_review_country',
        6 => 'field_review_body',
      ),
    ),
    'fields' => array(
      'group_transform_container' => 'ds_content',
      'group_default' => 'ds_content',
      'title' => 'ds_content',
      'group_hover' => 'ds_content',
      'field_review_city' => 'ds_content',
      'field_review_country' => 'ds_content',
      'field_review_body' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|review|widget'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|webform|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'webform';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'title',
        1 => 'field_webform_body',
        2 => 'comments',
        3 => 'webform',
      ),
    ),
    'fields' => array(
      'title' => 'central',
      'field_webform_body' => 'central',
      'comments' => 'central',
      'webform' => 'central',
    ),
    'classes' => array(),
    'wrappers' => array(
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
    'hide_page_title' => '0',
    'page_option_title' => '',
  );
  $export['node|webform|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|webform|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'webform';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'field_webform_body',
        1 => 'webform',
      ),
    ),
    'fields' => array(
      'field_webform_body' => 'central',
      'webform' => 'central',
    ),
    'classes' => array(),
    'wrappers' => array(
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|webform|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|webform|widget';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'webform';
  $ds_layout->view_mode = 'widget';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'group_accordion',
        1 => 'title',
        2 => 'field_webform_body',
        3 => 'webform',
        4 => 'group_accordion1',
        5 => 'group_closed',
      ),
    ),
    'fields' => array(
      'group_accordion' => 'central',
      'title' => 'central',
      'field_webform_body' => 'central',
      'webform' => 'central',
      'group_accordion1' => 'central',
      'group_closed' => 'central',
    ),
    'classes' => array(),
    'wrappers' => array(
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|webform|widget'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'taxonomy_term|conditions|default';
  $ds_layout->entity_type = 'taxonomy_term';
  $ds_layout->bundle = 'conditions';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['taxonomy_term|conditions|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'taxonomy_term|conditions|full';
  $ds_layout->entity_type = 'taxonomy_term';
  $ds_layout->bundle = 'conditions';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'title',
        1 => 'description',
        2 => 'more_link',
      ),
    ),
    'fields' => array(
      'title' => 'central',
      'description' => 'central',
      'more_link' => 'central',
    ),
    'classes' => array(),
    'wrappers' => array(
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'hide_page_title' => '1',
    'page_option_title' => '',
  );
  $export['taxonomy_term|conditions|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'taxonomy_term|conditions|widget';
  $ds_layout->entity_type = 'taxonomy_term';
  $ds_layout->bundle = 'conditions';
  $ds_layout->view_mode = 'widget';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_condition_image',
      ),
      'right' => array(
        1 => 'description',
        2 => 'more_link',
      ),
    ),
    'fields' => array(
      'field_condition_image' => 'left',
      'description' => 'right',
      'more_link' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['taxonomy_term|conditions|widget'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'taxonomy_term|product_category|default';
  $ds_layout->entity_type = 'taxonomy_term';
  $ds_layout->bundle = 'product_category';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['taxonomy_term|product_category|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'taxonomy_term|product_category|full';
  $ds_layout->entity_type = 'taxonomy_term';
  $ds_layout->bundle = 'product_category';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'description',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'description' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'hide_page_title' => '0',
    'page_option_title' => '',
  );
  $export['taxonomy_term|product_category|full'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function flexitol_content_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'widget';
  $ds_view_mode->label = 'Widget';
  $ds_view_mode->entities = array(
    'node' => 'node',
    'taxonomy_term' => 'taxonomy_term',
  );
  $export['widget'] = $ds_view_mode;

  return $export;
}
