<?php
if ($node = menu_get_object()) {

//echo "<pre>";var_dump($node->field_product_video['und'][0]);echo "</pre>";die;

  if (!empty($node->field_product_video['und'][0]['video_url'])) {

      $containerOpen = substr($rows, 0, strpos($rows, '<ul class="slides">'));

      $lis = substr($rows, strpos($rows, '<ul class="slides">'), strpos($rows, '</ul>'));

      $lis = str_replace(array('<ul class="slides">', '</ul>', "</div>"), '', $lis);

      $video_link = $node->field_product_video['und'][0]['video_url'];

      $video_html = "";

      if (preg_match("/youtube/i", $video_link)) {
            $video_ID = substr($video_link, strpos($video_link, "?v=") + 3);

            $video_html = '<iframe class="reframe" width="1266" height="712" src="https://www.youtube.com/embed/'.$video_ID.'" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>';
        }

        //https://vimeo.com/86291629
        //<iframe src="https://player.vimeo.com/video/86291629" width="640" height="360" frameborder="0" allow="autoplay; fullscreen" allowfullscreen></iframe>

        elseif (preg_match("/vimeo/i", $video_link)) {
            $video_ID = substr($video_link, strpos($video_link, ".com/") + 5);

            $video_html = '<iframe class="reframe" width="1266" height="712" src="https://player.vimeo.com/video/'.$video_ID.'" width="640" height="360" frameborder="0" allow="autoplay; fullscreen" allowfullscreen></iframe>';
        }

      $lis .= "<li class='video' data-thumb='".file_create_url($node->field_product_video['und'][0]['thumbnail_path'])."'><div>".$video_html."</div></li>";

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
