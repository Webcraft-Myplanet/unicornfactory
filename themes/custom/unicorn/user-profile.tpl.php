<?php
dsm ($variables);
?>

<section id="wrapper">

<!-- static top nav found throughout the site -->
  <header id="site_nav common_title">
    <div class="unicorn_logo">
      <img src="" alt="">
    </div>
    <div class="site_title">
      <h1>Unicorn Factory</h1>
    </div>
    <div class="teams_button">Teams</div>
    <div class="projects_button">Projects</div>
  </header>

<!-- personal info div containing avatar, name and current team status -->
  <section id="personal_info">
    <div class="personal_avatar">
      <img src="" alt="">
    </div>
    <div class="name_status">
      <h2><?php print $user->name ?></h2>
      <p>Current Team</p>
      <p>Current Project</p>
    </div>
    <div class="personal_social">
      <ul>
        <li><img src="" alt=""><a href=""></a></li>
        <li><img src="" alt=""><a href=""></a></li>
        <li><img src="" alt=""><a href=""></a></li>
        <li><img src="" alt=""><a href=""></a></li>
      </ul>
    </div>
  </section>

<!-- dynamic skills section with accordion fold -->
  <section id="skills">

  <!-- static header -->
    <div id="skills_header common_title">
      <h2>Skills</h2>
      <ul>
        <li>My best skill is ... </li>
        <li>My most desiteable skill is ... </li>
      </ul>
    </div>
<!-- accordion content -->
    <div id="skills_content">
      <div class="skill_graph">
        <h3>Code Name</h3>
        <div class="skill_rating_input">
          
        </div>
      </div>
    </div>
  </section>

<!-- static project section with dynamic project inputs -->
  <section id="projects">
    <div class="project_header common_title">
      <h2>Projects</h2>
    </div>
    <div class="project_content">
      <div class="project1">
        <h3>Project 1</h3>
      </div>
      <div class="project2">
        <h3>Project 2</h3>
      </div>
      <div class="project3">
        <h3>Project 3</h3>
      </div>
    </div>
  </section>

<!-- wishlist -->
  <section class="wishlist col-md-6">
    <div class="wishlist_title common_title">
      <h2>Wishlist</h2>
    </div>
    <ul>
      <li></li>
      <li></li>
      <li></li>
      <li></li>
      <li></li>
      <li></li>
      <li></li>
      <li></li>
      <li></li>
      <li></li>
    </ul>
  </section>

<!-- live activity feed -->
  <section class="activity_feed col-md-6">
    <div class="activity_title common_title">
      <h2>Activity Feed</h2>
    </div>
    <div class="live_feed">
      
    </div>
  </section>
  
  <!-- sitewide common footer -->
  <footer class="common_title">
    <h3>My Planet Digital</h3>
    <address>
      <h3>Company Address</h3>
      <a href="mailto:you@youraddress.com">Email My Planet Digital</a>
    </address>
    <div class="phone">555-555-5555</div>
  </footer>


<!-- end of wrapper -->
</section>
