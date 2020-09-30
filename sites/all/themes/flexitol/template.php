<?php

/**
 * @file
 * template.php
 *
 * function flexitol_preprocess_taxonomy_term(&$vars) {
 * if ($vars['vocabulary_machine_name'] == 'conditions') {
 * if ($vars['view_mode'] == 'widget') {
 * $vars['content']['description']['#prefix'] .= '<div
 *   class="condition-fixed-title">' . t("CONDITIONS") .'</div>';
 * }
 * }
 * }
 *
 * /**
 * Override or insert variables into the html template.
 */


function flexitol_preprocess_html(&$vars)
{
    $vars['background_image'] = base_path() . drupal_get_path('theme', 'flexitol') . "/images" . "/default_background.jpg";

    // Set background of product and other pages
    if (arg(0) == 'node' && is_numeric(arg(1))) {
        $node = node_load(arg(1));
        // If product set background
        // if (isset($node->field_page_background_image['und'][0]['uri'])) {
        //     $uri = $node->field_page_background_image['und'][0]['uri'];
        //     $wrapper = file_stream_wrapper_get_instance_by_uri($uri);
        //     if ($wrapper instanceof DrupalLocalStreamWrapper) {
        //         $path = $wrapper->getDirectoryPath() . '/' . file_uri_target($uri);
        //     }
        //     $vars['background_image'] = base_path() . $path;
        // }
        // if ($node->type == 'product') {
        //     if (isset($node->field_product_category['und'][0]['target_id'])) {
        //         $term_id = $node->field_product_category['und'][0]['target_id'];
        //         $term = taxonomy_term_load($term_id);
        //         if (isset($term->field_category_image['und'][0]['uri'])) {
        //             $uri = $term->field_category_image['und'][0]['uri'];
        //             $wrapper = file_stream_wrapper_get_instance_by_uri($uri);
        //             if ($wrapper instanceof DrupalLocalStreamWrapper) {
        //                 $path = $wrapper->getDirectoryPath() . '/' . file_uri_target($uri);
        //             }
        //             $vars['background_image'] = base_path() . $path;
        //         }
        //     }
        //
        //     $vars['background_image'] = "";
        // }

        // Add product review script
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
            // if (isset($term->field_category_image['und'][0]['uri'])) {
            //     $uri = $term->field_category_image['und'][0]['uri'];
            //     $wrapper = file_stream_wrapper_get_instance_by_uri($uri);
            //     if ($wrapper instanceof DrupalLocalStreamWrapper) {
            //         $path = $wrapper->getDirectoryPath() . '/' . file_uri_target($uri);
            //     }
            //     $vars['background_image'] = base_path() . $path;
            // }
            $vars['classes_array'][] = 'productcat';
        }
    }

    // custom background image for contact pages
    // else {
    //     if (in_array($vars['classes_array'][6], [
    //   'page-node-221',
    //   'page-node-185',
    //   'page-node-36',
    // ])) {
    //         // Place url of img inside quotes below
    //         $vars['background_image'] = "/sites/all/themes/flexitol/images/dt-contact-us-background.jpeg";
    //     }
    // }

    // Set background of view pages
    // if (function_exists('views_get_page_view') && views_get_page_view()) {
    //     $view = views_get_page_view();
    //
    //     //Background for Healthcare Professionals
    //     if (isset($view) && $view->name == 'healthcare_professional_page') {
    //         // Place url of img inside quotes below
    //         $vars['background_image'] = "/sites/all/themes/flexitol/images/healthcare_bg.jpg";
    //     }
    //     //Background for 'Review' page
    //     else {
    //         if (isset($view) && $view->name == 'review') {
    //             // Place url of img inside quotes below
    //             $vars['background_image'] = "/sites/all/themes/flexitol/images/testimonials_bg.jpg";
    //         }
    //         //Background for Special offers and events
    //         else {
    //             if (isset($view) && $view->name == 'special_offers') {
    //                 // Place url of img inside quotes below
    //                 $vars['background_image'] = "/sites/all/themes/flexitol/images/special_offer_bg.jpg";
    //             }
    //         }
    //     }
    // }

    // if (drupal_is_front_page()) {
    //     $vars['background_image'] = null;
    // }
}

/**
 * Add product review
 *
 * @param $vars
 */
function flexitol_preprocess_views_view__leave_a_testimonial(&$vars)
{
    if (arg(0) == 'node' && is_numeric(arg(1))) {
        $node = node_load(arg(1));
        $categ = $node->field_product_category['und'][0]['target_id'];
    }
    $vars['prefix'] = _product_review($categ, 'product-review');
}

