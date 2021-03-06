<?php
/**
 * @file
 * example_oai_eac_consumer.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function example_oai_eac_consumer_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'example_oai_phm_eac_cpf';
  $feeds_importer->config = array(
    'name' => 'Example OAI-PHM EAC-CPF',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsOAIHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'last_fetched_timestamp' => '',
        'earliest_timestamp' => '',
        'use_dates' => FALSE,
        'to' => array(),
        'from' => array(),
        'metadata_prefix' => 'eac-cpf',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'metadata/eac-cpf/cpfDescription/identity/nameEntry/part[localType="surname"]',
          'xpathparser:1' => 'metadata/eac-cpf/cpfDescription/identity/nameEntry/part[localType="forename"]',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
        ),
        'context' => '/OAI-PMH/ListRecords/record',
        'exp' => array(
          'errors' => 0,
          'tidy' => 0,
          'tidy_encoding' => 'UTF8',
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
          ),
        ),
        'allow_override' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'field_name:family',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'field_name:given',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'body',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'title',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'guid',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'full_html',
        'skip_hash_check' => 0,
        'bundle' => 'person',
      ),
    ),
    'content_type' => 'oai_repository_eac_cpf',
    'update' => 0,
    'import_period' => '1800',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['example_oai_phm_eac_cpf'] = $feeds_importer;

  return $export;
}
