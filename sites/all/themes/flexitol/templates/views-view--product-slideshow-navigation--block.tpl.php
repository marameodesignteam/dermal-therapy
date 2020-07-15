<?php



if ($node = menu_get_object()) {

//echo "<pre>";var_dump($node->field_product_video['und'][0]);echo "</pre>";die;

  if (is_array($node->field_product_video['und']) && count($node->field_product_video['und']) > 0) {

    $containerOpen = substr($rows, 0, strpos($rows, '<ul class="slides">'));

    $lis = substr($rows, strpos($rows, '<ul class="slides">'), strpos($rows, '</ul>'));

    $lis = str_replace(array('<ul class="slides">', '</ul>', "</div>"), '', $lis);

    foreach ($node->field_product_video['und'] as $video_arr) {

      if (!empty($video_arr['video_url'])) {

          $lis .= '<li><div class="views-field views-field-field-image-gallery"><div class="field-content"><img typeof="foaf:Image" class="img-responsive" src="'.file_create_url($video_arr['thumbnail_path']).'" alt="" draggable="false"></div></div></li>';

          //echo "<pre>";var_dump($rows);echo "</pre>";die;

      }

    }

    $rows = $containerOpen.'<ul class="slides">'.$lis.'</ul></div>';

  }

}

if (!empty($rows)) :

  print $rows;

  if ($footer): ?>
      <div class="view-footer">
        <?php print $footer; ?>
      </div>
<?php

  endif;

endif;
