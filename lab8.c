
#include <ctype.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <stdio_ext.h>

int mygetch()
{
  struct termios oldt, newt;
  int c;
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  c = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  return c;
}

int main()
{
    printf("Numbers: ");
    unsigned char a;
    while(1)
    {
        a = mygetch();
        if ((iscntrl(a) == 1) && (a != 8)) continue; //игнор функ клав кроме BACKSPACE
        else if (a == 8) break; //остановка программы BACKSPACEом
        else if (isdigit(a))
        {
            a++;
            if (a == 58) a -=10; //9 -> 0
            printf("%c", a);
        }
    }
return 0;
}
