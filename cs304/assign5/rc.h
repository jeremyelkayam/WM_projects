#ifndef RC_H
#define RC_H

typedef struct {
  double origin,direction;
} RAY_T;

typedef struct  {
  int r,g,b;
} COLOR_T;

typedef struct {
  double center,radius;
} SPHERE_T;

typedef struct {
  SPHERE_T sphere;
  COLOR_T color;
  *OBJ_T next;
} OBJ_T

void read_objs(OBJ_T **list);

int intersect_sphere(RAY_T ray, SPHERE_T sphere, double *t);

COLOR_T cast(RAY_T ray, OBJ_T *list);

int main();

#endif
