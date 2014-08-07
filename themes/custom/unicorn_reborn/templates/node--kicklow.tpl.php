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

<div class="proj-wrapper clearfix">
  <div class="proj-info box">
    <h2>Project Information</h2>

    <div class="proj-deets clearfix box">
      <div class="proj-owner"> <?php print $name ?></div>
      <div class="proj-type"><?php print $project_type ?></div>
      <div class="proj-date"><?php print $date ?></div>
    </div> <!-- proj-deets -->

    <div class="proj-status box">
      <div class="chart1">
        <canvas id="totalProgressChart" width="200" height="200"></canvas>
        <h2 class="title">Total Progress</h2>
      </div>
      <div class="chart1">
        <canvas id="kicklowChart" width="200" height="200"></canvas>
        <h2 class="title">Kicklow Progress</h2>
      </div>
      <div class="chart1">
        <canvas id="bountyChart" width="200" height="200"></canvas>
        <h2 class="title">Bounty Progress</h2>
      </div>
      <div class="stats">
        <ul>
          <li><?php print $total_contribs; ?> Contributors</li>
          <li><?php print $total_bounties; ?> Bounties</li>
          <li><?php print $total_updates; ?> Updates</li>
          <li><?php print $comment_count; ?> Comments</li>
        </ul>
      </div>
    </div> <!-- proj-status -->
    <div class="desc-resources clearfix box">
      <div class="proj-desc">
       <h3>Description</h3>
       <?php print $proj_desc ?>
      </div> <!-- proj-desc -->
      <div class="proj-resources">
       <h3>Resources</h3>
       <div class="one-res"><?php print $resources ?></div>
      </div> <!-- proj-resources -->
    </div> <!-- desc-resource -->

    <div class="proj-contribs box">
      <h2>Contributors</h2>.
      <?php print $contribs ?>
    </div> <!-- proj-contribs -->

    <div class="all-bounties bounties-mobile">
      <span class="filter-button">Filter bounties</span>
      <ul class="filter">
        <li value="my bounties">My Bounties</li>
        <li value="all">All</li>
        <li value="open">Open</li>
        <li value="in_progress">In Progress</li>
        <li value="postponed">Postponed</li>
        <li value="closed">Closed</li>
      </ul>

      <div class="bounty-user">
        <!-- fail statement in case not open bounty -->
        <?php if (!empty($bounties['current_user_bounty'])): ?>
          <?php foreach ($bounties['current_user_bounty'] as $bounty): ?>
            <div class="bounty">
              <div class="headline">
                <h4 class="bounty-title"><?php print $bounty['title']; ?></h4>
                <p class="bounty-date">Posted: <?php print $bounty['date']; ?></p>
              </div>
              <button><a href="/node/<?php print($bounty['node_id'])?>">Apply</a></button>
              <div class="bounty-desc trunk"><?php print $bounty['description']; ?></div>
              <div class="expand-button clearfix"><p>See More</p></div>
            </div>
          <?php endforeach; ?>
        <?php endif; ?>
      </div>

      <div class="bounty-open all">
        <!-- fail statement in case not open bounty -->
        <?php if (!empty($bounties['Open '])): ?>

          <?php foreach ($bounties['Open '] as $bounty): ?>
            <div class="bounty">
              <div class="headline">
                <h4 class="bounty-title"><?php print $bounty['title']; ?></h4>
                <p class="bounty-date">Posted: <?php print $bounty['date']; ?></p>
              </div>
              <button><a href="/node/<?php print($bounty['node_id'])?>">Apply</a></button>
              <div class="bounty-desc trunk"><?php print $bounty['description']; ?></div>
              <div class="expand-button clearfix"><p>See More</p></div>
            </div>
          <?php endforeach; ?>
        <?php endif; ?>
      </div>

      <div class="bounty-in-progress all">
       <!-- fail statement in case not open bounty -->
        <?php if (!empty($bounties['In Progress '])): ?>

          <?php foreach ($bounties['In Progress '] as $bounty): ?>
            <div class="bounty">
              <div class="headline">
                <h4 class="bounty-title"><?php print $bounty['title']; ?></h4>
                <?php if (!empty($bounty['owner_img'])): ?>
                  <img class="owner-img" src="<?php print($bounty['owner_img'])?>">
                <?php endif; ?>
                <h5 class="bounty-date">Posted: <?php print $bounty['date']; ?></h5>
              </div>
              <div class="bounty-desc trunk"><?php print $bounty['description']; ?></div>
              <div class="expand-button clearfix"><p>See More</p></div>
            </div>
          <?php endforeach; ?>
        <?php endif; ?>
      </div>

      <div class="bounty-postponed all">
        <!-- fail statement in case not open bounty -->
        <?php if (!empty($bounties['Postponed '])): ?>
          <?php foreach ($bounties['Postponed '] as $bounty): ?>
            <div class="bounty-postponed all">
              <div class="bounty">
                <div class="headline">
                  <h4 class="bounty-title"><?php print $bounty['title']; ?></h4>
                  <?php if (!empty($bounty['owner_img'])): ?>
                    <img class="owner-img" src="<?php print($bounty['owner_img'])?>">
                  <?php endif; ?>
                  <h5 class="bounty-date">Posted: <?php print $bounty['date']; ?></h5>
                </div>
                <div class="bounty-desc trunk"><?php print $bounty['description']; ?></div>
                <div class="expand-button clearfix"><p>See More</p></div>
            </div>
          <?php endforeach; ?>
        <?php endif; ?>
      </div>

      <div class="bounty-closed all">
        <!-- fail statement in case not open bounty -->
        <?php if (!empty($bounties['Closed '])): ?>
          <?php foreach ($bounties['Closed '] as $bounty): ?>
            <div class="bounty">
              <div class="headline">
                <h4 class="bounty-title"><?php print $bounty['title']; ?></h4>
                <?php if (!empty($bounty['owner_img'])): ?>
                  <img class="owner-img" src="<?php print($bounty['owner_img'])?>">
                <?php endif; ?>
                <p class="bounty-date">Posted: <?php print $bounty['date']; ?></p>
              </div>
            </div>
          <?php endforeach; ?>
        <?php endif; ?>
      </div>
    </div><!-- all-bounties -->

    <div class="proj-updates box trunk">
     <h2>Updates</h2>
     <div class="one-update"><?php print $updates ?></div>
    </div> <!-- proj-updates -->

    <div class="proj-comments box">
      <h2>Comments</h2>
      <?php print render($content['comments']); ?>
    </div><!-- proj-comments -->
  </div> <!-- proj-info -->

  <div class="all-bounties bounties-desktop">
    <span value="my bounties" class="filter-button">My Bounties</span>
    <ul class="filter">
      <li value="all">All</li>
      <li value="open">Open</li>
      <li value="in_progress">In Progress</li>
      <li value="postponed">Postponed</li>
      <li value="closed">Closed</li>
    </ul>

    <div class="bounty-user">
      <!-- fail statement in case not open bounty -->
      <?php if (!empty($bounties['current_user_bounty'])): ?>
        <?php foreach ($bounties['current_user_bounty'] as $bounty): ?>
          <div class="bounty">
            <div class="headline">
              <h4 class="bounty-title"><?php print $bounty['title']; ?></h4>
              <p class="bounty-date">Posted: <?php print $bounty['date']; ?></p>
            </div>
            <button><a href="/node/<?php print($bounty['node_id'])?>">Apply</a></button>
            <div class="bounty-desc trunk"><?php print $bounty['description']; ?></div>
            <div class="expand-button clearfix"><p>See More</p></div>
          </div>
        <?php endforeach; ?>
      <?php endif; ?>
    </div>

    <div class="bounty-open all">
      <!-- fail statement in case not open bounty -->
      <?php if (!empty($bounties['Open '])): ?>
        <?php foreach ($bounties['Open '] as $bounty): ?>
          <div class="bounty">
            <div class="headline">
              <h4 class="bounty-title"><?php print $bounty['title']; ?></h4>
              <?php if (!empty($bounty['owner_img'])): ?>
                <img class="owner-img" src="<?php print($bounty['owner_img'])?>">
              <?php endif; ?>
              <h5 class="bounty-date">Posted: <?php print $bounty['date']; ?></h5>
            </div>
            <button><a href="/node/<?php print($bounty['node_id'])?>">Apply</a></button>
            <div class="bounty-desc trunk"><?php print $bounty['description']; ?></div>
            <div class="expand-button clearfix"><p>See More</p></div>
          </div>
        <?php endforeach; ?>
      <?php endif; ?>
    </div>

    <div class="bounty-in-progress all">
     <!-- fail statement in case not open bounty -->
      <?php if (!empty($bounties['In Progress '])): ?>
        <?php foreach ($bounties['In Progress '] as $bounty): ?>
          <div class="bounty">
            <div class="headline">
              <h4 class="bounty-title"><?php print $bounty['title']; ?></h4>
              <?php if (!empty($bounty['owner_img'])): ?>
                <img class="owner-img" src="<?php print($bounty['owner_img'])?>">
              <?php endif; ?>
              <h5 class="bounty-date">Posted: <?php print $bounty['date']; ?></h5>
            </div>
            <div class="bounty-desc trunk"><?php print $bounty['description']; ?></div>
            <div class="expand-button clearfix"><p>See More</p></div>
          </div>
        <?php endforeach; ?>
      <?php endif; ?>
    </div>

    <div class="bounty-postponed all">
      <!-- fail statement in case not open bounty -->
      <?php if (!empty($bounties['Postponed '])): ?>
        <?php foreach ($bounties['Postponed '] as $bounty): ?>
          <div class="bounty-postponed all">
            <div class="bounty">
              <div class="headline">
                <h4 class="bounty-title"><?php print $bounty['title']; ?></h4>
                <?php if (!empty($bounty['owner_img'])): ?>
                  <img class="owner-img" src="<?php print($bounty['owner_img'])?>">
                <?php endif; ?>
                <h5 class="bounty-date">Posted: <?php print $bounty['date']; ?></h5>
              </div>
              <div class="bounty-desc trunk"><?php print $bounty['description']; ?></div>
              <div class="expand-button clearfix"><p>See More</p></div>
          </div>
        <?php endforeach; ?>
      <?php endif; ?>
    </div>

    <div class="bounty-closed all">
      <!-- fail statement in case not open bounty -->
      <?php if (!empty($bounties['Closed '])): ?>
        <?php foreach ($bounties['Closed '] as $bounty): ?>
          <div class="bounty">
            <div class="headline">
              <h4 class="bounty-title"><?php print $bounty['title']; ?></h4>
              <?php if (!empty($bounty['owner_img'])): ?>
                <img class="owner-img" src="<?php print($bounty['owner_img'])?>">
              <?php endif; ?>
              <h5 class="bounty-date">Posted: <?php print $bounty['date']; ?></h5>
            </div>
          </div>
        <?php endforeach; ?>
      <?php endif; ?>
    </div>
  </div><!-- all-bounties -->
</div>
