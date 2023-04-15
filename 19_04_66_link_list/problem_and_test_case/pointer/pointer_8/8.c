#include <stdio.h>
#include <stdlib.h>

void power (int *a) {
    *a = *a * *a;
}

int main () {
    int x = 0;

    scanf("%d", &x);
    
    power(&x);

    printf("%d", x);
    return 0;
}