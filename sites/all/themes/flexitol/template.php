<?php

/**
 * @file
 * template.php

function flexitol_preprocess_taxonomy_term(&$vars) {
  if ($vars['vocabulary_machine_name'] == 'conditions') {
    if ($vars['view_mode'] == 'widget') {
     $vars['content']['description']['#prefix'] .= '<div class="condition-fixed-title">' . t("CONDITIONS") .'</div>';
    }
  }
}

/**
 * Override or insert variables into the html template.
 */


function flexitol_preprocess_html(&$vars) {
   $vars['background_image'] = base_path() . drupal_get_path('theme', 'flexitol') . "/images" . "/default_background.jpg";

  // Set background of product and other pages
  if (arg(0) == 'node' && is_numeric(arg(1))) {
    $node = node_load(arg(1));
    // If product set background
    if (isset($node->field_page_background_image['und'][0]['uri'])) {
      $uri = $node->field_page_background_image['und'][0]['uri'];
      $wrapper = file_stream_wrapper_get_instance_by_uri($uri);
      if ($wrapper instanceof DrupalLocalStreamWrapper) {
        $path = $wrapper->getDirectoryPath() . '/' . file_uri_target($uri);
      }
      $vars['background_image'] = base_path() . $path;
    }
    if ($node->type == 'product') {
      if (isset($node->field_product_category['und'][0]['target_id'])) {
        $term_id = $node->field_product_category['und'][0]['target_id'];
        $term = taxonomy_term_load($term_id);
        if (isset($term->field_category_image['und'][0]['uri'])) {
          $uri = $term->field_category_image['und'][0]['uri'];
          $wrapper = file_stream_wrapper_get_instance_by_uri($uri);
          if ($wrapper instanceof DrupalLocalStreamWrapper) {
            $path = $wrapper->getDirectoryPath() . '/' . file_uri_target($uri);
          }
          $vars['background_image'] = base_path() . $path;
        }

      }
    }
  }
  // Set background of product category page
  if (arg(0) == 'taxonomy' && arg(1) == 'term' && is_numeric(arg(2))) {
    $term = taxonomy_term_load(arg(2));
    // If term of type category set background
    if ($term->vocabulary_machine_name == 'product_category') {
      if (isset($term->field_category_image['und'][0]['uri'])) {
        $uri = $term->field_category_image['und'][0]['uri'];
        $wrapper = file_stream_wrapper_get_instance_by_uri($uri);
        if ($wrapper instanceof DrupalLocalStreamWrapper) {
          $path = $wrapper->getDirectoryPath() . '/' . file_uri_target($uri);
        }
        $vars['background_image'] = base_path() . $path;
      }
      $vars['classes_array'][] = 'productcat';
    }
  }

  // custom background image for contact pages
  else if ( in_array( $vars['classes_array'][6], array('page-node-221', 'page-node-185', 'page-node-36') ) ) {
      // Place url of img inside quotes below
    $vars['background_image'] = "/sites/all/themes/flexitol/images/dt-contact-us-background.jpeg";
  }

// Set background of view pages
  if(function_exists('views_get_page_view') && views_get_page_view()){
      $view = views_get_page_view();
   
      //Background for Healthcare Professionals
      if (isset($view) && $view->name == 'healthcare_professional_page') {
        // Place url of img inside quotes below
      $vars['background_image'] = "/sites/all/themes/flexitol/images/healthcare_bg.jpg";

      }
  //Background for 'Review' page
      else if(isset($view) && $view->name == 'review'){
       // Place url of img inside quotes below
      $vars['background_image'] = "/sites/all/themes/flexitol/images/testimonials_bg.jpg";

    }
  //Background for Special offers and events
    else if(isset($view) && $view->name == 'special_offers'){
       // Place url of img inside quotes below
      $vars['background_image'] = "/sites/all/themes/flexitol/images/special_offer_bg.jpg";
    }

  }



     if (drupal_is_front_page()) {
    $vars['background_image'] = NULL;
  }

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
    //ie if($node ->type =='conditions'){}
    if ($node->type == 'conditions') {
	  $vars['content_column_class'] = 'col-sm-9';
      $vars['sidebar_first_class'] = 'col-sm-3';
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
	
	if ($term->vocabulary_machine_name == 'product_category' && $term->name == 'Hand care' ) {
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
        $query = new EntityFieldQuery();
        $query->entityCondition('entity_type', 'node')
          ->entityCondition('bundle', 'beautyheaven_review')
          ->fieldCondition('field_product', 'value', arg(1))
          ->addMetaData('account', user_load(1));
        $result = $query->execute();

        $rate_total = 0;
        $rate_count = 0;
        if (isset($result['node'])) {
          $nids = array_keys($result['node']);
          $review_nodes = entity_load('node', $nids);
          foreach ($review_nodes as $review_node) {
            $rate = $review_node->field_rate[LANGUAGE_NONE][0]['value'];
            $rate_total += $rate;
            $rate_count++;
          }
        }

        $aggregate_rating = empty($rate_count) ? '' : ',
              "aggregateRating": {
                "@type": "AggregateRating",
                "ratingValue": "' . round($rate_total / $rate_count) . '",
                "ratingCount": "' . $rate_count . '"
              }';

        $google_product = '
          <script type="application/ld+json">
            {
              "@context": "http://schema.org",
              "mainEntityOfPage": "' . url("node/{$node->nid}", array('absolute' => TRUE)) . '",
              "@type": "Product",
              "name": "' . $node->title . '",
              "description": "' . trim(preg_replace('/\s+/', ' ', strip_tags($node->field_product_information['und'][0]['value']))) . '",
              "image": "' . image_style_url('width_250', $node->field_product_image['und'][0]['uri']) . '",
              "brand": {
                "@type": "Thing",
                "name": "Dermal Therapy"
              }' . $aggregate_rating . '
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

/**
 * Implements template_preprocess_block().
 
Adds col-sm-6 to products page condition blocks and related products blocks
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
  if (current_path() == 'taxonomy/term/28') {
    $variables['rows'] .= '<div class="views-row col-sm-12"><a target="_blank" href="https://littlebodies.com.au"><img src="/sites/all/themes/flexitol/images/little_bodies_button.png"/></a></div>';
  }
}
