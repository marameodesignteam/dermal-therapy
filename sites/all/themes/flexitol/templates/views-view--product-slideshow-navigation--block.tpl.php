<?php
if ($node = menu_get_object()) {

//echo "<pre>";var_dump($node->field_product_video['und'][0]);echo "</pre>";die;

  if (!empty($node->field_product_video['und'][0]['video_url'])) {

      $containerOpen = substr($rows, 0, strpos($rows, '<ul class="slides">'));

      $lis = substr($rows, strpos($rows, '<ul class="slides">'), strpos($rows, '</ul>'));

      $lis = str_replace(array('<ul class="slides">', '</ul>', "</div>"), '', $lis);

      $video_link = $node->field_product_video['und'][0]['video_url'];

      $lis .= '<li><div class="views-field views-field-field-image-gallery"><div class="field-content"><img typeof="foaf:Image" class="img-responsive" src="'.file_create_url($node->field_product_video['und'][0]['thumbnail_path']).'" alt="" draggable="false"></div></div></li>';

      $rows = $containerOpen.'<ul class="slides">'.$lis.'</ul></div>';

      //echo "<pre>";var_dump($rows);echo "</pre>";die;

  }

}
?>

<?php print $rows; ?>
<?php if ($footer): ?>
    <div class="view-footer">
      <?php print $footer; ?>
    </div>
<?php endif; ?>
