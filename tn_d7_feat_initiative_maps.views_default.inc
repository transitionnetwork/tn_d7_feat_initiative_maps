<?php
/**
 * @file
 * tn_d7_feat_initiative_maps.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function tn_d7_feat_initiative_maps_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'tn_initiatives_maps';
  $view->description = 'A set of lists, searches and directories for Initiatives';
  $view->tag = 'Transition Network';
  $view->base_table = 'node';
  $view->human_name = 'TN - Initiatives maps';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Initiatives';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'leaflet';
  $handler->display->display_options['style_options']['data_source'] = 'field_coordinates';
  $handler->display->display_options['style_options']['name_field'] = 'title';
  $handler->display->display_options['style_options']['description_field'] = 'field_summary';
  $handler->display->display_options['style_options']['map'] = 'google-high-res';
  $handler->display->display_options['style_options']['zoom']['initialZoom'] = '-1';
  $handler->display->display_options['style_options']['zoom']['minZoom'] = '0';
  $handler->display->display_options['style_options']['zoom']['maxZoom'] = '18';
  $handler->display->display_options['style_options']['vector_display']['stroke'] = 0;
  $handler->display->display_options['style_options']['vector_display']['fill'] = 0;
  $handler->display->display_options['style_options']['vector_display']['clickable'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['table'] = 'field_data_field_location';
  $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['label'] = '';
  $handler->display->display_options['fields']['field_location']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_location']['alter']['text'] = '[field_location-locality], [field_location-country]';
  $handler->display->display_options['fields']['field_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_location']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_location']['settings'] = array(
    'use_widget_handlers' => 0,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Summary */
  $handler->display->display_options['fields']['field_summary']['id'] = 'field_summary';
  $handler->display->display_options['fields']['field_summary']['table'] = 'field_data_field_summary';
  $handler->display->display_options['fields']['field_summary']['field'] = 'field_summary';
  $handler->display->display_options['fields']['field_summary']['label'] = '';
  $handler->display->display_options['fields']['field_summary']['alter']['max_length'] = '300';
  $handler->display->display_options['fields']['field_summary']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_summary']['element_label_colon'] = FALSE;
  /* Field: Content: Coordinates */
  $handler->display->display_options['fields']['field_coordinates']['id'] = 'field_coordinates';
  $handler->display->display_options['fields']['field_coordinates']['table'] = 'field_data_field_coordinates';
  $handler->display->display_options['fields']['field_coordinates']['field'] = 'field_coordinates';
  $handler->display->display_options['fields']['field_coordinates']['label'] = '';
  $handler->display->display_options['fields']['field_coordinates']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_coordinates']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_coordinates']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_coordinates']['type'] = 'geofield_latlon';
  $handler->display->display_options['fields']['field_coordinates']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
    'labels' => 1,
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Location - Country */
  $handler->display->display_options['arguments']['field_location_country']['id'] = 'field_location_country';
  $handler->display->display_options['arguments']['field_location_country']['table'] = 'field_data_field_location';
  $handler->display->display_options['arguments']['field_location_country']['field'] = 'field_location_country';
  $handler->display->display_options['arguments']['field_location_country']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_location_country']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_location_country']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_location_country']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_location_country']['limit'] = '0';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    6 => 0,
    3 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Coordinates (field_coordinates:lon) */
  $handler->display->display_options['filters']['field_coordinates_lon']['id'] = 'field_coordinates_lon';
  $handler->display->display_options['filters']['field_coordinates_lon']['table'] = 'field_data_field_coordinates';
  $handler->display->display_options['filters']['field_coordinates_lon']['field'] = 'field_coordinates_lon';
  $handler->display->display_options['filters']['field_coordinates_lon']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_coordinates_lon']['expose']['operator_id'] = 'field_coordinates_lon_op';
  $handler->display->display_options['filters']['field_coordinates_lon']['expose']['label'] = 'Coordinates (field_coordinates:lon)';
  $handler->display->display_options['filters']['field_coordinates_lon']['expose']['operator'] = 'field_coordinates_lon_op';
  $handler->display->display_options['filters']['field_coordinates_lon']['expose']['identifier'] = 'field_coordinates_lon';
  /* Filter criterion: Content: Coordinates (field_coordinates:lat) */
  $handler->display->display_options['filters']['field_coordinates_lat']['id'] = 'field_coordinates_lat';
  $handler->display->display_options['filters']['field_coordinates_lat']['table'] = 'field_data_field_coordinates';
  $handler->display->display_options['filters']['field_coordinates_lat']['field'] = 'field_coordinates_lat';
  $handler->display->display_options['filters']['field_coordinates_lat']['operator'] = 'not empty';

  /* Display: Google map */
  $handler = $view->new_display('panel_pane', 'Google map', 'panel_pane_2');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'ip_geoloc_map';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => '',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['ip_geoloc_views_plugin_latitude'] = 'field_coordinates';
  $handler->display->display_options['style_options']['ip_geoloc_views_plugin_longitude'] = '';
  $handler->display->display_options['style_options']['default_marker_color'] = 'green';
  $handler->display->display_options['style_options']['center_option'] = '3';
  $handler->display->display_options['style_options']['gps_roles'] = array(
    1 => '1',
    2 => '2',
    4 => 0,
    6 => 0,
    3 => 0,
    5 => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['pane_category']['name'] = 'Transition Network';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 'exposed_form';
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'field_location_country' => array(
      'type' => 'context',
      'context' => 'entity:country.iso2',
      'context_optional' => 1,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Location - Country',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Leaflet map */
  $handler = $view->new_display('panel_pane', 'Leaflet map', 'panel_pane_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'ip_geoloc_leaflet';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => '',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['ip_geoloc_views_plugin_latitude'] = 'field_coordinates';
  $handler->display->display_options['style_options']['ip_geoloc_views_plugin_longitude'] = '';
  $handler->display->display_options['style_options']['default_marker_color'] = 'green';
  $handler->display->display_options['style_options']['center_option'] = '0';
  $handler->display->display_options['style_options']['empty_map_center'] = 'visitor';
  $handler->display->display_options['style_options']['visitor_marker_color'] = 'blue';
  $handler->display->display_options['style_options']['map'] = 'google-high-res';
  $handler->display->display_options['style_options']['map_height'] = '300';
  $handler->display->display_options['style_options']['tooltips']['marker_tooltip'] = 'title';
  $handler->display->display_options['style_options']['map_options']['maxzoom'] = '18';
  $handler->display->display_options['style_options']['map_options']['zoom'] = '2';
  $handler->display->display_options['style_options']['map_options']['scrollwheelzoom'] = '1';
  $handler->display->display_options['style_options']['map_options']['dragging'] = '1';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['pane_category']['name'] = 'Transition Network';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 'exposed_form';
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'field_location_country' => array(
      'type' => 'context',
      'context' => 'entity:country.iso2',
      'context_optional' => 1,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Location - Country',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'initiatives/map';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Ini map';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['tn_initiatives_maps'] = array(
    t('Master'),
    t('Initiatives'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('[field_location-locality], [field_location-country]'),
    t('All'),
    t('Type'),
    t('Coordinates (field_coordinates:lon)'),
    t('Google map'),
    t('Transition Network'),
    t('Leaflet map'),
    t('Page'),
  );
  $export['tn_initiatives_maps'] = $view;

  return $export;
}
