#include <cmath>
#include <iostream>
#include <sstream>

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

     std::string svgLine(Point *d){
         std::stringstream str;
         str << "<line x1='" << x << "' y1='" << y << "' x2='" << d->getX() << "' y2='" << d->getY() << "' style='stroke:rgb(255,255,255);stroke-width:2' />";
         return str.str();
     }

     std::string svgLine(Point d){
         std::stringstream str;
         str << "<line x1='" << x << "' y1='" << y << "' x2='" << d.getX() << "' y2='" << d.getY() << "' style='stroke:rgb(255,255,255);stroke-width:2' />";
         return str.str();
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
   Point getPoint(){
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
       return p.distanceTo(c.getPoint()) - c.getR() - r;
   }

   double distanceTo(Circle* c)
   {
       return std::sqrt((pow((p.getX() - c->getPoint().getX()), 2) + pow((p.getY() - c->getPoint().getY()),2)));
   }

   std::string svgCircle(){
       std::stringstream str;
       str << "<circle cx='" << p.getX() << "' cy='" << p.getY() <<"' r='" << r <<"' stroke='black' stroke-width='3' fill='red' />";
       return str.str();
   }


};

int main() {
  Circle* circles [5];

  std::string svgOut = "<svg height='100' width='300'>";

  for(int x=0; x<5; x++)
  {
    circles[x] = new Circle(x*40, 50 , x*3 + 5);
    svgOut += circles[x]->svgCircle();
  }
  for(int x=0; x<4; x++)
  {
    svgOut += circles[x]->getPoint().svgLine(circles[x+1]->getPoint());
  }

  svgOut+= "</svg>";

  std::cout << svgOut << std::endl;
}
