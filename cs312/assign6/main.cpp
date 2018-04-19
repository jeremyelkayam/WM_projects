//author: Jeremy Elkayam
#include <iostream>
#include "cone.h"
#include "box.h"
#include "sphere.h"

using namespace std;

//Reads object definitions from cin and chains them together using list as the beginning of the list and the next field of each Shape.
void read_objs (Shape **list)
{
  Shape *node;                    // variable used to create a new node each time through the loop
  double x, y, z, xx, yy, zz, rad;     // temporary variables used to read in values; fill in the rest
  string type, color, color2;// temporary variables used to read in values; fill in the rest
  
  // initialize list
  *list = NULL;
  
  while (cin >> type) {
    
    if (type.compare ("sphere") == 0) {

      //read in values from 
      cin >> x >> y >> z >> rad >> color;
      
      node = new Sphere(type,color,Point(x,y,z),rad);
    }
    
    else if (type.compare ("box") == 0) {

      cin >> x >> y >> z >> xx >> yy >> zz >> color >> color2;
      
	node = new Box(type,color,color2,x,y,z,Point(xx,yy,zz));
    }
   
    else if (type.compare ("cone") == 0) {
      
      cin >> x >> y >> z >> xx >> yy >> zz >> rad >> color >> color2;
      
      node = new Cone (type, color, color2, Point (x, y, z), Point (xx, yy, zz), rad);
    }
    
    // link new node at front of list:
    //   set the next field of node to the beginning of the list (*list)
    //   set the beginning of the list to node

    node->set_next(*list);
    *list=node;
  }
}

void print_objs(Shape *list)
{
  Shape *current=list;

  cout << "Objects:\n\n";
  
  while(current!=NULL){
    current->print_type();
    current->print_color();
    current->print_loc();
    cout << "Volume: " << current->compute_volume() <<"\n\n";
    
    current=current->get_next();
  }
}

int main()
{
  /*
  Point hello;
  hello.set(0,0,0);
  hello.print();
  cout << "Distance from origin: " << hello.length() << "\n";
  hello.set(2,5,6);
  hello.print();
  cout << "Distance from origin: " << hello.length() << "\n";
  Point *hi=new Point(1,1,1);
  hi->print();
  Point hey;
  hey.set(1,1,1);
  hey.print();
  Point subtract=hello-hey;
  cout << "2,5,6 - 1,1,1 = ";
  subtract.print();
  subtract=hey-hello;
  cout << "1,1,1 - 2,5,6 = ";
  subtract.print();


  Sphere yo=Sphere("sphere","yellow",subtract,6);
  yo.print_type();
  yo.print_loc();
  yo.print_color();
  cout << "Volume: " << yo.compute_volume() << "\n";

  Box yikeo=Box("box","green","black",5,6,7,hello);
  yikeo.print_type();
  yikeo.print_loc();
  yikeo.print_color();
  cout << "Volume: " << yikeo.compute_volume() << "\n";
  */
  
  Shape *objects;
  read_objs(&objects);
  print_objs(objects);
  
  return 0;
}
