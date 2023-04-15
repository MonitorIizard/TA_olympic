#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int x;
    struct Node* next_node;
} Node;

// next_node = [int x, str Node next_node]
void insert(Node** root, int value) {
    Node* temp = malloc(sizeof(Node));
    if (temp == NULL) {
        exit(1);
    }
    temp -> x = value;
    temp -> next_node = NULL;

    if (*root == NULL) {
        *root = temp;
        return;
    }

    Node* curr = *root;
    while (curr -> next_node != NULL) {
        curr = curr -> next_node; 
    }
    curr -> next_node = temp;
}



int main () {
    Node* root = malloc(sizeof(Node));
    root -> x = 5;
    root -> next_node = NULL;

    insert(&root, 5);

    Node* curr = root;
    while (curr -> next_node != NULL) {
        printf("%d\n", curr->x);
        curr = curr -> next_node;
    }

    return 0;
}