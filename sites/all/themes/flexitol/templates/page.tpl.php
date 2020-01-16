<?php
/**
* @file
* Default theme implementation to display a single Drupal page.
*
* The doctype, html, head and body tags are not in this template. Instead they
* can be found in the html.tpl.php template in this directory.
*
* Available variables:
*
* General utility variables:
* - $base_path: The base URL path of the Drupal installation. At the very
*   least, this will always default to /.
* - $directory: The directory the template is located in, e.g. modules/system
*   or themes/bartik.
* - $is_front: TRUE if the current page is the front page.
* - $logged_in: TRUE if the user is registered and signed in.
* - $is_admin: TRUE if the user has permission to access administration pages.
*
* Site identity:
* - $front_page: The URL of the front page. Use this instead of $base_path,
*   when linking to the front page. This includes the language domain or
*   prefix.
* - $logo: The path to the logo image, as defined in theme configuration.
* - $site_name: The name of the site, empty when display has been disabled
*   in theme settings.
* - $site_slogan: The slogan of the site, empty when display has been disabled
*   in theme settings.
*
* Navigation:
* - $main_menu (array): An array containing the Main menu links for the
*   site, if they have been configured.
* - $secondary_menu (array): An array containing the Secondary menu links for
*   the site, if they have been configured.
* - $breadcrumb: The breadcrumb trail for the current page.
*
* Page content (in order of occurrence in the default page.tpl.php):
* - $title_prefix (array): An array containing additional output populated by
*   modules, intended to be displayed in front of the main title tag that
*   appears in the template.
* - $title: The page title, for use in the actual HTML content.
* - $title_suffix (array): An array containing additional output populated by
*   modules, intended to be displayed after the main title tag that appears in
*   the template.
* - $messages: HTML for status and error messages. Should be displayed
*   prominently.
* - $tabs (array): Tabs linking to any sub-pages beneath the current page
*   (e.g., the view and edit tabs when displaying a node).
* - $action_links (array): Actions local to the page, such as 'Add menu' on the
*   menu administration interface.
* - $feed_icons: A string of all feed icons for the current page.
* - $node: The node object, if there is an automatically-loaded node
*   associated with the page, and the node ID is the second argument
*   in the page's path (e.g. node/12345 and node/12345/revisions, but not
*   comment/reply/12345).
*
* Regions:
* - $page['help']: Dynamic help text, mostly for admin pages.
* - $page['highlighted']: Items for the highlighted content region.
* - $page['content']: The main content of the current page.
* - $page['sidebar_first']: Items for the first sidebar.
* - $page['sidebar_second']: Items for the second sidebar.
* - $page['header']: Items for the header region.
* - $page['footer']: Items for the footer region.
*
* @see bootstrap_preprocess_page()
* @see template_preprocess()
* @see template_preprocess_page()
* @see bootstrap_process_page()
* @see template_process()
* @see html.tpl.php
*
* @ingroup themeable
*/
?>
<?php $block_language = module_invoke('locale', 'block_view', 'language'); ?>
<?php global $_domain, $theme_path, $base_url; ?>
<?php if ($_domain['domain_id'] == 1): ?>
    <script async>(function(s,u,m,o,j,v){j=u.createElement(m);v=u.getElementsByTagName(m)[0];j.async=1;j.src=o;j.dataset.sumoSiteId='4e362358e23874bb5aaf766e8b37533605b209a7bef67a95ce8244d4f23ad645';v.parentNode.insertBefore(j,v)})(window,document,'script','//load.sumo.com/');</script>
<?php endif; ?>
<?php $path_to_theme = $base_url.'/'.$theme_path;
$serverHost = strval($_SERVER['HTTP_HOST']); ?>
<div class="row">
	<div class="col-xs-12 tablet-top-bar visible-sm-* visible-xs-* hidden-md hidden-lg">
      <div id="countryselecdt-tablet" class="countryselecdt lower">
        <label for="op">
          <i class="fa fa-globe"></i>
          <div class="curr-domain">

            <?php if ($_domain['domain_id'] == 1){
            	echo "AUS";
            } elseif ($_domain['domain_id'] == 2){
            	echo "SG";
            } elseif($_domain['domain_id'] == 3){
            	echo "NZ";
            } else {
            	echo "AUS";
            }
            ?>
          </div>
        </label>
      </div>
    </div>
