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
  $field_groups[''] = $field_group;

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
  $field_groups[''] = $field_group;

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
      0 => 'group_onlineresellers',
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
  $field_groups[''] = $field_group;

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
      19 => 'field_terry_white_chemmart',
      20 => 'field_discount_drug_stores',
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
  $field_groups[''] = $field_group;

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
    'weight' => '56',
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
  $field_groups[''] = $field_group;

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
  $field_groups[''] = $field_group;

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
  $field_groups[''] = $field_group;

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
    'weight' => '55',
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
  $field_groups[''] = $field_group;

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
  $field_groups[''] = $field_group;

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
    'weight' => '57',
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
  $field_groups[''] = $field_group;

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
  $field_groups[''] = $field_group;

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
    'weight' => '58',
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
  $field_groups[''] = $field_group;

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
      2 => 'group_related',
      3 => 'group_obsolete',
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
  $field_groups[''] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Beauty review link');
  t('Beauty review link clone');
  t('Buy online now');
  t('Directions');
  t('Information');
  t('Ingredients');
  t('Online resellers');
  t('Research');
  t('Vertical tabs');

  return $field_groups;
}
