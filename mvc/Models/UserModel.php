<?php
class UserModel {
	public function getAllUsers() {
		// Logique pour récupérer tous le utilisateurs depuis la base de données
		return array(
			array('id' => 1, 'name' => 'John'),
			array('id' => 2, 'name' => 'Jane')
		);
	}
}
?>
