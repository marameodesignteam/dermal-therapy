<?php

/**
 * @file
 * Lib file for context image loader.
 */

/**
 * Function to alter img tags for lazy loading.
 */
function _set_lazy_image_container(&$e, $region, $loader_img_url) {
  //global $conf;
  $trans_img_url = drupal_get_path('module', 'context_image_loader').'/transparent.png';
  $org_src = $org_height = $org_width = $style = '';
  // Collect the attributes
  $all_attr = $e->getAllAttributes();
  foreach($all_attr as $attr_name=>$attr_val) {
    if($attr_name) {
      if($attr_name == 'src')
        $org_src = $attr_val;
      elseif($attr_name == 'height')
        $org_height = $attr_val;
      elseif($attr_name == 'width')
        $org_width = $attr_val;
      elseif($attr_name == 'style') {
        if(strpos($attr_val, ";")!==FALSE)
          $style = str_replace(";", " !important ;", $attr_val);
        else
          $style = $attr_val . " !important ;";
      }
    }
  }
  // Get the minimum height/ width of the loader div for maintaining layout
  if(!$org_height)
    $org_height = variable_get('context_lazy_load_div_min_height', 50);
  if(is_numeric($org_height))
    $org_height = $org_height.'px';

  if(!$org_width)
    $org_width = variable_get('context_lazy_load_div_min_width', 50);
  if(is_numeric($org_width))
    $org_width = $org_width.'px';

  $e->setAttribute('org-src', $org_src);
  if($style)
    $e->setAttribute('style', $style);

  //Get the immediate parent div
  $p = $e->parent();
  while(!in_array($p->tag, ['div','span','li', 'td'])) {
    $p = $p->parent();
  }

  //Set properties to parent div
  $existing_class = $p->getAttribute('class');
  $p->setAttribute('class', $existing_class. ' context-lazy-load');
  $p->setAttribute('delay', intval($region['delay']));
  $p->setAttribute('set_on_scroll', $region['set_on_scroll']);

  // Check if alternate image uploaded, set the image url accordingly
  if($region['alternate_img'] && $alt_img = file_load($region['alternate_img'])) {
    $alt_image_url = file_create_url($alt_img->uri);
    $e->setAttribute('src', $alt_image_url);
  } else {
    //Request to regenerate trans image
    if($region['trans_image']) {
      $new_trans_name = preg_replace('/\s+-/', '', $existing_class).'_'.$region['context_name'].'.png';
      $new_trans_path = drupal_realpath('public://').'/context-lazy-load/'.$new_trans_name;
      _generate_trans_image($trans_img_url, $org_src, $new_trans_path);
      $e->setAttribute('src', file_create_url('public://').'context-lazy-load/'.$new_trans_name);
    } else
      $e->setAttribute('src', '/' . $trans_img_url);
  }

  // For no alternate image uploaded, set hidden class for hidden loader
  $existing_class = $e->getAttribute('class');
  if ($region['selector'] != 'img' && !$region['alternate_img'] && !$region['use_loader'])
    $updated_class = $existing_class. ' hidden-loader';
  else
    $updated_class = $existing_class. ' hidden-loader-temp';
  $e->setAttribute('class', $updated_class);


  // For loader image only, manipulate other styles to keep layout intact
  if($region['use_loader'] && !$region['alternate_img']) {

    $parent_style = $p->getAttribute('style');
    if($parent_style)
      $parent_style = $parent_style."; position:relative;"; //min-height:$org_height; min-width:$org_width;
    else
      $parent_style = "position:relative;"; //min-height:$org_height; min-width:$org_width;
    $p->setAttribute('style', $parent_style);

    //$e->outertext = '<div class="context-img-loader-div context-lazy-load context-img-use-loader" delay="'. intval($region['delay']).'">'.$e->outertext.'</div>';
    $p->innertext = $p->innertext . '<div class="context-img-loader-div context-img-use-loader"><img src="'.$loader_img_url.'" /></div>';
  } else {
    //$e->outertext = '<div class="context-img-loader-div context-lazy-load" delay="'. intval($region['delay']).'" >'.$e->outertext.'</div>';
    //$e->parent()->innertext = $e->parent()->innertext . '<div class="context-img-loader-div" ></div>';
  }

  return $e;
}

/**
 * Function to alter background images for lazy loading.
 */
function _set_lazy_bg_image_container(&$e, $region) {
  //global $conf;
  //Get style property
  $style = $e->getAttribute('style');
  //Check for background image and replace it with null
  preg_match_all("/(background[-image]*?)\s*?:.*?url[\s]*\([\'\"]?([^\'\"]+)[\'\"]?\)/", $style, $matches, PREG_SET_ORDER);
  //print_r($matches);
  $org_src = [];
  foreach($matches as $match) {
   $org_src[] = $match[1].'::'.$match[2];
  }
  $org_src = implode(",", $org_src);

  //if we have alternate images
  if($region['alternate_img'] && $alt_img = file_load($region['alternate_img'])) {
    $alt_image_url = file_create_url($alt_img->uri);
  } else
    $alt_image_url = '';

  $new_style = preg_replace("/(background[-image]*?\s*?:.*?url[\s]*\([\'\"]?)([^\'\"]+)([\'\"]?\))/", '$1'.$alt_image_url.'$3', $style);

  $e->setAttribute('style', $new_style);
  $e->setAttribute('org-src', $org_src);
  $e->setAttribute('delay', intval($region['delay']));

  $bg_img_class= 'context-lazy-background';
  $existing_class = $e->getAttribute('class');
  $e->setAttribute('class', $existing_class. ' '.$bg_img_class);

  return $e;
}

