#ifdef _WIN32
#include <windows.h>
#endif
#include <stdio.h>
#include <GL/glut.h>
#include <PrintManager.h>

void PrintManager::print(int width, int height){
#ifdef _WIN32
	RECT rcClient;
	GetClientRect( GetForegroundWindow(), &rcClient );

		
	int cxImage=rcClient.right, cyImage=rcClient.bottom;
	GLubyte *pImageBits;

	BITMAPFILEHEADER bmFileHeader;
	BITMAPINFOHEADER *pBmInfoHeader;
	HBITMAP BitmapImage;
	BITMAPINFO BitmapInfo;
	GLubyte *pBitmapBits;
	HDC hDc;

	hDc = GetDC( NULL );
	memset( &BitmapInfo, 0, sizeof(BITMAPINFO) );
	BitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	BitmapInfo.bmiHeader.biWidth = cxImage;
	BitmapInfo.bmiHeader.biHeight = cyImage;
	BitmapInfo.bmiHeader.biPlanes = 1;
	BitmapInfo.bmiHeader.biBitCount = 24;
	BitmapInfo.bmiHeader.biCompression = BI_RGB;
	BitmapInfo.bmiHeader.biSizeImage =
		(((cxImage * 24 + 31) & ~31) / 8) * cyImage;
	BitmapImage = CreateDIBSection( hDc,
		&BitmapInfo, DIB_RGB_COLORS,
		(void **)(&pBitmapBits), NULL, 0 );
	ReleaseDC( NULL, hDc );

	pBmInfoHeader = &BitmapInfo.bmiHeader;

	pImageBits = pBitmapBits;
	glReadPixels( 0, 0, cxImage, cyImage,
			GL_RGB, GL_UNSIGNED_BYTE,
			pImageBits );

	memset( &bmFileHeader, 0, sizeof(BITMAPFILEHEADER) );
	bmFileHeader.bfType = 0x4D42;
	bmFileHeader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
	bmFileHeader.bfSize = bmFileHeader.bfOffBits
				+ pBmInfoHeader->biSizeImage;

	memset( &bmFileHeader, 0, sizeof(BITMAPFILEHEADER) );
	bmFileHeader.bfType = 0x4D42;
	bmFileHeader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
	bmFileHeader.bfSize = bmFileHeader.bfOffBits
				+ pBmInfoHeader->biSizeImage;
	HDC hdcPrint = GetPrinterDC();
	int cxDib = pBmInfoHeader->biWidth;
	int cyDib = abs(pBmInfoHeader->biHeight);
	int cxClient = GetDeviceCaps(hdcPrint,HORZRES);
	int cyClient = GetDeviceCaps(hdcPrint,VERTRES);
	static DOCINFO di = {sizeof(DOCINFO),TEXT("FormFeed")};
	if(hdcPrint!= NULL){
		if(!(RC_BITBLT & GetDeviceCaps(hdcPrint,RASTERCAPS))){
			return;
		}

		if(StartDoc(hdcPrint,&di)>0)
			StartPage(hdcPrint);
			SetStretchBltMode(hdcPrint,COLORONCOLOR);
			
			StretchDIBits(hdcPrint,0,0,cxClient,cyClient,0,0,cxDib,cyDib,pImageBits,&BitmapInfo,DIB_RGB_COLORS,SRCCOPY);
			EndPage(hdcPrint);		
			EndDoc(hdcPrint);
			DeleteDC(hdcPrint);
	}
#else
	return;
#endif
}

#ifdef _WIN32
HDC PrintManager::GetPrinterDC(){
	DWORD			dwNeeded, dwReturned;
	HDC				hdc;
	PRINTER_INFO_4*	pinfo4;
	PRINTER_INFO_5* pinfo5;
	if(GetVersion() & 0x80000000){ //win 98
		EnumPrinters(PRINTER_ENUM_DEFAULT,NULL,5,NULL,0,&dwNeeded,&dwReturned);
		pinfo5 = (PRINTER_INFO_5*)malloc(dwNeeded);
		EnumPrinters(PRINTER_ENUM_DEFAULT,NULL,5,(PBYTE)pinfo5,dwNeeded,&dwNeeded,&dwReturned);
		hdc = CreateDC(NULL,pinfo5->pPrinterName,NULL,NULL);
		free(pinfo5);
	}else{
		EnumPrinters(PRINTER_ENUM_LOCAL,NULL,4,NULL,0,&dwNeeded,&dwReturned);
		pinfo4 = (PRINTER_INFO_4*)malloc(dwNeeded);
		EnumPrinters(PRINTER_ENUM_LOCAL,NULL,4,(PBYTE)pinfo4,dwNeeded,&dwNeeded,&dwReturned);
		  DWORD pcchBuffer;
		 GetDefaultPrinter(NULL,&pcchBuffer);
		 TCHAR* pszBuffer = new TCHAR[pcchBuffer];   // printer name buffer
		 GetDefaultPrinter(pszBuffer,&pcchBuffer);
		 pinfo4->pPrinterName = pszBuffer;
		 hdc = CreateDC(NULL,pinfo4[0].pPrinterName,NULL,NULL);
		free(pinfo4);
	}
	return hdc;
}
#endif
