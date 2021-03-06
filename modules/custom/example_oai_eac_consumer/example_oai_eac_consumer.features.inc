<?php
/**
 * @file
 * example_oai_eac_consumer.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function example_oai_eac_consumer_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function example_oai_eac_consumer_node_info() {
  $items = array(
    'oai_repository_eac_cpf' => array(
      'name' => t('OAI EAC repository'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
