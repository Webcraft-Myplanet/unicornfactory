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
<div class="proj-wrapper">
 <div class="proj-info">
   <div class="proj-deets">
    <div class="proj-owner"><?php print $name ?></div>
    <div class="proj-type"><?php print $project_type ?></div>
    <div class="proj-date"><?php print $date ?></div>
   </div> <!-- proj-deets -->
   <div class="proj-status">
     <p>
     Obviously you're not a golfer. Lorem aliquam placerat posuere neque, at dignissim magna. I'm unemployed. Ullamcorper in aliquam sagittis massa ac tortor ultrices faucibus curabitur eu mi. That fucking bitch! Sapien, ut ultricies ipsum morbi eget. One a those days, huh. Wal, a wiser fella than m'self once said, sometimes you eat the bar and sometimes the bar, wal, he eats you. Risus nulla nullam vel nisi enim, vel auctor ante morbi.
     </p>
   </div> <!-- proj-status -->
   <div class="proj-desc">
     <?php print $proj_desc ?>
   </div> <!-- proj-desc -->
   <div class="proj-resources">
     <?php print $resources ?>
   </div> <!-- proj-resources -->
 </div> <!-- proj-info -->

 <div class="proj-contribs">
  <?php print $contribs ?>
 </div> <!-- proj-contribs -->

 <div class="proj-updates">
  <?php print $updates ?>
 </div> <!-- proj-updates -->

 <div class="proj-comments">
  <?php print render($content['comments']); ?>
 </div>

<div class="all-bounties">
    <?php dpm($bounties) ?>

  <div class="bounty-open">
      <!-- fail statement in case not open bounty -->
    <?php if (!empty($bounties['Open '])): ?>

      <?php foreach ($bounties['Open '] as $bounty): ?>
        <div class="bounty">

            <h3><?php print $bounty['title']; ?></h3>
            <p><?php print $bounty['date']; ?></p>
            <p><?php print $bounty['description']; ?></p>
            <button><a href="/node/<?php print($bounty['node_id'])?>">Apply for Bounty</a></button>
        </div>
      <?php endforeach; ?>
    <?php endif; ?>
  </div>

    <div class="bounty-in-progress">
      <!-- fail statement in case not open bounty -->
    <?php if (!empty($bounties['In Progress '])): ?>

      <?php foreach ($bounties['In Progress '] as $bounty): ?>
        <div class="bounty">

            <h3><?php print $bounty['title']; ?></h3>
           <?php if (!empty($bounty['owner_img'])): ?>
              <img src="/sites/default/files/styles/thumbnail/public/profile_pictures/<?php print($bounty['owner_img'])?>"></a>
            <?php endif; ?>
            <p><?php print $bounty['date']; ?></p>
            <p><?php print $bounty['description']; ?></p>
        </div>
      <?php endforeach; ?>
    <?php endif; ?>
  </div>

      <div class="bounty-postponed">
      <!-- fail statement in case not open bounty -->
    <?php if (!empty($bounties['Postponed '])): ?>

      <?php foreach ($bounties['Postponed '] as $bounty): ?>
      <div class="bounty-postponed"): ?>
        <div class="bounty">

            <h3><?php print $bounty['title']; ?></h3>
           <?php if (!empty($bounty['owner_img'])): ?>
              <img src="/sites/default/files/styles/thumbnail/public/profile_pictures/<?php print($bounty['owner_img'])?>"></a>
            <?php endif; ?>
            <p><?php print $bounty['date']; ?></p>
            <p><?php print $bounty['description']; ?></p>
        </div>
      <?php endforeach; ?>
    <?php endif; ?>
  </div>


    <div class="bounty-closed">
      <!-- fail statement in case not open bounty -->
    <?php if (!empty($bounties['Closed '])): ?>

      <?php foreach ($bounties['Closed '] as $bounty): ?>
        <div class="bounty">

            <h3><?php print $bounty['title']; ?></h3>
           <?php if (!empty($bounty['owner_img'])): ?>
              <img src="/sites/default/files/styles/thumbnail/public/profile_pictures/<?php print($bounty['owner_img'])?>"></a>
            <?php endif; ?>
            <p><?php print $bounty['date']; ?></p>
        </div>
      <?php endforeach; ?>
    <?php endif; ?>
  </div>


</div>
