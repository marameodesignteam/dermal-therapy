<?php
/**
 * @file
 * flexitol_content.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function flexitol_content_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_accordion1|node|webform|teaser';
  $field_group->group_name = 'group_accordion1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'webform';
  $field_group->mode = 'teaser';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Leave a Testimonial',
    'weight' => '1',
    'children' => array(
      0 => 'field_webform_body',
      1 => 'webform',
      2 => 'group_accordion',
    ),
    'format_type' => 'bootstrap_fieldgroup_accordion_item',
    'format_settings' => array(
      'label' => 'Leave a Testimonial',
      'instance_settings' => array(
        'classes' => 'group-accordion1 field-group-bootstrap_fieldgroup_accordion_item',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_accordion1|node|webform|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_accordion1|node|webform|widget';
  $field_group->group_name = 'group_accordion1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'webform';
  $field_group->mode = 'widget';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Leave a testimonial',
    'weight' => '4',
    'children' => array(
      0 => 'field_webform_body',
      1 => 'webform',
    ),
    'format_type' => 'bootstrap_fieldgroup_accordion_item',
    'format_settings' => array(
      'label' => 'Leave a testimonial',
      'instance_settings' => array(
        'classes' => 'group-accordion1 field-group-bootstrap_fieldgroup_accordion_item',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_accordion1|node|webform|widget'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_accordion|node|webform|teaser';
  $field_group->group_name = 'group_accordion';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'webform';
  $field_group->mode = 'teaser';
  $field_group->parent_name = 'group_accordion1';
  $field_group->data = array(
    'label' => 'Group',
    'weight' => '0',
    'children' => array(
      0 => 'group_accordion1',
    ),
    'format_type' => 'bootstrap_fieldgroup_accordion',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-accordion field-group-bootstrap_fieldgroup_accordion',
        'id' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_accordion|node|webform|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_accordion|node|webform|widget';
  $field_group->group_name = 'group_accordion';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'webform';
  $field_group->mode = 'widget';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Group',
    'weight' => '0',
    'children' => array(
      0 => 'group_accordion1',
      1 => 'group_closed',
    ),
    'format_type' => 'bootstrap_fieldgroup_accordion',
    'format_settings' => array(
      'label' => 'Group',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-accordion field-group-bootstrap_fieldgroup_accordion',
      ),
    ),
  );
  $field_groups['group_accordion|node|webform|widget'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_beauty_review_tab|node|product|form';
  $field_group->group_name = 'group_beauty_review_tab';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_vertical';
  $field_group->data = array(
    'label' => 'Beauty review',
    'weight' => '43',
    'children' => array(
      0 => 'field_beauty_review_link',
      1 => 'field_write_a_review_url',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-beauty-review-tab field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_beauty_review_tab|node|product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bt_link_clone|node|product|full';
  $field_group->group_name = 'group_bt_link_clone';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_dt_clone';
  $field_group->data = array(
    'label' => 'Beauty review link clone',
    'weight' => '58',
    'children' => array(
      0 => 'beauty_review_data_clone_',
    ),
    'format_type' => 'link',
    'format_settings' => array(
      'label' => 'Beauty review link clone',
      'instance_settings' => array(
        'link_to' => 'field_beauty_review_link',
        'custom_url' => '',
        'custom_url_normalize' => 0,
        'target' => '_blank',
        'classes' => 'group-bt-link-clone field-group-div',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_bt_link_clone|node|product|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bt_link|node|product|full';
  $field_group->group_name = 'group_bt_link';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_dt';
  $field_group->data = array(
    'label' => 'Beauty review link',
    'weight' => '8',
    'children' => array(
      0 => 'field_beauty_review_data',
    ),
    'format_type' => 'link',
    'format_settings' => array(
      'label' => 'Beauty review link',
      'instance_settings' => array(
        'link_to' => 'field_beauty_review_link',
        'custom_url' => '',
        'custom_url_normalize' => 0,
        'target' => '_blank',
        'classes' => 'group-bt-link field-group-link',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_bt_link|node|product|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_buttons|node|product|full';
  $field_group->group_name = 'group_buttons';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '9',
    'children' => array(
      0 => 'where_to_buy_button',
      1 => 'group_onlineresellers',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-buttons field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_buttons|node|product|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_buylinks|node|product|form';
  $field_group->group_name = 'group_buylinks';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_vertical';
  $field_group->data = array(
    'label' => 'Buy Online Links',
    'weight' => '45',
    'children' => array(
      0 => 'field__shopee',
      1 => 'field_amcal_',
      2 => 'field_bargain_chemist',
      3 => 'field_chemist_warehouse',
      4 => 'field_chempro',
      5 => 'field_coles',
      6 => 'field_lazada',
      7 => 'field_pharmacy_direct',
      8 => 'field_priceline',
      9 => 'field_watsons',
      10 => 'field_woolworths',
      11 => 'field_good_price',
      12 => 'field_pharmacy_4_less',
      13 => 'field_catch',
      14 => 'field_pharmacy_online',
      15 => 'field_guardian',
      16 => 'field_life_pharmacy',
      17 => 'field_amazon',
      18 => 'field_chemist_discount_centre',
      19 => 'field_discount_drug_stores',
      20 => 'field_terry_white_chemmart',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-buylinks field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_buylinks|node|product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_buyonline_group|node|product|full';
  $field_group->group_name = 'group_buyonline_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_onlineresellers';
  $field_group->data = array(
    'label' => 'Buy online now',
    'weight' => '55',
    'children' => array(
      0 => 'field__shopee',
      1 => 'field_amcal_',
      2 => 'field_bargain_chemist',
      3 => 'field_chemist_warehouse',
      4 => 'field_chempro',
      5 => 'field_coles',
      6 => 'field_lazada',
      7 => 'field_pharmacy_direct',
      8 => 'field_priceline',
      9 => 'field_watsons',
      10 => 'field_woolworths',
      11 => 'field_good_price',
      12 => 'field_pharmacy_4_less',
      13 => 'field_catch',
      14 => 'field_pharmacy_online',
      15 => 'field_guardian',
      16 => 'field_life_pharmacy',
      17 => 'field_amazon',
      18 => 'field_chemist_discount_centre',
      19 => 'field_discount_drug_stores',
      20 => 'field_terry_white_chemmart',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Buy online now',
      'instance_settings' => array(
        'classes' => 'group-buyonline-group field-group-accordion-item',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_buyonline_group|node|product|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_clinical_studies_accordion|field_collection_item|field_clinical_study|default';
  $field_group->group_name = 'group_clinical_studies_accordion';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_clinical_study';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Clinical Studies',
    'weight' => '0',
    'children' => array(
      0 => 'group_clinical_studies_item',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'label' => 'Clinical Studies',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-clinical-studies-accordion field-group-bootstrap_fieldgroup_accordion',
        'description' => '',
        'effect' => 'none',
      ),
    ),
  );
  $field_groups['group_clinical_studies_accordion|field_collection_item|field_clinical_study|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_clinical_studies_item|field_collection_item|field_clinical_study|default';
  $field_group->group_name = 'group_clinical_studies_item';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_clinical_study';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_clinical_studies_accordion';
  $field_group->data = array(
    'label' => 'Clinical Studies',
    'weight' => '1',
    'children' => array(
      0 => 'field_clinical_study_description',
      1 => 'field_clinical_study_images',
      2 => 'field_clinical_study_title',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group-clinical-studies-item field-group-bootstrap_fieldgroup_accordion_item',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_clinical_studies_item|field_collection_item|field_clinical_study|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_default|node|review|widget';
  $field_group->group_name = 'group_default';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'review';
  $field_group->mode = 'widget';
  $field_group->parent_name = 'group_transform_container';
  $field_group->data = array(
    'label' => 'Dafault',
    'weight' => '1',
    'children' => array(
      0 => 'field_review_city',
      1 => 'field_review_country',
      2 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Dafault',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-default field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_default|node|review|widget'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_directions|node|product|full';
  $field_group->group_name = 'group_directions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_info';
  $field_group->data = array(
    'label' => 'Directions',
    'weight' => '17',
    'children' => array(
      0 => 'field_product_directions',
    ),
    'format_type' => 'bootstrap_fieldgroup_accordion_item',
    'format_settings' => array(
      'label' => 'Directions',
      'instance_settings' => array(
        'classes' => 'group-directions field-group-bootstrap_fieldgroup_nav_item',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_directions|node|product|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dt_clone|node|product|full';
  $field_group->group_name = 'group_dt_clone';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '1',
    'children' => array(
      0 => 'write_a_review_url_clone_',
      1 => 'group_bt_link_clone',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-dt-clone field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_dt_clone|node|product|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dt|node|product|full';
  $field_group->group_name = 'group_dt';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '8',
    'children' => array(
      0 => 'field_write_a_review_url',
      1 => 'group_bt_link',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-dt field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_dt|node|product|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_find_stockist|node|product|full';
  $field_group->group_name = 'group_find_stockist';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_onlineresellers';
  $field_group->data = array(
    'label' => 'Where to buy',
    'weight' => '56',
    'children' => array(
      0 => 'stockist_by_product',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group-find-stockist field-group-accordion-item',
      ),
    ),
  );
  $field_groups['group_find_stockist|node|product|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_healthcare_graph_1|node|health_professionals_product|form';
  $field_group->group_name = 'group_healthcare_graph_1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'health_professionals_product';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_healthcare_graphs';
  $field_group->data = array(
    'label' => 'Graph 1',
    'weight' => '7',
    'children' => array(
      0 => 'field_healthcare_graph_1',
      1 => 'field_healthcare_graph_1_notes',
      2 => 'field_healthcare_graph_1_text',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_healthcare_graph_1|node|health_professionals_product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_healthcare_graph_2|node|health_professionals_product|form';
  $field_group->group_name = 'group_healthcare_graph_2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'health_professionals_product';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_healthcare_graphs';
  $field_group->data = array(
    'label' => 'Graph 2',
    'weight' => '8',
    'children' => array(
      0 => 'field_graph_2_notes',
      1 => 'field_healthcare_graph_2',
      2 => 'field_healthcare_graph_2_text',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_healthcare_graph_2|node|health_professionals_product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_healthcare_graphs|node|health_professionals_product|form';
  $field_group->group_name = 'group_healthcare_graphs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'health_professionals_product';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Graphs',
    'weight' => '5',
    'children' => array(
      0 => 'field_health_graph_image_single',
      1 => 'field_healthcare_wysiwyg_editor',
      2 => 'group_healthcare_graph_1',
      3 => 'group_healthcare_graph_2',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_healthcare_graphs|node|health_professionals_product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hover|node|homepage_featured_content|widget';
  $field_group->group_name = 'group_hover';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'homepage_featured_content';
  $field_group->mode = 'widget';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Hover Block',
    'weight' => '3',
    'children' => array(
      0 => 'field_hfc_hover_text',
      1 => 'field_hfc_hover_title',
      2 => 'field_hfc_link',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Hover Block',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-hover field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_hover|node|homepage_featured_content|widget'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hover|node|review|widget';
  $field_group->group_name = 'group_hover';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'review';
  $field_group->mode = 'widget';
  $field_group->parent_name = 'group_transform_container';
  $field_group->data = array(
    'label' => 'Hover Block',
    'weight' => '2',
    'children' => array(
      0 => 'field_review_body',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Hover Block',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-hover field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_hover|node|review|widget'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_information|node|product|full';
  $field_group->group_name = 'group_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_info';
  $field_group->data = array(
    'label' => 'Information',
    'weight' => '16',
    'children' => array(
      0 => 'field_product_information',
    ),
    'format_type' => 'bootstrap_fieldgroup_accordion_item',
    'format_settings' => array(
      'label' => 'Information',
      'instance_settings' => array(
        'classes' => 'group-information field-group-bootstrap_fieldgroup_nav_item ',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_information|node|product|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info|node|product|full';
  $field_group->group_name = 'group_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Information',
    'weight' => '10',
    'children' => array(
      0 => 'group_directions',
      1 => 'group_information',
      2 => 'group_ingredients',
      3 => 'group_research',
    ),
    'format_type' => 'bootstrap_fieldgroup_accordion',
    'format_settings' => array(
      'label' => 'Information',
      'instance_settings' => array(
        'bootstrap_nav_type' => 'pills',
        'bootstrap_stacked' => '0',
        'bootstrap_orientation' => '0',
        'classes' => 'group-info field-group-bootstrap_fieldgroup_nav',
        'id' => '',
        'required_fields' => 1,
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_info|node|product|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ingredients|node|product|full';
  $field_group->group_name = 'group_ingredients';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_info';
  $field_group->data = array(
    'label' => 'Ingredients',
    'weight' => '18',
    'children' => array(
      0 => 'field_product_ingredients',
    ),
    'format_type' => 'bootstrap_fieldgroup_accordion_item',
    'format_settings' => array(
      'label' => 'Ingredients',
      'instance_settings' => array(
        'classes' => 'group-ingredients field-group-bootstrap_fieldgroup_nav_item',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_ingredients|node|product|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_obsolete|node|product|form';
  $field_group->group_name = 'group_obsolete';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_vertical';
  $field_group->data = array(
    'label' => 'Obsolete fields',
    'weight' => '46',
    'children' => array(
      0 => 'field_product_buy_link',
      1 => 'field_product_condition',
      2 => 'field_beauty_review_data',
      3 => 'field_weight',
      4 => 'field_bh_rate',
      5 => 'field_product_review_link',
      6 => 'field_rating_count',
      7 => 'field_rating_value',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-obsolete field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_obsolete|node|product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_onlineresellers|node|product|full';
  $field_group->group_name = 'group_onlineresellers';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_buttons';
  $field_group->data = array(
    'label' => 'Online resellers',
    'weight' => '52',
    'children' => array(
      0 => 'group_buyonline_group',
      1 => 'group_find_stockist',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'label' => 'Online resellers',
      'instance_settings' => array(
        'id' => 'online-resellers',
        'classes' => 'group-onlineresellers field-group-accordion',
        'description' => '',
        'effect' => 'bounceslide',
      ),
    ),
  );
  $field_groups['group_onlineresellers|node|product|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related|node|product|form';
  $field_group->group_name = 'group_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_vertical';
  $field_group->data = array(
    'label' => 'Related Products',
    'weight' => '44',
    'children' => array(
      0 => 'field_product_related_product',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-related field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_related|node|product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_research|node|product|full';
  $field_group->group_name = 'group_research';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_info';
  $field_group->data = array(
    'label' => 'Research',
    'weight' => '19',
    'children' => array(
      0 => 'field_product_research',
      1 => 'field_clinical_study',
    ),
    'format_type' => 'bootstrap_fieldgroup_accordion_item',
    'format_settings' => array(
      'label' => 'Research',
      'instance_settings' => array(
        'classes' => 'group-research field-group-bootstrap_fieldgroup_nav_item',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_research|node|product|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_title|node|product|related_product';
  $field_group->group_name = 'group_title';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'related_product';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Title',
    'weight' => '0',
    'children' => array(
      0 => 'field_product_image',
      1 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Title',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-title field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_title|node|product|related_product'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_transform_container|node|review|widget';
  $field_group->group_name = 'group_transform_container';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'review';
  $field_group->mode = 'widget';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Transform Container',
    'weight' => '0',
    'children' => array(
      0 => 'group_default',
      1 => 'group_hover',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Transform Container',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-transform-container field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_transform_container|node|review|widget'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_vertical|node|product|form';
  $field_group->group_name = 'group_vertical';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Vertical tabs',
    'weight' => '19',
    'children' => array(
      0 => 'group_beauty_review_tab',
      1 => 'group_buylinks',
      2 => 'group_obsolete',
      3 => 'group_related',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-vertical field-group-tabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_vertical|node|product|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Beauty review');
  t('Beauty review link');
  t('Beauty review link clone');
  t('Buy Online Links');
  t('Buy online now');
  t('Clinical Studies');
  t('Dafault');
  t('Directions');
  t('Graph 1');
  t('Graph 2');
  t('Graphs');
  t('Group');
  t('Hover Block');
  t('Information');
  t('Ingredients');
  t('Leave a Testimonial');
  t('Leave a testimonial');
  t('Obsolete fields');
  t('Online resellers');
  t('Related Products');
  t('Research');
  t('Title');
  t('Transform Container');
  t('Vertical tabs');
  t('Where to buy');

  return $field_groups;
}
