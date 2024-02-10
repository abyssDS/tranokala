<?php
// Autoload des classes
function __autoload($class_name) {
	include 'app/' .$class_name . '.php';
}

// Routage des requêtes
$action = isset($_GET['action']) ? $_GET[,ACTION,] : 'index';
$controller = new HomeController();

// Appel de la méthode appropriée du contrôleur
$controller->$action();
?>
