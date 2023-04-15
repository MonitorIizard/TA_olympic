#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    char *ms1;
    ms1 = (char*) malloc(50);
    scanf("%s", ms1);

    char *ms2;
    ms2 = (char*) malloc(50);
    scanf("%s", ms2);

    char *ms3;
    ms3 = (char*) malloc(50);
    scanf("%s", ms3);

    char *ms4;
    ms4 = (char*) malloc(50);
    scanf("%s", ms4);

    printf("%s\n",ms1);
    printf("%s\n",ms2);
    printf("%s\n",ms3);
    printf("%s",ms4);
    
    return 0;
}