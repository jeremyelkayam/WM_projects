#include "vec.h"
#include <stddef.h>
#include <math.h>

VEC_T normalize(VEC_T v){
  VEC_T result;

  //Compute magnitude using 3D Pythagorean
  double length=sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));

  //Normalize by dividing by length
  result.x=v.x/length;
  result.y=v.y/length;
  result.z=v.z/length;
  
  return result;
}
