#ifndef PROFILEWINDOW_H
#define PROFILEWINDOW_H
#include <string>
#include <Rectangle1.h>
#include <InputBox.h>
#include <Profile.h>
#include <UserManager.h>
#include <ProfileManager.h>

using namespace std;

class ProfileWindow{
	public:
		ProfileWindow();
		void draw();
		bool handleMouseDown(Point p);
		bool handleMouseUp(Point p);
		void processInput(unsigned int key);
		void saveProfile(){UserManager::setProfile(profile);ProfileManager::setProfile(UserManager::getID(),profile);}
	private:
		InputBox* nickname;
		Rectangle1* colors[5];
		Rectangle1* title;
		Rectangle1* character;
		Rectangle1* save;
		Rectangle1* pexit;
		Rectangle1* nname;
		Profile     profile;
};
#endif //PROFILEWINDOW_H
