#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/glut.h>
#include "Rectangle1.h"
#include <iostream>
using namespace std;
Rectangle1::Rectangle1(){
	this->height = 0.0;
	this->width = 0.0;
	this->text = "";
	texture_image[0] = NULL;
}
Rectangle1::Rectangle1(float h, float w, Point p, Color c, string s){
	this->height = h;
	this->width = w;
	this->point = p;
	this->color = c;
	this->text = s;
	texture_image[0] = NULL;
}

Rectangle1::Rectangle1(float h, float w, Point p, string filename){
	//Color c(1.0,1.0,1.0);
	//this->color = c;
	this->height = h;
	this->width = w;
	this->point = p;
	this->color = Color(1.0,1.0,1.0,0.5);
	LoadGLTextures(filename,true);
}

Rectangle1::Rectangle1(float h, float w, Point p, string filename, Color c){
	//Color c(1.0,1.0,1.0);
	//this->color = c;
	this->height = h;
	this->width = w;
	this->point = p;
	this->color = c;
	LoadGLTextures(filename,true);
}

Rectangle1::Rectangle1(const Rectangle1 &rhs){
	this->height = rhs.height;
	this->width = rhs.width;
	this->text = rhs.text;
	this->point = rhs.point;
	this->color = rhs.color;
	this->text = rhs.text;
	this->texture_image[0] = rhs.texture_image[0];
	this->texture_image[1] = rhs.texture_image[1];
	this->texture_image[2] = rhs.texture_image[2];
	this->texture_image[3] = rhs.texture_image[3];
	this->texture[0] = rhs.texture[0];
	this->texture[1] = rhs.texture[1];
	this->texture[2] = rhs.texture[2];
	this->texture[3] = rhs.texture[3];
	
}
void Rectangle1::draw(){
  if(texture_image[0] != NULL){
    textureRecDraw();
  }else if(text.length() > 0){
    this->width = text.length()*.8;
    this->height = 1.25;
    textRecDraw();
  }
  else{
    colorRecDraw();
  }
}
void Rectangle1::colorRecDraw(){
	glPushMatrix();
		glTranslatef(0.0f, 0.0f, -0.1);				// Move Right 1.5 Units And Into The Screen 6.0
		glColor4f(color.getRed(), color.getGreen(), color.getBlue(),1.0);							// Set The Color To Blue One Time Only
		glBegin(GL_POLYGON);									// Draw A Poly
		glVertex3f(point.getX() - width/2, point.getY() + height/2, point.getZ());					// Top Left
			glVertex3f(point.getX() + width/2, point.getY() + height/2, point.getZ());					// Top Right
			glVertex3f(point.getX() + width/2, point.getY() - height/2, point.getZ());					// Bottom Left
			glVertex3f(point.getX() - width/2, point.getY() - height/2, point.getZ());					// Bottom Right
		glEnd(); // Done Drawing The Poly
	glPopMatrix();
}
void Rectangle1::textRecDraw(){
	colorRecDraw();
	glPushMatrix();
	glPushAttrib(GL_LINE_BIT);
		glColor4f(1.0, 1.0, 1.0,1.0);
		glLineWidth(1.5f);
		if(text.length()%2 != 0)
			glTranslatef(point.getX() - (text.length() * .36), point.getY() - .35, 0);
		else
			glTranslatef(point.getX() - (text.length()/2)*.725, point.getY() - .35, 0);
		if(text.length() > 20){
		  glTranslatef(12.0,0.0,0.0);
		  glScalef(0.4,0.4,0.0);		  
		}
		glScalef(0.007,0.007,0.01);
		for(unsigned int c = 0;c < text.length(); c++)
			glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, text[c]);
	glPopAttrib();
	glPopMatrix();
}

