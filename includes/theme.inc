<?php

function pre_render() {
	
	$theme_info_data = file_get_contents(CMS_ROOT . '/themes/greenforest/greenforest.info');
	$theme_info = parse_info_format($theme_info_data);
	
	// change paths on stylessheets
	if($theme_info['stylesheets'] && count($theme_info['stylesheets']) > 0){
		foreach($theme_info['stylesheets'] as $key => $stylesheet){
			$theme_info['stylesheets'][$key] = '<link rel="stylesheet" type="text/css" media="screen" href="' . CMS_ROOT_URL . 'themes/greenforest/' . $stylesheet . '" />';
		}
	}
	
	return $theme_info;
}

function render() {
	
	$theme_info = pre_render();
	
	$variables = array('stylesheets' => implode("\n", $theme_info['stylesheets']));
	
	extract($variables, EXTR_SKIP);               // Extract the variables to a local namespace
	ob_start();                                   // Start output buffering
	include CMS_ROOT . '/themes/greenforest/index.tpl.php';   // Include the template file
	return ob_get_clean();                        // End buffering and return its contents
}