<?php
session_start();
if( empty($_SESSION['Account_Type']) || $_SESSION['Account_Type'] != 'student' ){
	header( 'Location: /index.php' );
}
?>
<?php
if( isset ( $_POST['nickname'] ) && isset ( $_POST['color']) )
{
$nickname=$_POST['nickname'];
$color=$_POST['color'];
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

//update
if($color=="white")
	mysql_query("UPDATE Students SET student_alias = '$nickname', Red = '1', Green = '1', Blue = '1' WHERE uID = '".stripslashes($_SESSION['uID'])."'");
if($color=="red")
	mysql_query("UPDATE Students SET student_alias = '$nickname', Red = '1', Green = '0', Blue = '0' WHERE uID = '".stripslashes($_SESSION['uID'])."'");
if($color=="green")
	mysql_query("UPDATE Students SET student_alias = '$nickname', Red = '0', Green = '1', Blue = '0' WHERE uID = '".stripslashes($_SESSION['uID'])."'");
if($color=="blue")
	mysql_query("UPDATE Students SET student_alias = '$nickname', Red = '0', Green = '0', Blue = '1' WHERE uID = '".stripslashes($_SESSION['uID'])."'");
if($color=="pink")
	mysql_query("UPDATE Students SET student_alias = '$nickname', Red = '1', Green = '0', Blue = '.5' WHERE uID = '".stripslashes($_SESSION['uID'])."'");

print "<html>\n<body>\n<script type=\"text/javascript\">\nalert(\"Profile updated\")\n</script>\n</body>\n</html>";

}
?>
<html>
<body>
<?php

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
$result = mysql_query( "SELECT * FROM Students WHERE uID = '".stripslashes($_SESSION['uID'])."'");

//iterate through each row and column
$a_row = mysql_fetch_array($result , MYSQL_ASSOC);
print "<form action=\"".$_SERVER['PHP_SELF']."\" method=\"post\"><tr>\n";
print "NickName<input type=\"text\" name=\"nickname\" value=\"".stripslashes($a_row['student_alias'])."\"><br>\n";
print "Color<select name=\"color\"><br>\n";
if($a_row['Red'] == 1 && $a_row['Green'] == 1 && $a_row['Blue'] == 1)
{
	print "<option value=\"white\" selected=\"selected\">White</option><br>\n";
	print "<option value=\"red\">Red</option><br>\n";
	print "<option value=\"green\">Green</option><br>\n";
	print "<option value=\"blue\">Blue</option><br>\n";
	print "<option value=\"pink\">Pink</option><br>\n";
}
else if($a_row['Red'] == 1 && $a_row['Green'] == 0 && $a_row['Blue'] == 0)
{
	print "<option value=\"white\">White</option><br>\n";
	print "<option value=\"red\" selected=\"selected\">Red</option><br>\n";
	print "<option value=\"green\">Green</option><br>\n";
	print "<option value=\"blue\">Blue</option><br>\n";
	print "<option value=\"pink\">Pink</option><br>\n";
}
else if($a_row['Red'] == 0 && $a_row['Green'] == 1 && $a_row['Blue'] == 0)
{
	print "<option value=\"white\">White</option><br>\n";
	print "<option value=\"red\">Red</option><br>\n";
	print "<option value=\"green\" selected=\"selected\">Green</option><br>\n";
	print "<option value=\"blue\">Blue</option><br>\n";
	print "<option value=\"pink\">Pink</option><br>\n";
}
else if($a_row['Red'] == 0 && $a_row['Green'] == 0 && $a_row['Blue'] == 1)
{
	print "<option value=\"white\">White</option><br>\n";
	print "<option value=\"red\">Red</option><br>\n";
	print "<option value=\"green\">Green</option><br>\n";
	print "<option value=\"blue'\" selected=\"selected\">Blue</option><br>\n";
	print "<option value=\"pink\">Pink</option><br>\n";
}
else if($a_row['Red'] == 1 && $a_row['Green'] == 0 && $a_row['Blue'] == .5)
{
	print "<option value=\"white\">White</option><br>\n";
	print "<option value=\"red\">Red</option><br>\n";
	print "<option value=\"green\">Green</option><br>\n";
	print "<option value=\"blue\">Blue</option><br>\n";
	print "<option value=\"pink\" selected=\"selected\">Pink</option><br>\n";
}
else
{
	print "<option value=\"white\">White</option><br>\n";
	print "<option value=\"red\">Red</option><br>\n";
	print "<option value=\"green\">Green</option><br>\n";
	print "<option value=\"blue\">Blue</option><br>\n";
	print "<option value=\"pink\">Pink</option><br>\n";
}
print "</select><br>\n";
print "<input type=\"submit\" name=\"submit\" value=\"Update\"><br>\n<input type=\"reset\" name=\"reset\" value=\"Reset\">\n</form>\n";


print "<form action=\"index.php\">\n<input type=\"submit\" value=\"Back\">\n</form>\n";

//close connection
mysql_close($link);
?>
</body>
</html>