#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

    int main()
    {
       double x;
       printf("Enter{-1.0 <= x <= 1.0}");
       printf(" or {1.0 < x <= 2.0}-> ");
       scanf("%lf", &x);
       if(-1.0<=x && x<=1.0)
       {  printf("%5s %10s\n","x","f(x)");
          printf("------------------\n");
         while ( -1.0 <= x && x <=1.0 )
         {
            double y = exp(-2.0*sin(x));
            printf("%-10f%-10f\n", x , y);
            x+=0.1;
         }
        }   
         else
           if (1.0 < x && x <= 2.0)
            {
             printf("%5s %10s\n","x","f(x)");
             printf("------------------\n");
             while(1.0 < x && x <= 2.0)
              {
                double z = x*x-(1/(tan(x)));
                printf("%-10f%-10f\n", x , z);
                x+=0.1;
              }
           }
             else
             printf("x value is incorrect!\n");
             return 0; 
    }
