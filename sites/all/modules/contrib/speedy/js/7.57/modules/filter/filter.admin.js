(function($){Drupal.behaviors.filterStatus={attach:function(context,settings){$("#filters-status-wrapper input.form-checkbox",context).once("filter-status",function(){var $checkbox=$(this);var $row=$("#"+$checkbox.attr("id").replace(/-status$/,"-weight"),context).closest("tr");var tab=$("#"+$checkbox.attr("id").replace(/-status$/,"-settings"),context).data("verticalTab");$checkbox.bind("click.filterUpdate",function(){if($checkbox.is(":checked")){$row.show();if(tab){tab.tabShow().updateSummary()}}else{$row.hide();if(tab){tab.tabHide().updateSummary()}}Drupal.tableDrag["filter-order"].restripeTable()});if(tab){tab.fieldset.drupalSetSummary(function(tabContext){return $checkbox.is(":checked")?Drupal.t("Enabled"):Drupal.t("Disabled")})}$checkbox.triggerHandler("click.filterUpdate")})}}})(jQuery);
