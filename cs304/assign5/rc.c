#include "rc.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <float.h>

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
  //quadratic formula
  double a,b,c;
  a=1;
  b=2 * ((ray.direction.x * (ray.origin.x - sphere.center.x)) + (ray.direction.y * (ray.origin.y - sphere.center.y)) + (ray.direction.z * (ray.origin.z - sphere.center.z)));
  c=( (ray.origin.x - sphere.center.x) * (ray.origin.x - sphere.center.x) + (ray.origin.y - sphere.center.y) * (ray.origin.y - sphere.center.y) + (ray.origin.z - sphere.center.z) * (ray.origin.z - sphere.center.z)) - (sphere.radius * sphere.radius);

  //calculate discriminant, b^2 - 4ac
  double disc = b * b - 4 * a * c;
  //negative discriminant means no real solution, which means no intersection exists
  if(disc < 0){
    return 0;
  }
  double t0,t1; //if the ray intersects the sphere, it will intersect it at 2 locations. these can store those 2
  //t0 is the closer intersection. t1 is the further
  t0 = (-b + sqrt (disc)) / (2*a);
  t1 = (-b - sqrt (disc)) / (2*a);

  //printf("%lf,%lf\n",t0,t1);
  if(t0 < 0){
    if(t1 < 0){//if they're both negative there's no intersect.
      return 0;
    }
    t0 = t1; //if t0 is negative but t1 isn't, we can use t1 instead
  } 
  *t = t0;
  
  return 1;
}

COLOR_T cast (RAY_T ray, OBJ_T *list){
  COLOR_T result;
  result.r=1;
  result.g=1;
  result.b=1;
  double dist,closest_so_far;

  closest_so_far=DBL_MAX;

  OBJ_T *current;
  for(current=list;current!=NULL;current=current->next){
    if(intersect_sphere(ray,current->sphere,&dist)){
      if(dist<closest_so_far){
	  closest_so_far=dist;
	  result=current->color;
	}
      }
  }

  //if(result.r!=1 && result.g!=1 && result.b!=1) printf("r: %lf g: %lf b: %lf\n",result.r,result.g,result.b);
  
  return result;
}


int main(){
  
  OBJ_T *list = NULL;

  read_objs(&list); // Read in the object parameters from stdin and append them to list

  //printf("object radius: %lf\n",list->sphere.radius);

  printf("P6 1000 1000 255\n"); //PPM header

  RAY_T current_px;
  
  current_px.direction.z=1;
  current_px.origin.x=0;
  current_px.origin.y=0;
  current_px.origin.z=0;

  COLOR_T px_color;
  int row,col;
  
  for(row=0;row<1000;row++){//iterate through every row, then every col
    for(col=0;col<1000;col++){
      //set up ray pointing from origin to here
      current_px.direction.x = -.5 + col / 1000.0;
      current_px.direction.y = .5 - row / 1000.0;

      current_px.direction=normalize(current_px.direction);
      //printf("%d,%d\n",row,col);
      //cast the ray, get its color
      px_color=cast(current_px,list);
      
      unsigned char r,g,b;
      r=(int)(255*px_color.r);
      g=(int)(255*px_color.g);
      b=(int)(255*px_color.b);
      printf("%c%c%c",r,g,b);
    }
  }
  
  //free all members of list
  OBJ_T *current;
  for(current=list;current!=NULL;current=current->next){
    //printf("freeing\n");
    free(current);
    //current=current->next;
  }
  
  return 0;
}
