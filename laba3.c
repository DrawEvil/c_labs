#include <stdio.h>
#include <math.h>
#include <string.h>

    int main()
    {
       double x,z;
       printf("Enter{-1.0 <= x <= 1.0}");
       printf(" or {1.0 < x <= 2.0}-> ");
       scanf("%lf", &x);
       if(-1.0<=x && x<=1.0)
       {  printf("%5s %10s\n","x","f(x)");
          printf("------------------\n");
         for(double i=-1.0,y;i<=x; i+=0.1 , y)
          {
            double y = exp(-2.0*sin(i));
            printf("%-10f%-10f\n", i , y);
           
          }
       }
         else
         
          if (1.0 < x && x <= 2.0)
          {
            printf("%5s %10s\n","x","f(x)");
            printf("------------------\n");
            for(double i= 1.0,y;i<=x; i+=0.1 , z)
            {
             double z = i*i-(1/(tan(i)));
             printf("%-10f%-10f\n", i , z);
           }
         }
           else
           printf("x value is incorrect!\n");
           return 0; 
     }
