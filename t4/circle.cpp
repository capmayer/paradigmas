#include <cmath>
#include <iostream>

const double PI = 3.14159;

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


class Circle {
private:
   Point p;
   double r;
public:
   Circle(){
     r = 0.0;
   }
   Circle(int x, int y, int r) : p(x, y){
      this->r = r;
   }
   Point getPoit(){
     return p;
   }
   double area() {
      return PI * r * r;
   }
   double getR(){
     return r;
   }
   double distanceTo(Circle c)
   {
       return p.distanceTo(c.getPoit()) - c.getR() - r;
   }

   double distanceTo(Circle* c)
   {
       return std::sqrt((pow((p.getX() - c->getPoit().getX()), 2) + pow((p.getY() - c->getPoit().getY()),2)));
   }
};

int main() {
   Circle c1(2,2,2);
   Circle* c2 = new Circle(1,1,1);
   std::cout << c1.distanceTo(c2) << std::endl;
   std::cout << c2->area() << std::endl;
   delete c2;
}
