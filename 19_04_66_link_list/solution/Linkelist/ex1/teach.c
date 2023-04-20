#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

Node *temp = NULL;
Node *curr = NULL;

void printAll();

void insert(int data, int* index) {
    printf("curr index = %d\n", *index);
    temp = malloc(sizeof(Node));
    temp -> data = data;

    if (head == NULL) {
        head = temp;
        head -> next = NULL;
        printf("case1\n");
        return;
    }

    Node *loop = head;
    int i = 0;
    if (*index < 0) {
        *index = 0;
        printf("case 500\n");
    }
    while (i != *index - 1) {
        if (loop -> next == NULL) {
            break;
        }
        else { 
            loop = loop -> next;
            i++;
        }   
    }
    if (*index > i) {
         *index = i;
         printf("case 600\n");
    }
    
    printf("case2\n");
    printf("index out = %d\n", *index);

    if (*index == 0) {
        temp -> next = head;
        head = temp;
        return;
    } 
    //printf("%d\n", loop -> data);
    temp -> next = loop;
    loop  = temp;
}

void move(int* index, int distance) {
    *index = *index + distance;
}   

void printAll () {
    temp = head;
    printf("linked link : ");
    while (temp != NULL) {
        if (temp -> next == NULL) {
            printf("%d\n\n", temp ->data);
            return;
        }

        printf("%d->", temp -> data);
        temp = temp -> next;
    }
}

int main () {
    int index = 0;
    int size = 0;   
    scanf("%d", &size);
    int i = 0;
    int data = 0;
    int distance = 0;
    int c;

    while (i < size) {
        
        scanf("%d", &c);

        if (c == 0) {
            scanf(" %d", &data);
            insert(data, &index);
            printAll();

        }

        if (c == 1) {
            scanf(" %d", &distance);
            printf("%d index int0 move\n", distance);
            move(&index, distance);
            printf("%d index in move\n", index);
            printAll();
        }

        i++;
    }
    printAll();
    return 0;
}