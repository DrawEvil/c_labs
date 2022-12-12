#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill(int n, int m, int a[n][m])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        a[i][j] = rand () % 101 - 50;
    }
}
void print(int n, int m, int a[n][m])
{
    int i, j;
    printf("Матрица: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%4d", a[i][j]);
        printf("\n");
    }
}
int summ(int n,int m, int a[n][m])
{
    int i,j,dia=0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            if(i==j)
                dia+=a[i][j];
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            if(i+1==j)
                dia+=a[i][j];
    }
     for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            if(i-1==j)
                dia+=a[i][j];
    }
    printf("Сумма: = %d\n",dia);
    return dia;
}
void trans(int n,int m,int a[n][m],int r[m][n])
{
   for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        r[j][i]=a[i][j];
        
}
int printtrans(int m,int n,int r[m][n])
{
   for(int i=0;i<m;i++)
   {
      printf("\n");
      for(int j=0;j<n;j++)
      printf("%-3d ",r[i][j]);
   }
      printf("\n "); 
     return 0;
}
void zero(int m,int n,int a[n][m]){
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      while (i == j && i + j == n - 1)
        a[i][j] = 0;
      
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
    int a[n][m];
    int r[n][m];
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
