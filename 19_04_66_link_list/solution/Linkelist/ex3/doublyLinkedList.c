#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int value;
    Node *next;
    Node *previous;
} Node;

Node *head = NULL;
Node *current = NULL; 
Node *last = NULL;

void displayForward () {
    struct Node *ptr = head;

    while (ptr != NULL) {
        printf("%d", ptr -> value);
        ptr = ptr -> next;
    }
}

void displayBackward () {
    struct Node *ptr = last;

    while (ptr != NULL) {
        printf("%d", ptr -> value);
        ptr = ptr -> previous;
    }
}

void insertFirst (int value) {
    Node *link = (Node*) malloc(sizeof(Node));
    link -> value = value;

    if (isEmpty()) {
        last = link;
    } else {
        head -> previous = link;
    }

    link -> next = head;
    head = link;
}

void insertLast (int value) {
    Node *link = (Node*) malloc(sizeof(Node));
    link -> value = value;
    
    if (isEmpty()) {
        last = link;
    } else {
        last -> next = link;
        link -> previous = last;
    }

    last = link;
}

void deleteFirst (int value) {
    Node *templink = last;

    if (head -> next == NULL) {
        head = NULL;
    } 
    
    
}
