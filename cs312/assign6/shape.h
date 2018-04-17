#ifndef CONE_H
#define CONE_H

#include <string>
#include "shape.h"
#include "point.h"

using namespace std;


class Cone : public Shape {

   private:
  string type,color;
  Point loc;
  Shape *next;

   public:
      Shape(string type, string color, Point loc);

      virtual void print_color (void);

      virtual double compute_volume (void);

      void print_type (void);

      void print_loc (void);
};

#endif
