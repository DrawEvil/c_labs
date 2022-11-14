#include <stdio.h>
unsigned int NODw(unsigned int a,unsigned int b)
{
  while(a && b)
      if(a>b) a%=b;
      else b%=a;
  return a+b;

}
unsigned int NODr( unsigned int a , unsigned int b)
{
    return b ? NODr (b, a % b) : a;
}
int main()
{
    int a,b;
    scanf("%d%d", &a, &b);
    printf("Cycle: = %d\n ", NODw(a,b));
    printf("Recursion: = %d\n", NODr(a,b));

    return 0;

}
