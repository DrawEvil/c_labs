#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[100];
    int sum = 0;
    printf("Enter a string: ");
    scanf("%[^\n]s", input);

    char [club38800631|*token] = strtok(input, " ");
    while (token != NULL) {
        if (isdigit([club38800631|*token])) {
            sum += atoi(token);
        }
        token = strtok(NULL, " ");
    }

    printf("Sum of integers in the string: %d\n", sum);
    return 0;
}
