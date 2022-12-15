#include <stdio.h>
#include <string.h>

void revStr(char str)
{
    int wordStart = 0, wordEnd = 0;
    char buf;
    for(int i = 0; i < strlen(str); i++)
    {

        wordEnd = i - 1;
        while(wordStart < wordEnd)
        {
            buf = str[wordStart];
            str[wordStart] = str[wordEnd];
            str[wordEnd] = buf;
            wordStart++;
            wordEnd--;
        }
        wordStart = i + 1;


    }
}

int main()
{
    char str[1000];

    fgets(str, 1000, stdin);


    char delim[] = ", ";
    char *p = strtok(str, delim);
    revstr(p);
    printf(p);


    while ((p = strtok(NULL, delim)))
        printf("%s\n", p);
    printf("\n");
    return 0;





 

    char delim[] = ", ";
    char *p = strtok(inpstr, delim);
    printf(p);
    // while ((p = strtok(NULL, delim)))
    // {



    // }



    printf("\n");
    return 0;


}
