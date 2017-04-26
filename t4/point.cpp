#include <cmath>
#include <iostream>

class Point
{
   private:
     double x;
     double y;

   public:

     Point()
     {
         x = 0;
         y = 0;
     }

     Point(double x, double y)
     {
         this->x = x;
         this->y = y;
     }


     void move(double dx, double dy)
     {
         this->x += dx;
         this->y += dy;
     }

     double distanceTo(Point d)
     {
         return std::sqrt((pow((x - d.getX()), 2) + pow((y - d.getY()),2)));
     }

     double distanceTo(Point* d)
     {
         return std::sqrt((pow((x - d->getX()), 2) + pow((y - d->getY()),2)));
     }

     int getX()
     {
         return x;
     }
     int getY()
     {
         return y;
     }
};

int main() {
  Point p(1,1);
  Point* points[5];
  
  for(int x=0; x<5; x++)
    points[x] = new Point(x*2, x*3);

  for(int x=0; x<5; x++)
    std::cout << points[x]->distanceTo(p) << std::endl;

  for(int x=0; x<5; x++)
    delete points[x];
}
