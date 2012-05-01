<?php
session_start();
if( isset( $_POST['username'] ) && isset( $_POST['password'] ) )
{
$user='schoogl';
$pass='schoogl';
$db="SchooGL";
$link=@mysql_connect( "localhost", $user, $pass );
if ( ! $link ){
	die ( "Couldn't connect to server".mysql_error() );
}
@mysql_select_db( $db ) or die ("couldn't open $db".mysql_error() );
$result = mysql_query( "SELECT * FROM Users WHERE Users.UserName = '{$_POST['username']}' AND Users.Password = '{$_POST['password']}'");

$num_rows = mysql_num_rows( $result );
$row = mysql_fetch_array( $result );

if ( $row['UserName'] == $_POST['username'] && $row['Password'] == $_POST['password'] )
{
	//sucess
	$_SESSION['Account_Type'] = stripslashes($row['Account_Type']);
	$_SESSION['uID'] = stripslashes($row['uID']);
	$_SESSION['username'] = stripslashes($row['UserName']);
	switch(stripslashes( $row['Account_Type'] ) ){
		case "teacher":
			header( 'Location: teacher/index.php' );
			break;
		case "admin":
			header( 'Location: admin/index.php' );
			break;
		case "student":
			$result = mysql_query( "SELECT * FROM Users,Students WHERE Users.UserName = '{$_POST['username']}' AND Users.Password = '{$_POST['password']}'");

			$num_rows = mysql_num_rows( $result );
			$row = mysql_fetch_array( $result );

			$_SESSION['teacher'] = stripslashes($row['teacher_id']);
			header( 'Location: student/index.php' );
			break;
		default:
			$message = "logged in";
	}
	
}
else
{
	//failure
	$message = "incorrect login!";
}
mysql_close($link);
}
else 
{

}
?>
<html>
<body>

<h1>SchooGL Login Page</h1>
<?php print $message ?>

<form name="login" action="<?php print $_SERVER['PHP_SELF']?>" method="post">

Username:
<input type="text" name="username"><br>
Password:
<input type="password" name="password"><br>
<input type="submit" value="Submit">
<input type="reset" Value="Reset">

</form>

</body>
</html>