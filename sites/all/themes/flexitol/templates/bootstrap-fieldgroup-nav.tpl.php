<?php
/**
 * @file
 * Displays a Bootstrap-style nav for tabs/pills.
 *
 * Available variables:
 * - $is_empty: Boolean: any content to render at all?
 * - $wrapper_classes: The classes set on the wrapping div.
 * - $nav_classes: The classes set on the nav ul.
 * - $navs: An array of nav elements (tabs, pills)
 * - $pane_classes: The classes set on the panes containing content.
 * - $panes: An array of panes containing content.
 * - $index: The index of the active tab/pane.
 *
 * @ingroup themeable
 */
?>

<?php if (!$is_empty) : ?>

  <div class="<?php print $wrapper_classes; ?>">

    <?php if ($flip) : ?>
      <div class="tab-content <?php print $pane_classes; ?>">
        <?php foreach ($panes as $index => $pane) : ?>
          <div id="<?php print $pane['id']; ?>" class="tab-pane <?php if ($index === $active) print 'active'; ?>">
            <?php print $pane['content']; ?>
          </div>
        <?php endforeach; ?>
      </div>
    <?php endif; ?>

    <?php if (!$is_single) : ?>
      <ul class="nav <?php print $nav_classes; ?>">
        <?php foreach ($navs as $index => $nav) : ?>
          <li class="<?php print $nav['classes']; ?><?php if ($index === $active) print 'active'; ?>">
            <?php print $nav['content']; ?>
          </li>
        <?php endforeach; ?>
      </ul>
    <?php endif; ?>

    <?php if (strpos($wrapper_classes,'group-info') !== false) : ?>
      <div class="mobile-only-buttons">
        <?php
        $node_obj =  $variables['items']['group_information']['field_product_information']['#object'];
        $buy_link_field = field_view_field('node', $node_obj, 'field_product_buy_link', 'full');
        print render($buy_link_field);
//        $where = (($node_obj->nid == 1331 || $node_obj->nid == 1332 || $node_obj->nid == 1333)) ? 'https://littlebodies.com.au/' : '/where-buy';
        $where = '/where-buy';
        ?>
        <div class="field field-name-where-to-buy-button field-type-ds field-label-hidden">
          <div class="field-items">
            <div class="field-item even">
              <p><a class="btn btn-danger" href="<?php echo $where; ?>">Where to buy</a></p>
            </div>
          </div>
        </div>
      </div>
    <?php endif; ?>

    <?php if (!$flip) : ?>
      <div class="tab-content <?php print $pane_classes; ?>">
        <?php foreach ($panes as $index => $pane) : ?>
          <div id="<?php print $pane['id']; ?>" class="tab-pane <?php if ($index === $active) print 'active'; ?>">
            <?php print $pane['content']; ?>
          </div>
        <?php endforeach; ?>
      </div>
    <?php endif; ?>

  </div>

<?php endif; ?>
