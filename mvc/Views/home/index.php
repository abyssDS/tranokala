<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<title>Home Page</title>
</head>
<body>
	<h1>List of Users</h1>
	<u1>
	<?php foreach($users as $user): ?>
		<li><?php echo $user['name']; ?></li>
	<?php endforeach; ?>
	</ul>
</body>
</html>
