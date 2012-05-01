#include <iostream>
#include <Color.h>
using namespace std;

int main() {
	Color c1;
	if(!(c1.getRed() == 0.0)){
		cout << "red not set correctly in the default constructor" << endl;
		return -1;
	}

	if(!(c1.getGreen() == 0.0)){
		cout << "green not set correctly in the default constructor" << endl;
		return -1;
	}

	if(!(c1.getBlue() == 0.0)){
		cout << "blue not set correctly in the default constructor" << endl;
		return -1;
	}
	if(!(c1.getAlpha() == 0.0)){
		cout << "alpha not set correctly in the default constructor" << endl;
		return -1;
	}

	Color c2(1.0, 1.0, 1.0, 1.0);
	if(!(c2.getRed() == 1.0)){
		cout << "red not set correctly in the constructor" << endl;
		return -1;
	}

	if(!(c2.getGreen() == 1.0)){
		cout << "green not set correctly in the constructor" << endl;
		return -1;
	}

	if(!(c2.getBlue() == 1.0)){
		cout << "blue not set correctly in the constructor" << endl;
		return -1;
	}
	if(!(c2.getAlpha() == 1.0)){
		cout << "alpha not set correctly in the constructor" << endl;
		return -1;
	}

	Color c3(1.0, 1.0, 1.0);
	if(!(c3.getRed() == 1.0)){
		cout << "red not set correctly in the constructor" << endl;
		return -1;
	}

	if(!(c3.getGreen() == 1.0)){
		cout << "green not set correctly in the constructor" << endl;
		return -1;
	}

	if(!(c3.getBlue() == 1.0)){
		cout << "blue not set correctly in the constructor" << endl;
		return -1;
	}
	if(!(c3.getAlpha() == 1.0)){
		cout << "alpha not set correctly in the constructor" << endl;
		return -1;
	}
	
	c3.setRed(0.5);
	c3.setGreen(0.0);
	c3.setBlue(0.0);
	c3.setAlpha(0.0);
	if(!(c3.getRed() == 0.5)){
		cout << "red not set correctly with the set method" << endl;
		return -1;
	}

	if(!(c3.getGreen() == 0.0)){
		cout << "green not set correctly with the set method" << endl;
		return -1;
	}

	if(!(c3.getBlue() == 0.0)){
		cout << "blue not set correctly with the set method" << endl;
		return -1;
	}
	if(!(c3.getAlpha() == 0.0)){
		cout << "alpha not set correctly with the set method" << endl;
		return -1;
	}
}