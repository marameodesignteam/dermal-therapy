<?php

/**
 * Override or insert variables into the html template.
 */


function flexitol_preprocess_html(&$vars) {
  $vars['background_image'] = base_path() . drupal_get_path('theme', 'flexitol') . "/images" . "/default_background.jpg";

  // Add to Dermal Therapy Australia
  global $_domain;
  if ($_domain['domain_id'] == 1) {
    // Setup IE meta tag to force IE rendering mode
    $meta_google_site_verification = [
      '#type' => 'html_tag',
      '#tag' => 'meta',
      '#attributes' => [
        'name' => 'google-site-verification',
        'content' =>  'Tre2nYB-UOA_PC1q2k4m6aiOBhgGQlSSkD2d6l92ciQ',
      ]
    ];
    drupal_add_html_head($meta_google_site_verification, 'meta_google_site_verification');
    // <meta name="google-site-verification" content="Tre2nYB-UOA_PC1q2k4m6aiOBhgGQlSSkD2d6l92ciQ" />
  }

  // Set background of product and other pages
  if (arg(0) == 'node' && is_numeric(arg(1))) {
    // Setup IE meta tag to force IE rendering mode
    $product_review = [
      '#type' => 'markup',
      '#markup' => "
<script>
    window.__productReviewSettings = {
        brandId: '3c70d8a7-f94e-4e4a-9789-fc10a3106cb8'
    };
</script>
<script src=\"https://cdn.productreview.com.au/assets/widgets/loader.js\" async></script>
",
    ];

    // Add header meta tag for IE to head
    drupal_add_html_head($product_review, 'product_review');
  }
  // Set background of product category page
  if (arg(0) == 'taxonomy' && arg(1) == 'term' && is_numeric(arg(2))) {
    $term = taxonomy_term_load(arg(2));
    // If term of type category set background
    if ($term->vocabulary_machine_name == 'product_category') {
      $vars['classes_array'][] = 'productcat';
    }
  }
}

/**
 * Add product review
 *
 * @param $vars
 */
function flexitol_preprocess_views_view__leave_a_testimonial(&$vars) {
  if (arg(0) == 'node' && is_numeric(arg(1))) {
    $node = node_load(arg(1));
    $categ = $node->field_product_category['und'][0]['target_id'];
  }
  $vars['prefix'] = _product_review($categ, 'product-review');
}

