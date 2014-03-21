<?php
/**
 * @file
 * Default theme implementation to display a block.
 *
 * Available variables:
 * - $block->subject: Block title.
 * - $content: Block content.
 * - $block->module: Module that generated the block.
 * - $block->delta: An ID for the block, unique within each module.
 * - $block->region: The block region embedding the current block.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - block: The current template type, i.e., "theming hook".
 *   - block-[module]: The module generating the block. For example, the user
 *     module is responsible for handling the default user navigation block. In
 *     that case the class would be 'block-user'.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Helper variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $block_zebra: Outputs 'odd' and 'even' dependent on each block region.
 * - $zebra: Same output as $block_zebra but independent of any block region.
 * - $block_id: Counter dependent on each block region.
 * - $id: Same output as $block_id but independent of any block region.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 * - $block_html_id: A valid HTML ID and guaranteed unique.
 *
 * @see bootstrap_preprocess_block()
 * @see template_preprocess()
 * @see template_preprocess_block()
 * @see bootstrap_process_block()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>
<?php if ($logged_in): ?>
  <section ng-controller="TeamsCtrl" id="<?php print $block_html_id; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

    <div class="row">
      <div class="col-xs-2 filters-wrapper">
        <fieldset>
          <legend>Sort Options</legend>
          <form ng-model="sort" title="Sort Options" value="" ng-selected="">
            <input type="radio" ng-model="sort" id="team_unsorted" value="" ng-value=""><label for="team_unsorted">default</label><br/>
            <input type="radio" ng-model="sort" id="team_alpha" value="name"><label for="team_alpha">Alphabetical</label><br/>
            <input type="radio" ng-model="sort" id="team_reverse" value="-name" ><label for="team_reverse">Reverse Alpha</label><br/>
          </form>
        </fieldset>
      </div>
    <div class="col-xs-10 list-wrapper">
      <accordion close-others"oneAtATime">
        <div class="team col-xs-6" ng-repeat="team in page.teams | orderBy:sort">
            <accordion-group is-open="isopen">
              <accordion-heading>
                <a href="#team{{team.nid}}" id="team{{team.nid}}">{{team.name}}</a><i class="pull-right glyphicon" ng-class="{'glyphicon-chevron-up': isopen, 'glyphicon-chevron-down': !isopen}"></i> 
              </accordion-heading>
              <div class="pull-left" ng-bind-html="team.profilePicture" alt="{{team.name}}"></div>
              <p ng-bind-html="team.slogan"></p>
              <p>Team Working:</p><p ng-bind-html="team.working"></p>
              <a ng-href="/node/{{team.nid}}" class="pull-right">{{team.name}}'s Profile</a>
            </accordion-group>
            </div>
          </accordion>
        </div>
    </div>
        
  </section> <!-- /.block -->
<?php endif;?>