/**
 * Function to get image physical path.
 */
function _get_real_path($image_name) {
  $image_arr = parse_url($image_name);
  return DRUPAL_ROOT.$image_arr['path'];
}

/**
 * Function to alter imag tags for for loading on viewport ( Experimental)
 */
function _set_scroll_image_container(&$e) {
  //global $conf;
  $org_src = $org_height = $org_width = $style = '';
  // Collect the attributes
  $all_attr = $e->getAllAttributes();
  foreach($all_attr as $attr_name=>$attr_val) {
    if($attr_name) {
      if($attr_name == 'src')
        $org_src = $attr_val;
      elseif($attr_name == 'height')
        $org_height = $attr_val;
      elseif($attr_name == 'width')
        $org_width = $attr_val;
      elseif($attr_name == 'style') {
        if(strpos($attr_val, ";")!==FALSE)
          $style = str_replace(";", " !important ;", $attr_val);
        else
          $style = $attr_val . " !important ;";
      }
    }
  }
  watchdog('image scroll', 'org src : '.$org_src);
  // Get the minimum height/ width of the loader div for maintaining layout
  if(!$org_height)
    $org_height = variable_get('context_lazy_load_div_min_height', 50);
  if(is_numeric($org_height))
    $org_height = $org_height.'px';

  if(!$org_width)
    $org_width = variable_get('context_lazy_load_div_min_width', 50);
  if(is_numeric($org_width))
    $org_width = $org_width.'px';

  $e->setAttribute('org-scroll-src', $org_src);
  if($style)
    $e->setAttribute('style', $style);

  //Get the immediate parent div
  $p = $e->parent();
  while(!in_array($p->tag, ['div','span','li', 'td'])) {
    $p = $p->parent();
  }

  //set properties to parent div
  $existing_class = $p->getAttribute('class');
  $p->setAttribute('class', $existing_class. ' context-scroll-load');
  //$p->setAttribute('delay', intval($region['delay']));
  //$e->setAttribute('src', $trans_img_url);
  return $e;

}

/**
 * Function to create new trans image.
 */
function _generate_trans_image($org_image, $refer_image, $dest_image) {

  $refer_image = _get_real_path($refer_image);
  $org_image = _get_real_path($org_image);

  list($width , $height) = getimagesize($refer_image);
  //check if dest image exists
  if(file_exists($dest_image)) {
    //get size
    list($dest_width, $dest_height) = getimagesize($dest_image);
    //if size mathes, return
    if($dest_width == $width && $dest_height == $height)
      return;
  }
  //prepare directory
  file_prepare_directory(dirname($dest_image), FILE_CREATE_DIRECTORY);
  //no image found or does not match, recreate
  $destination = imagecreatetruecolor($width, $height);
  imagesavealpha($destination, true);
  $color = imagecolorallocatealpha($destination, 0, 0, 0, 127);
  imagefill($destination, 0, 0, $color);
  imagepng($destination, $dest_image, 9);
}

/**
 * Function to create the query filter for xpath.
 */
function _generate_path_selector($selector) {
  // Split and get the elements.
  $allowed_elements = ['div', 'span', 'p', 'table', 'tr', 'td', 'li', 'ul'];
  $allowed_properties = ['id', 'class', 'class-contain', 'name'];
  $temp_filter_str = '';
  $selector_arr = explode('>', $selector);
  $final_filter_arr = [];
  $matches = [];
  foreach ($selector_arr as $item) {
    $filter = preg_match_all("/([a-zA-Z]+)(\[(.*?)\])*/", $item, $matches);
    $element = $matches[1][0];
    if (in_array($element, $allowed_elements)) {
      $temp_filter_str = $temp_filter_str . $element;
      $filter = explode("=", $matches[3][0]);
      if (in_array($filter[0], $allowed_properties) && $filter[1]) {
        $sub_filter = explode(",", $filter[1]);
        $sub_filter_elem = $sub_filter[0];
        $sub_filter_elem_count = isset($sub_filter[1])?intval($sub_filter[1]):FALSE;
        switch ($filter[0]) {
          case 'id':
          case 'name':
            $temp_filter_str = $temp_filter_str . "[" . $filter[0] . "=$sub_filter_elem]";
            break;
          case 'class-contain':
          case 'class':
            $temp_filter_str = $temp_filter_str . ".$sub_filter_elem";
            break;
        }
        $temp_filter_str = $temp_filter_str . ' ';
        if($sub_filter_elem_count!==FALSE) {
          // store the counter, if any
          $final_filter_arr[1] = $sub_filter_elem_count;
          break;
        }
      }
    }
  }
  $temp_filter_str = trim($temp_filter_str, " ");
  $final_filter_arr[0] = $temp_filter_str;
  return $final_filter_arr;
}
