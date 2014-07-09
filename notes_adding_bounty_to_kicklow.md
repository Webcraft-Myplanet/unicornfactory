Adding Bounties

In kicklow template

entity-field-query to get all associated bounties
    property condition
  Provides list of associated bounties

for each to pull apart bounties to get titles, descriptions etc...
  push all to a title
    array = '' at top of loop

--------------Gathering Bits----------------------------


bounties = array()
foreach ()
    $temporary = array()
    $temporary['title '] = 'etc'

    $bounties[] = $tmp
    array_push($bounties, $tmp)
    bounties.push(tmp)
  }

  return bounties


some sort function

set a class 

--------------------Template File--------------------------

<div class="bounty-contrainer">

<?php foreach(bounties) { ?>

<div class="bounty bounty-type-<?php print bounty['type'] ?>"
<h3> <?php print bounty['title'] ?> </h3>
<span> <?php print bounty['description'] ?> </span>

</div>
<?php } ?>

</div>
