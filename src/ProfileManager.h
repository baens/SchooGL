#ifndef PROFILEMANGER_H
#define PROFILEMANGER_H
#include <Profile.h>
class ProfileManager{
 public:
  static Profile getProfile(int uID);
  static bool setProfile(int uID,Profile p);
};
#endif
