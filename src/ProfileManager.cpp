#include <LoginManager.h>
#include <ProfileManager.h>
#include <Util.h>
#include <CacheSystem.h>
#include <UserManager.h>

Profile ProfileManager::getProfile(int uID)
{
  MYSQL *connect;
  connect = mysql_init(NULL);
  if(!connect){
    cout << "Failed to start!" << endl;
    return Profile();
  }
  
  connect = mysql_real_connect(connect,DB_SR,DB_UN,DB_PW,DB_DB,0,NULL,0);
  if(!connect)
    return Profile();
	
  MYSQL_RES *my_res;
  string nick;
  Color color;
  string query = "SELECT student_alias,Red,Green,Blue FROM Students WHERE uID = '"+to_string(uID)+"'";
  //string query = "SELECT nickname,color FROM Profile,Students WHERE uID = '"+to_string(uID)+"'";
  mysql_query(connect,query.c_str());
  my_res = mysql_store_result(connect);
  MYSQL_ROW row = mysql_fetch_row(my_res);

  nick = row[0];
  double red = to_double(row[1]);
  double green = to_double(row[2]);
  double blue = to_double(row[3]);
  /*
  double red;
  double green;
  double blue;
  string strColor = to_int(row[1]);
  if(strColor("white") == strColor){
	red = 1.0;
	green = 1.0;
	blue = 1.0;
  }
  else if(strColor("red") == strColor){
	red = 1.0;
	green = 0.0;
	blue = 0.0;
  }
  else if(strColor("green") == strColor){
	red = 0.0;
	green = 1.0;
	blue = 0.0;
  }
  else if(strColor("blue") == strColor){
	red = 0.0;
	green = 0.0;
	blue = 1.0;
  }
  else{
	red = 1.0;
	green = 0.0;
	blue = 0.5;
  }
  */

  color.setRed(red);
  color.setGreen(green);
  color.setBlue(blue);
  return Profile(nick,color);
}

bool ProfileManager::setProfile(int uID,Profile p)
{
    MYSQL *connect;
  connect = mysql_init(NULL);
  if(!connect){
    cout << "Failed to start!" << endl;
    return false;
  }
  
  connect = mysql_real_connect(connect,DB_SR,DB_UN,DB_PW,DB_DB,0,NULL,0);
  if(!connect)
    return false;
	
  MYSQL_RES *my_res;
  string nick = p.getNick();
  Color color = p.getColor();
  string query = "UPDATE Students SET student_alias = '"+nick+"',Red = '"+to_string(color.getRed())+"',Green = '"+to_string(color.getGreen())+"',Blue = '"+to_string(color.getBlue())+"' WHERE uID = '"+to_string(uID)+"'";
  /*string strColor;
  switch(color.getRed()){
	  case 1.0:
		  if(color.getBlue() == 0.5)
			  strColor = "pink";
		  else if(color.getGreen == 1.0)
			  strColor = "white";
		  else
			  strColor = "red";
		  break;
	  case 0.0:
		  if(color.getGreen() == 1.0)
			  strColor = "green";
		  else
			  strColor = "blue";
		  break;
  }
  string user = UserManager::getUsername();
  string query = "UPDATE Profile SET nickname = '"+nick+"',strColor WHERE user_name = '"+user+"'";
  */

  mysql_query(connect,query.c_str());
  CacheSystem::cacheProfile(UserManager::getUsername(),p);
  return true;
}
