<?php

/**
*  Plugin definition
*/
$plugin = array(
  'title' => t('Custom access'),
  'description' => t('Switch the content by interval.'),
  'category' => t('Custom access'),
  'callback' => 'custom_access_switch_content',
  'defaults' => array(),
);

/**
 * callback.
 */
function custom_access_switch_content($conf, $context) {
        
  drupal_add_js(drupal_get_path('module', 'custom_ctools_plugins') . '/js/script.js');
  
  return true;
}
