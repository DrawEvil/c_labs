#include <stdio.h>
#include <math.h>

int main()
{
   double x;
   printf("Enter x { x<1 and x>-1}-> ");
   scanf("%lf", &x);
   if (x<1 && x>-1)
   {
      double y = (x - 2) * sqrt(1+x/1-x);
      if (y!=1 && y!=-1 && y!=0)
      {
         double z = log10(pow(y,2)-1);
         printf("y(x) = %lf\nz(y) = %lf\n",y, z);
      }
      else
      printf("x value is incorrect!\n");

   }
      else
      printf("x value is incorrect!\n");
   return 0;
}   
