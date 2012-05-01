#include <Profile.h>

Profile::Profile():nick(""),user_color(Color(0.0,0.0,0.0))
{
}

Profile::Profile(string nick, Color user_color):nick(nick),user_color(user_color)
{
}
