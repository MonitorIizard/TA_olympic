#include <stdio.h>
#include <stdlib.h>

int main () {
    
    int *ptx, *pty;
        
    ptx = (int*) malloc(8);;
    pty = (int*) malloc(8);

    scanf("%d %d", ptx, pty);
    
    printf("%d\n", *ptx + *pty);
    printf("%d\n", *ptx - *pty);
    printf("%d", *ptx * *pty);
    
    return 0;
}