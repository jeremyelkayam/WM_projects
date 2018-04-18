#ifndef SPHERE_H
#define SPHERE_H

#include <string>
#include "shape.h"

using namespace std;


class Sphere : public Shape {

   private:
      Point center;
      double radius;

   public:
      Sphere(string type, string color, Point center, double radius);

      void print_color (void);

      double compute_volume (void);

      // the following overrides print_type in the base class, but can never be called
      //  through a pointer to the base class
      void print_type (void) { cout << "should never be called" << endl; }
};

#endif
