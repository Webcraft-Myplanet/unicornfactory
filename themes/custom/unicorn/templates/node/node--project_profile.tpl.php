<?php

/**
 * @file
 * Default theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct URL of the current node.
 * - $display_submitted: Whether submission information should be displayed.
 * - $submitted: Submission information created from $name and $date during
 *   template_preprocess_node().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type; for example, "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type; for example, story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode; for example, "full", "teaser".
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined; for example, $node->body becomes $body. When needing to
 * access a field's raw values, developers/themers are strongly encouraged to
 * use these variables. Otherwise they will have to explicitly specify the
 * desired field language; for example, $node->body['en'], thus overriding any
 * language negotiation rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>
<div ng-controller="ProjectProfileCtrl" ng-init="nid = <?php print $nid ?>; uid = <?php print $user->uid ?>" id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <section class="container-fluid">
    <div class="row">
      <div class="projectName">
        <h2 editable-text="page.title" buttons="no" onaftersave="updateProject()">{{page.title}}</h2>
      </div>
      <div class="projectLogo col-lg-4" ng-bind-html="page.field_avatar.und[0].html"></div>

      <div class="col-lg-8">
        <div class="project_dates">
          <span onaftersave="updateProject()" editable-bsdate="page.field_start_date.und[0].value.date" e-datepicker-popup="MMM d, yyyy">
            {{ (page.field_start_date.und[0].value.date | date:"MMM d, yyyy") }}
          </span>
          -
          <span onaftersave="updateProject()" editable-bsdate="page.field_start_date.und[0].value2.date" e-datepicker-popup="MMM d, yyyy">
            {{ (page.field_start_date.und[0].value2.date | date:"MMM d, yyyy") }}
          </span>
        </div>
        <div e-ng-options="status for status in options.field_status" editable-radiolist="page.field_status.und" buttons="no" onaftersave="updateProject()">{{page.field_status.und}}</div>
        <div onaftersave="updateProject()" class="projectDesc" editable-textarea="page.body.und[0].value" e-rows="7" e-cols="40">
          {{page.body.und[0].value}}
        </div>
      </div>
    </div>

    <hr>

    <div class="projectPpl row">
      <h3 class="col-lg-3">People: </h3>
      <ul style="list-style: none">
        <li ng-repeat="num in [1,2,3,4]" class="col-lg-2">
          <div class="people-thumb col-lg-4" ng-bind-html="page.field_avatar.und[0].html"></div>
        </li>
      </ul>
    </div>
    <br>
    <hr>
    <br>
    <div class="projectTeams row">
      <h3 class="col-lg-3">Teams: </h3>
      <ul style="list-style: none">
        <li ng-repeat="num in [1,2,3,4]" class="col-lg-2">
          <div class="people-thumb col-lg-4" ng-bind-html="page.field_avatar.und[0].html"></div>
        </li>
      </ul>
    </div>
    <br>
    <hr>

    <div class="row">
      <div class="projectSkills col-lg-6">
        <h3>Skills: </h3>
        <ul class="row">
          <li ng-repeat="skill in page.field_skill.und">
            <span e-typeahead="skill for skill in options.field_skill | filter:$viewValue | limitTo:8" editable-text="skill" onaftersave="updateProject()" onbeforesave="validateSkill($data)">{{skill}}</span>
          </li>
          <li>
            <span e-typeahead="skill for skill in options.field_skill | filter:$viewValue | limitTo:8" editable-text="newSkill" onaftersave="addSkill()" onbeforesave="validateSkill($data)">+ Add another</span>
          </li>
        </ul>
      </div>
      <div class="projectInt col-lg-6">
        <h3>Interested: </h3>
        <ul class="row">
          <li><a href="">Seb</a></li>
          <li><a href="">Anne</a></li>
          <li><a href="">Teresa</a></li>
          <li><a href="">Luis</a></li>
        </ul>
        <a href="#" class="btn btn-default btn-lg" role="button">Sign Me Up!</a>
      </div>
    </div>

  </section>
</div>


