#include <stdio.h>
#include <stdlib.h>

void print(char *character, char *str, int *number, float *decimal) {
    printf("%c\n", *character);
    printf("%s\n", str);
    printf("%d\n", *number);
    printf("%g", *decimal);
}

int main () {
    char character = 'x';
    scanf("%c", &character);

    char sentence[100];
    scanf("%s", sentence);

    int num1;
    scanf("%d", &num1);

    float num2;
    scanf("%f", &num2);

    print(&character, sentence, &num1, &num2);
    return 0;
}