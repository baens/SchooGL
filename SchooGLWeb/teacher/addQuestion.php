<?php
session_start();
if( empty($_SESSION['Account_Type']) || $_SESSION['Account_Type'] != 'teacher' ){
	header( 'Location: /index.php' );
}
?>
<?php
if( isset( $_POST['type']) && isset( $_POST['diff'] ) && isset( $_POST['question']) && isset( $_POST['answer']))
{
$type = $_POST['type'];
$diff = $_POST['diff'];
$question = $_POST['question'];
$answer = $_POST['answer'];
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

if($answer != 'NaN')
{
	$question_insert = "INSERT INTO Questions(type,diff,question,answer) VALUES ('$type','$diff','$question','$answer')";
	print "<html>\n<body>\n<script type=\"text/javascript\">\nalert(\"Question Added\")\n</script>\n</body>\n</html>";


if(!mysql_query( $question_insert, $link)){
	die( "Couldn't insert into database for question".mysql_error());
}
}
else
{
	print "<html>\n<body>\n<script type=\"text/javascript\">\nalert(\"The values you are trying to input are invalid\")\n</script>\n</body>\n</html>";
}

mysql_close($link);
}
?>

<html>
<head>
<script type="text/javascript">
number1=0;
number2=0;
type=0;
place=0;
difficulty="easy";

function update()
{
question();
answer();
}

function setNum(arg)
{
number1=parseInt(arg);
question();
answer();
}

function getPlace(arg)
{
place=parseInt(arg);
temp=parseInt(number1)/parseInt(place);
number2=parseInt(temp)%10;
setNum(document.getElementById("number2").value);
question();
answer();
}

function difficulty(arg)
{
difficulty=arg;
question();
answer();
}

function set1(arg)
{
number1=parseInt(arg);
question();
answer();
}

function set2(arg)
{
number2=parseInt(arg);
question();
answer();
}

function question()
{
if(document.getElementById("add").checked)
{
x=number1 + "+" + number2 + "=?";
document.getElementById("question").value=x;
}
if(document.getElementById("minus").checked)
{
{
	if(parseInt(number1)>=parseInt(number2))
	{
	  x=number1 + "-" + number2 + "=?";
	  document.getElementById("question").value=x;
	}
	else
	{
	  x=number2 + "-" + number1 + "=?";
	  document.getElementById("question").value=x;
	}
}
}

if(document.getElementById("place").checked)
{
if(document.getElementById("easy").checked)
{
x=number1 + ":" + place + "?";
document.getElementById("question").value=x;
}
if(document.getElementById("med").checked)
{
x=number1 + ":" + number2 + "?";
document.getElementById("question").value=x;
}
}

}

function answer()
{
if(document.getElementById("add").checked)
{
x=parseInt(number1)+parseInt(number2);
document.getElementById("answer").value=x;
}
if(document.getElementById("minus").checked)
{
	if(parseInt(number1)>=parseInt(number2))
	{
	  x=parseInt(number1)-parseInt(number2);
	  document.getElementById("answer").value=x;
	}
	else
	{
	  x=parseInt(number2)-parseInt(number1);
	  document.getElementById("answer").value=x;
	}
}

if(document.getElementById("place").checked)
{
if(document.getElementById("easy").checked)
{
document.getElementById("answer").value=number2;
}
if(document.getElementById("med").checked)
{
document.getElementById("answer").value=place;
}
}

}

function show(txt)
{
number1=0;
number2=0;
type=0;
place=0;
document.getElementById("question").value=document.getElementById("question").defaultValue;
document.getElementById("answer").value=document.getElementById("answer").defaultValue;
type=txt;
if(document.getElementById("add").checked || document.getElementById("minus").checked)
{
document.getElementById("1number").style.visibility="visible";
document.getElementById("1number2").style.visibility="visible";
document.getElementById("hard").style.visibility="visible";
document.getElementById("2number").style.visibility="visible";
}
if(document.getElementById("place").checked)
{
document.getElementById("number").style.visibility="visible";
document.getElementById("place1").style.visibility="visible";
}
document.getElementById("all2").style.visibility="visible";
document.getElementById("all3").style.visibility="visible";
document.getElementById("1number2").value=document.getElementById("1number2").defaultValue;
document.getElementById("2number2").value=document.getElementById("2number2").defaultValue;
document.getElementById("question").value=document.getElementById("question").defaultValue;
document.getElementById("answer").value=document.getElementById("answer").defaultValue;
document.getElementById("number").value=document.getElementById("number").defaultValue;
document.getElementById("place1").value=document.getElementById("place").defaultValue;
document.getElementById("number2").value=document.getElementById("number2").defaultValue;
document.getElementById("diff").style.visibility="visible";
document.getElementById("all4").style.visibility="visible";

hide();
}

function hide()
{
if(document.getElementById("add").checked || document.getElementById("minus").checked)
{
document.getElementById("number").style.visibility="collapse";
document.getElementById("place1").style.visibility="collapse";
}
if(document.getElementById("place").checked)
{
document.getElementById("1number").style.visibility="collapse";
document.getElementById("1number2").style.visibility="collapse";
document.getElementById("hard").style.visibility="collapse";
document.getElementById("2number").style.visibility="collapse";
}
}
</script>
</head>
<body onmouseover="update()">

<form action="<?php print $_SERVER['PHP_SELF']?>" method="post">
<input type="radio" onclick="show('add')" name="type" value="Add" id="add">Addition

<input type="radio" onclick="show('minus')" name="type" value="Sub" id="minus">Subtraction

<input type="radio" onclick="show('place')" name="type" value="Place" id="place">Placement<br>

<a style="visibility: collapse" id="diff">
<input type="radio" onchange="difficulty(value)" checked="checked" name="diff" id="easy" value="easy">Easy
<input type="radio" onchange="difficulty(value)" name="diff" id="med" value="med">Medium

<a style="visibility: collapse" id="hard"><input type="radio" onclick="difficulty(value)" name="diff" id="hard2" value="hard">Hard</a><br>

<a style="visibility: collapse" id="number">Number: <input type="text" id="number2" onkeyup="setNum(value)" onchange="setNum(value)"><br></a>

<a style="visibility: collapse" id="1number">First Number: <input type="text" name="1number" id="1number2" onkeyup="set1(value)" onchange="set1(value)"></a><br>

<a style="visibility: collapse" id="place1">
<input type="radio" onclick="getPlace('1')" name="place" id="place2" value="1">1's
<input type="radio" onclick="getPlace('10')" name="place" id="place3" value="10">10's
<input type="radio" onclick="getPlace('100')" name="place" id="place4" value="100">100's
<input type="radio" onclick="getPlace('1000')" name="place" id="place5" value="1000">1000's</a><br>

<a style="visibility: collapse" id="2number">Second Number: <input type="text" name="2number" id="2number2" onkeyup="set2(value)" onchange="set2(value)"></a><br>

<a style="visibility: collapse" id="all2">Question: <input type="text"  name="question" readonly="true" id="question"></a><br>
<a style="visibility: collapse" id="all3">Answer: <input type="text" name="answer" readonly="true" id="answer"></a><br>
<br><input style="visibility: collapse" type="submit" value="Add Question" id="all4">
</form>
<form action="index.php">
<input type="submit" value="back">

</body>
</html>