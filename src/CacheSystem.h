#ifndef CACHESYSTEM_H
#define CACHESYSTEM_H
#include <Question.h>
#include <Profile.h>
#include <Difficulty.h>
#include <Subject.h>
class CacheSystem {
 public:
  static bool tryCacheLogin(string username,string password);
  static void cacheLogin(string username, string password,int uid);
  static void cacheProfile(string username, Profile p);
  static int getUserID(string username);
  static Profile* getProfile(string username);
  static bool cacheQuestion(Question* q, Subject s, Difficulty d);
  static Question* getQuestionFromCache(Subject s, Difficulty d);
  static void startQuestionCachingThread();
  static bool isOffLine();
};
#endif
