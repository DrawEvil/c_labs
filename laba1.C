 #include <stdio.h>
 int gmd(int n)
 {
  int min = -1;
  while(n>0){
     int d =n % 10;
     if(min==-1){
      min = d;
     }
     else if(min>d){
      min = d;
     }
     n/=10;
  }
  return min;
 } 
 int main()
 {
  int a;
  int b;
  printf("Enter a-> ");
  scanf("%d", &a);
  printf("Enter b-> ");
  scanf("%d", &b);
  if(b==0)
  {
    printf("Division 0!");
    return 1;
  }
  int sum=gmd(a)+gmd(b);
  printf("%.4f\n",((float)sum/(float)b));
  return 0;
 }   
