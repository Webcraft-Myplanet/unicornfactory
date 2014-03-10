<section id="wrapper" class="fluid-container">

  <!-- personal info div containing avatar, name and current team status -->
  <section ng-controller="UserProfileCtrl" ng-init="uid = <?php print $elements["#account"]->uid ?> ">
    <div class="row">
        <div class="personal_avatar col-lg-4">
          <!-- For some reason the avatar is loading, but being returned a 403 Forbidden error -->
          <div ng-bind-html="page.field_avatar.und[0].html"></div>
        </div>
        <!-- leaving picture out of form for editing personal info for now -->
        <form editable-form name="PersonalInfoForm" onaftersave="updateUser()">
          <div class="name_status col-lg-4">
            <h2 editable-text="page.name" buttons="no" onbeforesave="validateName($data)" onaftersave="updateUser()" e-form="nameEdit" ng-click="nameEdit.$show()">{{page.name}}</h2>
            <p>{{page.mail}}</p>
            <!-- The following ng-show/ng-hide depend on value of Slogan.
               if Slogan is defined it will display, otherwise a link to add a slogan. -->
            <div editable-textarea="page.field_slogan.und[0].value" e-rows="2" e-cols="50" e-placeholder="Add your slogan" buttons="no" onbeforesave="validateSlogan($data)" onaftersave="updateUser()" e-form="sloganEdit" ng-click="sloganEdit.$show()"><p>{{page.field_slogan.und[0].value}}</p></div>
          </div>
          <div class="personal_social col-lg-4">
            <ul class="social_network row">
              <li class="col-lg-3"><a href="https://www.facebook.com/{{page.field_facebook.und[0].value}}" class="btn btn-default btn-lg btn-primary active" role="button">FB</a></li>
              <li class="col-lg-3"><a href="https://twitter.com/{{page.field_twitter.und[0].value}}" class="btn btn-default btn-lg" role="button">TW</a></li>
              <li class="col-lg-3"><a href="http://github.com/{{page.field_github.und[0].value}}" class="btn btn-default btn-lg" role="button">GH</a></li>
              <li class="col-lg-3"><a href="{{page.field_linkedin.und[0].url}}" class="btn btn-default btn-lg" role="button">LI</a></li>
            </ul>
          </div>
          <div ng-show="PersonalInfoForm.$visible" class="edit_social_media col-lg-6 col-lg-offset-6 text-right">
            <!-- Social media editting fields -->
            <ul>
              <li><label>Facebook: </label>https://www.facebook.com/<div editable-text="page.field_facebook.und[0].value" buttons="no" onbeforesave="validateSocialMedia($data)" onaftersave="updateUser()" e-form="socialEdit"><p>{{page.field_facebook.und[0].value}}</p></li>
              <li><label>Twitter: </label>https://twitter.com/<div editable-text="page.field_twitter.und[0].value" buttons="no" onbeforesave="validateSocialMedia($data)" onaftersave="updateUser()" e-form="socialEdit"><p>{{page.field_twitter.und[0].value}}</p></li>
              <li><label>Github: </label>http://github.com/<div editable-text="page.field_github.und[0].value" buttons="no" onbeforesave="validateSocialMedia($data)" onaftersave="updateUser()" e-form="socialEdit"><p>{{page.field_github.und[0].value}}</p></li>
              <li><label>LinkedIn </label><div editable-text="page.field_linkedin.und[0].value" buttons="no" onbeforesave="validateSocialMedia($data)" onaftersave="updateUser()" e-form="socialEdit"><p>{{page.field_linkedin.und[0].value}}</p></li>
            </ul>
          </div>
          <div class="buttons col-lg-2 col-lg-offset-10" >
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
    <h2 class="col-lg-4">Teams</h2>
    <div class="col-lg-4">
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
        <h2 class="col-lg-8">Skills</h2>
        <ul class="col-lg-4">
          <!-- This is currently hard-coded, obviously we'd like to set these dynamically according to skill levels -->
          <li class="small">My highest level skill is: {{highestCurrentObject.field_skill.und}}</li>
          <li class="small">My most desireable skill is: {{highestDesiredObject.field_skill.und}}</li>
        </ul>
      </div>
    </div>

    <hr>

    <!-- Skills Legend -->
    Skills Legend!
    <progress>
      <div popover="You Suck!" popover-trigger="mouseenter"><bar value="10" type="progress-striped active"><div class="glyphicon glyphicon-trash"></div></bar></div>
      <div popover="Did You Even Bother?" popover-trigger="mouseenter"><bar value="10" type="progress-striped active"><div class="glyphicon glyphicon-thumbs-down"></div></bar></div>
      <div popover="Almost Mediocre" popover-trigger="mouseenter"><bar value="10" type="progress-striped active"><div class="glyphicon glyphicon-bullhorn"></div></bar></div>
      <div popover="Fairly Poor" popover-trigger="mouseenter"><bar value="10" type="progress-striped active"><div class="glyphicon glyphicon-paperclip"></div></bar></div>
      <div popover="Meh" popover-trigger="mouseenter"><bar value="10" type="progress-striped active"><div class="glyphicon glyphicon-bell"></div></bar></div>
      <div popover="Getting There" popover-trigger="mouseenter"><bar value="10" type="progress-striped active"><div class="glyphicon glyphicon-pushpin"></div></bar></div>
      <div popover="You Could Try Harder" popover-trigger="mouseenter"><bar value="10" type="progress-striped active"><div class="glyphicon glyphicon-tree-conifer"></div></bar></div>
      <div popover="Not Quite What We'd Call An Overachiever" popover-trigger="mouseenter"><bar value="10" type="progress-striped active"><div class="glyphicon glyphicon-tower"></div></bar></div>
      <div popover="Now You're Talking" popover-trigger="mouseenter"><bar value="10" type="progress-striped active"><div class="glyphicon glyphicon-star"></div></bar></div>
      <div popover="El Jefe!" popover-trigger="mouseenter"><bar value="10" type="progress-striped active"><div class="glyphicon glyphicon-fire"></div></bar></div>
    </progress>

    <!-- top 3 skills -->
    <div class="row">
      <div id="top3" class="row" ng-repeat="skill in skills | orderBy:'-current'| limitTo:3 "> 
        <h3 class="skill_name col-sm-2" >{{skill.name}}</h3>
        <div class="progress">
          <div class="progress-bar progress-bar-success" style="width: {{skill.current * 10}}%" popover="Current Skill Level : {{skill.current}}" popover-trigger="mouseenter">
          </div>
          <div class="progress-bar progress-bar-warning" style="width: {{(skill.desired - skill.current) * 10}}%" popover="Desired Skill Level : {{skill.desired}}" popover-trigger="mouseenter">
          </div>
        </div>
      </div>
    </div>


  
  <!-- Accordion of all skills below the top 3 -->
  <div class="row list-wrapper">
    <br>
      <accordion>
        <accordion-group is-open="isopen">
          <div id="remaining"  class="row" ng-repeat="skill in skills | orderBy:'current' | limitTo: (otherSkills - 3) | orderBy:'-current'">
            <accordion-heading>
              More Skills<i class="pull-right glyphicon" ng-class="{'glyphicon-chevron-down': isopen, 'glyphicon-chevron-right': !isopen}"></i>
            </accordion-heading>

            <p class="skill_name col-sm-2">{{skill.name}}</p>
              <div class="progress col-sm-10">
                <div class="progress-bar progress-bar-success" style="width: {{skill.current * 10}}%" popover="Current Skill Level : {{skill.current}}" popover-trigger="mouseenter">
            </div>
            <div class="progress-bar progress-bar-warning" style="width: {{(skill.desired - skill.current) * 10}}%" popover="Desired Skill Level : {{skill.desired}}" popover-trigger="mouseenter">
            </div>
              </div>
          </div>
        </accordion-group>
      </accordion>
    </div>
  </div>

  </section>

  <hr>

  <!-- static project section with dynamic project inputs -->
  <section ng-controller="UserProfileCtrl" ng-init="uid = <?php print $elements["#account"]->uid ?>" id="projects" class="container-fluid">
    <div class="project_header common_title">
      <h2>Projects</h2>
    </div>

    <hr>

    <div class="project_content row">
      <div class="project1 col-lg-4" ng-repeat="project in page.related_projects">
        <h3><a href="node/{{project.nid}}">{{project.name}}</a></h3>
        <div ng-bind-html="project.avatar"></div>
      </div>
    </div>
  </section>

</div>
<div class="scroll_button">
 <a href="#navbar"><button type="button" class="btn btn-primary active">TOP</button></a>
</div>

<hr>

<!-- sitewide common footer -->
<footer class="common_title row">
  <div class="col-lg-12">
    <h3>My Planet Digital</h3>
    <address>
      <h3>Company Address</h3>
      <a href="mailto:you@youraddress.com">Email My Planet Digital</a>
    </address>
    <div class="phone">555-555-5555</div>
  </div>
</footer>

<!-- end of wrapper for user profile -->
</section>

