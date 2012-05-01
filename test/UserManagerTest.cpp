#include <iostream>
#include <UserManager.h>
#include <Teacher.h>
using namespace std;

int main()
{
  //check default values
  if(!(UserManager::getID() == 0)){
    cout << "getCurrentID() failed" << endl;
    return -1;
  }
  if(!(UserManager::getAddScore() == 0)){
    cout << "getAddScore() failed" << endl;
    return -1;
  }
  if(!(UserManager::getSubScore() == 0)){
    cout << "getSubScore() failed" << endl;
  }
  //check get and set
  UserManager::setID(4);
  if(!(UserManager::getID() == 4)){
    cout << "set/getID() failed" << endl;
    return -1;
  }
  
  UserManager::setAddScore(10);
  if(!(UserManager::getAddScore() == 10)){
    cout << "set/getAddScore() failed" << endl;
    return -1;
  }

  UserManager::setSubScore(15);
  if(!(UserManager::getSubScore() == 15)){
    cout << "set/getSubScore() failed" << endl;
    return -1;
  }

  UserManager::setPlaceScore(12);
  if(!(UserManager::getPlaceScore() == 12)){
    cout << "getPlaceScore() failed" << endl;
    return -1;
  }

  Teacher teacher;
  teacher.setAddEasy(10);
  UserManager::setTeacher(teacher);
  if(!(UserManager::getTeacher().getAddEasy() == 10)){
    cout << "set/getTeacher failed" << endl;
    return -1;
  }
  
  Profile profile;
  profile.setColor(Color(1.0,0.0,0.0));
  UserManager::setProfile(profile);
  if(!(UserManager::getProfile().getColor().getRed() == 1.0)){
    cout << "set/getProfile failed" << endl;
    return -1;
  }

  //all passed if reached
  return 0;
}
