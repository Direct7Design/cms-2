<?php

	define('CMS_ROOT', getcwd());
	$path = substr(__FILE__, strlen($_SERVER["DOCUMENT_ROOT"]));
	define('CMS_ROOT_URL', "http" . ((isset($_SERVER['https']))? "s" : "") . "://" . $_SERVER["HTTP_HOST"] . dirname($path) . '/');

	require_once 'includes/common.inc';	
	require_once 'includes/theme.inc';

	// need to move to bootstrap process
	if(!isset($_GET['q'])) {
	  $request_path = strtok($_SERVER['REQUEST_URI'], '?');
	  $base_path_len = strlen(rtrim(dirname($_SERVER['SCRIPT_NAME']), '\/'));
	  $_GET['q'] = substr(urldecode($request_path), $base_path_len + 1);
	}
	
	print render();