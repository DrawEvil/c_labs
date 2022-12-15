#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <ctype.h>
#include <math.h>
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
    char input = mygetch(), avg = input;
    int i = 0, summ = 0;

    // while(1)
    // {

    
    //     printf("Summ symbol: %c, code: %d\n\n", input, (int)input);
    //     input = mygetch();
    //     //fflush(stdin);
    //     __fpurge(stdin);  

    //     printf("Summ symbol: %c, code: %d\n\n", input, (int)input);
    //     input = mygetch();
    //     __fpurge(stdin);      

    //     printf("Summ symbol: %c, code: %d\n\n", input, (int)input);
    //     input = mygetch();
    //     __fpurge(stdin); 

    //     printf("Summ symbol: %c, code: %d\n\n", input, (int)input);
    //     input = mygetch();
    //     __fpurge(stdin); 

    // }

    while(1)
    {

        if(input == 27) //Functional key
        {
            input = mygetch();
            input = mygetch();
            if(input == 80)
            {
                system("clear");
                printf("F1 was pressed!\n");
                break;
            }
            __fpurge(stdin);

        }
        else
        {   
            i++;
            summ += input;

            //printf("Summ symbol: %c, code: %d\n\n", avg, (int)avg);

            avg = (char)round((double)summ / (double)(i));
            system("clear");
            
            // printf("symbol: %c\n", input);
            // printf("Summ: %d\n", summ);
            // printf("Delenie: %lf\n", (double)summ / (double)(i));

            printf("%c\n", avg);
        }
        input = mygetch();
        
    }

    //getchar();
    return 0;
}
