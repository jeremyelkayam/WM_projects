#include <string>
#include <cmath>
#include <iostream>
#include "point.h"

using namespace std;

//Gives the Euclidean distance of the point from the origin.
double Point::length()
{
  //using the distance formula (sqrt(a^2+b^2+c^2)) with (0,0,0) as the origin
  return sqrt(this->x*this->x+this->y*this->y+this->z*this->z);
}

//Prints the coordinates of the point.
void Point::print(void)
{
  cout << "x: " << this->x << " y: " << this->y << " z: " << this->z << "\n";
}

//Subtraction overload case for points; subtracts the coordinates of the second point from the first.
Point Point::operator-(const Point& param)
{
  //Generate a new point with subtracted coordinates.
  Point temp;
  temp.set(this->x-param.x,this->y-param.y,this->z-param.z);
  return temp;
}