</div>
<?php if ($_domain['domain_id'] == 1): ?>

<?php elseif ($_domain['domain_id'] == 3) : ?>
    <!--div class="container-fluid top-banner-container">
        <div class="container">
            <div class="row top-banner">
                <a href="https://offers.dermaltherapy.com.au/new-zeala" target="_blank">
                    <img src="<?php print $path_to_theme; ?>/images/nz-top-banner--desktop-ok.jpg" class="big-banner">
                    <img src="<?php print $path_to_theme; ?>/images/nz-top-banner--mobile.jpg" class="small-banner">
                </a>
            </div>
        </div>
    </div-->
<?php endif; ?>

<div class="container-fluid header-fluid">
	<header id="navbar" role="banner" class="<?php print $navbar_classes; ?>">
		<div class="container">
		  <div class="row">
			<div class="col-xs-4 hamburger-menu">
			  <!-- .btn-navbar is used as the toggle for collapsed navbar content -->
			  <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
				<div style="float: left; padding-top: 2px;">
				  <span class="sr-only">Toggle navigation</span>
				  <span class="icon-bar"></span>
				  <span class="icon-bar"></span>
				  <span class="icon-bar"></span>
				</div>
				<div style="float: right;"><span class="menu-label"><?php print t("Menu")?></span></div>

			  </button>
			</div>
			<div class="col-xs-4 tablet-logo">
			  <?php if ($logo): ?>
				<a class="logo navbar-btn" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
				  <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
				</a>
			  <?php endif; ?>
			</div>
			<div class="col-xs-4 top-icons">
			  	<?php print render($page['headerright']); ?>
				<?php global $base_url; ?>
				<input type="checkbox" id="op"></input>
					<div id="countryselecdt-dsktop" class="countryselecdt lower">
						<label for="op">
							<i class="fa fa-globe"></i>
							<div class="curr-domain">
						        <?php if ($_domain['domain_id'] == 1){
					            	echo "AUS";
					            } elseif ($_domain['domain_id'] == 2){
					            	echo "SG";
					            } elseif ($_domain['domain_id'] == 3){
					            	echo "NZ";
					            }  else {
					            	echo "AUS";
					            }?>
		            		</div>
					    </label>
					</div>
					<a href="https://www.youtube.com/channel/UCu72syrSnOcHoEifAZWR-kA/videos" target="_blank"><i class="fa fa-youtube"></i></a>
					<?php if ($_domain['domain_id'] == 2) {
						echo '<a href="https://www.facebook.com/dermaltherapysg" target="_blank"><i class="fa fa-facebook"></i></a>';
						echo '<a href="https://www.instagram.com/dermaltherapysingapore/" target="_blank"><i class="fa fa-instagram"></i></a>';
					} elseif ($_domain['domain_id'] == 1) {
						echo '<a href="https://www.facebook.com/DermalTherapy/" target="_blank"><i class="fa fa-facebook"></i></a>';
						echo '<a href="https://www.instagram.com/dermaltherapy/" target="_blank"><i class="fa fa-instagram"></i></a>';
					} else {
						echo '<a href="https://www.facebook.com/DermalTherapy/" target="_blank"><i class="fa fa-facebook"></i></a>';
						echo '<a href="https://www.instagram.com/dermaltherapy/" target="_blank"><i class="fa fa-instagram"></i></a>';
					}

					?>
			<!--  <a href="#"><span class="header-icon header-icon-world"></span></a> -->
			  <a class="searchicon" href="#"><i class="fa fa-search"></i></a>
			  <div class="sblock"><?php $search_form = drupal_get_form('search_block_form'); print render($search_form);?>

			  </div>
				<?php include 'overlay.tpl.php'; ?>
			  <!-- <div id="countryselecdt-dsktop"class="countryselecdt"> -->
				<?php // echo $country_menu; ?>
				<!-- </div> -->
				<?php // print '<div id="language-switcher-dsktop" class="language-switcher-block">'.$block_language['content'].'</div>'; ?>
			</div>


				<div class="col-xs-12 mobile-logo">
				  <?php if ($logo): ?>
					<a class="logo navbar-btn" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
					  <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
					</a>
				  <?php endif; ?>
				</div>
		  </div>
		  <div class="navbar-header">
		  </div>

		  <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
			<div class="navbar-collapse collapse">
			  <nav role="navigation">
				<?php if (!empty($primary_nav)): ?>
				  <?php print render($primary_nav); ?>
				<?php endif; ?>
			  </nav>
			</div>
		  <?php endif; ?>
		</div>

	</header>
