<?php
session_start();
if( empty($_SESSION['Account_Type']) || $_SESSION['Account_Type'] != 'teacher' ){
	header( 'Location: /index.php' );
}
?>
<?php
if( isset ( $_POST['Addition_Easy_Threshold'] ) && isset ( $_POST['Addition_Medium_Threshold']) && isset ( $_POST['Subtraction_Easy_Threshold']) && isset ( $_POST['Subtraction_Medium_Threshold']) && isset ( $_POST['Placement_Easy_Threshold']) && isset ( $_POST['Placement_Medium_Threshold']) )
{
$addEasy=$_POST['Addition_Easy_Threshold'];
$addMed=$_POST['Addition_Medium_Threshold'];
$subEasy=$_POST['Subtraction_Easy_Threshold'];
$subMed=$_POST['Subtraction_Medium_Threshold'];
$placeEasy=$_POST['Placement_Easy_Threshold'];
$placeMed=$_POST['Placement_Medium_Threshold'];
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
mysql_query("UPDATE Teachers SET Addition_Easy_Threshold = '$addEasy', Addition_Medium_Threshold = '$addMed', Subtraction_Easy_Threshold = '$subEasy', Subtraction_Medium_Threshold = '$subMed', Placement_Easy_Threshold = '$placeEasy', Placement_Medium_Threshold = '$placeMed' WHERE uID = '".stripslashes($_SESSION['uID'])."'");
print "<html>\n<body>\n<script type=\"text/javascript\">\nalert(\"Thresholds Updated\")\n</script>\n</body>\n</html>";

}
?>
<html>
<head>
<script language="javascript" type="text/Javascript">
function check(num)
{
	if(parseInt(document.getElementById(num).value) == 0)
	{
		alert("The threshold cannot be set to 0");
		document.getElementById(num).value=document.getElementById(num).title;

	}
	else if(num==0 || num==2 || num==4)
	{
		if(parseInt(document.getElementById(num).value) > parseInt(document.getElementById(parseInt(num)+1).value))
		{
			alert("The easy threshold has been set higher than the medium threshold");
			document.getElementById(num).value=parseInt(document.getElementById(parseInt(num) + 1).value);
		}
	}
	else
	{
		if(parseInt(document.getElementById(num).value) < parseInt(document.getElementById(parseInt(num)-1).value))
		{
			alert("The medium threshold has been set higher than the easy threshold");
			document.getElementById(num).value=parseInt(document.getElementById(parseInt(num) - 1).value);
		}
	}
}
</script>
</head>
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
$result = mysql_query( "SELECT Addition_Easy_Threshold,Addition_Medium_Threshold,Subtraction_Easy_Threshold,Subtraction_Medium_Threshold,Placement_Easy_Threshold,Placement_Medium_Threshold FROM Teachers WHERE uID = '".stripslashes($_SESSION['uID'])."'");

//iterate through each row and column
$a_row = mysql_fetch_array($result , MYSQL_ASSOC);
	//start new row
	print "<form action=\"".$_SERVER['PHP_SELF']."\" method=\"post\"><tr>\n";
	//go through each column
	$x=0;
	$i=0;
	foreach($a_row as $field)
	{
		$colum = mysql_field_name($result,$x++);
		$value = $field;
		print $colum;
		print "<input type=\"text\" name=\"".$colum."\" value=\"".stripslashes($value)."\" id=\"".$i++."\" onkeyup=\"check(id)\" title=\"".stripslashes($value)."\"><br>\n";
	}
	//end row
	print "<input type=\"submit\" name=\"submit\" value=\"Update\"><br>\n<input type=\"reset\" name=\"reset\" value=\"Reset\">\n</form>\n";


print "<form action=\"index.php\">\n<input type=\"submit\" value=\"Back\">\n</form>\n";

//close connection
mysql_close($link);
?>
</body>
</html>