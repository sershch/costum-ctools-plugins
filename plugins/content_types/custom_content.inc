<?php

/**
*  Plugin definition
*/
$plugin = array(
  'title' => t('Custom content'),
  'description' => t('Render a custom node fields.'),
  'category' => t('Custom panes'),
  'render callback' => 'custom_content_type_render',
  'edit form' => 'custom_content_type_edit_form',
  'single' => TRUE,
);


/**
 * Edit form callback for the content type.
 */
function custom_content_type_edit_form($form, &$form_state) {
  // Get settings
  $conf = $form_state['conf'];

  $form['number_integer'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of nodes'),
    '#size' => 60, 
    '#maxlength' => 128, 
    '#required' => TRUE,
    '#default_value' => !empty($conf['limit']) ? $conf['limit'] : 1,
  );

  return $form;
}

/**
 * Submit callback for the custom_content_type_edit_form().
 */
function custom_content_type_edit_form_submit($form, &$form_state) {
  // Saveing settings 
  $form_state['conf'] = array(
    'limit' => $form_state['values']['number_integer'],
  );
}

/**
 * Render callback for the content type.
 */
function custom_content_type_render($subtype, $conf, $args, $context) {
    
  $limit = $conf['limit'];
  
  //limit nodes
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->propertyCondition('status', 1)
    ->propertyOrderBy('created', 'DESC')
    ->range(0, $limit);
  $result = $query->execute();
  
  $nodes = array();
  if (isset($result['node'])) {
    $nids = array_keys($result['node']);
    //get node objects
    $nodes = node_load_multiple($nids, array());
  }
  
  $content = array(
      '#theme' => 'custom_content',
      '#content' => $nodes,
  );
    
  $block = new stdClass();
  $block->content = $content;
  
  return $block;
}