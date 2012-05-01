#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <Color.h>
#include <Profile.h>
#include <Teacher.h>

using namespace std;

class UserManager{
 public:
  static int getID(){return UserManager::currentID;}
  static void setID(int id){UserManager::currentID = id;}
  static void setProfile(Profile p){UserManager::profile = p;}
  static Profile getProfile(){return UserManager::profile;}
  static void setTeacher(Teacher t){UserManager::teacher = t;}
  static Teacher getTeacher(){return UserManager::teacher;}
  static void setAddScore(int score){UserManager::addScore = score;}
  static void setSubScore(int score){UserManager::subScore = score;}
  static void setPlaceScore(int score){UserManager::placeScore = score;}
  static int getAddScore(){return UserManager::addScore;}
  static int getSubScore(){return UserManager::subScore;}
  static int getPlaceScore(){return UserManager::placeScore;}
  static string getUsername(){return UserManager::username;}
  static void setUsername(string un){UserManager::username = un;}
 private:
  static int currentID;
  static Profile profile;
  static Teacher teacher;
  static int addScore;
  static int subScore;
  static int placeScore;
  static string username;
};
#endif
