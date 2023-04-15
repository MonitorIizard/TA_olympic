#include <stdio.h>

int main () {
    int x = 0;
    int *pt = &x;
    scanf("%d", pt);
    *pt = *pt * *pt;
    printf("%d", *pt);
    return 0;
}