<?php
session_start();
if( empty($_SESSION['Account_Type']) || $_SESSION['Account_Type'] != 'student' ){
	header( 'Location: /index.php' );
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

$student_result = mysql_query("SELECT * FROM Users WHERE uID = '".stripslashes($_SESSION['uID'])."'");

print "<table border=\"1\">\n";
print "<tr>\n<td>Username</td>\n<td>Add Easy Total</td>\n<td>Add Easy Missed</td>\n<td>Place Easy Total</td>\n<td>Place Easy Missed</td>\n<td>Minus Easy Total</td>\n<td>Minus Easy Missed</td>\n<td>Add Medium Total</td>\n<td>Add Medium Missed</td>\n<td>Place Medium Total</td>\n<td>Place Medium Missed</td>\n<td>Minus Medium Total</td>\n<td>Minus Medium Missed</td>\n<td>Add Hard Total</td>\n<td>Add Hard Missed</td>\n<td>Place Hard Total</td>\n<td>Place Hard Missed</td>\n<td>Minus Hard Total</td>\n<td>Minus Hard Missed</td>\n</tr>\n";

$a_student_row = mysql_fetch_array($student_result);

print "<tr>\n<td>".stripslashes($a_student_row['UserName'])."</td>\n";
$stats = mysql_query("SELECT Addition.Easy_Total,Addition.Easy_Missed,Placement.Easy_Total,Placement.Easy_Missed,Subtraction.Easy_Total,Subtraction.Easy_Missed,Addition.Medium_Total,Addition.Medium_Missed,Placement.Medium_Total,Placement.Medium_Missed,Subtraction.Medium_Total,Subtraction.Medium_Missed,Addition.Hard_Total,Addition.Hard_Missed,Placement.Hard_Total,Placement.Hard_Missed,Subtraction.Hard_Total,Subtraction.Hard_Missed FROM Addition,Subtraction,Placement WHERE Addition.uID = '".stripslashes($_SESSION['uID'])."' AND Subtraction.uID = '".stripslashes($_SESSION['uID'])."' AND Placement.uID = '".stripslashes($_SESSION['uID'])."'");
while($a_row = mysql_fetch_row($stats)) {
		foreach( $a_row as $field ) {
			print "\t<td>".stripslashes($field)."</td>\n";
	}
}
print "</tr>\n";
//}
print "</table><br>\n";
print "<form action=\"index.php\">\n<input type=\"submit\" value=\"Back\">\n</form>\n";
//close connection
mysql_close($link);
?>
</body>
</html>