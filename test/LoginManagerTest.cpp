#include <LoginManager.h>
#include <iostream>
using namespace std;

int main()
{
  //try valid login
  if(!LoginManager::tryLogin("s","s")){
    cout << "tryLogin failed" << endl;
    return -1;
  }
  
  //try case senstive
  if(LoginManager::tryLogin("s","S")){
    cout << "tryLoginFailed with password case sentive test" << endl;
    return -1;
  }

  if(LoginManager::tryLogin("S","s")){
    cout << "tryLoginfailed with username case sentive test" << endl;
    return -1;
  }
  //try invalid login
  if(LoginManager::tryLogin("abasdfas","asdf234afasdf")){
    cout << "tryLogin failed with invalid user name" << endl;
    return -1;
  }

  return 0;

}
