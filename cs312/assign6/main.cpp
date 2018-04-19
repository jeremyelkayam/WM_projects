#include <iostream>
#include "cone.h"
#include "box.h"
#include "sphere.h"

using namespace std;

int main()
{
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

  
  return 0;
}

void read_objs (Shape **list)

{
   Shape *node;                    // variable used to create a new node each time through the loop
   double x, y, z, xx, yy, zz, rad;     // temporary variables used to read in values; fill in the rest
   string type, color, color2;// temporary variables used to read in values; fill in the rest

   // initialize list
   *list = NULL;

   while (cin >> type) {

      if (type.compare ("sphere") == 0) {

         // fill in code here to read in the sphere values and create a new node
      }

      else if (type.compare ("box") == 0) {

         // fill in code here to read in the box values and create a new node
      }
   
      else if (type.compare ("cone") == 0) {

         cin >> x >> y >> z >> xx >> yy >> zz >> rad >> color >> color2;

         node = new Cone (type, color, color2, Point (x, y, z), Point (xx, yy, zz), rad);
      }

      // link new node at front of list:
      //   set the next field of node to the beginning of the list (*list)
      //   set the beginning of the list to node
   }
}
