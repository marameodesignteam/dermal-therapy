<?php
/**
 * @file
 * flexitol_content.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function flexitol_content_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'category';
  $context->description = 'Category page';
  $context->tag = '';
  $context->conditions = array(
    'taxonomy_term' => array(
      'values' => array(
        'product_category' => 'product_category',
      ),
      'options' => array(
        'term_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-category-block' => array(
          'module' => 'views',
          'delta' => 'category-block',
          'region' => 'header',
          'weight' => '-10',
        ),
        'views-products-block' => array(
          'module' => 'views',
          'delta' => 'products-block',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'views-category-block_1' => array(
          'module' => 'views',
          'delta' => 'category-block_1',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Category page');
  $export['category'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'clone_of_where_2_buy_nz';
  $context->description = 'where to buy page singapore';
  $context->tag = '';
  $context->conditions = array(
    'domain' => array(
      'values' => array(
        3 => 3,
      ),
    ),
    'path' => array(
      'values' => array(
        'node/30' => 'node/30',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
        'block-11' => array(
          'module' => 'block',
          'delta' => '11',
          'region' => 'content',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('where to buy page singapore');
  $export['clone_of_where_2_buy_nz'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'conditions';
  $context->description = 'Condition page';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'conditions' => 'conditions',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'taxonomy_term' => array(
      'values' => array(
        'conditions' => 'conditions',
      ),
      'options' => array(
        'term_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'ds_extras-banner_conditions' => array(
          'module' => 'ds_extras',
          'delta' => 'banner_conditions',
          'region' => 'header',
          'weight' => '-9',
        ),
        'views-conditions_menu-block' => array(
          'module' => 'views',
          'delta' => 'conditions_menu-block',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'views-8a88aca1c0589e095165a67e4cdec26f' => array(
          'module' => 'views',
          'delta' => '8a88aca1c0589e095165a67e4cdec26f',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Condition page');
  $export['conditions'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'homepage';
  $context->description = 'Homepage AU';
  $context->tag = '';
  $context->conditions = array(
    'domain' => array(
      'values' => array(
        1 => 1,
      ),
    ),
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-nodequeue_1-block' => array(
          'module' => 'views',
          'delta' => 'nodequeue_1-block',
          'region' => 'content',
          'weight' => '22',
        ),
        'conf_block-welcome_block' => array(
          'module' => 'conf_block',
          'delta' => 'welcome_block',
          'region' => 'content_secondary',
          'weight' => '0',
        ),
        'views-nodequeue_2-block' => array(
          'module' => 'views',
          'delta' => 'nodequeue_2-block',
          'region' => 'content_tertiary',
          'weight' => '0',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Homepage AU');
  $export['homepage'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'homepage_nz';
  $context->description = 'Homepage NZ';
  $context->tag = '';
  $context->conditions = array(
    'domain' => array(
      'values' => array(
        3 => 3,
      ),
    ),
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-nodequeue_1-block_2' => array(
          'module' => 'views',
          'delta' => 'nodequeue_1-block_2',
          'region' => 'content',
          'weight' => '10',
        ),
        'conf_block-welcome_block' => array(
          'module' => 'conf_block',
          'delta' => 'welcome_block',
          'region' => 'content_secondary',
          'weight' => '0',
        ),
        'views-nodequeue_2-block_2' => array(
          'module' => 'views',
          'delta' => 'nodequeue_2-block_2',
          'region' => 'content_tertiary',
          'weight' => '1',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Homepage NZ');
  $export['homepage_nz'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'homepage_sg';
  $context->description = 'Homepage sg';
  $context->tag = '';
  $context->conditions = array(
    'domain' => array(
      'values' => array(
        2 => 2,
      ),
    ),
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-nodequeue_1-block_1' => array(
          'module' => 'views',
          'delta' => 'nodequeue_1-block_1',
          'region' => 'content',
          'weight' => '10',
        ),
        'conf_block-welcome_block' => array(
          'module' => 'conf_block',
          'delta' => 'welcome_block',
          'region' => 'content_secondary',
          'weight' => '0',
        ),
        'views-nodequeue_2-block_1' => array(
          'module' => 'views',
          'delta' => 'nodequeue_2-block_1',
          'region' => 'content_tertiary',
          'weight' => '0',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Homepage sg');
  $export['homepage_sg'] = $context;

  $context = new stdClass();
  $context->disabled = TRUE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'product';
  $context->description = 'Product page';
  $context->tag = '';
  $context->conditions = array();
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'ds_extras-banner' => array(
          'module' => 'ds_extras',
          'delta' => 'banner',
          'region' => 'header',
          'weight' => '-10',
        ),
        'views-11d287f0dab888795c67e49bfb01f5ba' => array(
          'module' => 'views',
          'delta' => '11d287f0dab888795c67e49bfb01f5ba',
          'region' => 'content_bottom',
          'weight' => '-35',
        ),
        'views-leave_a_testimonial-block' => array(
          'module' => 'views',
          'delta' => 'leave_a_testimonial-block',
          'region' => 'content_bottom',
          'weight' => '-33',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Product page');
  $export['product'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'where_2_buy';
  $context->description = 'where to buy page australia';
  $context->tag = '';
  $context->conditions = array(
    'domain' => array(
      'values' => array(
        1 => 1,
      ),
    ),
    'path' => array(
      'values' => array(
        'node/30' => 'node/30',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-8' => array(
          'module' => 'block',
          'delta' => '8',
          'region' => 'header',
          'weight' => '-10',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
        'block-1' => array(
          'module' => 'block',
          'delta' => '1',
          'region' => 'content',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('where to buy page australia');
  $export['where_2_buy'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'where_2_buy_sg';
  $context->description = 'where to buy page singapore';
  $context->tag = '';
  $context->conditions = array(
    'domain' => array(
      'values' => array(
        2 => 2,
      ),
    ),
    'path' => array(
      'values' => array(
        'node/30' => 'node/30',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-8' => array(
          'module' => 'block',
          'delta' => '8',
          'region' => 'header',
          'weight' => '-8',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
        'block-10' => array(
          'module' => 'block',
          'delta' => '10',
          'region' => 'content',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('where to buy page singapore');
  $export['where_2_buy_sg'] = $context;

  return $export;
}
