<?php
session_start();
if( empty($_SESSION['Account_Type']) || $_SESSION['Account_Type'] != 'admin' ){
	header( 'Location: /index.php' );
}
?>
<?php
if( isset( $_POST['username']) && isset( $_POST['password'] ) && isset( $_POST['password_check']))
{
$username = $_POST['username'];
$password = $_POST['password'];
$cpassword = $_POST['password_check'];
$user='schoogl';
$pass='schoogl';
$db="SchooGL";
$link=@mysql_connect( "localhost", $user, $pass);

if ( ! $link ) {
	die ( "Couldn't connect to server".mysql_error() );
}
if ( ! mysql_select_db( $db, $link) ){
	die ( "Couldn't select database".mysql_error() );
}
$user_insert = true;
if ($password == $cpassword){
	$user_insert = "INSERT INTO Users(UserName,Password,Account_Type) VALUES ('$username','$password','teacher')";
}else
{
	print "Passwords do not match <form action=\"addTeacher.php\">\n<input type=\"submit\" value=\"back\">\n</form>";
	$user_insert = false;
}
if(!mysql_query( $user_insert, $link)){
	die( "Couldn't insert into database for user".mysql_error());
}
$id = mysql_insert_id();
$user_insert = "INSERT INTO Teachers(uID) VALUES ('$id')";
if(!mysql_query( $user_insert, $link)){
	die( "Couldn't insert into database for user".mysql_error());
}
print "<html>\n<body>\n<script type=\"text/javascript\">\nalert(\"Teacher Added\")\n</script>\n</body>\n</html>";


mysql_close($link);
}
?>

<html>
<body>
<form name="login" action="<?php print $_SERVER['PHP_SELF']?>" method="post">
Username:
<input type="text" name="username"><br>
Password:
<input type="text" name="password"><br>
Re-enter Password:
<input type="text" name="password_check"><br>
<input type="submit" value="Submit"> <br>
</form>
<form action="index.php"><input type="submit" value="Back"></form>
</body>
</html>