function _product_review($categ, $wrapper_class)
{
    $identifiers = [
    9 => '90cc9147-c35a-4183-bf7a-2579c553c8b8', // FOOT CARE
    14 => 'd08068ab-88f8-4124-ba4c-b198e23c7465', // LIP CARE
    19 => 'fe658376-e2db-4c78-bc04-f24d0fe7e44f', // ECZEMA PRONE SKIN CARE
    20 => 'fe658376-e2db-4c78-bc04-f24d0fe7e44f', // ITCHY SKIN CARE
    21 => 'fe658376-e2db-4c78-bc04-f24d0fe7e44f', // VERY DRY SKIN CARE
    22 => 'fe658376-e2db-4c78-bc04-f24d0fe7e44f', // SENSITIVE SKIN CARE
    23 => 'fe658376-e2db-4c78-bc04-f24d0fe7e44f', // PERSONAL CARE
    10 => 'b1a40f30-4372-4788-bc38-da37413ff560', // HAND CARE
    28 => '28023c61-e180-43fc-8219-e6f318688388', // CHILDREN SKIN CARE
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
    28 => '<a target="_blank" href="https://www.productreview.com.au/listings/dermal-therapy-australia" rel="noopener">
<img
width="160"
src="https://api.productreview.com.au/api/services/rating-badge/v2/au/28023c61-e180-43fc-8219-e6f318688388/from-internal-entry-id?resolution=hd&theme=light&width=160"
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
    <div class='{$wrapper_class}' style='text-align: center; margin-bottom: 10px; margin-top: 100px;'>
      {$markups[$categ]}
    </div>";
    }

    return '';
}

/**
 * Override or insert variables into the page template.
 */

function flexitol_preprocess_page(&$vars)
{
    $vars['background_image'] = base_path() . drupal_get_path('theme', 'flexitol') . "/images" . "/default_background.jpg";
    $vars['content_container_class'] = "";
    // Add information about the number of sidebars.
    if (!empty($variables['page']['sidebar_first']) && !empty($variables['page']['sidebar_second'])) {
        $vars['content_column_class'] = 'col-sm-6';
    } elseif (!empty($variables['page']['sidebar_first']) || !empty($variables['page']['sidebar_second'])) {
        $vars['content_column_class'] = 'col-sm-9';
    } else {
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

        if ($node->type == 'product') {
            $variables['#attached']['js'][] = array(
              'type' => 'file',
              'data' => '/sites/all/themes/flexitol/js/jquery.fitvids.js',
            );
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
              "mainEntityOfPage": "' . url("node/{$node->nid}", ['absolute' => true]) . '",
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
function flexitol_preprocess_block(&$vars)
{
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
function flexitol_preprocess_field(&$vars)
{
    if ($vars['element']['#field_name'] == "field_hfc_link") {
    }
}

/**
 * Implements template_preprocess_HOOK().
 */
function flexitol_preprocess_views_view__taxonomy_term_clone(&$variables) {
    if (current_path() == 'taxonomy/term/28') {
        $variables['rows'] .= '
    <div class="views-row col-sm-12">
      <div class="product-review" style="text-align: center; margin-bottom: 10px; margin-top: 50px;">
        <a target="_blank" href="https://www.productreview.com.au/listings/dermal-therapy-australia" rel="noopener">
          <img width="160" src="https://api.productreview.com.au/api/services/rating-badge/v2/au/28023c61-e180-43fc-8219-e6f318688388/from-internal-entry-id?resolution=hd&amp;theme=light&amp;width=160" alt="Dermal Therapy Australia Children\'s Skin Care">
        </a>
      </div>
      <a target="_blank" href="https://littlebodies.com.au"><img style="margin-top: 100px" src="/sites/all/themes/flexitol/images/little_bodies_button.png"/></a>
    </div>';
    } elseif (current_path() == 'taxonomy/term/34') {

        $variables['rows'] .= '<div class="views-row col-sm-12"><a target="_blank" href="https://littlebodies.com"><img style="margin-top: 100px" src="/sites/all/themes/flexitol/images/little_bodies_com_button.png"/></a></div>';
    } elseif (current_path() == 'taxonomy/term/9') {
        $variables['rows'] .= _product_review(9, 'views-row col-sm-12');
    } elseif (current_path() == 'taxonomy/term/10') {
        $variables['rows'] .= _product_review(10, 'views-row col-sm-12');
    } elseif (current_path() == 'taxonomy/term/14') {
        $variables['rows'] .= _product_review(14, 'views-row col-sm-12');
    } elseif (current_path() == 'taxonomy/term/19') {
        $variables['rows'] .= _product_review(19, 'views-row col-sm-12');
    } elseif (current_path() == 'taxonomy/term/20') {
        $variables['rows'] .= _product_review(20, 'views-row col-sm-12');
    } elseif (current_path() == 'taxonomy/term/21') {
        $variables['rows'] .= _product_review(21, 'views-row col-sm-12');
    } elseif (current_path() == 'taxonomy/term/22') {
        $variables['rows'] .= _product_review(22, 'views-row col-sm-12');
    } elseif (current_path() == 'taxonomy/term/23') {
        $variables['rows'] .= _product_review(23, 'views-row col-sm-12');
    } elseif (current_path() == 'taxonomy/term/35') {
        $variables['rows'] .= _product_review(35, 'views-row col-sm-12');
    }
}
