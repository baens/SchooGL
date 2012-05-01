#include "Vector.h"

Vector::Vector(){
  this->x = 0.0;
  this->y = 0.0;
  this->z = 0.0;
}
Vector::Vector(double x, double y, double z){
  this->x = x;
  this->y = y;
  this->z = z;
}
Vector::Vector(Vector &rhs){
  this->x = rhs.x;
  this->y = rhs.y;
  this->z = rhs.z;
}
