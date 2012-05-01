#ifndef LOGINMANGER_H
#define LOGINMANGER_H
#ifdef _WIN32
#include <windows.h>
#endif

#include <mysql.h>

#include <string>
using namespace std;

#define DB_SR "gensrv.baens.net"
#define DB_UN "schoogl"
#define DB_PW "schoogl"
#define DB_DB "SchooGL"
//#define DB_UN "schoogl"
//#define DB_PW "schoogl"
//#define DB_DB "mathtool"

class LoginManager {
public:
	static bool tryLogin(string username, string password);
};

#endif

