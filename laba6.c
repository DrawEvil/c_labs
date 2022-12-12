#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void fill(int n, int a[])
{
    int i;
    for (i = 0; i < n; i++)
        a[i] = rand() % 101 - 50;
}

void print(int n, int a[])
{
    int i;
    for (i = 0; i < n; i++)
        printf("%4d", a[i]);
    printf("\n");
}

int search(int n, int a[], int v)
{
    int i;
    for (i = 0; i < n; i++)
        if (a[i] == v)
            return i;
    return -1;
}

void reverse(int n, int a[])
{
    int li, ri, sw;
    for (li = 0, ri = n - 1; li < ri; li++, ri--)
    {
        sw = a[li];
        a[li] = a[ri];
        a[ri] = sw;
    }
}
void reverse2(int n, int a[],int r)
{
    int li, ri, sw;
    for (li = n+1, ri = r - 1; li < ri; li++, ri--)
    {
        sw = a[li];
        a[li] = a[ri];
        a[ri] = sw;
    }
}


int main()
{
    srand(time(NULL));
    int arr, size, value, index;
    printf("array size -> ");
    scanf("%d", &size);
    int A[size];
    fill(size, A);
    printf("source array: ");
    print(size, A);
    printf("\nvalue to search -> ");
    scanf("%d", &value);
    index = search(size,A,value);
    if(index!=-1)
    {
        printf("after revese: ");
        reverse(index,A);
        reverse2(index,A,size);
    }
    else
    {
        printf("after revese: ");
        reverse(size,A);
    }
    print(size,A);
    return 0;
}
