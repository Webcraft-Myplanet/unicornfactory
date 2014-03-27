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
  <a class="sr-only" href="/projects">Skip to Projects page</a>
  <section ng-controller="ProjectsTimelineCtrl" id="<?php print $block_html_id; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="row filters-wrapper">
      <div class="col-xs-3 col-xs-offset-1">
        <select ng-model="sort" class="form-control" title="Sort Options" value="">
          <option value="name">Sorted by Name</option>
          <option value="date">Sorted by Date</option>
        </select>
    </div>
    <div class="col-xs-3">
      <select ng-model="filter" class="form-control" title="Project Status Filter" value="">
        <option value="All">All Projects</option> 
        <option value="Active">Active</option>
        <option value="Potential">Potential</option>
      </select>
    </div>
    <button ng-click="centerDate()" id="scrollTodayBtn" class="btn btn-default" type="button">Scroll to Today</button>
  </div>
  <div class="row list-wrapper"><gantt data="page.gantt"
    							allow-task-moving="false"
    							allow-task-resizing="false"
    							allow-row-sorting="false"
    							center-date="scrollToToday = fn"
    							sort-mode="sort"
    							filter-status="filter"
    							view-scale="month"
    							column-width="15"></gantt></div>

  </section> <!-- /.block -->
<?php endif;?>
