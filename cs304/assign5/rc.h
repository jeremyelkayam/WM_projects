/*
 * rc.h
 * 
 * purpose: a simple raycasting implementation for drawing spheres
 * 
 * @author Jeremy Elkayam
 */

#ifndef RC_H
#define RC_H

#include "vec.h"

//Ray typedef storing 2 vectors
//origin: the ray's origin
//direction: a point the ray passes through
typedef struct {
  VEC_T origin,direction;
} RAY_T;

//color struct storing 3 doubles
//has much precision
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

//read in objs from stdin, malloc the info required
void read_objs(OBJ_T **list);

//compute whether or not and where the ray intersects the sphere
int intersect_sphere(RAY_T ray, SPHERE_T sphere, double *t);

//if the ray intersects a sphere, give the color of the closest sphere
//if not just give white
COLOR_T cast(RAY_T ray, OBJ_T *list);

//draw all pixels. figure out whether or not it intersects an object.
//draw the corresponding color if so
int main();

#endif
