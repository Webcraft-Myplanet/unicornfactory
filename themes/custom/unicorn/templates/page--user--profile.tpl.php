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
<div id="wrap">
  <header id="navbar" role="banner" class="<?php print $navbar_classes; ?>">
    <div class="container">
      
      <div class="navbar-header">
        <?php if ($logo): ?>
        <a class="logo navbar-btn pull-left" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
          <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
        </a>
        <?php endif; ?>

        <?php if (!empty($site_name)): ?>
          <a class="name navbar-brand" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>"><?php print $site_name; ?></a>
        <?php endif; ?>

        <!-- .btn-navbar is used as the toggle for collapsed navbar content -->
        <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
          <span class="sr-only">Toggle navigation</span>
          <span class="icon-bar"></span>
          <span class="icon-bar"></span>
          <span class="icon-bar"></span>
        </button>
      </div>

      <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
        <div class="navbar-collapse collapse">
          <nav role="navigation">
            <?php if (!empty($primary_nav)): ?>
              <?php print render($primary_nav); ?>
            <?php endif; ?>
            <?php if (!empty($secondary_nav)): ?>
              <?php print render($secondary_nav); ?>
            <?php endif; ?>
            <?php if (!empty($page['navigation'])): ?>
              <?php print render($page['navigation']); ?>
            <?php endif; ?>
          </nav>
        </div>
      <?php endif; ?>
    </div>
  </header>

  <div class="main-container container-fluid">

    <header role="banner" id="page-header">
      <?php if (!empty($site_slogan)): ?>
        <p class="lead"><?php print $site_slogan; ?></p>
      <?php endif; ?>

      <?php print render($page['header']); ?>
    </header> <!-- /#page-header -->
    
    <?php if (!empty($page['sidebar_first'])): ?>
      <aside class="col-sm-3" role="complementary">
        <?php print render($page['sidebar_first']); ?>
      </aside>  <!-- /#sidebar-first -->
    <?php endif; ?>
      <section<?php print $content_column_class; ?> ng-controller="UserProfileCtrl" ng-init="uid = <?php print $page['content']['system_main']["#account"]->uid ?> ">
        <div class="col-xs-2 left_sidebar">
          <?php print render($title_prefix); ?>
          <?php if (!empty($title)): ?>
            <h1 class="page_header"><?php print $title; ?></h1>
          <?php endif; ?>
          <?php print render($title_suffix); ?>
          <!-- personal info div containing avatar, name and current team status -->
          <section id="info_teams" class="col-xs-12">
            <div>
              <!-- Avatar -->
              <div class="personal_avatar col-md-12 text-center">
                <div ng-bind-html="page.picture.html"></div>
              </div>
              <!-- leaving picture out of form for editing personal info for now -->
                <div class="name_status col-xs-12 text-center">
                  <p>{{page.mail}}</p>
                    <!-- The following ng-show/ng-hide depend on value of Slogan.
                    if Slogan is defined it will display, otherwise a link to add a slogan. -->
                    <div><p>{{page.field_slogan.und[0].value}}</p></div>
                  </div>
                  <div class="personal_social row">
                    <ul class="social_network">
                      <li class="col-xs-3" ng-show="page.field_facebook.und[0].value">
                        <a href="https://www.facebook.com/{{page.field_facebook.und[0].value}}" title="Facebook">
                          <i class="fa fa-facebook-square fa-3x"></i>
                        </a>
                      </li>
                      <li class="col-xs-3" ng-show="page.field_twitter.und[0].value">
                        <a href="https://twitter.com/{{page.field_twitter.und[0].value}}" title="Twitter">
                          <i class="fa fa-twitter-square fa-3x"></i>
                        </a>
                      </li>
                      <li class="col-xs-3" ng-show="page.field_github.und[0].value">
                        <a href="http://github.com/{{page.field_github.und[0].value}}" title="GitHub">
                          <i class="fa fa-github-square fa-3x"></i>
                        </a>
                      </li>
                      <li class="col-xs-3" ng-show="page.field_linkedin.und[0].url" title="LinkedIn">
                        <a href="{{page.field_linkedin.und[0].url}}">
                          <i class="fa fa-linkedin-square fa-3x"></i>
                        </a>
                      </li>
                    </ul>
                  </div>
             </div><!--end row-->
             <!-- Teams -->
             <hr>
             <div class="row">
              <h2 class="col-xs-4">Teams</h2><br><br>
              <p ng-show="page.related_teams.length == 0">This user is not a member of any teams... yet!</p>
              <div class="col-xs-10 col-centered" ng-repeat="team in page.related_teams">
                <button type="button" class="btn btn-default" id="team_button"><a href="/node/{{team.nid}}">{{team.name}}</a></button><br>
              </div>
            </div>
          </section>
        </div>
        <?php if (!empty($page['highlighted'])): ?>
          <div class="highlighted jumbotron"><?php print render($page['highlighted']); ?></div>
        <?php endif; ?>
        <?php if (!empty($breadcrumb)): print $breadcrumb; endif;?>
        <a id="main-content"></a>
        <?php print $messages; ?>
        <?php if (!empty($page['help'])): ?>
          <?php print render($page['help']); ?>
        <?php endif; ?>
        <?php if (!empty($action_links)): ?>
          <ul class="action-links"><?php print render($action_links); ?></ul>
        <?php endif; ?>
        <?php if (!empty($tabs)): ?>
          <?php print render($tabs); ?>
        <?php endif; ?>
        <?php print render($page['content']); ?>
      </section>

      <?php if (!empty($page['sidebar_second'])): ?>
        <aside class="col-sm-3" role="complementary">
          <?php print render($page['sidebar_second']); ?>
        </aside>  <!-- /#sidebar-second -->
      <?php endif; ?>

    </div>
  </div>
</div>

<div id="footer">
  <div class="container">
    <?php print render($page['footer']); ?>
  </div>
</div>