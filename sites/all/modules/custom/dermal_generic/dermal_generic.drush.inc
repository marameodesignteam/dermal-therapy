<?php

/**
 * Implements hook_drush_command().
 */
function dermal_generic_drush_command() {

  $items['bhrating-sync'] = array(
    'description' => 'Crawl rating result from Beauty Heaven.',
  );

  $items['bhrating-reviews'] = array(
    'description' => 'Crawl all ratings from Beauty Heaven.',
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

/**
 * Callback for the pub-config command
 *
 * @param $token_url
 * @param $pub_url
 */
function drush_dermal_generic_bhrating_reviews() {
  _truncate_old_reviews();

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
    $reviews = $xpath->query( "//div[contains(@class,'view-product-reviews')]/div[contains(@class,'view-content')]/div[contains(@class,'views-row')]" );

    foreach ($reviews as $node) {
      $authorElement = $xpath->query(".//h4[contains(@class,'author')]/span", $node)->item(0);
      $author = strip_tags($dom->saveHTML($authorElement));

      $dateElement = $xpath->query(".//div[contains(@class,'date')]", $node)->item(0);
      $date = strip_tags($dom->saveHTML($dateElement));

      $titleElement = $xpath->query(".//div[contains(@class,'review-info')]/h4", $node)->item(0);
      $title = strip_tags($dom->saveHTML($titleElement));

      $bodyElement = $xpath->query(".//div[contains(@class,'field-name-body')]", $node)->item(0);
      $body = strip_tags($dom->saveHTML($bodyElement));

      $ratingElement = $xpath->query(".//div[contains(@class,'star')]/span[contains(@class,'on')]", $node);
      $rating = $ratingElement->length;

      // Create node
      $values = array(
        'type' => 'beautyheaven_review',
        'uid' => 1,
        'status' => 1,
        'comment' => 1,
        'promote' => 0,
      );
      $entity = entity_create('node', $values);
      $ewrapper = entity_metadata_wrapper('node', $entity);
      $ewrapper->title->set($title);
      $ewrapper->body->set(array('value' => $body));
      $ewrapper->field_author->set($author);
      $ewrapper->field_review_date->set($date);
      $ewrapper->field_rate->set($rating);
      $ewrapper->save();
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
