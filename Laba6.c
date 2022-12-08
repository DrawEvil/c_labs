define _CRT_SECURE_NO_WARNINGS
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


int main()
{
    srand((unsigned)time(NULL));
    int* arr, size, value, index;

    printf("array size -> ");
    scanf("%d", &size);
    
    arr = (int*)malloc(size * sizeof(int));
    fill(size, arr);
    printf("source array: ");
    print(size, arr);

    printf("\nvalue to search -> ");
    scanf("%d", &value);
    index = search(size, arr, value);

    if (index != -1)
    {
        printf("\nindex of value: %d\n", index);
        reverse(index, arr);
        reverse(size - 1 - index, arr + 1 + index);
    }
    else
    {
        printf("\nvalue not found\n");
        reverse(size, arr);
    }

    printf("after reverse: ");
    print(size, arr);

    free(arr);
    return 0;
}
