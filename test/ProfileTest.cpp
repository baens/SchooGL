#include <iostream>
#include <Profile.h>
using namespace std;

int main()
{
  //test default consturctor
  Profile p1;
  if(!(p1.getNick() == "")){
    cout << "nick not set correctly for default" << endl;
    return -1;
  }

  if(!(p1.getColor().getRed() == 0.0)){
    cout << "color not set correctly for default" << endl;
    return -1;
  }
  //test other consturctor
  Profile p2("test",Color(1.0,1.0,1.0));
  if(!(p2.getNick() == "test")){
    cout << "nick not set correctly for parameter consturctor" << endl;
    return -1;
  }

  if(!(p2.getColor().getRed() == 1.0)){
    cout << "color not set correctly for parameter consturctor" << endl;
    return -1;
  }

  //test get/set nick
  p2.setNick("yay");
  if(!(p2.getNick() == "yay")){
    cout << "set/getNick failed" << endl;
    return -1;
  }

  //test get/set color
  p2.setColor(Color(0.5,0.5,0.5));
  if(!(p2.getColor().getRed() == 0.5)){
    cout << "set/getColor failed" << endl;
    return -1;
  }

  //all tests passed
  return 0;
}
