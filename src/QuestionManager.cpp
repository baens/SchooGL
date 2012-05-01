#ifdef _WIN32
#include <windows.h>
#endif
#include <mysql.h>
#include <iostream>
#include <time.h>
#include <LoginManager.h>
#include <QuestionManager.h>
#include <Util.h>
#include <CacheSystem.h>

using namespace std;
Question* QuestionManager::getQuestion()
{
	MYSQL *connect;
	MYSQL_RES* res;
	MYSQL_ROW row;
	connect = mysql_init(NULL);
	if(!connect){
		cout << "Failed to start!" << endl;
		return false;
	}

	connect = mysql_real_connect(connect,DB_SR,DB_UN,DB_PW,DB_DB,0,NULL,0);
	if(!connect)
	     return false;
    
	srand(time(NULL));
	string query = "SELECT Question,Answer FROM Questions WHERE Diff = 'Easy' AND Type = 'Add'";
	//string query = "SELECT question, answer FROM Problems WHERE question_difficulty = 'easy' AND question_type = 'add'";
	mysql_query(connect,query.c_str());
	res = mysql_store_result(connect);
	int num_rows = mysql_num_rows(res);
	int count = 0;
	int stopCount = rand()%num_rows-1;
	while(mysql_fetch_row(res) && count++ < stopCount);

	row = mysql_fetch_row(res);
	Point p(0,8);
	Color c(0.0,0.0,1.0,0.0);
	string questionStr=row[0];
	
	int correctPlace = rand()%4;
	string answerStr[4];

	//get the display array ready
	for(int a = 0; a < 4; a++){
	  if(correctPlace == a)
	    answerStr[a] = row[1];
	  else{
	    
	    answerStr[a] = to_string(rand()%10+10);
	  }
	}
	Question* question = new Question(p,c,questionStr,answerStr,correctPlace);	
	return question;
}

Question* QuestionManager::getQuestion(Subject s, Difficulty d)
{
  if(CacheSystem::isOffLine()){
    Question* q = CacheSystem::getQuestionFromCache(s,d);
    if(q == NULL)
      return new Question();
    else
      return q;
  }
  string subjectString;
  string difficultyString;
  switch(s){
  case Addition:
    subjectString = "Add";
	//subjectString = "add";
    break;
  case Subtraction:
    subjectString = "Sub";
	//subjectString = "sub";
    break;
  case Placement:
    subjectString = "Place";
	//subjectString = "place";
    break;
  }
  
  switch(d){
  case Easy:
    difficultyString = "Easy";
	//difficultyString = "easy";
    break;
  case Medium:
    difficultyString = "Med";
	//difficultyString = "med";
    break;
  case Hard:
    difficultyString = "Hard";
	//difficultyString = "hard";
    break;
  }
  
  MYSQL *connect;
  MYSQL_RES* res;
  MYSQL_ROW row;
  connect = mysql_init(NULL);
  if(!connect){
    cout << "Failed to start!" << endl;
    return false;
  }
  
  connect = mysql_real_connect(connect,DB_SR,DB_UN,DB_PW,DB_DB,0,NULL,0);
  if(!connect)
    return false;
  
  srand(time(NULL));
  if(s == Placement && d == Hard){
    if(rand()%2==0)
      d == Easy;
    else
      d == Medium;
  }
  
  string query = "SELECT Question,Answer FROM Questions WHERE Diff = '"+difficultyString+"' AND Type = '"+subjectString+"'";
  //string query = "SELECT question, answer FROM Problems WHERE question_difficulty = '"+difficultyString+"' AND question_type = '"+subjectString+"'";
  
  mysql_query(connect,query.c_str());
  
  res = mysql_store_result(connect);
  
  int num_rows = mysql_num_rows(res);
  
  if(num_rows == 0)
    return new Question();
  
  Point p(0,8);
  Color c(0.0,0.0,1.0,0.0);
  int count = 0;
  int stopCount = rand()%num_rows-1;
  if(num_rows > 1)
    while(mysql_fetch_row(res) && count++ < stopCount);
  
  row = mysql_fetch_row(res);

  if(s == Placement){
    
    string temp_question = row[0];
    string question;
    string answers[4];
    string num = "";
    for(int i = 0; i < temp_question.length(); i++){
      if(temp_question[i] == ':')
	break;
      num += temp_question[i];
    }
    string ans = "";
    for(int i = temp_question.find(':')+1; i < temp_question.length(); i++){
      if(row[0][i] == '?')
	break;
      ans+= row[0][i];
    }
    if(d == Easy){
      
      question = "From the number "+num+" what number is in the "+ans+"'s place";
      int correctPlace = rand()%4;
      string answerStr[4];
      int possibleAnswers[] = {0,0,0};
      int delta = (int)(to_int(row[1]) *.2);
      if(delta < 10)
	delta = 10;
      int answer = 0;
      //find answers  
      for(int a = 0; a < 3; a++){	
	bool foundAnswer = false;
	while(!foundAnswer){
	  answer = rand()%delta;
	  int add = rand()%2;
	  answer = add == 0 ? answer+to_int(row[1]) : abs(answer-to_int(row[1]));
	  if(answer >= 10 || answer == to_int(row[1]))
	    continue;
	  for(int b = 0; b < 3; b++){
	    if(answer == possibleAnswers[b])
	      break;
	    if(b == 2)
	      foundAnswer = true;
	  }
	}
	possibleAnswers[a] = answer;
      }
      int pos = 0;
      for(int a = 0; a < 4; a++)
	if(correctPlace == a)
	  answerStr[a] = row[1];
	else{
	  answerStr[a] = to_string(possibleAnswers[pos]);
	  pos++;
	}
      return new Question(p,c,question,answerStr,correctPlace);
    } else {
      string possibleAnswers[] = {"1","10","100","1000"};
      question = "From the number "+num+" what place is the "+ans;
      int pos = 0;
      if(row[1] == possibleAnswers[1])
	pos = 1;
      else if (row[1] == possibleAnswers[2])
	pos = 2;
      else if (row[1] == possibleAnswers[3])
	pos = 3;
      return new Question(p,c,question,possibleAnswers,pos,1.8);
      
    }
    cout << num << " " << ans << endl;
    return new Question();
  
  } else {
    
    
    string questionStr=row[0];
    
    int correctPlace = rand()%4;
    string answerStr[4];
    int possibleAnswers[] = {0,0,0};
    int delta = to_int(row[1]) *.2;
    if(delta < 10)
      delta = 4;
    int answer = 0;
    //find answers  
    for(int a = 0; a < 3; a++){	
      bool foundAnswer = false;
      while(!foundAnswer){
	answer = rand()%delta;
	for(int b = 0; b < 3; b++){
	  if(answer == possibleAnswers[b])
	    break;
	  if(b == 2)
	    foundAnswer = true;
	}
      }
      possibleAnswers[a] = answer;
    }
    int pos = 0;
    for(int a = 0; a < 4; a++)
      if(correctPlace == a)
	answerStr[a] = row[1];
      else{
	int place = rand()%2?possibleAnswers[pos] + to_int(row[1]):
	  abs(possibleAnswers[pos]-to_int(row[1]));
	answerStr[a] = to_string(place);
	pos++;
      }
    Question* question = new Question(p,c,questionStr,answerStr,correctPlace);
    CacheSystem::cacheQuestion(question,s,d);
    return question;
  }
}
