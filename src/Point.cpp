#include "Point.h"
#include <iostream>

using namespace std;

Point::Point(){
  this->x = 0.0;
  this->y = 0.0;
  this->z = 0.0;
}

Point::Point(double x, double y){
  this->x = x;
  this->y = y;
  this->z = 0.0;
}

Point::Point(double x, double y, double z){
  this->x = x;
  this->y = y;
  this->z = z;
}
Point::Point(const Point& rhs){
  this->x = rhs.x;
  this->y = rhs.y;
  this->z = rhs.z;
}

double Point::getX(){
	return this->x;
}
double Point::getY(){
	return this->y;
}
double Point::getZ(){
	return this->z;
}
void Point::output(){
  cout << x << " " << y << " " << z << endl;
}
