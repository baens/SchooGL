#include "Color.h"

Color::Color(){
	this->red = 0.0;
	this->green = 0.0;
	this->blue = 0.0;
	this->alpha = 0.0;
}
Color::Color(double r, double g, double b, double a){
	this->red = r;
	this->green = g;
	this->blue = b;
	this->alpha = a;
}
Color::Color(double r, double g, double b){
	this->red = r;
	this->green = g;
	this->blue = b;
	this->alpha = 1.0;
}
Color::Color(const Color& rhs){
	this->red = rhs.red;
	this->green = rhs.green;
	this->blue = rhs.blue;
	this->alpha = rhs.alpha;
}
void Color::setRed(double r){
	this->red = r;
}
double Color::getRed(){
	return this->red;
}
void Color::setGreen(double g){
	this->green = g;
}
double Color::getGreen(){
	return this->green;
}
void Color::setBlue(double b){
	this->blue = b;
}
double Color::getBlue(){
	return this->blue;
}
void Color::setAlpha(double a){
	this->alpha = a;
}
double Color::getAlpha(){
	return this->alpha;
}