function _product_review($categ, $wrapper_class) {
  $identifiers = [
    9 => '90cc9147-c35a-4183-bf7a-2579c553c8b8', // FOOT CARE
    14 => 'd08068ab-88f8-4124-ba4c-b198e23c7465', // LIP CARE
    19 => 'fe658376-e2db-4c78-bc04-f24d0fe7e44f', // ECZEMA PRONE SKIN CARE
    20 => 'fe658376-e2db-4c78-bc04-f24d0fe7e44f', // ITCHY SKIN CARE
    21 => 'fe658376-e2db-4c78-bc04-f24d0fe7e44f', // VERY DRY SKIN CARE
    22 => 'fe658376-e2db-4c78-bc04-f24d0fe7e44f', // SENSITIVE SKIN CARE
    23 => 'fe658376-e2db-4c78-bc04-f24d0fe7e44f', // PERSONAL CARE
    10 => 'b1a40f30-4372-4788-bc38-da37413ff560', // HAND CARE
    28 => '46923d38-dfcc-3924-b544-5ae6720bb473', // CHILDREN SKIN CARE
    35 => '7c8f468c-ef56-41cd-a2e6-927619a3a5e8', // SCALP CARE
  ];
  $markups = [
    9 => '<a target="_blank" href="https://www.productreview.com.au/listings/dermal-therapy-australia-foot-care-range" rel="noopener">
<img
width="160"
src="https://api.productreview.com.au/api/services/rating-badge/v2/au/90cc9147-c35a-4183-bf7a-2579c553c8b8/from-internal-entry-id?resolution=hd&theme=light&width=160"
alt="Dermal Therapy Australia Foot Care Range"
>
</a>', // FOOT CARE
    14 => '<a target="_blank" href="https://www.productreview.com.au/listings/dermal-therapy-australia-lip-care-range" rel="noopener">
<img
width="160"
src="https://api.productreview.com.au/api/services/rating-badge/v2/au/d08068ab-88f8-4124-ba4c-b198e23c7465/from-internal-entry-id?resolution=hd&theme=light&width=160"
alt="Dermal Therapy Australia Lip Care Range"
>
</a>', // LIP CARE
    19 => '<a target="_blank" href="https://www.productreview.com.au/listings/dermal-therapy-australia-body-care-range" rel="noopener">
<img
width="160"
src="https://api.productreview.com.au/api/services/rating-badge/v2/au/fe658376-e2db-4c78-bc04-f24d0fe7e44f/from-internal-entry-id?resolution=hd&theme=light&width=160"
alt="Dermal Therapy Australia Body Care Range"
>
</a>', // ECZEMA PRONE SKIN CARE
    20 => '<a target="_blank" href="https://www.productreview.com.au/listings/dermal-therapy-australia-body-care-range" rel="noopener">
<img
width="160"
src="https://api.productreview.com.au/api/services/rating-badge/v2/au/fe658376-e2db-4c78-bc04-f24d0fe7e44f/from-internal-entry-id?resolution=hd&theme=light&width=160"
alt="Dermal Therapy Australia Body Care Range"
>
</a>', // ITCHY SKIN CARE
    21 => '<a target="_blank" href="https://www.productreview.com.au/listings/dermal-therapy-australia-body-care-range" rel="noopener">
<img
width="160"
src="https://api.productreview.com.au/api/services/rating-badge/v2/au/fe658376-e2db-4c78-bc04-f24d0fe7e44f/from-internal-entry-id?resolution=hd&theme=light&width=160"
alt="Dermal Therapy Australia Body Care Range"
>
</a>', // VERY DRY SKIN CARE
    22 => '<a target="_blank" href="https://www.productreview.com.au/listings/dermal-therapy-australia-body-care-range" rel="noopener">
<img
width="160"
src="https://api.productreview.com.au/api/services/rating-badge/v2/au/fe658376-e2db-4c78-bc04-f24d0fe7e44f/from-internal-entry-id?resolution=hd&theme=light&width=160"
alt="Dermal Therapy Australia Body Care Range"
>
</a>', // SENSITIVE SKIN CARE
    23 => '<a target="_blank" href="https://www.productreview.com.au/listings/dermal-therapy-australia-body-care-range" rel="noopener">
<img
width="160"
src="https://api.productreview.com.au/api/services/rating-badge/v2/au/fe658376-e2db-4c78-bc04-f24d0fe7e44f/from-internal-entry-id?resolution=hd&theme=light&width=160"
alt="Dermal Therapy Australia Body Care Range"
>
</a>', // PERSONAL CARE
    10 => '<a target="_blank" href="https://www.productreview.com.au/listings/dermal-therapy-australia-hand-care-range" rel="noopener">
<img
width="160"
src="https://api.productreview.com.au/api/services/rating-badge/v2/au/b1a40f30-4372-4788-bc38-da37413ff560/from-internal-entry-id?resolution=hd&theme=light&width=160"
alt="Dermal Therapy Australia Hand Care Range"
>
</a>', // HAND CARE
    28 => '<a target="_blank" href="https://www.productreview.com.au/listings/little-bodies" rel="noopener">
<img
width="160"
src="https://api.productreview.com.au/api/services/rating-badge/v2/au/46923d38-dfcc-3924-b544-5ae6720bb473/from-internal-entry-id?resolution=hd&theme=light&width=160"
alt="Dermal Therapy Australia Children\'s Skin Care"
>
</a>', // CHILDREN SKIN CARE
    35 => '<a target="_blank" href="https://www.productreview.com.au/listings/dermal-therapy-australia-scalp-care-range" rel="noopener">
<img
width="160"
src="https://api.productreview.com.au/api/services/rating-badge/v2/au/7c8f468c-ef56-41cd-a2e6-927619a3a5e8/from-internal-entry-id?resolution=hd&theme=light&width=160"
alt="Dermal Therapy Australia Scalp Care"
>
</a>', // CHILDREN SKIN CARE
  ];
  if (!empty($categ) && !empty($identifiers[$categ])) {
    return "
        <div class='{$wrapper_class}'>
    <script>
        window.__productReviewCallbackQueue = window.__productReviewCallbackQueue || [];
        window.__productReviewCallbackQueue.push(function(ProductReview) {
            ProductReview.use('seo-listing-aggregated-rating', {
                'identificationDetails': {
                  'type': 'single',
                  'strategy': 'from-internal-entry-id',
                  'identifier': '{$identifiers[$categ]}'
                }
            });
        });
    </script>

      {$markups[$categ]}
    </div>";
  }

  return '';
}

/**
 * Override or insert variables into the page template.
 */

