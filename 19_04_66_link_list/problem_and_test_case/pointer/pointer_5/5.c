#include <stdio.h>
#include <stdlib.h>

int main () {
    int *x = malloc(8);
    int *y = malloc(8);
    char *str = malloc(9);

    scanf("%s", str);
    scanf("%d", x);
    scanf("%d", y);
     
    int sum = *x + *y;

    

    printf("%s has money %d bath",str, sum);
    return 0;
}