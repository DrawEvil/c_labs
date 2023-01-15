#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill(int n, int m, int a)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        a[im+j] = rand () % 101 - 50;
    }
}
void print(int n, int m, int a)
{
    int i, j;
    printf("Матрица: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%4d", a[im+j]);
        printf("\n");
    }
}
int summ(int n,int m, int a)
{
    int i,j,dia=0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            if(i==j)
                dia+=a[im+j];
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            if(i+1==j)
                dia+=a[im+j];
    }
     for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            if(i-1==j)
                dia+=a[im+j];
    }
    printf("Сумма: = %d\n",dia);
    return dia;
}
void trans(int n,int m,int a,intr)
{
   for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        r[jm+i]=a[im+j];

}
int printtrans(int m,int n,int r)
{
   for(int i=0;i<m;i++)
   {
      printf("\n");
      for(int j=0;j<n;j++)
      printf("%-3d ",r[im+j]);
   }
      printf("\n "); 
     return 0;
}
void zero(int n,int m,int a){
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
        if(i!=j && i+1!=j && i != j+1) 
        {
            a[im+j]=0; 
        }
    }
  }

}
int main()
{
    srand(time(NULL));
    int n,m,P,y;
    printf("Задайте значение: \n");
    scanf("%d",&n);
    scanf("%d",&m);
    int a=(int)malloc(nsizeof(int));;
    intr=(int )malloc(nsizeof(int));;
    fill(n,m,a);
    print(n,m,a);
    y=summ(n,m,a);
    printf("\nВвидите чилсо-> ");
    scanf("%d",&P);
    if(y>P)
    {
      printf("Транспонированая матрица: \n");
      trans(n,m,a,r);
     printtrans(m,n,r);

    }
    else
      zero(n,m,a);
      print(n,m,a);
   return 0;
}
