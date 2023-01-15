#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

/*atoi-преобразование строки в целое число*/
static int my_sum(const char *src)
{
int sum = 0;
while (*src) {
while (*src && !isdigit(*src))
++src;
sum += atoi(src);
while (*src && isdigit(*src))
++src;
}

return sum;
}

int main()
{
char string[256];
printf("Enter a string:");
scanf("%s", string);
int something=my_sum(string);
printf("%d\n", something);
}
