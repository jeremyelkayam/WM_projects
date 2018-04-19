//author: Jeremy Elkayam
#include <string>
#include <cmath>
#include "sphere.h"

using namespace std;

//Initializes class with specified attributes, using Shape's constructor as a helper.
Sphere::Sphere(string type, string color, Point center, double radius):Shape(type,color,center)
{
  this->radius=radius;
}

void Sphere

//Returns the volume of the solid using (4/3)(pi)(r^3).
double Sphere::compute_volume(void)
{
  return (4.0/3.0)*M_PI*radius*radius*radius;
}

//there is only one color, so no need to redefine print_color
