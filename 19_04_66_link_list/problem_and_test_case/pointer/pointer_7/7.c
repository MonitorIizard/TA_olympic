#include <stdio.h>
#include <stdlib.h>

int main () {
    float* x = malloc(8);
    scanf("%f", x);

    float* area = malloc(8);
    *area = 3.14 * *x * *x;

    float* cir = malloc(8);
    *cir = 3.14 * 2 * *x;

    printf("%.4g\n", *cir);
    printf("%.4g", *area);
    
    return 0;
}