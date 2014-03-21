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
  <section ng-controller="ProjectsCtrl" id="<?php print $block_html_id; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
      <div class="col-xs-2" filters-wrapper>
        <fieldset>
          <legend>Sort Options</legend>
          <form ng-model="sort" title="Sort Options" ng-selected="">
            <input type="radio" ng-model="sort" id="proj_default" value="" ng-value=""><label for="proj_default">default</label><br/>
            <input type="radio" ng-model="sort" id="proj_alpha" value="title"><label for="proj_alpha">Alphabetical</label><br/>
            <input type="radio" ng-model="sort" id="proj_startDate" value="startDate"><label for="proj_startDate">Start Date</label><br/>
            <input type="radio" ng-model="sort" id="proj_endDate" value="endDate"><label for="proj_endDate">End Date</label><br/>
          </form>
        </fieldset>
        <fieldset>
        <legend>Project Status:</legend>
          <form ng-model="filter" title="Project Status Filter" ng-selected="">
            <input type="radio" ng-model="filter" id="proj_all" value="" ng-value=""><label for="proj_all">all projects</label><br/>
            <input type="radio" ng-model="filter" id="proj_active" value="Active"><label for="proj_active">Active</label><br/>
            <input type="radio" ng-model="filter" id="proj_maybe" value="Potential"><label for="proj_maybe">Potential</label><br/>
          </form>
        </fieldset>
        <label for="skill_filter">Filter by skill:</label><br/>
        <input type="text" id="skill_filter" ng-model="skillSearch" placeholder="Skills" title="Skills Filter">
      </div>
    <div class="col-xs-10 list-wrapper">
      <div class="col-xs-6" ng-repeat="project in page.projects | orderBy:sort | filter:filter | filter:skillSearch">        
      <accordion>
        <accordion-group is-open="isopen">
            <accordion-heading>
              {{project.title}}<i class="pull-right glyphicon" ng-class="{'glyphicon-chevron-up': isopen, 'glyphicon-chevron-down': !isopen}"></i>
            </accordion-heading>
            <div class="pull-left" ng-bind-html="project.logo" alt="{{project.title}}"></div>
            <p>{{project.status}}</p>
            <p ng-bind-html="project.description"></p>
            <p ng-show="project.startDate">{{project.startDate}} - {{project.endDate}}</p>
            <p ng-hide="project.startDate">No starting date</p>
            <p>{{project.skills.length >5 ? project.skills.slice(0,5).join(", ") + " ..." : project.skills.slice(0,5).join(", ")}}</p>
            <a ng-href="/node/{{project.nid}}" class="pull-right"> View {{project.title}}</a>
        </accordion-group>
      </accordion>
      </div>
    </div>
</section> <!-- /.block -->
<?php endif;?>
