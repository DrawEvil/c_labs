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
    printf("Starting matrix: \n");
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
    printf("%d",dia);
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
   for(int i=0;i<m;i++)//Печатаем транспонированный массив
   {
      printf("\n");
      for(int j=0;j<n;j++)
      printf("%-3d ",r[i][j]);
   }
      printf("\n"); 
     return 0;
}
int main()
{
    srand(time(NULL));
    int n,m,P;
    printf("Задайте значение: ");
    scanf("%d",&n);
    scanf("%d",&m);
    int a[n][m];
    int r[n][m];
    fill(n,m,a);
    print(n,m,a);
    summ(n,m,a);
    printf("Ввидите чилсо-> ");
    scanf("%d",&P);
    if(summ(n,m,a)>P){
       trans(n,m,a,r);
    printtrans(m,n,r); 
    }
    else
    
    return 0;
}
