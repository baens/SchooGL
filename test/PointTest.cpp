#include <iostream>
#include <Point.h>
using namespace std;

int main(){
	Point p1;
	if(!(p1.getX() == 0.0)){
		cout << "X not set correctly for default" << endl;
		return -1;
	}
	if(!(p1.getY() == 0.0)){
		cout << "Y not set correctly for default" << endl;
		return -1;
	}
	if(!(p1.getZ() == 0.0)){
		cout << "Z not set correctly for default" << endl;
		return -1;
	}

	Point p2(1.0, 1.0);
	if(!(p2.getX() == 1.0)){
		cout << "X not set correctly in constructor" << endl;
		return -1;
	}
	if(!(p2.getY() == 1.0)){
		cout << "Y not set correctly in constructor" << endl;
		return -1;
	}
	if(!(p2.getZ() == 0.0)){
		cout << "Z not set correctly in constructor" << endl;
		return -1;
	}

	Point p3(1.0, 1.0, 1.0);
	if(!(p3.getX() == 1.0)){
		cout << "X not set correctly in constructor" << endl;
		return -1;
	}
	if(!(p3.getY() == 1.0)){
		cout << "Y not set correctly in constructor" << endl;
		return -1;
	}
	if(!(p3.getZ() == 1.0)){
		cout << "Z not set correctly in constructor" << endl;
		return -1;
	}
}
