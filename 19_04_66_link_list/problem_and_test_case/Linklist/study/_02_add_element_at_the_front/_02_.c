#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int x;
    struct node* next;
} node;


void deallocation(node** root) {
    node *curr = *root;
    while (curr != NULL)
    {
        node* aux = curr;
        curr = curr -> next;
        free(aux);
    }
    *root = NULL;
}

void insertBeginning (node** root, int value) {
    node* new_node = malloc(sizeof(node));

    new_node -> x = value;
    new_node -> next = *root;

    *root = new_node;
}

int main () {
    //node root; ตอนเเรกเป็นเเเบบนี้เเต่พี่เเกบอกว่ามันจะไม่ dynamic
    node* root = NULL; // root is address    

    insertBeginning(&root, 5);
    insertBeginning(&root, 6);
    insertBeginning(&root, 7);
    for (node* curr = root; curr != NULL; curr = curr->next) {
        //printf("%d ", curr -> x);
        //printf("curr add = %p\n", curr);
        printf("address of %d is %p\n", curr->x, curr);
    }

    deallocation(&root);
    return 0;
}