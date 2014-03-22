<section ng-controller="UserProfileCtrl" ng-init="uid = <?php print $elements["#account"]->uid ?> " id="wrapper" class="container-fluid usr_profile">
<div class="col-xs-2 left_sidebar"></div>
  <!-- personal info div containing avatar, name and current team status -->
  <section id="info_teams" class="col-xs-12 col-sm-12 col-md-2 col-lg-2 col-xl-2">
    <div>
      <!-- Avatar -->
      <div class="personal_avatar col-md-12 text-center">
        <div><?php print $variables['user_profile']['user_picture']['#markup']; ?></div>
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
              <li class="col-xs-2" ng-show="page.field_facebook.und[0].value">
                <a href="https://www.facebook.com/{{page.field_facebook.und[0].value}}" title="Facebook">
                  <i class="fa fa-facebook-square fa-3x"></i>
                </a>
              </li>
              <li class="col-xs-2" ng-show="page.field_twitter.und[0].value">
                <a href="https://twitter.com/{{page.field_twitter.und[0].value}}" title="Twitter">
                  <i class="fa fa-twitter-square fa-3x"></i>
                </a>
              </li>
              <li class="col-xs-2" ng-show="page.field_github.und[0].value">
                <a href="http://github.com/{{page.field_github.und[0].value}}" title="GitHub">
                  <i class="fa fa-github-square fa-3x"></i>
                </a>
              </li>
              <li class="col-xs-2" ng-show="page.field_linkedin.und[0].url" title="LinkedIn">
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
      <h2 class="col-xs-4">Teams</h2>
      <p ng-show="page.related_teams.length == 0">This user is not a member of any teams... yet!</p>
      <div class="col-xs-4" ng-repeat="team in page.related_teams">
        <button type="button" class="btn btn-default"><a href="/node/{{team.nid}}">{{team.name}}</a></button>
      </div>
    </div>
  </section>

  <hr>

  <!-- dynamic skills section with accordion fold -->
  <section id="skills" class="col-xs-10">
    <!-- static header -->
    <div class="row common_title">
      <div id="skills_header" class="row">
        <h2 class="col-xs-8">Skills</h2>
        <ul class="col-xs-4" ng-show="page.skills.0.name">
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
          <div class="progress-bar guidebar" style="width: 10%" popover="Little to no knowledge" popover-trigger="mouseenter"><span>1</span></div>
          <div class="progress-bar guidebar" style="width: 10%" popover="Beginner Skill Level" popover-trigger="mouseenter"><span>2</span></div>
          <div class="progress-bar guidebar" style="width: 10%" popover="Limited Knowledge" popover-trigger="mouseenter"><span>3</span></div>
          <div class="progress-bar guidebar" style="width: 10%" popover="Competent User" popover-trigger="mouseenter"><span>4</span></div>
          <div class="progress-bar guidebar" style="width: 10%" popover="Team Contributor" popover-trigger="mouseenter"><span>5</span></div>
          <div class="progress-bar guidebar" style="width: 10%" popover="Team Leader" popover-trigger="mouseenter"><span></span>6</div>
          <div class="progress-bar guidebar" style="width: 10%" popover="Myplanet Contributor" popover-trigger="mouseenter"><span>7</span></div>
          <div class="progress-bar guidebar" style="width: 10%" popover="Myplanet Leader" popover-trigger="mouseenter"><span>8</span></div>
          <div class="progress-bar guidebar" style="width: 10%" popover="Industry Contributor" popover-trigger="mouseenter">9</div>
          <div class="progress-bar guidebar" style="width: 10%" popover="Industry Leader (El Jefe!)" popover-trigger="mouseenter"><span>10</span></div>
        </div>
      </div>
    </div>

    <p ng-show="!page.skills.0.name">This user has no skills... yet!</p>
    <!-- skills -->
    <div ng-if="page.skills.0.name !== ''" ng-repeat="skill in page.skills | orderBy: '-current' | limitTo: 3">
      <div class="row col-xs-12">
        <h3 class="skill_name col-xs-2">{{skill.name}}</h3>
          <div class="progress col-xs-10">
            <div class="progress-bar pbcurrent" style="width: {{skill.current * 10}}%" popover="Current Skill Level: {{skill.current}}" popover-trigger="mouseenter"></div>
            <div class="progress-bar pbdesired" style="width: {{(skill.desired - skill.current) * 10}}%" popover="Desired Skill Level: {{skill.desired}}" popover-trigger="mouseenter"></div>
          </div>
      </div>
    </div>
    <div ng-show="page.skills.length > 3">
      <accordion>
        <accordion-group is-open="isopen">
            <accordion-heading >
              <a href="#moreskills" id="moreskills">More Skills</a><i class="pull-right glyphicon" ng-class="{'glyphicon-chevron-down': isopen, 'glyphicon-chevron-right': !isopen}"></i></a>
            </accordion-heading>
            <div class="low_skills" ng-repeat="skill in page.skills | orderBy:'current' | limitTo: (page.skills.length -3) | orderBy:'-current'">
              <div class="row col-xs-12">
              <h3 class="skill_name col-xs-2">{{skill.name}}</h3>
                <div class="progress col-xs-10">
                  <div class="progress-bar pbcurrent" style="width: {{skill.current * 10}}%" popover="Current Skill Level: {{skill.current}}" popover-trigger="mouseenter"></div>
                  <div class="progress-bar pbdesired" style="width: {{(skill.desired - skill.current) * 10}}%" popover="Desired Skill Level: {{skill.desired}}" popover-trigger="mouseenter"></div>
              </div>
            </div>
        </accordion-group>
      </accordion>
    </div>
  </section>

  <hr>

  <!-- static project section with dynamic project inputs -->
    <section id="projects" class="col-xs-10 col-xs-offset-2">
      <div class="project_header common_title">
        <h2>Projects</h2>
      </div>

      <hr>

      <div class="project_content row">
        <p ng-show="page.related_projects.length == 0">This user is not working on any projects... yet!</p>
        <div class="project1 col-xs-4" ng-repeat="project in page.related_projects">
          <h3><a href="node/{{project.nid}}">{{project.name}}</a></h3>
          <div class="people-thumb" ng-bind-html="project.avatar" alt="{{project.name}}"></div>
        </div>
      </div>
    </section>

<div class="scroll_button">
 <a href="#skip-link" title="Skip to beginning of page" ><button type="button" class="btn btn-link"><img src="/profiles/skeletor/themes/custom/unicorn/images/up-black-arrow-md.png" width="50px" alt=""></button></a>
</div>

<!-- end of wrapper for user profile -->
</section>

