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
     <p>Lebowski ipsum hey! This is a private residence, man! Dolor sit amet, consectetur adipiscing elit praesent ac. Please see him, Jeffrey. He's a good man. And thorough. Magna justo pellentesque ac lectus quis elit blandit fringilla a ut turpis praesent. And yet his son is a fucking dunce. Felis ligula, malesuada suscipit malesuada non, ultrices non urna sed orci ipsum. They call Los Angeles the City of Angels. I didn't find it to be that exactly, but I'll allow as there are some nice folks there. 'Course, I can't say I seen London, and I never been to France, and I ain't never seen no queen in her damn undies as the fella says. But I'll tell you what, after seeing Los Angeles and thisahere story I'm about to unfold —wal, I guess I seen somethin' ever' bit as stupefyin' as ya'd see in any a those other places, and in English too, so I can die with a smile on my face without feelin' like the good Lord gypped me. Placerat id condimentum rutrum, rhoncus ac.</p>
   </div> <!-- proj-deets -->
   <div class="proj-status">
     <p>
     Obviously you're not a golfer. Lorem aliquam placerat posuere neque, at dignissim magna. I'm unemployed. Ullamcorper in aliquam sagittis massa ac tortor ultrices faucibus curabitur eu mi. That fucking bitch! Sapien, ut ultricies ipsum morbi eget. One a those days, huh. Wal, a wiser fella than m'self once said, sometimes you eat the bar and sometimes the bar, wal, he eats you. Risus nulla nullam vel nisi enim, vel auctor ante morbi.
     </p>
   </div> <!-- proj-status -->
   <div class="proj-desc">
     <p>
     Well sir, it's this rug I have, really tied the room together. Id urna vel felis lacinia placerat vestibulum turpis nulla, viverra nec volutpat ac. WALTER, FOR CHRIST'S SAKE! HE'S CRIPPLED! PUT HIM DOWN! Ornare id lectus cras pharetra faucibus tristique nullam non accumsan justo nulla facilisi. You want a toe? I can get you a toe, believe me. There are ways, Dude. You don't wanna know about it, believe me. Integer interdum elementum nulla, nec eleifend nisl euismod ac maecenas vitae eros velit.
     </p>
   </div> <!-- proj-desc -->
   <div class="proj-resources">
     <p>
     Obviously you're not a golfer. Lorem aliquam placerat posuere neque, at dignissim magna. I'm unemployed. Ullamcorper in aliquam sagittis massa ac tortor ultrices faucibus curabitur eu mi. That fucking bitch! Sapien, ut ultricies ipsum morbi eget. One a those days, huh. Wal, a wiser fella than m'self once said, sometimes you eat the bar and sometimes the bar, wal, he eats you. Risus nulla nullam vel nisi enim, vel auctor ante morbi.
     </p>
   </div> <!-- proj-resources -->
 </div> <!-- proj-info -->

 <div class="proj-contribs">
 </div> <!-- proj-contribs -->

 <div class="proj-updates">
 </div> <!-- proj-updates -->

 <div class="proj-comments">
 </div> <!-- proj-comments -->
</div>

<div class="proj-bounties">
 <div class="proj-avail">
 </div> <!-- proj-avail -->
 <div class="proj-taken">
 </div> <!-- proj-taken -->
</div> <!-- proj-bounties -->









1