#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int x;
    struct node* next;
} node;

void insert_end(node** root, int value) {
    node* new_node = malloc(sizeof(node));
    if (new_node == NULL) {
        exit(1); // in case computer is out of memory
    }
    new_node -> next = NULL;
    new_node -> x = value;
    if (*root == NULL) {
        *root = new_node;
        return;
    }
    
    node* curr = *root;
    while (curr->next != NULL) {
        curr = curr -> next;
        printf("x");
    }
    curr -> next = new_node; 
}

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

int main () {
    //node root; ตอนเเรกเป็นเเเบบนี้เเต่พี่เเกบอกว่ามันจะไม่ dynamic
    node* root = NULL; // root is address    

    insert_end(&root, 6);
    insert_end(&root, -5);
    for (node* curr = root; curr != NULL; curr = curr->next) {
        //printf("%d ", curr -> x);
        //printf("curr add = %p\n", curr);
        printf("address of %d is %p\n", curr->x, curr);
    }

    deallocation(&root);
    return 0;
}