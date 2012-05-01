<?php
session_start();
if( isset ($_POST['logout']))
{
	session_destroy();
	header( 'Location: /index.php' );
}
if( empty($_SESSION['Account_Type']) || $_SESSION['Account_Type'] != 'admin' ){
	header( 'Location: /index.php' );
}
?>
<html>
<body>
<h1>Hello <?php print $_SESSION['username']; ?></h1>
<a href="addTeacher.php">Add Teacher Here</a><br>
<a href="addAdmin.php">Add Admin Here</a><br>
<br><form action="index.php" method="post">
<input type="submit" value="Log Out" name="logout">
</form>
</body>
</html>