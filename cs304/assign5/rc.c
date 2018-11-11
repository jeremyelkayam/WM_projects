#include "rc.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

void read_objs(OBJ_T **list){
  double x,y,z,rad,r,g,b;
  *list=NULL;
  OBJ_T *obj;
  
  while(scanf("%lf%lf%lf%lf%lf%lf%lf",&x,&y,&z,&rad,&r,&g,&b)==7){

    //printf("scanned in:\n%lf %lf %lf\n%lf\n%lf %lf %lf\n",x,y,z,rad,r,g,b);

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
  result.r=1;
  result.g=1;
  result.b=1;
  double dist,closest_so_far;

  for(OBJ_T *current=list;current!=NULL;current=current->next){
    if(intersect_sphere(ray,current->sphere,&dist)){
	if(dist<closest_so_far){
	  closest_so_far=dist;
	  result=current->color;
	}
      }
  }
  
  return result;
}


int main(){
  VEC_T origin_vect;
  origin_vect.x=0;
  origin_vect.y=0;
  origin_vect.z=0;
  
  OBJ_T *list;

  read_objs(&list); // Read in the object parameters from stdin and append them to list
  
  printf("P6 1000 1000 255\n"); //PPM header
  
  for(int row=0;row<1000;row++){//iterate through every row, then every col
    for(int col=0;col<1000;col++){
      RAY_T current_px;
      current_px.direction.x=col;
      current_px.direction.y=row;
      current_px.direction.z=500/tan(30);

      current_px.origin.x=0;
      current_px.origin.y=0;
      current_px.origin.z=0;
      
      COLOR_T color=cast(current_px,list);
      
      unsigned char r,g,b;
      r=255*color.r;
      g=255*color.g;
      b=255*color.b;
      printf("%c%c%c",r,g,b);
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
