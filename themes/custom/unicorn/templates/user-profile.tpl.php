<section id="wrapper" class="container-fluid usr_profile">

  <!-- dynamic skills section with accordion fold -->
  <section id="skills" class="col-xs-10">
    <!-- static header -->
    <div class="row common_title">
      <div id="skills_header" class="row">
        <h2 class="col-xs-8">Skills</h2>
        <ul class="col-xs-4" ng-show="page.skills.0.name">
          <li class="small" ng-repeat="skill in page.skills | orderBy: '-current'| limitTo: 1">My highest level skill is: {{skill.name}}</li>
          <li class="small" ng-repeat="skill in page.skills | orderBy: '-desired'| limitTo: 1">My most desireable skill is: {{skill.name}}</li>
        </ul>
      </div>
    </div>

    <hr>
    <!-- skills -->
    <div class="row">
      <p ng-show="!page.skills.0.name">This user has no skills... yet!</p>
      <dl ng-show="page.skills.0.name !== ''">
        <div class="row col-xs-12" ng-repeat="skill in page.skills | orderBy: '-current'">
          <dt class="skill_name col-xs-2">{{skill.name}}</dt>
          <dd>
            <div class="progress col-xs-10">
              <div class="progress-bar pbcurrent" style="width: {{skill.current * 5}}%" popover="Current Skill Level: {{skill.current}}" popover-trigger="mouseenter"></div>
              <div class="progress-bar pbdesired" style="width: {{(skill.desired - skill.current) * 5}}%" popover="Desired Skill Level: {{skill.desired}}" popover-trigger="mouseenter"></div>
            </div>
            <p class="sr-only">Current Skill Level: {{skill.current}}</p>
            <p class="sr-only">Desired Skill Level: {{skill.desired}}</p>
          </dd>
        </div>
      </dl>
    </div>
    <div ng-show="page.skills.length > 3">
      <accordion>
        <accordion-group is-open="isopen">
            <accordion-heading >
              <h3 class="inline-heading"><a href="#moreskills" id="moreskills">More Skills</a></h3><i class="pull-right glyphicon" ng-class="{'glyphicon-chevron-down': isopen, 'glyphicon-chevron-right': !isopen}"></i></a>
            </accordion-heading>
            <dl>
              <div class="low_skills row col-xs-12" ng-repeat="skill in page.skills | orderBy:'current' | limitTo: (page.skills.length -3) | orderBy:'-current'">
                <dt class="skill_name col-xs-2">{{skill.name}}</dt>
                <dd>
                  <div class="progress col-xs-10">
                    <div class="progress-bar pbcurrent" style="width: {{skill.current * 5}}%" popover="Current Skill Level: {{skill.current}}" popover-trigger="mouseenter"></div>
                    <div class="progress-bar pbdesired" style="width: {{(skill.desired - skill.current) * 5}}%" popover="Desired Skill Level: {{skill.desired}}" popover-trigger="mouseenter"></div>
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
            <li>Level 1: Mercury</li>
            <li>Level 2: Venus</li>
            <li>Level 3: Earth</li>
            <li>Level 4: Mars</li>
            <li>Level 5: Jupiter</li>
           <!--  <li>Level 6: Team Leader</li>
            <li>Level 7: Myplanet Contributor</li>
            <li>Level 8: Myplanet Leader</li>
            <li>Level 9: Industry Contributor</li>
            <li>Level 10: Industry Leader</li> -->
          </ul>
        </div>
        <div class="progress" id="legend">
          <div class="progress-bar guidebar" style="width: 20%" popover="n00b" popover-trigger="mouseenter"><span>Mercury</span></div>
          <div class="progress-bar guidebar" style="width: 20%" popover="Trying" popover-trigger="mouseenter"><span>Venus</span></div>
          <div class="progress-bar guidebar" style="width: 20%" popover="Understanding" popover-trigger="mouseenter"><span>Earth</span></div>
          <div class="progress-bar guidebar" style="width: 20%" popover="Knowing" popover-trigger="mouseenter"><span>Mars</span></div>
          <div class="progress-bar guidebar" style="width: 20%" popover="Teaching" popover-trigger="mouseenter"><span>Jupiter</span></div>
        </div>
      </div>
    </div>
  </section>

  <hr>

  <!-- static project section with dynamic project inputs -->
    <section id="projects" class="col-xs-10">
      <div class="project_header common_title">
        <h2>Projects</h2>
      </div>

      <hr>

      <div class="project_content row">
        <p ng-show="page.related_projects.length == 0">This user is not working on any projects... yet!</p>
        <div class="project1 col-xs-4" ng-repeat="project in page.related_projects">
          <h3><a href="node/{{project.nid}}">{{project.name}}</a></h3>
          <a href="node/{{project.nid}}"><div class="people-thumb" ng-bind-html="project.avatar" alt="{{project.name}}"></div></a>
        </div>
      </div>
    </section>

<!-- end of wrapper for user profile -->
</section>
