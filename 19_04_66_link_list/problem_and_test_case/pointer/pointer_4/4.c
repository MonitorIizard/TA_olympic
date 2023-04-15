#include <stdio.h>
#include <stdlib.h>

int main() {

    int *x = malloc(8);
    int *y = malloc(8);
    int *z = malloc(8);
    
    scanf("%d", x);
    scanf("%d", y);
    scanf("%d", z);

    float mean = (*x + *y + *z) / 3.0 ; 
    printf("%.4g", mean);
    return 0;
}