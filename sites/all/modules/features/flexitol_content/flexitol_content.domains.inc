<?php
/**
 * @file
 * flexitol_content.domains.inc
 */

/**
 * Implements hook_domain_default_domains().
 */
function flexitol_content_domain_default_domains() {
  $domains = array();
  $domains['wipe-domain-tables'] = 'wipe-domain-tables';
  $domains['australia_dt'] = array(
    'subdomain' => 'dev-newdermal.pantheonsite.io',
    'sitename' => 'Dermal Therapy Australia | Effective Skincare Products',
    'scheme' => 'http',
    'valid' => 1,
    'weight' => -1,
    'is_default' => 1,
    'machine_name' => 'australia_dt',
  );
  $domains['newzealand_dt'] = array(
    'subdomain' => 'dev-nz.dermaltherapy.com.au',
    'sitename' => 'Dermal Therapy New Zealand | Effective Skincare Products	',
    'scheme' => 'http',
    'valid' => 1,
    'weight' => 1,
    'is_default' => 0,
    'machine_name' => 'newzealand_dt',
  );
  $domains['singapore_dt'] = array(
    'subdomain' => 'dev-sg.dermaltherapy.com.au',
    'sitename' => 'Dermal Therapy Singapore | Effective Skincare Products',
    'scheme' => 'http',
    'valid' => 1,
    'weight' => 0,
    'is_default' => 0,
    'machine_name' => 'singapore_dt',
  );

  return $domains;
}

/**
 * Implements hook_domain_alias_default_aliases().
 */
function flexitol_content_domain_alias_default_aliases() {
  $domain_aliases = array();
  $domain_aliases['wipe-domain-tables'] = 'wipe-domain-tables';
  $domain_aliases['australia_dt'] = array();
  $domain_aliases['newzealand_dt'] = array();
  $domain_aliases['singapore_dt'] = array();

  return $domain_aliases;
}

/**
 * Implements hook_domain_conf_default_variables().
 */
function flexitol_content_domain_conf_default_variables() {
  $domain_variables = array();
  $domain_variables['wipe-domain-tables'] = 'wipe-domain-tables';
  $domain_variables['australia_dt'] = array();
  $domain_variables['newzealand_dt'] = array();
  $domain_variables['singapore_dt'] = array(
    'googleanalytics_account' => 'UA-25402788-9',
    'googleanalytics_domain_mode' => 0,
    'googleanalytics_cross_domains' => '',
    'googleanalytics_visibility_pages' => 0,
    'googleanalytics_pages' => 'admin
admin/*
batch
node/add*
node/*/*
user/*/*',
    'googleanalytics_visibility_roles' => 1,
    'googleanalytics_roles' => array(
      1 => 0,
      2 => 0,
      4 => 0,
      3 => 0,
    ),
    'googleanalytics_custom' => 0,
    'googleanalytics_trackuserid' => 0,
    'googleanalytics_trackoutbound' => 1,
    'googleanalytics_trackmailto' => 1,
    'googleanalytics_trackfiles' => 1,
    'googleanalytics_trackfiles_extensions' => '7z|aac|arc|arj|asf|asx|avi|bin|csv|doc(x|m)?|dot(x|m)?|exe|flv|gif|gz|gzip|hqx|jar|jpe?g|js|mp(2|3|4|e?g)|mov(ie)?|msi|msp|pdf|phps|png|ppt(x|m)?|pot(x|m)?|pps(x|m)?|ppam|sld(x|m)?|thmx|qtm?|ra(m|r)?|sea|sit|tar|tgz|torrent|txt|wav|wma|wmv|wpd|xls(x|m|b)?|xlt(x|m)|xlam|xml|z|zip',
    'googleanalytics_trackcolorbox' => 1,
    'googleanalytics_tracklinkid' => 0,
    'googleanalytics_trackurlfragments' => 0,
    'googleanalytics_trackmessages' => array(
      'status' => 0,
      'warning' => 0,
      'error' => 0,
    ),
    'googleanalytics_site_search' => 1,
    'googleanalytics_trackadsense' => 0,
    'googleanalytics_trackdoubleclick' => 0,
    'googleanalytics_tracker_anonymizeip' => 1,
    'googleanalytics_privacy_donottrack' => 1,
    'tracking__active_tab' => 'edit-search-and-advertising',
    'googleanalytics_custom_dimension' => array(),
    'googleanalytics_custom_metric' => array(),
    'googleanalytics_cache' => 0,
    'googleanalytics_codesnippet_create' => array(),
    'googleanalytics_codesnippet_before' => '',
    'googleanalytics_codesnippet_after' => '',
    'googleanalytics_debug' => 0,
    'site_name' => 'Dermal Therapy Singapore | Effective Skincare Products',
    'site_slogan' => '',
    'site_mail' => 'info@dermaltherapy.com.sg',
    'default_nodes_main' => 10,
    'site_frontpage' => 'homepage',
    'site_403' => '',
    'site_404' => 'search404',
  );

  return $domain_variables;
}
