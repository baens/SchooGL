<?php
session_start();
if( empty($_SESSION['Account_Type']) || $_SESSION['Account_Type'] != 'teacher' ){
	header( 'Location: /index.php' );
}
?>
<?php
if( isset ( $_POST['Addition_Score'] ) && isset ( $_POST['Subtraction_Score']) && isset ( $_POST['Placement_Score']) )
{
$add=$_POST['Addition_Score'];
$sub=$_POST['Subtraction_Score'];
$place=$_POST['Placement_Score'];
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
mysql_query("UPDATE Teachers SET Addition_Score = '$add', Subtraction_Score = '$sub', Placement_Score = '$place' WHERE uID = '".stripslashes($_SESSION['uID'])."'");
print "<html>\n<body>\n<script type=\"text/javascript\">\nalert(\"Scores Updated\")\n</script>\n</body>\n</html>";

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
$result = mysql_query( "SELECT Addition_Score,Subtraction_Score,Placement_Score FROM Teachers WHERE uID = '".stripslashes($_SESSION['uID'])."'");

//iterate through each row and column
$a_row = mysql_fetch_array($result , MYSQL_ASSOC);
	//start new row
	print "<form action=\"".$_SERVER['PHP_SELF']."\" method=\"post\"><tr>\n";
	//go through each column
	$x=0;
	foreach($a_row as $field)
	{
		$colum = mysql_field_name($result,$x++);
		print $colum;
		print "<input type=\"text\" name=\"".$colum."\" value=\"".stripslashes($field)."\"><br>\n";
	}
	//end row
	print "<input type=\"submit\" name=\"submit\" value=\"Update\"><br>\n<input type=\"reset\" name=\"reset\" value=\"Reset\">\n</form>\n";


print "<form action=\"index.php\">\n<input type=\"submit\" value=\"Back\">\n</form>\n";

//close connection
mysql_close($link);
?>
</body>
</html>