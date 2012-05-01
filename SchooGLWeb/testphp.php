<?php
if( isset ( $_POST['uID'] ) && isset ( $_POST['UserName']) && isset ( $_POST['Password']) && isset ( $_POST['Account_Type']) && isset ( $_POST['submit']) )
{
$ID=$_POST['uID'];
$username=$_POST['UserName'];
$password=$_POST['Password'];
$account=$_POST['Account_Type'];
//user name and password for connection
$user="schoogl";
$pass="schoogl";
$db="SchooGL";
//open connection
$link=@mysql_connect( "gensrv.baens.net", $user, $pass );
if ( ! $link ){
	die ( "Couldn't connect to server".mysql_error() );
}

//select the database
@mysql_select_db( $db ) or die ("couldn't open $db".mysql_error() );

//remove entry
mysql_query("UPDATE Users SET UserName = '$username', Password = '$password', Account_Type = '$account' WHERE uID = '$ID'");
$message = "yay updated!";
}
if( isset ( $_POST['uID'] ) && isset ( $_POST['remove']) )
{
$ID=$_POST['uID'];
//user name and password for connection
$user="schoogl";
$pass="schoogl";
$db="SchooGL";
//open connection
$link=@mysql_connect( "gensrv.baens.net", $user, $pass );
if ( ! $link ){
	die ( "Couldn't connect to server".mysql_error() );
}

//select the database
@mysql_select_db( $db ) or die ("couldn't open $db".mysql_error() );

//remove entry
mysql_query("DELETE FROM Users WHERE uID = '$ID'");
$message = "yay deletion!";
}
?>
<html>
<body>
<?php
print $message;
//user name and password for connection
$user="schoogl";
$pass="schoogl";
$db="SchooGL";
//open connection
$link=@mysql_connect( "gensrv.baens.net", $user, $pass );
if ( ! $link ){
	die ( "Couldn't connect to server".mysql_error() );
}

//select the database
@mysql_select_db( $db ) or die ("couldn't open $db".mysql_error() );

//setup the query and store the result
$result = mysql_query( "SELECT * FROM Users");

//start the table
print "<table border=\"1\">\n";

//iterate through each row and column
while ($a_row = mysql_fetch_row($result) ) {
	//store user ID
	$uID = mysql_query( "SELECT uId FROM Users");
	//start new row
	print "<form action=\"".$_SERVER['PHP_SELF']."\" method=\"post\"><tr>\n";
	//go through each column
	$x=0;
	foreach($a_row as $field){
		$colum = mysql_field_name($result,$x++);
		print "\t<td><input type=\"text\" name=\"".$colum."\" value=\"".stripslashes($field)."\"></td>\n";
	}
	//end row
	print "<td><input type=\"submit\" name=\"submit\" value=\"Submit Row\"></td>\n<td><input type=\"reset\" value=\"Reset\"></td>\n<td><input type=\"submit\" name=\"remove\" value=\"Remove\"></td>\n</tr>\n</form>\n";
}
//end table
print "</table>\n";

//close connection
mysql_close($link);
?>
</body>
</html>