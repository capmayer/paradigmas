#include <cmath>

class Point()
{
   private double x;
   private double y;

   Point()
   {
       this.x = 0;
       this.y = 0;
   }

   Point(double x, double y)
   {
       this.x = x;
       this.y = y;
   }

   public void move(double dx, double dy)
   {
       this.x += dx;
       this.y += dy;
   }

   public double distanceTo(Point d)
   {
       return 10;
   }
}
