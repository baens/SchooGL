<?php
session_start();
if( empty($_SESSION['Account_Type']) || $_SESSION['Account_Type'] != 'teacher' ){
	header( 'Location: /index.php' );
}
?>
<?php
if( isset ( $_POST['uID'] ) && isset ( $_POST['Type']) && isset ( $_POST['Diff']) && isset ( $_POST['Question']) && isset ( $_POST['Answer']) && isset ( $_POST['submit']) )
{
$ID=$_POST['uID'];
$type=$_POST['Type'];
$diff=$_POST['Diff'];
$question=$_POST['Question'];
$answer=$_POST['Answer'];
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
mysql_query("UPDATE Questions SET Type = '$type', Diff = '$diff', Question = '$question', Answer = '$answer' WHERE uID = '$ID'");
print "<html>\n<body>\n<script type=\"text/javascript\">\nalert(\"Question Updated\")\n</script>\n</body>\n</html>";

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
mysql_query("DELETE FROM Questions WHERE uID = '$ID'");
print "<html>\n<body>\n<script type=\"text/javascript\">\nalert(\"Question Removed\")\n</script>\n</body>\n</html>";

}
?>
<html>
<head>
<script type="text/javascript">

Type="All";
Diff="All";

function typeShow(type)
{
	Type=type;
	count = document.getElementById("count").value;
	for(i=0;i < parseInt(count);i+=6)
	{
		id1=parseInt(i)+2;
		id2=parseInt(i)+3;
		if((document.getElementById(id1).value == type || type == "All") && (document.getElementById(id2).value == Diff || Diff == "All"))
		{
			document.getElementById(i).style.display="table-row";
		}
		else
		{
			document.getElementById(i).style.display="none";
		}
	}
}

function diffShow(diff)
{
	Diff=diff;
	count = document.getElementById("count").value;
	for(i=0;i < parseInt(count);i+=6)
	{
		id1=parseInt(i)+2;
		id2=parseInt(i)+3;
		if((document.getElementById(id1).value == Type || Type == "All") && (document.getElementById(id2).value == diff || diff == "All"))
		{
			document.getElementById(i).style.display="table-row";
		}
		else
		{
			document.getElementById(i).style.display="none";
		}
	}
}
</script>
</head>
<body>
<input name="showType" type="radio" onclick="typeShow('All')" checked="checked">Show All Types
<input name="showType" type="radio" onclick="typeShow('Add')">Show Addition Only
<input name="showType" type="radio" onclick="typeShow('Sub')">Show Subtraction Only
<input name="showType" type="radio" onclick="typeShow('Place')">Show Placement Only<br>
<input name="showDiff" type="radio" onclick="diffShow('All')" checked="checked">Show All Difficulties
<input name="showDiff" type="radio" onclick="diffShow('Easy')">Show Easy Only
<input name="showDiff" type="radio" onclick="diffShow('Med')">Show Medium Only
<input name="showDiff" type="radio" onclick="diffShow('Hard')">Show Hard Only<br>
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
$result = mysql_query( "SELECT * FROM Questions");

//start the table
$id=0;
print "<table border=\"1\">\n<tr>\n<td>Question ID</td>\n<td>Type</td>\n<td>Difficulty</td>\n<td>Question</td>\n<td>Answer<td>\n";

//iterate through each row and column
while ($a_row = mysql_fetch_array($result , MYSQL_ASSOC) ) {
	//start new row
	print "<tr id=\"".$id++."\" style=\"visibility: visible\">\n<form action=\"".$_SERVER['PHP_SELF']."\" method=\"post\">\n";
	//go through each column
	$x = 0;
	foreach($a_row as $field)
	{
		$colum = mysql_field_name($result,$x++);
		$Qtype = $a_row['Type'];
		if($colum != 'Diff')
		{
			print "\t<td><input type=\"text\" name=\"".$colum."\" readonly=\"readonly\" value=\"".stripslashes($field)."\" id=\"".$id++."\"></td>\n";
		}
		if($colum == 'Diff')
		{
			$diff = $a_row['Diff'];
			if($Qtype != 'Place')
			{
				if($diff == 'Easy')
				{
					print "\t<td><input type=\"radio\" name=\"Diff\" value=\"Easy\" checked=\"checked\" id=\"".$id++."\">Easy\n<input type=\"radio\" name=\"Diff\" value=\"Med\">Medium\n<input type=\"radio\" name=\"Diff\" value=\"Hard\">Hard<br></td>\n";
				}
				else if($diff == 'Med')
				{
					print "\t<td><input type=\"radio\" name=\"Diff\" value=\"Easy\">Easy\n<input type=\"radio\" name=\"Diff\" value=\"Med\" checked=\"checked\" id=\"".$id++."\">Medium\n<input type=\"radio\" name=\"Diff\" value=\"Hard\">Hard<br></td>\n";
				}
				else if($diff == 'Hard')
				{
					print "\t<td><input type=\"radio\" name=\"Diff\" value=\"Easy\">Easy\n<input type=\"radio\" name=\"Diff\" value=\"Med\">Medium\n<input type=\"radio\" name=\"Diff\" value=\"Hard\" checked=\"checked\" id=\"".$id++."\">Hard<br></td>\n";
				}
			}
			if($Qtype == 'Place')
			{
				if($diff == 'Easy')
				{
					print "\t<td><input type=\"radio\" name=\"Diff\" value=\"Easy\" checked=\"checked\" id=\"".$id++."\">Easy<br></td>\n";
				}
				else if($diff == 'Med')
				{
					print "\t<td><input type=\"radio\" name=\"Diff\" value=\"Med\" checked=\"checked\" id=\"".$id++."\">Medium<br></td>\n";
				}
			}
		}
	}
	//end row
	print "<td><input type=\"submit\" name=\"submit\" value=\"Submit Row\"></td>\n<td><input type=\"submit\" name=\"remove\" value=\"Remove\"></td>\n</form>\n</tr>\n";
}
//end table
print "</table><br>\n";
print "<form action=\"index.php\">\n<input type=\"submit\" value=\"Back\">\n</form>\n";

print "<input type=\"text\" id=\"count\" value=\"".$id++."\" style=\"visibility: collapse\">";
//close connection
mysql_close($link);
?>
</body>
</html>