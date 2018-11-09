#include "rc.h"
#include <stdio.h>

void read_objs(OBJ_T **list){
  return;
}

int intersect_sphere(RAY_T ray, SPHERE_T sphere, double *t){
  return 0;
}

COLOR_T cast (RAY_T ray, OBJ_T *list){
  COLOR_T result;
  return result;
}


int main(){
  printf("P6 1000 1000 255\n"); //PPM header
  
  for(int row=0;row<1000;row++){//iterate through every row, then every col
    for(int col=0;col<1000;col++){
      unsigned char r,g,b;
      r=255;
      g=255;
      b=255;
      printf("%c%c%c",r,g,b);
    }
  }
  return 0;
}
