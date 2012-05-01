#ifndef PRINTMANAGER_H
#define PRINTMANAGER_H
#ifdef _WIN32
#include <Windows.h>
#endif

class PrintManager{
public:
	static void print(int width, int height);
private:
#ifdef _WIN32
	static HDC GetPrinterDC();
#endif
};
#endif
