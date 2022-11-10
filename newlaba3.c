#include <stdio.h>
#include <math.h>
int main()
{
  double x,s,h,f;
  x=0;
  printf("Введите шаг h\n");
  scanf("%lf", &h);
  s = 2.00/h;
  if(h >= -1.00 && h <= 2.00)
  {
   printf("\tx\tf(x)\n");
   printf("------------------\n");
   for( int i=0; i<=s; i++)
   {
       x=i*h;
    if(x>=-1 && x<=1)
        f = exp(-2.0*sin(x));
    else
        f = x*x-(1/(tan(x)));
     printf("%lf\t%lf\n", x ,f);

   }
  }
  else
  {
   printf("inccorect h");
  }
  return 0;
  

}