function flexitol_preprocess_page(&$vars) {
  $vars['background_image'] = base_path() . drupal_get_path('theme', 'flexitol') . "/images" . "/default_background.jpg";
  $vars['content_container_class'] = "";
  // Add information about the number of sidebars.
  if (!empty($variables['page']['sidebar_first']) && !empty($variables['page']['sidebar_second'])) {
    $vars['content_column_class'] = 'col-sm-6';
  }
  elseif (!empty($variables['page']['sidebar_first']) || !empty($variables['page']['sidebar_second'])) {
    $vars['content_column_class'] = 'col-sm-9';
  }
  else {
    $vars['content_column_class'] = 'col-sm-12';
  }
  $vars['sidebar_class'] = "col-sm-3";

  //set variables for specific nodes here:
  if (arg(0) == 'node' && is_numeric(arg(1))) {
    $node = node_load(arg(1));

    if ($node->type == 'conditions') {
      $vars['content_column_class'] = 'col-sm-9';
      $vars['sidebar_first_class'] = 'col-sm-3';
    }

    if ($node->type == 'product') {
      $variables['#attached']['js'][] = [
        'type' => 'file',
        'data' => '/sites/all/themes/flexitol/js/jquery.fitvids.js',
      ];
    }
  }
  // Old background function - references to background removed.
  //set variables for specific taxonomy taxonomy terms
  if (arg(0) == 'taxonomy' && arg(1) == 'term' && is_numeric(arg(2))) {
    $term = taxonomy_term_load(arg(2));
    // sets container classnames etc
    if ($term->vocabulary_machine_name == 'product_category') {
      $vars['content_container_class'] = 'product-category-container';
      $vars['content_column_class'] = 'col-sm-9';
      $vars['sidebar_first_class'] = 'col-sm-3';
    }

    if ($term->vocabulary_machine_name == 'product_category' && $term->name == 'Hand care') {
      $vars['content_column_class'] = 'col-sm-8';
      $vars['sidebar_first_class'] = 'col-sm-4';
    }

    if ($term->vocabulary_machine_name == 'conditions') {
      $vars['content_container_class'] = 'conditions-container';
      $vars['content_column_class'] = 'col-sm-9';
      $vars['sidebar_first_class'] = 'col-sm-3';
    }
  }

  if (arg(0) == 'node' && arg(1) && is_numeric(arg(1)) && !arg(2)) {
    $node = node_load(arg(1));
    if ($node->type == 'product') {
      $current = domain_get_domain();
      if ($current['machine_name'] == 'australia_dt') {
        $rate_value = $node->field_rating_value['und'][0]['value'];
        $rate_count = $node->field_rating_count['und'][0]['value'];
        if (!empty($rate_count)) {
          $google_product = '
          <script type="application/ld+json">
            {
              "@context": "http://schema.org",
              "mainEntityOfPage": "' . url("node/{$node->nid}", ['absolute' => TRUE]) . '",
              "@type": "Product",
              "name": "' . $node->title . '",
              "image": "' . image_style_url('width_250', $node->field_product_image['und'][0]['uri']) . '",
              "brand": {
                "@type": "Thing",
                "name": "Dermal Therapy"
              },
              "aggregateRating": {
                "@type": "AggregateRating",
                "ratingValue": "' . $rate_value . '",
                "ratingCount": "' . $rate_count . '"
              }
            }
          </script>';
          $element = [
            '#type' => 'markup',
            '#markup' => $google_product,
          ];

          drupal_add_html_head($element, 'jquery-tmpl');
        }
      }
    }
  }
}

/**
 * Implements template_preprocess_block().
 *
 * Adds col-sm-6 to products page condition blocks and related products blocks
 */
function flexitol_preprocess_block(&$vars) {
  if ($vars['block']->module == 'views') {
    $view = $vars['elements']['#views_contextual_links_info']['views_ui']['view'];
    $display_id = $vars['elements']['#views_contextual_links_info']['views_ui']['view_display_id'];
    if (($view->name == "products_related_conditions" or $view->name == "related_products") and $display_id == "block") {
      $vars['classes_array'][] = "col-sm-6";
    }
  }
}

/**
 * Implements template_preprocess_field().
 */
function flexitol_preprocess_field(&$vars) {
  if ($vars['element']['#field_name'] == "field_hfc_link") {
  }
}

/**
 * Implements template_preprocess_HOOK().
 */
function flexitol_preprocess_views_view__taxonomy_term_clone(&$variables) {
  $col = "lg-4";

  if (current_path() == 'taxonomy/term/28') {
    $variables['header'] .= _product_review(28, 'views-row col-' . $col);
  }
  elseif (current_path() == 'taxonomy/term/34') {
    $variables['row'] .= '<div class="views-row col-sm-6"><a target="_blank" href="https://littlebodies.com"><img alt="Little Bodies" src="/sites/all/themes/flexitol/images/little_bodies_com_button.png"/></a></div>';
  }
  elseif (current_path() == 'taxonomy/term/9') {
    $variables['header'] .= _product_review(9, 'views-row col-' . $col);
  }
  elseif (current_path() == 'taxonomy/term/10') {
    $variables['header'] .= _product_review(10, 'views-row col-' . $col);
  }
  elseif (current_path() == 'taxonomy/term/14') {
    $variables['header'] .= _product_review(14, 'views-row col-' . $col);
  }
  elseif (current_path() == 'taxonomy/term/19') {
    $variables['header'] .= _product_review(19, 'views-row col-' . $col);
  }
  elseif (current_path() == 'taxonomy/term/20') {
    $variables['header'] .= _product_review(20, 'views-row col-' . $col);
  }
  elseif (current_path() == 'taxonomy/term/101') {
    $variables['header'] .= _product_review(20, 'views-row col-' . $col);
  }
  elseif (current_path() == 'taxonomy/term/21') {
    $variables['header'] .= _product_review(21, 'views-row col-' . $col);
  }
  elseif (current_path() == 'taxonomy/term/22') {
    $variables['header'] .= _product_review(22, 'views-row col-' . $col);
  }
  elseif (current_path() == 'taxonomy/term/23') {
    $variables['header'] .= _product_review(23, 'views-row col-' . $col);
  }
  elseif (current_path() == 'taxonomy/term/35') {
    $variables['header'] .= _product_review(35, 'views-row col-' . $col);
  }
}
