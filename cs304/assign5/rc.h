#ifndef RC_H
#define RC_H

#include "vec.h"

typedef struct {
  VEC_T origin,direction;
} RAY_T;

typedef struct  {
  double r,g,b; // all 3 are between 0 and 1
} COLOR_T;

typedef struct {
  VEC_T center; //xyz coords of the center
  double radius; //radius
} SPHERE_T;

typedef struct OBJ {
  SPHERE_T sphere;
  COLOR_T color;
  struct OBJ *next;
} OBJ_T;

void read_objs(OBJ_T **list);

int intersect_sphere(RAY_T ray, SPHERE_T sphere, double *t);

COLOR_T cast(RAY_T ray, OBJ_T *list);

int main();

#endif
