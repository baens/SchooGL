#include <LoginManager.h>
#include <StatManager.h>
#include <Util.h>
#include <iostream>
#include <mysql.h>
#include <UserManager.h>

string* StatManager::getStats(int uID)
{
  //  attempt to connect
  MYSQL *connect;
  MYSQL_RES* res;
  MYSQL_ROW row;
  connect = mysql_init(NULL);
  if(!connect){
    cout << "Failed to start!" << endl;
    return NULL;
  }
  
  connect = mysql_real_connect(connect,DB_SR,DB_UN,DB_PW,DB_DB,0,NULL,0);
  if(!connect)
    return NULL;

  //get the stats from the correct database and the amounts for total and missed
  string query = "SELECT Placement_score,Addition_score,Subtraction_score FROM Students  WHERE uID = '"+to_string(uID)+"'";
  //string query = "SELECT perfect_placeValue,perfect_addition,perfect_subtraction FROM Achievements  WHERE uID = '"+to_string(uID)+"'";
  mysql_query(connect,query.c_str());
  //fetch the one row
  res = mysql_store_result(connect);
  row = mysql_fetch_row(res);
  double scores[3];

  //place items into UserManager for use in program
  UserManager::setAddScore(to_int(row[1]));
  UserManager::setSubScore(to_int(row[2]));
  UserManager::setPlaceScore(to_int(row[0]));

  //setup the teacher settings
  Teacher t = UserManager::getTeacher();
  
  scores[0] = (int)(((to_int(row[0]))/(double)(t.getPlaceScore()))*100);
  scores[1] = (int)((to_int(row[1])/(double)(t.getAddScore()))*100);
  scores[2] = (int)((to_int(row[2])/((double)t.getSubScore()))*100);

  //turn the pertances into strings for use in the SelectionScene
  string* ret = new string[3];
  ret[0] = to_string(scores[0]);
  ret[1] = to_string(scores[1]);
  ret[2] = to_string(scores[2]);
  return ret;
}

void StatManager::updateStats(Subject s, Difficulty d, int missed, int total)
{
  if(d != Hard){
    switch(s){
    case Addition:
      if(d == Easy && UserManager::getAddScore() > UserManager::getTeacher().getAddEasy())
	return;
      if(d == Medium && UserManager::getAddScore() > UserManager::getTeacher().getAddMed())
	return;
      break;
    case Subtraction:
      if(d == Easy && UserManager::getSubScore() > UserManager::getTeacher().getSubEasy())
	return;
      if(d == Medium && UserManager::getSubScore() > UserManager::getTeacher().getSubMed())
	return;
      break;
    case Placement:
      if(d == Easy && UserManager::getPlaceScore() > UserManager::getTeacher().getPlaceEasy())
	return;
      if(d == Medium && UserManager::getPlaceScore() > UserManager::getTeacher().getPlaceMed())
	return;
      break;
    }
  }
  
  string db;
  string difficulty;
  string total_str;
  string missed_str;
  //turn all the enumeraters into strings
  db = to_string(s);
  difficulty = to_string(d);
  
  //  attempt to connect
  MYSQL *connect;
  MYSQL_RES* res;
  MYSQL_ROW row;
  connect = mysql_init(NULL);
  if(!connect){
    cout << "Failed to start!" << endl;
    return;
  }
  
  connect = mysql_real_connect(connect,DB_SR,DB_UN,DB_PW,DB_DB,0,NULL,0);
  if(!connect)
    return;
  string uID = to_string(UserManager::getID());
  //get the stats from the correct database and the amounts for total and missed
  string query = "SELECT "+difficulty+"_Total,"+difficulty+"_Missed FROM "+db+" WHERE uID = '"+uID+"'";
  //string query = "SELECT "+difficulty+"_correct,"+difficulty+"_missed FROM Stats WHERE question_type = '"+db+"', uID = '"+uID+"'";
  mysql_query(connect,query.c_str());
  res = mysql_store_result(connect);
  row = mysql_fetch_row(res);
  
  
  double score = ((total-missed)/(double)total) * 100;
  //int correct = total-missed;

  //update everything and place them into the database
  total += to_int(row[0]);
  //correct += to_int(row[0]);
  missed += to_int(row[1]);

  query = "UPDATE "+db+" SET "+difficulty+"_Total = '"+to_string(total)+"', "+difficulty+"_Missed = '"+to_string(missed)+"' WHERE uID = '"+uID+ "'";
  //query = "UPDATE Stats SET "+difficulty+"_correct = '"+correct+"', "+difficulty+"_missed = '"+missed+"' WHERE question_type = '"+db+"', uID = '"+uID+ "'";
  mysql_query(connect,query.c_str());

  
  int points;
  if(score < 50)
    points = 0;
  else if(score >= 50 && score < 60)
    points = 1;
  else if(score >= 60 && score < 70)
    points = 2;
  else if(score >= 70 && score < 80)
    points = 3;
  else if(score >= 80 && score < 90)
    points = 4;
  else
    points = 5;
  int multiplyer = 0;
  switch(d){
  case Easy:
    multiplyer = 1;
    break;
  case Medium:
    multiplyer = 2;
    break;
  case Hard:
    multiplyer = 3;
    break;
  default:
    multiplyer = 1;
    break;
  }

  //get points from database
  query = "SELECT "+db+"_score FROM Students WHERE uID = '"+uID+"'";
  mysql_query(connect,query.c_str());
  res = mysql_store_result(connect);
  row = mysql_fetch_row(res);

  //replace in database
  int total_points = to_int(row[0]) + (points * multiplyer);
  query = "UPDATE Students SET "+db+"_score = "+to_string(total_points)+" WHERE uID = '"+uID+"'";
  mysql_query(connect,query.c_str());

}

