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
<div ng-controller="TeamProfileCtrl" ng-init="nid = <?php print $nid ?>; uid = <?php print $user->uid ?>" id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <section class="container-fluid">
    <div class="row">
        <div class="teamLogo col-xs-4" alt="{{page.title}}"><?php print $field_avatar[0]['html']; ?></div>
        

        <div class="col-xs-8">
          <p>Slogan: {{page.field_slogan.und[0].value}}</p>
          <p>Location: {{page.field_location.und[0].value}}</p>
        </div>
    </div>

    <hr>

    <div class="projectPpl row">
      <h2 class="col-xs-3">People: </h2>
      <p ng-show="page.related_users.length == 0">No one belongs to this team.</p>
      <ul style="list-style: none" ng-show="page.related_users.length > 0">
        <li ng-repeat="person in page.related_users" class="col-xs-2">
          <a href="/user/{{person.uid}}" title="{{person.name}}">
            <div class="people-thumb col-xs-4" ng-bind-html="person.avatar" alt="{{project.name}}"></div>
          </a>
        </li>
      </ul>
    </div>
    <br>
    <hr>
    <br>
    <div class="projectTeams row">
      <h2 class="col-xs-3">Projects: </h2>
      <p ng-show="page.related_projects.length == 0">This team isn't working on any projects.</p>
      <ul style="list-style: none" ng-show="page.related_projects.length > 0">
        <li ng-repeat="project in page.related_projects" class="col-xs-2">
          <a href="/node/{{project.nid}}" title="{{project.name}}">
            <div class="people-thumb col-xs-4" ng-bind-html="project.avatar" alt="{{project.name}}"></div>
          </a>
        </li>
      </ul>
    </div>
    <br>
    <hr>

<!-- dynamic skills section with accordion fold -->
  <section id="skills" class="container-fluid">
    <!-- static header -->
    <div class="row common_title">
      <div id="skills_header" class="row">
        <h2 class="col-xs-8">Skills</h2>
        <ul class="col-xs-4" ng-show="page.skills_composite.0.name">
          <!-- This is currently hard-coded, obviously we'd like to set these dynamically according to skill levels -->
          <li class="small" ng-repeat="skill in page.skills_composite | orderBy: '-current'| limitTo: 1">The team's highest level skill is: {{skill.name}}</li>
          <li class="small" ng-repeat="skill in page.skills_composite | orderBy: '-desired'| limitTo: 1">The team's most desirable skill is: {{skill.name}}</li>
        </ul>
      </div>
    </div>

    <hr>

    <!-- skills -->
    <div class="row">
      <p ng-show="!page.skills_composite.0.name">This team has no skills... yet!</p>
      <dl ng-show="page.skills_composite.0.name !== ''">
        <div id="top3" class="row" ng-repeat="skill in page.skills_composite | orderBy: '-current' | limitTo: 3">
          <dt class="skill_name col-xs-2">{{skill.name}} ({{skill.count}})</dt>
          <dd>
            <div class="progress col-xs-10 base_bar">
              <div class="progress-bar pbcurrent" style="width: {{skill.current * 10}}%" popover="Current Skill Level: {{skill.current}}" popover-trigger="mouseenter"></div>
              <div class="progress-bar pbdesired" style="width: {{(skill.desired - skill.current) * 10}}%" popover="Desired Skill Level: {{skill.desired}}" popover-trigger="mouseenter"></div>
            </div>
            <p class="sr-only">Current Skill Level: {{skill.current}}</p>
            <p class="sr-only">Desired Skill Level: {{skill.desired}}</p>
          </dd>
        </div>
      </dl>
    </div>
    <div ng-show="page.skills_composite.length > 3">
      <accordion>
        <accordion-group is-open="isopen">
            <accordion-heading >
              <h3 class="inline-heading"><a href="#moreskills" id="moreskills">More Skills</a></h3><i class="pull-right glyphicon" ng-class="{'glyphicon-chevron-down': isopen, 'glyphicon-chevron-right': !isopen}"></i></a>
            </accordion-heading>
            <dl>
              <div class="low_skills row col-xs-12" ng-repeat="skill in page.skills_composite | orderBy:'current' | limitTo: (page.skills_composite.length -3) | orderBy:'-current'">
                <dt class="skill_name col-xs-2">{{skill.name}} ({{skill.count}})</dt>
                <dd>
                  <div class="progress col-xs-10 base_bar">
                    <div class="progress-bar pbcurrent" style="width: {{skill.current * 10}}%" popover="Current Skill Level: {{skill.current}}" popover-trigger="mouseenter"></div>
                    <div class="progress-bar pbdesired" style="width: {{(skill.desired - skill.current) * 10}}%" popover="Desired Skill Level: {{skill.desired}}" popover-trigger="mouseenter"></div>
                    <p class="sr-only">Current Skill Level: {{skill.current}}</p>
                    <p class="sr-only">Desired Skill Level: {{skill.desired}}</p>
                  </div>
                </dd>
              </div>
            </dl>
        </accordion-group>
      </accordion>
    </div>

    <!-- Skills Legend -->
    <div class="row">
      <div id="skill_legend">
        <h3 class="skill_name col-sm-2">Skill Guide</h3>
        <div class="sr-only">
          <ul>
            <li>Level 1: Little to no knowledge</li>
            <li>Level 2: Beginner Skill Level</li>
            <li>Level 3: Limited Knowledge</li>
            <li>Level 4: Competent User</li>
            <li>Level 5: Team Contributor</li>
            <li>Level 6: Team Leader</li>
            <li>Level 7: Myplanet Contributor</li>
            <li>Level 8: Myplanet Leader</li>
            <li>Level 9: Industry Contributor</li>
            <li>Level 10: Industry Leader</li>
          </ul>
        </div>
        <div class="progress" id="legend">
          <div class="progress-bar guidebar" style="width: 10%" popover="Little to no knowledge" popover-trigger="mouseenter"><span>1</span></div>
          <div class="progress-bar guidebar" style="width: 10%" popover="Beginner Skill Level" popover-trigger="mouseenter"><span>2</span></div>
          <div class="progress-bar guidebar" style="width: 10%" popover="Limited Knowledge" popover-trigger="mouseenter"><span>3</span></div>
          <div class="progress-bar guidebar" style="width: 10%" popover="Competent User" popover-trigger="mouseenter"><span>4</span></div>
          <div class="progress-bar guidebar" style="width: 10%" popover="Team Contributor" popover-trigger="mouseenter"><span>5</span></div>
          <div class="progress-bar guidebar" style="width: 10%" popover="Team Leader" popover-trigger="mouseenter"><span>6</span></div>
          <div class="progress-bar guidebar" style="width: 10%" popover="Myplanet Contributor" popover-trigger="mouseenter"><span>7</span></div>
          <div class="progress-bar guidebar" style="width: 10%" popover="Myplanet Leader" popover-trigger="mouseenter"><span>8</span></div>
          <div class="progress-bar guidebar" style="width: 10%" popover="Industry Contributor" popover-trigger="mouseenter"><span>9</span></div>
          <div class="progress-bar guidebar" style="width: 10%" popover="Industry Leader (El Jefe!)" popover-trigger="mouseenter"><span>10</span></div>
        </div>
      </div>
    </div>

  </section>
</div>