</div>

<div class="container-fluid main-fluid" >
<div class="main-container">

	<header role="banner" id="page-header" class="container">
	  <?php if (!empty($site_slogan)): ?>
		<p class="lead"><?php print $site_slogan; ?></p>
	  <?php endif; ?>
	  <?php if (!empty($breadcrumb)): print $breadcrumb; endif;?>

	  <?php print render($page['header']); ?>
	</header> <!-- /#page-header -->

<div id="content-wrapper">
  <div class="container">
	<div class="row <?php print $content_container_class; ?>">

	  <?php if (!empty($page['sidebar_first'])): ?>
		<aside class="<?php print $sidebar_first_class?>" role="complementary">
		  <?php print render($page['sidebar_first']); ?>
		</aside>  <!-- /#sidebar-first -->
	  <?php endif; ?>

	  <section class="content-column <?php print $content_column_class; ?>">
		<?php if (!empty($page['highlighted'])): ?>
		  <div class="highlighted jumbotron"><?php print render($page['highlighted']); ?></div>
		<?php endif; ?>
		<a id="main-content"></a>
		<?php print $messages; ?>
		<?php if (!empty($tabs)): ?>
		  <?php print render($tabs); ?>
		<?php endif; ?>
		<?php if (!empty($page['help'])): ?>
		  <?php print render($page['help']); ?>
		<?php endif; ?>
		<?php if (!empty($action_links)): ?>
		  <ul class="action-links"><?php print render($action_links); ?></ul>
		<?php endif; ?>
		<?php print render($page['content']); ?>
	  </section>

	  <?php if (!empty($page['sidebar_second'])): ?>
		<aside class="col-sm-3" role="complementary">
		  <?php print render($page['sidebar_second']); ?>
		</aside>  <!-- /#sidebar-second -->
	  <?php endif; ?>
	</div>

	  <?php if (!empty($page['content_bottom'])): ?>
		<div class="row">
			<section class="col-sm-12">
			  <?php print render($page['content_bottom']); ?>
			</section>
		</div>
	  <?php endif; ?>
  </div>
</div>
</div>
</div>

<?php if (!empty($page['content_secondary'])): ?>
<div class="container-fluid content-secondary-fluid">
<div class="content-secondary container">
<?php print render($page['content_secondary']); ?>
</div>
</div>
<?php endif; ?>

<?php if (!empty($page['content_tertiary'])): ?>
<div class="container-fluid content-tertiary-fluid">
<div class="content-tertiary container">
  <?php print render($page['content_tertiary']); ?>
</div>
</div>
<?php endif; ?>

<div class="container-fluid footer-fluid">
  <footer class="footer container no-padding">
    <?php print render($page['footer']); ?>
    <div class="col-xs-12 col-sm-3 no-padding-left">
			<a href="https://www.youtube.com/channel/UCu72syrSnOcHoEifAZWR-kA/videos" target="_blank"><i class="fa fa-youtube"></i></a>

      <?php if ($_domain['domain_id'] == 1):  ?>
        <!-- <div class="social twitter"><a href="https://www.twitter.com/FlexitolCanada/" target="_blank"><i class="fa fa-twitter"></i></a></div>-->
        <a href="https://www.instagram.com/dermaltherapy/" target="_blank"><i class="fa fa-instagram"></i></a>
        <a href="https://www.facebook.com/DermalTherapy/" target="_blank"><i class="fa fa-facebook"></i></a>


      <?php elseif ($_domain['domain_id'] == 2):  ?>
			<a href="https://www.instagram.com/dermaltherapysingapore/" target="_blank"><i class="fa fa-instagram"></i></a>
      	<a href="https://www.facebook.com/dermaltherapysg" target="_blank"><i class="fa fa-facebook"></i></a>


      <?php else:  ?>

        <a href="https://www.instagram.com/dermaltherapy/" target="_blank"><i class="fa fa-instagram"></i></a>
        <a href="https://www.facebook.com/DermalTherapy/" target="_blank"><i class="fa fa-facebook"></i></a>

      <?php endif; ?>
    </div>
  </footer>
</div>
