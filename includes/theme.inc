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
	
	// change paths on javascripts
	if($theme_info['scripts'] && count($theme_info['scripts']) > 0){
		foreach($theme_info['scripts'] as $key => $javascript){
			$theme_info['scripts'][$key] = '<script type="text/javascript" src="' . CMS_ROOT_URL . 'themes/greenforest/' . $javascript . '"></script>';
		}
	}	
	
	// add system scripts to beginning of scripts array
	array_unshift($theme_info['scripts'], '<script type="text/javascript" src="' . CMS_ROOT_URL . 'includes/js/edit-menu.js"></script>');
	array_unshift($theme_info['scripts'], '<script type="text/javascript" src="' . CMS_ROOT_URL . 'libraries/jquery/js/jquery-ui-1.8.14.custom.min.js"></script>');	
	array_unshift($theme_info['scripts'], '<script type="text/javascript" src="' . CMS_ROOT_URL . 'libraries/jquery/js/jquery-1.5.1.min.js"></script>');
	
	// add system stylesheets to beginning of stylesheets array
	array_unshift($theme_info['stylesheets'], '<link rel="stylesheet" type="text/css" media="screen" href="' . CMS_ROOT_URL . 'libraries/jquery/css/ui-lightness/jquery-ui-1.8.14.custom.css" />');
	
	return $theme_info;
}

function render() {
	
	$theme_info = pre_render();
	
	$variables = array(
			'stylesheets' => implode("\n", $theme_info['stylesheets']),
			'javascripts' => implode("\n", $theme_info['scripts'])			
		);
	
	extract($variables, EXTR_SKIP);               // Extract the variables to a local namespace
	ob_start();                                   // Start output buffering
	include CMS_ROOT . '/themes/greenforest/index.tpl.php';   // Include the template file
	return ob_get_clean();                        // End buffering and return its contents
}