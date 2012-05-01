#ifndef STATMANAGER_H
#define STATMANAGER_H
#include <Subject.h>
#include <Difficulty.h>
#include <UserManager.h>
class StatManager{
 public:
  static string* getStats(int uID);
  static void updateStats(Subject s, Difficulty d, int missed, int total);
};
#endif
