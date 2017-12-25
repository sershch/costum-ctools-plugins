<?php

/**
 * @file
 * Display a ctolls custom content type.
 *
 * Available variables:
 * - $data['#content']: array with node objects for custom content plugin.
 */
?>

<?php
?>
<div class="custom-content-paine">
    
<?php foreach ($data['#content'] as $node): ?>
    <b> <?php print l($node->title, "node/$node->nid"); ?></b>
    <p><i> <?php print format_date($node->created); ?></i></p>
<?php endforeach; ?>
    
</div>