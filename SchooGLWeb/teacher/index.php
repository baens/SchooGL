<?php
session_start();
if( isset ($_POST['logout']))
{
	session_destroy();
	header( 'Location: /index.php' );
}
if( empty($_SESSION['Account_Type']) || $_SESSION['Account_Type'] != 'teacher' ){
	header( 'Location: /index.php' );
}
?>
<html>
<body>
<h1>Hello <?php print $_SESSION['username']; ?></h1>
<a href="addStudent.php">Add Student Here</a><br>
<a href="Students.php">View Student Stats</a><br>
<a href="addQuestion.php">Add Question</a><br>
<a href="Questions.php">Modify Questions</a><br>
<a href="Score.php">Change Points to Complete Subject</a><br>
<a href="Threshold.php">Change Point Cap for Easy and Medium Difficulties</a><br>
<br><form action="index.php" method="post">
<input type="submit" value="Log Out" name="logout">
</form>
</body>
</html>