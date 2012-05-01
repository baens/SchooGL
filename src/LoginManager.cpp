#include <LoginManager.h>
#include <Util.h>
#include <StatManager.h>
#include <ProfileManager.h>
#include <TeacherManager.h>
#include <CacheSystem.h>

#include <iostream>
using namespace std;
bool LoginManager::tryLogin(string username, string password){
  if(CacheSystem::tryCacheLogin(username,password)){
    if(CacheSystem::isOffLine()){
      UserManager::setProfile(*CacheSystem::getProfile(username));
      UserManager::setUsername(username);
    }else{
      UserManager::setID(CacheSystem::getUserID(username));
      UserManager::setUsername(username);
      Profile* p = CacheSystem::getProfile(username);
      if(p == NULL)
		UserManager::setProfile(ProfileManager::getProfile(UserManager::getID()));
      else
		UserManager::setProfile(*p);
      UserManager::setTeacher(TeacherManager::getTeacher(UserManager::getID()));
    }
  }
  if(CacheSystem::isOffLine())
    return false;
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
  string query = "SELECT Username,Password FROM Users WHERE Username = '"+username+"' AND Password = '"+password+"'";
  //string query = "SELECT user_name, password FROM Person WHERE user_name = '"+username+"' AND password = '"+password+"'";
  mysql_query(connect,query.c_str());
  string test = mysql_error(connect);
  my_ulonglong num_rows = 0;
  my_res = mysql_store_result(connect);
  test = mysql_error(connect);
  num_rows = mysql_num_rows(my_res);
  MYSQL_ROW row = mysql_fetch_row(my_res);
  if(num_rows == 0)
    return false;
  else{
    if(username == row[0] && password == row[1]){
      query = "SELECT uID FROM Users WHERE Username = '"+username+"' AND Password = '"+password+"'";
	  //query = "SELECT uID FROM Person WHERE user_name = '"+username+"' AND password = '"+password+"'";
      mysql_query(connect,query.c_str());
      my_res = mysql_store_result(connect);
      row = mysql_fetch_row(my_res);
      UserManager::setID(to_int(row[0]));
      UserManager::setUsername(username);
      UserManager::setProfile(ProfileManager::getProfile(UserManager::getID()));
      UserManager::setTeacher(TeacherManager::getTeacher(UserManager::getID()));
      CacheSystem::cacheLogin(username,password,UserManager::getID());
      CacheSystem::cacheProfile(username,UserManager::getProfile());
      return true;
    }
  }
  return false;
}
