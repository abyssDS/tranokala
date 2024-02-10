<?php
class HomeController{
	public function index(){
		// Logique métier pour récupérer des données
		$userModel = new UserModel();
		$users = $userModel->getAllUsers();

		// Chargement de la vue
		include('Views/home/index.php');
	}
}
?>
