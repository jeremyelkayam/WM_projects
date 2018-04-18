#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include "point.h"

using namespace std;


class Shape {

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
