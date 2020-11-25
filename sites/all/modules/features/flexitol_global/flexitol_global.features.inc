<?php
/**
 * @file
 * flexitol_global.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function flexitol_global_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_fontyourface_features_default_font().
 */
function flexitol_global_fontyourface_features_default_font() {
  return array(
    'Montserrat 700 (latin)' => array(
      'name' => 'Montserrat 700 (latin)',
      'enabled' => 1,
      'url' => 'http://www.google.com/webfonts/family?family=Montserrat&subset=latin#700',
      'provider' => 'google_fonts_api',
      'css_selector' => NULL,
      'css_family' => 'Montserrat',
      'css_style' => 'normal',
      'css_weight' => 700,
      'css_fallbacks' => '',
      'foundry' => '',
      'foundry_url' => '',
      'license' => '',
      'license_url' => '',
      'designer' => '',
      'designer_url' => '',
      'metadata' => 'a:2:{s:4:"path";s:14:"Montserrat:700";s:6:"subset";s:5:"latin";}',
    ),
    'Montserrat regular (latin)' => array(
      'name' => 'Montserrat regular (latin)',
      'enabled' => 1,
      'url' => 'http://www.google.com/webfonts/family?family=Montserrat&subset=latin#regular',
      'provider' => 'google_fonts_api',
      'css_selector' => NULL,
      'css_family' => 'Montserrat',
      'css_style' => 'normal',
      'css_weight' => 'normal',
      'css_fallbacks' => '',
      'foundry' => '',
      'foundry_url' => '',
      'license' => '',
      'license_url' => '',
      'designer' => '',
      'designer_url' => '',
      'metadata' => 'a:2:{s:4:"path";s:18:"Montserrat:regular";s:6:"subset";s:5:"latin";}',
    ),
  );
}

/**
 * Implements hook_image_default_styles().
 */
function flexitol_global_image_default_styles() {
  $styles = array();

  // Exported image style: article_full.
  $styles['article_full'] = array(
    'label' => 'Article full',
    'effects' => array(
      6 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1350,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: article_teaser.
  $styles['article_teaser'] = array(
    'label' => 'Article teaser',
    'effects' => array(
      5 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 768,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: crop_320_square.
  $styles['crop_320_square'] = array(
    'label' => 'Crop 320 square',
    'effects' => array(
      6 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 320,
          'height' => 320,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: crop_square.
  $styles['crop_square'] = array(
    'label' => 'Crop square',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 300,
          'height' => 300,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: height_310.
  $styles['height_310'] = array(
    'label' => 'height 310',
    'effects' => array(
      4 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => 310,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: homepage_review.
  $styles['homepage_review'] = array(
    'label' => 'Homepage review',
    'effects' => array(
      15 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 350,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: product_slideshow.
  $styles['product_slideshow'] = array(
    'label' => 'Product slideshow',
    'effects' => array(
      14 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 460,
          'height' => 430,
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: related_products.
  $styles['related_products'] = array(
    'label' => 'Related products',
    'effects' => array(
      6 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 250,
          'height' => 220,
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: slide.
  $styles['slide'] = array(
    'label' => 'Slide',
    'effects' => array(
      8 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1350,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: width_250.
  $styles['width_250'] = array(
    'label' => 'width_250',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 250,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: width_300.
  $styles['width_300'] = array(
    'label' => 'width_300',
    'effects' => array(
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 300,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
