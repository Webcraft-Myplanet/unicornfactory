<section id="wrapper" class="fluid-container">

  <!-- personal info div containing avatar, name and current team status -->
  <section ng-controller="UserProfileCtrl" ng-init="uid = <?php print $elements["#account"]->uid ?> ">
    <div class="row">
      <!-- Avatar -->
      <div class="personal_avatar col-xs-4">
        <div><?php print $variables['user_profile']['user_picture']['#markup']; ?></div>
      </div>
      <!-- leaving picture out of form for editing personal info for now -->
      <form editable-form name="PersonalInfoForm" onaftersave="updateUser()">
        <div class="name_status col-xs-4">
          <h2 editable-text="page.name" buttons="no" onbeforesave="validateName($data)" onaftersave="updateUser()" e-form="nameEdit" ng-click="nameEdit.$show()">{{page.name}}</h2>
          <p>{{page.mail}}</p>
            <!-- The following ng-show/ng-hide depend on value of Slogan.
            if Slogan is defined it will display, otherwise a link to add a slogan. -->
            <div editable-textarea="page.field_slogan.und[0].value" e-rows="2" e-cols="50" e-placeholder="Add your slogan" buttons="no" onbeforesave="validateSlogan($data)" onaftersave="updateUser()" e-form="sloganEdit" ng-click="sloganEdit.$show()"><p>{{page.field_slogan.und[0].value}}</p></div>
          </div>
          <div class="personal_social col-xs-4">
            <ul class="social_network row">
              <li class="col-xs-3">
                <a href="https://www.facebook.com/{{page.field_facebook.und[0].value}}">
                  <img src="/profiles/skeletor/themes/custom/unicorn/images/facebook-icon.png" width="50" />
                </a>
              </li>
              <li class="col-xs-3">
                <a href="https://twitter.com/{{page.field_twitter.und[0].value}}">
                  <img src="/profiles/skeletor/themes/custom/unicorn/images/Twitter-icon.png" width="50" />
                </a>
              </li>
              <li class="col-xs-3">
                <a href="http://github.com/{{page.field_github.und[0].value}}">
                  <img src="/profiles/skeletor/themes/custom/unicorn/images/github-logo.png" width="50" />
                </a>
              </li>
              <li class="col-xs-3">
                <a href="{{page.field_linkedin.und[0].url}}">
                  <img src="/profiles/skeletor/themes/custom/unicorn/images/LinkedIn-icon.png" width="50" />
                </a>
              </li>
            </ul>
          </div>
          <div ng-show="PersonalInfoForm.$visible" class="edit_social_media col-xs-6 col-xs-offset-6 text-right">
            <!-- Social media editting fields -->
            <ul>
              <li><label>Facebook: </label>https://www.facebook.com/<div editable-text="page.field_facebook.und[0].value" buttons="no" onbeforesave="validateSocialMedia($data)" onaftersave="updateUser()" e-form="socialEdit"><p>{{page.field_facebook.und[0].value}}</p></li>
              <li><label>Twitter: </label>https://twitter.com/<div editable-text="page.field_twitter.und[0].value" buttons="no" onbeforesave="validateSocialMedia($data)" onaftersave="updateUser()" e-form="socialEdit"><p>{{page.field_twitter.und[0].value}}</p></li>
              <li><label>Github: </label>http://github.com/<div editable-text="page.field_github.und[0].value" buttons="no" onbeforesave="validateSocialMedia($data)" onaftersave="updateUser()" e-form="socialEdit"><p>{{page.field_github.und[0].value}}</p></li>
              <li><label>LinkedIn </label><div editable-text="page.field_linkedin.und[0].value" buttons="no" onbeforesave="validateSocialMedia($data)" onaftersave="updateUser()" e-form="socialEdit"><p>{{page.field_linkedin.und[0].value}}</p></li>
            </ul>
          </div>
          <div class="buttons col-xs-2 col-xs-offset-10" >
            <!-- button to show form -->
            <button type="button" class="btn btn-default" ng-click="PersonalInfoForm.$show()" ng-show="!PersonalInfoForm.$visible"> Edit </button>
            <!-- buttons to submit / cancel form -->
            <span ng-show="PersonalInfoForm.$visible">
             <button type="submit" class="btn btn-primary" ng-disabled="PersonalInfoForm.$waiting"> Save </button>
             <button type="button" class="btn btn-default" ng-disabled="PersonalInfoForm.$waiting" ng-click="PersonalInfoForm.$cancel()"> Cancel </button>
           </span>
         </div>
       </form>
     </div><!--end row-->
     <!-- Teams -->
     <hr>
     <div class="row">
      <h2 class="col-xs-4">Teams</h2>
      <div class="col-xs-4">
        <button type="button" class="btn btn-default"><a href="/node/{{page.related_teams[0].nid}}">{{page.related_teams[0].name}}</a></button>
      </div>
    </div>
  </section>

  <hr>

  <!-- dynamic skills section with accordion fold -->
  <section ng-controller="UserProfileCtrl" ng-init="uid = <?php print $elements["#account"]->uid ?>" id="skills" class="container-fluid">
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
        <div class="progress" id="legend">
          <div class="progress-bar progress-bar-primary" style="width: 10%" popover="You Suck!" popover-trigger="mouseenter"><div class="glyphicon glyphicon-trash"></div></div>
          <div class="progress-bar progress-bar-primary" style="width: 10%" popover="Did You Even Bother?" popover-trigger="mouseenter"><div class="glyphicon glyphicon-thumbs-down"></div></div>
          <div class="progress-bar progress-bar-primary" style="width: 10%" popover="Almost Mediocre" popover-trigger="mouseenter"><div class="glyphicon glyphicon-bullhorn"></div></div>
          <div class="progress-bar progress-bar-primary" style="width: 10%" popover="Fairly Poor" popover-trigger="mouseenter"><div class="glyphicon glyphicon-paperclip"></div></div>
          <div class="progress-bar progress-bar-primary" style="width: 10%" popover="Meh" popover-trigger="mouseenter"><div class="glyphicon glyphicon-bell"></div></div>
          <div class="progress-bar progress-bar-primary" style="width: 10%" popover="Getting There" popover-trigger="mouseenter"><div class="glyphicon glyphicon-pushpin"></div></div>
          <div class="progress-bar progress-bar-primary" style="width: 10%" popover="You Could Try Harder" popover-trigger="mouseenter"><div class="glyphicon glyphicon-tree-conifer"></div></div>
          <div class="progress-bar progress-bar-primary" style="width: 10%" popover="Not Quite What We'd Call An Overachiever" popover-trigger="mouseenter"><div class="glyphicon glyphicon-tower"></div></div>
          <div class="progress-bar progress-bar-primary" style="width: 10%" popover="Now You're Talking" popover-trigger="mouseenter"><div class="glyphicon glyphicon-star"></div></div>
          <div class="progress-bar progress-bar-primary" style="width: 10%" popover="El Jefe!" popover-trigger="mouseenter"><div class="glyphicon glyphicon-fire"></div></div>
        </div>
      </div>
    </div>

    <!-- top 3 skills -->
    <div class="row">
      <form editable-form name="skillform" onaftersave="updateUser()"  oncancel="cancel()">

        <div id="top3" class="row" ng-repeat="skill in page.skills | orderBy: '-current'">
          <div class="row">
            <h3 class="skill_name col-sm-2" e-typeahead="skill for skill in options.field_skill | filter:$viewValue | limitTo:8" editable-text="skill.name" e-form="skillform">{{skill.name}}</h3>
            <span class="col-sm-3" editable-text="skill.current" e-form="skillform">Current level: {{skill.current}}</span>
            <span class="col-sm-3" editable-text="skill.desired" e-form="skillform">Desired level: {{skill.desired}}</span>
          </div>
          <div class="progress">
            <div class="progress-bar progress-bar-success" style="width: {{skill.current * 10}}%" popover="Current Skill Level : {{skill.current}}" popover-trigger="mouseenter"></div>
            <div class="progress-bar progress-bar-warning" style="width: {{(skill.desired - skill.current) * 10}}%" popover="Desired Skill Level : {{skill.desired}}" popover-trigger="mouseenter"></div>
          </div>
        </div>

        <div class="btn-form" ng-show="skillform.$visible">
          <button type="button" ng-disabled="skillform.$waiting" ng-click="addSkill()" class="btn btn-default pull-right">Add Skill</button>
          <button type="submit" ng-disabled="skillform.$waiting" class="btn btn-primary">Save</button>
          <button type="button" ng-disabled="skillform.$waiting" ng-click="skillform.$cancel()" class="btn btn-default">Cancel</button>
        </div>

        <div class="btn-edit">
          <button type="button" class="btn btn-default" ng-show="!skillform.$visible" ng-click="skillform.$show()">
            Edit Skills
          </button>
        </div>
      </form>
    </div>

  </section>

  <hr>

  <!-- static project section with dynamic project inputs -->
  <form editable-form name="projectform" onaftersave="updateUser()" oncancel="cancel()">
    <section ng-controller="UserProfileCtrl" ng-init="uid = <?php print $elements["#account"]->uid ?>" id="projects" class="container-fluid">
      <div class="project_header common_title">
        <h2>Projects</h2>
      </div>

      <hr>

      <div class="project_content row">
        <div class="project1 col-xs-4" ng-repeat="project in page.related_projects">
          <h3>
            <a ng-disabled="projectform.$visible" href="node/{{project.nid}}">
              <span editable-text="project.name" e-form="projectform">
                {{project.name}}
              </span>
            </a>
          </h3>
          <button type="button" ng-show="projectform.$visible" ng-click="deleteProject()" class="btn btn-danger pull-right">Del</button>
          <div ng-bind-html="project.avatar"></div>
        </div>
      </div>
      <div class="btn-edit">
        <button type="button" class="btn btn-default" ng-show="!projectform.$visible" ng-click="projectform.$show()">
         edit projects
       </button>
     </div>
     <div class="btn-form" ng-show="projectform.$visible">
      <button type="submit" ng-disabled="projectform.$waiting" class="btn btn-primary">save</button>
      <button type="button" ng-disabled="projectform.$waiting" ng-click="projectform.$cancel()" class="btn btn-default">cancel</button>
    </div>
  </section>
</form>

</div>
<div class="scroll_button">
 <a href="#navbar"><button type="button" class="btn btn-primary active">TOP</button></a>
</div>

<!-- end of wrapper for user profile -->
</section>