void Rectangle1::textureRecDraw(){
  glEnable(GL_TEXTURE_2D);
  glEnable(GL_BLEND);
  glDisable(GL_DEPTH_TEST);

  glTranslatef(0.0f,0.0f,-0.1f);
  glBlendFunc(GL_DST_COLOR,GL_ZERO);
  glBindTexture(GL_TEXTURE_2D,texture[3]);
  glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(point.getX() - width/2, point.getY() + height/2,  0.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(point.getX() + width/2, point.getY() + height/2, 0.0f);	
	glTexCoord2f(1.0f, 0.0f); glVertex3f(point.getX() + width/2, point.getY() - height/2, 0.0f);	
	glTexCoord2f(0.0f, 0.0f); glVertex3f(point.getX() - width/2, point.getY() - height/2, 0.0f);	
  glEnd();
  glBlendFunc(GL_ONE,GL_ONE);
  glBindTexture(GL_TEXTURE_2D,texture[2]);
  glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(point.getX() - width/2, point.getY() + height/2,  0.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(point.getX() + width/2, point.getY() + height/2, 0.0f);	
	glTexCoord2f(1.0f, 0.0f); glVertex3f(point.getX() + width/2, point.getY() - height/2, 0.0f);	
	glTexCoord2f(0.0f, 0.0f); glVertex3f(point.getX() - width/2, point.getY() - height/2, 0.0f);	
  glEnd();
  
  glBlendFunc(GL_DST_COLOR,GL_ZERO);
  glBindTexture(GL_TEXTURE_2D,texture[1]);
  glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(point.getX() - width/2, point.getY() + height/2,  0.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(point.getX() + width/2, point.getY() + height/2, 0.0f);	
	glTexCoord2f(1.0f, 0.0f); glVertex3f(point.getX() + width/2, point.getY() - height/2, 0.0f);	
	glTexCoord2f(0.0f, 0.0f); glVertex3f(point.getX() - width/2, point.getY() - height/2, 0.0f);	
  glEnd();
  glBlendFunc(GL_ONE,GL_ONE);
  glBindTexture(GL_TEXTURE_2D,texture[0]);
  glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(point.getX() - width/2, point.getY() + height/2,  0.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(point.getX() + width/2, point.getY() + height/2, 0.0f);	
	glTexCoord2f(1.0f, 0.0f); glVertex3f(point.getX() + width/2, point.getY() - height/2, 0.0f);	
	glTexCoord2f(0.0f, 0.0f); glVertex3f(point.getX() - width/2, point.getY() - height/2, 0.0f);	
  glEnd();
  
  glDisable(GL_BLEND);
  glEnable(GL_DEPTH_TEST);
  glDisable(GL_TEXTURE_2D);
}
BBox Rectangle1::getBBox(){
	Point minPoint(point.getX() - this->width/2, point.getY() - this->height/2);
	Point maxPoint(point.getX() + this->width/2, point.getY() + this->height/2);
	return BBox(minPoint,maxPoint);
}
void Rectangle1::setString(string s){
	this->text = s;
}
void Rectangle1::setColor(Color c){
	this->color = c;
}
void Rectangle1::setPoint(Point* p){
	this->point = *p;
}
Color Rectangle1::getColor(){
	return color;
}

int Rectangle1::ImageLoad(const char *filename, Image *image, bool color) {
	FILE *file;
	unsigned long size;                 // size of the image in bytes.
	unsigned long i;                    // standard counter.
	unsigned short int planes;          // number of planes in image (must be 1) 
	unsigned short int bpp;             // number of bits per pixel (must be 24)
	unsigned char temp;                          // temporary color storage for bgr-rgb conversion.

    // make sure the file is there.
	if ((file = fopen(filename, "rb"))==NULL)
	{
		printf("File Not Found : %s\n",filename);
		return 0;
	}
    
    // seek through the bmp header, up to the width/height:
	fseek(file, 18, SEEK_CUR);

    // read the width
	if ((i = fread(&image->sizeX, 4, 1, file)) != 1) {
		printf("Error reading width from %s.\n", filename);
		return 0;
	}
	//printf("Width of %s: %lu\n", filename, image->sizeX);
    
    // read the height 
	if ((i = fread(&image->sizeY, 4, 1, file)) != 1) {
		printf("Error reading height from %s.\n", filename);
		return 0;
	}
	//printf("Height of %s: %lu\n", filename, image->sizeY);
    
    // calculate the size (assuming 24 bits or 3 bytes per pixel).
	size = image->sizeX * image->sizeY * 3;

    // read the planes
	if ((fread(&planes, 2, 1, file)) != 1) {
		printf("Error reading planes from %s.\n", filename);
		return 0;
	}
	if (planes != 1) {
		printf("Planes from %s is not 1: %u\n", filename, planes);
		return 0;
	}

    // read the bpp
	if ((i = fread(&bpp, 2, 1, file)) != 1) {
		printf("Error reading bpp from %s.\n", filename);
		return 0;
	}
	if (bpp != 24) {
		printf("Bpp from %s is not 24: %u\n", filename, bpp);
		return 0;
	}
	
    // seek past the rest of the bitmap header.
	fseek(file, 24, SEEK_CUR);

    // read the data. 
	image->data = new unsigned char[size];
	if (image->data == NULL) {
		printf("Error allocating memory for color-corrected image data");
		return 0;	
	}

	if ((i = fread(image->data, size, 1, file)) != 1) {
		printf("Error reading image data from %s.\n", filename);
		return 0;
	}

	for (i=0;i<size;i+=3) { // reverse all of the colors. (bgr -> rgb)
		temp = image->data[i];
		image->data[i] = image->data[i+2];
		image->data[i+2] = temp;
		if(color){
		  if(image->data[i] == 255 && image->data[i+1] == 255&& image->data[i+2] == 255){
		    image->data[i] = this->color.getRed()*255;
		    image->data[i+1] = this->color.getGreen()*255;
		    image->data[i+2] = this->color.getBlue()*255;
		  }
		}
	}
    // we're done.
	//printf("All is well\n");
	return 1;
}

// Load Bitmaps And Convert To Textures
void Rectangle1::LoadGLTextures(string filename, bool color) {	

	char * path = getenv( "SCHOOGL_ROOT_PATH" );
	string schoogl_path = "";
	if( path != NULL ) {
		schoogl_path = string(path) + "/";
	}
	string filename_mask = schoogl_path+filename+"_mask.bmp";
	string filename_shield = schoogl_path+filename+"_shield.bmp";
	string filename_shield_mask = schoogl_path+filename+"_shield_mask.bmp";
	filename = schoogl_path+filename+".bmp";

  // allocate space for texture
		texture_image[0] = new Image;
		texture_image[1] = new Image;
		texture_image[2] = new Image;
		texture_image[3] = new Image;
		if (texture_image == NULL) {
			printf("Error allocating space for image");
			exit(0);
		}
		
		if (!ImageLoad(filename.c_str(), texture_image[0],color) || !ImageLoad(filename_mask.c_str(),texture_image[1],false) ||
		    !ImageLoad(filename_shield.c_str(),texture_image[2],color) || !ImageLoad(filename_shield_mask.c_str(),texture_image[3],false)) {
		  exit(1);
		}        
		
		// Create Texture	
		glGenTextures(4, texture);
		glBindTexture(GL_TEXTURE_2D, texture[0]);   // 2d texture (x and y size)
		
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // scale linearly when image smalled than texture
		
		// 2d texture, level of detail 0 (normal), 3 components (red, green, blue), x size from image, y size from image, 
		// border 0 (normal), rgb color data, unsigned byte data, and finally the data itself.
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture_image[0]->sizeX, texture_image[0]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture_image[0]->data);
		glBindTexture(GL_TEXTURE_2D,texture[1]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // scale linearly when image smalled than texture
		
		// 2d texture, level of detail 0 (normal), 3 components (red, green, blue), x size from image, y size from image, 
		// border 0 (normal), rgb color data, unsigned byte data, and finally the data itself.
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture_image[1]->sizeX, texture_image[1]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture_image[1]->data);

		glBindTexture(GL_TEXTURE_2D,texture[2]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // scale linearly when image smalled than texture
		
		// 2d texture, level of detail 0 (normal), 3 components (red, green, blue), x size from image, y size from image, 
		// border 0 (normal), rgb color data, unsigned byte data, and finally the data itself.
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture_image[2]->sizeX, texture_image[2]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture_image[2]->data);

		glBindTexture(GL_TEXTURE_2D,texture[3]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // scale linearly when image smalled than texture
		
		// 2d texture, level of detail 0 (normal), 3 components (red, green, blue), x size from image, y size from image, 
		// border 0 (normal), rgb color data, unsigned byte data, and finally the data itself.
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture_image[3]->sizeX, texture_image[3]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture_image[3]->data);
}
