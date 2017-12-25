<?php

/**
*  Plugin definition
*/
$plugin = array(
  'title' => t('Custom access'),
  'description' => t('Showing the content depends on even/odd minute.'),
  'callback' => 'custom_access_switch_content',
  'settings form' => 'custom_access_ctools_access_settings',
  'summary' => 'custom_access_ctools_access_summary',
);

/**
 * Settings form for the 'custom access' access plugin
 */
function custom_access_ctools_access_settings($form, &$form_state, $conf) {
  // No additional configuration necessary.
  return $form;
}

/**
 * Provide a summary description.
 */
function custom_access_ctools_access_summary($conf, $context) {
  return t('Visible on even minute');
}

/**
 * Check for access.
 */
function custom_access_switch_content($conf, $context) {
    
  $current_minute = date('i');

  if ($current_minute % 2 == 0){
    //show content on even minute  
    return true; 
  } else {
    //hide content on odd minute
    return false;
  }
}
