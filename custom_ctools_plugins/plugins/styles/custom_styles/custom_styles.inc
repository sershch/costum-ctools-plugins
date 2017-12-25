<?php

/**
 * @file
 *  Allow to display custom region style.
 */

/**
 * Plugin definition
 */
$plugin = array(
  'title' => t('Custom styles'),
  'description' => t('Custom css styles for the region'),
  'render region' => 'custom_styles_render_region',
  'hook theme' => array(
    'custom_styles' => array(
      'variables' => array(
        'content' => NULL,
      ),
      'template' => 'custom-styles',
      'path' => drupal_get_path('module', 'custom_ctools_plugins') . '/plugins/styles/custom_styles',
    ),
  ),
);

/**
 * Render callback.
 */
function theme_custom_styles_render_region($vars) {
  drupal_add_css(drupal_get_path('module', 'custom_ctools_plugins') . '/plugins/styles/custom_styles/custom_styles.css', array('group' => CSS_DEFAULT, 'every_page' => TRUE));
  $content = implode($vars['panes']);
  return theme('custom_styles', array('content' => $content));
}
