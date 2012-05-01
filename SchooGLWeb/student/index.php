<?php
session_start();
if( isset ($_POST['logout']))
{
	session_destroy();
	header( 'Location: /index.php' );
}
if( empty($_SESSION['Account_Type']) || $_SESSION['Account_Type'] != 'student' ){
	header( 'Location: /index.php' );
}
?>
<html>
<body>
<h1>Hello <?php print $_SESSION['username']; ?></h1>
<a href="Students.php">Where do you stand with your class</a><br>
<a href="stats.php">View Your Stats</a><br>
<a href="Profile.php">Change your profile</a><br>
<br><form action="index.php" method="post">
<input type="submit" value="Log Out" name="logout">
</form>
</body>
</html>