<?php

/**
 * Implements hook_drush_command().
 */
function dermal_generic_drush_command() {

  $items['bhrating-sync'] = array(
    'description' => 'Crawl rating result from Beauty Heaven.',
  );

  $items['bhrating-reviews'] = array(
    'description' => 'Crawl all rating items from Beauty Heaven for SEO purpose (no need anymore)',
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
    $rating = $xpath->query( "//div[contains(@class,'product-average-rating')]//div[contains(@class,'fivestar-widget-static-5')]" );
    if ($rating->length === 1) {
      $rating_block = $dom->saveHTML($rating->item(0));
      $node_wrapper = entity_metadata_wrapper('node', $node);
      $node_wrapper->field_bh_rate->set(trim(strip_tags($rating_block)));
      $node_wrapper->save();
    }
  }
}

/**
 * Callback for the product-review-fetch command
 *
 * @param $token_url
 * @param $pub_url
 */
function drush_dermal_generic_bhrating_reviews() {
  $nids = db_select('node', 'n')
    ->fields('n', array('nid'))
    ->fields('n', array('type'))
    ->condition('n.type', 'product')
    ->execute()
    ->fetchCol();
  $nodes = node_load_multiple($nids);
  foreach ($nodes as $node) {
    if (!empty($node->field_product_review_link['und'][0]['value'])) {
      $curl = curl_init($node->field_product_review_link['und'][0]['value']);

      curl_setopt($curl, CURLOPT_RETURNTRANSFER, true);
      curl_setopt($curl, CURLOPT_FOLLOWLOCATION, true);
      curl_setopt($curl, CURLOPT_USERAGENT, 'Mozilla/5.0 (Windows; U; Windows NT 6.1; en-US) AppleWebKit/534.10 (KHTML, like Gecko) Chrome/8.0.552.224 Safari/534.10');
      $html = curl_exec($curl);
      curl_close($curl);

      $dom = new DOMDocument();
      @$dom->loadHTML($html);
      $xpath = new DOMXPath($dom);
      $value = $xpath->query( "//*[@id='content']/div[2]/div/div/div[2]/div[1]/div[2]/div[1]/div/div/div/div[1]/div[2]/div[2]/div[2]/span/span[1]/span");
      $value_block = $dom->saveHTML($value->item(0));
      $count = $xpath->query( "//*[@id='content']/div[2]/div/div/div[2]/div[1]/div[2]/div[1]/div/div/div/div[1]/div[2]/div[2]/div[2]/span/span[2]/span/span/span");
      $count_block = $dom->saveHTML($count->item(0));

      $node_wrapper = entity_metadata_wrapper('node', $node);
      $node_wrapper->field_rating_value->set(trim(strip_tags($value_block)));
      $node_wrapper->field_rating_count->set(trim(strip_tags($count_block)));
      $node_wrapper->save();
    }
  }
}

function _truncate_old_reviews() {
  $results = db_select('node', 'n')
    ->fields('n', array('nid'))
    ->condition('type', 'beautyheaven_review')
    ->execute();

  foreach ($results as $result) {
    $nids[] = $result->nid;
  }

  if (!empty($nids)) {
    node_delete_multiple($nids);
    drupal_set_message(t('Deleted %count BeautyHeaven reviews.', array('%count' => count($nids))));
  }
}
