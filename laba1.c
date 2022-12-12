#include <stdio.h>
double sum(int a, int b){
  int b1=b;
 double n=0;
 double m=0;
    while (a>0){
        n=n+a%10;
        a/=10;
        
    }
    while(b>0){
        
        m=m+b%10;
        b/=10;
    }
    if(n>m)
        return m/b1;    
    else
        return n/b1;
    
    
}     
int main(){
int a;
int b;
scanf("%d", &a);
scanf("%d", &b);
printf("%lf" , sum(a,b));
return 0;

}
