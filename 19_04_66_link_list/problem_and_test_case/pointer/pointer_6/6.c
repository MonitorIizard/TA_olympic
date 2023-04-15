#include <stdio.h>
#include <stdlib.h>

int main() {
    float* x = malloc(8);

    scanf("%f", x);

    float* temp_in_cel = malloc(8);
    *temp_in_cel = (*x - 32)/ 1.8;

    printf("%.4g", *temp_in_cel);
    return 0;
}