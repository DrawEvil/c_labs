#include <stdio.h>
#include <math.h>

int main()
{
   double x;
   printf("Enter x { x<1.0 and x>-1.0}-> ");
   scanf("%lf", &x);
   if (-1.0<x && x<1.0)
   {
      double y = (x-2.0) * sqrt((1.0+x)/(1.0-x));
      double z = log(y*y-1.0);
      printf("y(x) = %lf\nz(y) = %lf\n",y, z);
   }
      else
      printf("x value is incorrect!\n");
   return 0;
}   
