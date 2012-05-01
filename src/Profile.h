#ifndef PROFILE_H
#define PROFILE_H
#include <Color.h>
#include <string>
using namespace std;

class Profile{
 public:
  Profile();
  Profile(string nick, Color user_color);
  string getNick(){return nick;}
  Color getColor(){return user_color;}
  void setNick(string s){nick = s;}
  void setColor(Color c){user_color = c;}
 private:
  string nick;
  Color user_color;
};
#endif
