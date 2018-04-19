#ifndef SPHERE_H
#define SPHERE_H

#include <string>
#include <iostream>
#include "shape.h"

using namespace std;


class Sphere : public Shape {

 private:
  double radius;//radius of the sphere
  
 public:
  //Initializes class with specified attributes, using Shape's constructor as a helper.
  Sphere(string type, string color, Point center, double radius);

  //Returns the volume of the solid using (4/3)(pi)(r^3).
  double compute_volume (void);
};

#endif
