#include "rc.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void read_objs(OBJ_T **list){
  double x,y,z,rad,r,g,b;
  *list=NULL;
  OBJ_T *obj;
  
  while(scanf("%lf%lf%lf%lf%lf%lf%lf",&x,&y,&z,&rad,&r,&g,&b)==7){

    printf("scanned in:\n%lf %lf %lf\n%lf\n%lf %lf %lf\n",x,y,z,rad,r,g,b);

    //Allocate memory for a new object
    obj=(OBJ_T *)malloc(sizeof(OBJ_T));

    
    //Initialize object with parameters from scanf
    obj->sphere.center.x=x;
    
    obj->sphere.center.y=y;
    obj->sphere.center.z=z;
    obj->sphere.radius=rad;
    obj->color.r=r;
    obj->color.g=g;
    obj->color.b=b;

    obj->next=*list;//Append list to obj
    *list=obj; //Set obj to head of list

  }
}

int intersect_sphere(RAY_T ray, SPHERE_T sphere, double *t){
  return 0;
}

COLOR_T cast (RAY_T ray, OBJ_T *list){
  COLOR_T result;
  return result;
}


int main(){
  VEC_T origin_vect;
  origin_vect.x=0;
  origin_vect.y=0;
  origin_vect.z=0;
  
  OBJ_T *list;

  read_objs(&list); // Read in the object parameters from stdin and append them to list
  
  //printf("P6 1000 1000 255\n"); //PPM header
  
  for(int row=0;row<1000;row++){//iterate through every row, then every col
    for(int col=0;col<1000;col++){
      unsigned char r,g,b;
      r=255;
      g=255;
      b=255;
      //printf("%c%c%c",r,g,b);
    }
  }
  
  //free all members of list
  for(OBJ_T *current=list ; current=current->next ; current!=NULL){
    VEC_T vecky=normalize(current->sphere.center);
    printf("normalized vect: %lf %lf %lf",vecky.x,vecky.y,vecky.z);
    
    free(current);
  }
  
  return 0;
}