<?php

/**
 * @file field.tpl.php
 * Default template implementation to display the value of a field.
 *
 * This file is not used and is here as a starting point for customization only.
 * @see theme_field()
 *
 * Available variables:
 * - $items: An array of field values. Use render() to output them.
 * - $label: The item label.
 * - $label_hidden: Whether the label display is set to 'hidden'.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - field: The current template type, i.e., "theming hook".
 *   - field-name-[field_name]: The current field name. For example, if the
 *     field name is "field_description" it would result in
 *     "field-name-field-description".
 *   - field-type-[field_type]: The current field type. For example, if the
 *     field type is "text" it would result in "field-type-text".
 *   - field-label-[label_display]: The current label position. For example, if
 *     the label position is "above" it would result in "field-label-above".
 *
 * Other variables:
 * - $element['#object']: The entity to which the field is attached.
 * - $element['#view_mode']: View mode, e.g. 'full', 'teaser'...
 * - $element['#field_name']: The field name.
 * - $element['#field_type']: The field type.
 * - $element['#field_language']: The field language.
 * - $element['#field_translatable']: Whether the field is translatable or not.
 * - $element['#label_display']: Position of label display, inline, above, or
 *   hidden.
 * - $field_name_css: The css-compatible field name.
 * - $field_type_css: The css-compatible field type.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess_field()
 * @see theme_field()
 *
 * @ingroup themeable
 */

$link = $element['#object']->nid == 89 ? 'https://ibdmedical.pharmacy.com.au/clickcollect' : 'https://nicepak-dermaltherapy.pharmacy.com.au/clickcollect';
global $theme_path, $base_url, $_domain;
$path_to_theme = $base_url . '/' . $theme_path;
?>

<?php if ($_domain['domain_id'] == 1): ?>
    <?php global $_domain, $theme_path, $base_url; ?>
    <?php $path_to_theme = $base_url.'/'.$theme_path;
    $serverHost = strval($_SERVER['HTTP_HOST']); ?>

    <a href="<?php print $link; ?>" target="_blank">
        <div class="click-and-collect">
                <img src="<?php print $path_to_theme; ?>/images/blue-click-collect.png">
        </div>
    </a>

    <?php echo $element['#object']->field_product_category['und'][0]['target_id'] == 28 ? '<div><a target="_blank" href="https://littlebodies.com.au"><img src="/sites/all/themes/flexitol/images/little_bodies_button.png"/></a>' : ''; ?>
<?php endif; ?>
