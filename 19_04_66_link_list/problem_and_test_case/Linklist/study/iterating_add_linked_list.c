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
    // printf("new node = %d\n", new_node -> x);
    // printf("root in this function %d\n", (*root) -> x);
    if (*root == NULL) {
        *root = new_node; //from base root is a pointer when it come to this function it a fucting pointer to pointer 
        return;
    }
    
    node* curr = *root;
    while (curr->next != NULL) {
        curr = curr -> next;
        printf("x");
    }
    curr -> next = new_node; //put the pointer to the last block of Null
    // // cause while loop is skip NULL
}

int main () {
    //node root; ตอนเเรกเป็นเเเบบนี้เเต่พี่เเกบอกว่ามันจะไม่ dynamic
    node* root = NULL; // root is address
    // if (root == NULL) {
    //     exit(2);
    // }
    // root -> x = 15;
    // root -> next = NULL;


    // node* curr = root;
    // while (curr != NULL) {
    //     // do sth
    //     printf("%d ", curr -> x);
    //     curr = curr -> next;

    // }
    

    insert_end(&root, 6);
    insert_end(&root, -5);
    for (node* curr = root; curr != NULL; curr = curr->next) {
        //printf("%d ", curr -> x);
        //printf("curr add = %p\n", curr);
        printf("address of %d is %p\n", curr->x, curr);
    }

    return 0;
}