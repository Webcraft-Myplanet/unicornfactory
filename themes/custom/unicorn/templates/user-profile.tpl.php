<section ng-controller="UserProfileCtrl" ng-init="uid = <?php print $elements["#account"]->uid ?> " id="wrapper" class="fluid-container">

  <!-- personal info div containing avatar, name and current team status -->
  <section>
    <div class="row">
      <!-- Avatar -->
      <div class="personal_avatar col-xs-4">
        <div><?php print $variables['user_profile']['user_picture']['#markup']; ?></div>
      </div>
      <!-- leaving picture out of form for editing personal info for now -->
        <div class="name_status col-xs-4">
          <p>{{page.mail}}</p>
            <!-- The following ng-show/ng-hide depend on value of Slogan.
            if Slogan is defined it will display, otherwise a link to add a slogan. -->
            <div><p>{{page.field_slogan.und[0].value}}</p></div>
          </div>
          <div class="personal_social col-xs-4">
            <ul class="social_network row">
              <li class="col-xs-3" ng-show="page.field_facebook.und[0].value">
                <a href="https://www.facebook.com/{{page.field_facebook.und[0].value}}">
                  <img src="/profiles/skeletor/themes/custom/unicorn/images/facebook-icon.png" alt="Facebook" width="50" />
                </a>
              </li>
              <li class="col-xs-3" ng-show="page.field_twitter.und[0].value">
                <a href="https://twitter.com/{{page.field_twitter.und[0].value}}">
                  <img src="/profiles/skeletor/themes/custom/unicorn/images/Twitter-icon.png" alt="Twitter" width="50" />
                </a>
              </li>
              <li class="col-xs-3" ng-show="page.field_github.und[0].value">
                <a href="http://github.com/{{page.field_github.und[0].value}}">
                  <img src="/profiles/skeletor/themes/custom/unicorn/images/github-logo.png" alt="GitHub" width="50" />
                </a>
              </li>
              <li class="col-xs-3" ng-show="page.field_linkedin.und[0].url">
                <a href="{{page.field_linkedin.und[0].url}}">
                  <img src="/profiles/skeletor/themes/custom/unicorn/images/LinkedIn-icon.png" alt="LinkedIn" width="50" />
                </a>
              </li>
            </ul>
          </div>
     </div><!--end row-->
     <!-- Teams -->
     <hr>
     <div class="row">
      <h2 class="col-xs-4">Teams</h2>
      <div class="col-xs-4" ng-repeat="team in page.related_teams">
        <button type="button" class="btn btn-default"><a href="/node/{{team.nid}}">{{team.name}}</a></button>
      </div>
    </div>
  </section>

  <hr>

  <!-- dynamic skills section with accordion fold -->
  <section id="skills" class="container-fluid">
    <!-- static header -->
    <div class="row common_title">
      <div id="skills_header" class="row">
        <h2 class="col-xs-8">Skills</h2>
        <ul class="col-xs-4">
          <!-- This is currently hard-coded, obviously we'd like to set these dynamically according to skill levels -->
          <li class="small" ng-repeat="skill in page.skills | orderBy: '-current'| limitTo: 1">My highest level skill is: {{skill.name}}</li>
          <li class="small" ng-repeat="skill in page.skills | orderBy: '-desired'| limitTo: 1">My most desireable skill is: {{skill.name}}</li>
        </ul>
      </div>
    </div>

    <hr>

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
          <div class="progress-bar progress-bar-primary" style="width: 10%" popover="Little to no knowledge" popover-trigger="mouseenter"><div class="glyphicon glyphicon-trash"></div></div>
          <div class="progress-bar progress-bar-primary" style="width: 10%" popover="Beginner Skill Level" popover-trigger="mouseenter"><div class="glyphicon glyphicon-thumbs-down"></div></div>
          <div class="progress-bar progress-bar-primary" style="width: 10%" popover="Limited Knowledge" popover-trigger="mouseenter"><div class="glyphicon glyphicon-bullhorn"></div></div>
          <div class="progress-bar progress-bar-primary" style="width: 10%" popover="Competent User" popover-trigger="mouseenter"><div class="glyphicon glyphicon-paperclip"></div></div>
          <div class="progress-bar progress-bar-primary" style="width: 10%" popover="Team Contributor" popover-trigger="mouseenter"><div class="glyphicon glyphicon-bell"></div></div>
          <div class="progress-bar progress-bar-primary" style="width: 10%" popover="Team Leader" popover-trigger="mouseenter"><div class="glyphicon glyphicon-pushpin"></div></div>
          <div class="progress-bar progress-bar-primary" style="width: 10%" popover="Myplanet Contributor" popover-trigger="mouseenter"><div class="glyphicon glyphicon-tree-conifer"></div></div>
          <div class="progress-bar progress-bar-primary" style="width: 10%" popover="Myplanet Leader" popover-trigger="mouseenter"><div class="glyphicon glyphicon-tower"></div></div>
          <div class="progress-bar progress-bar-primary" style="width: 10%" popover="Industry Contributor" popover-trigger="mouseenter"><div class="glyphicon glyphicon-star"></div></div>
          <div class="progress-bar progress-bar-primary" style="width: 10%" popover="Industry Leader (El Jefe!)" popover-trigger="mouseenter"><div class="glyphicon glyphicon-fire"></div></div>
        </div>
      </div>
    </div>

    <!-- skills -->
    <div class="row">
      <div id="top3" class="row" ng-repeat="skill in page.skills | orderBy: '-current' | limitTo: 3">
        <h3 class="skill_name col-xs-2">{{skill.name}}</h3>
          <div class="progress col-xs-10">
            <div class="progress-bar progress-bar-success" style="width: {{skill.current * 10}}%" popover="Current Skill Level: {{skill.current}}" popover-trigger="mouseenter"></div>
            <div class="progress-bar progress-bar-warning" style="width: {{(skill.desired - skill.current) * 10}}%" popover="Desired Skill Level: {{skill.desired}}" popover-trigger="mouseenter"></div>
          </div>
      </div>
    </div>
    <accordion>
      <accordion-group is-open="isopen">
          <accordion-heading>
            More Skills<i class="pull-right glyphicon" ng-class="{'glyphicon-chevron-down': isopen, 'glyphicon-chevron-right': !isopen}"></i>
          </accordion-heading>
          <div class="low_skills" ng-repeat="skill in page.skills | orderBy:'current' | limitTo: (page.skills.length -3) | orderBy:'-current'">
            <div class="row col-xs-12">
            <h3 class="skill_name col-xs-2">{{skill.name}}</h3>
              <div class="progress col-xs-10">
                <div class="progress-bar progress-bar-success" style="width: {{skill.current * 10}}%"></div>
                <div class="progress-bar progress-bar-warning" style="width: {{(skill.desired - skill.current) * 10}}%"></div>
              </div>
            </div>
          </div>
      </accordion-group>
    </accordion>
  </section>

  <hr>

  <!-- static project section with dynamic project inputs -->
    <section id="projects" class="container-fluid">
      <div class="project_header common_title">
        <h2>Projects</h2>
      </div>

      <hr>

      <div class="project_content row">
        <div class="project1 col-xs-4" ng-repeat="project in page.related_projects">
          <h3><a href="node/{{project.nid}}">{{project.name}}</a></h3>
          <div ng-bind-html="project.avatar" alt="{{project.name}}"></div>
        </div>
      </div>
    </section>

<div class="scroll_button">
 <a href="#skip-link"><button type="button" class="btn btn-primary active">TOP</button></a>
</div>

<!-- end of wrapper for user profile -->
</section>

