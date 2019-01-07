<?php

/**
 * Implements hook_drush_command().
 */
function dermal_generic_drush_command() {

  $items['bhrating-sync'] = array(
    'description' => 'Crawl rating result from Beauty Heaven.',
  );

  return $items;
}

/**
 * Callback for the pub-config command
 *
 * @param $token_url
 * @param $pub_url
 */
function drush_dermal_generic_bhrating_sync() {
  $nids = db_select('node', 'n')
    ->fields('n', array('nid'))
    ->fields('n', array('type'))
    ->condition('n.type', 'product')
    ->execute()
    ->fetchCol();
  $nodes = node_load_multiple($nids);
  foreach ($nodes as $node) {
    $curl = curl_init($node->field_beauty_review_link[LANGUAGE_NONE][0]['url']);
    curl_setopt($curl, CURLOPT_RETURNTRANSFER, true);
    curl_setopt($curl, CURLOPT_FOLLOWLOCATION, true);
    curl_setopt($curl, CURLOPT_USERAGENT, 'Mozilla/5.0 (Windows; U; Windows NT 6.1; en-US) AppleWebKit/534.10 (KHTML, like Gecko) Chrome/8.0.552.224 Safari/534.10');
    $html = curl_exec($curl);
    curl_close($curl);

    $dom = new DOMDocument();
    @$dom->loadHTML($html);
    $xpath = new DOMXPath($dom);
    $rating = $xpath->query( "//div[contains(@class,'product-average-rating')]" );
    if ($rating->length === 1) {
      $rating_block = $dom->saveHTML($rating->item(0));
      $node->field_beauty_review_data[LANGUAGE_NONE][0]['value'] = $rating_block;
      $node->field_beauty_review_data[LANGUAGE_NONE][0]['#format'] = 'php_code';
      node_save($node);
    }
  }
}
