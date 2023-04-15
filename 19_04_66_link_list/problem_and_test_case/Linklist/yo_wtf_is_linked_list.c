#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int x;
    struct node* next;
} node;

// void insert_end(node** root, int value) {
//     node* new_node = malloc(sizeof(node));
//     if (new_node == NULL) {
//         exit(1);
//     }
//     new_node -> x = value;

//     node* curr = &root;
//     while (curr != NULL) {
//         curr = curr -> next;

//     }
//     curr -> next = new_node;
// }

int main () {
    node root, elem2;
    root.x = 15;
    // root.next = &elem2; or
    root.next = NULL;

    // elem2.x = -2;
    // elem2.next = NULL;

    // printf("first element = %d\n", root.x);
    // printf("second element = %d\n", root.next -> x);
    // printf("second element = %d\n", root.next -> next);

    node* curr = &root;
    while (curr != NULL) {
        // do sth
        printf("%d ", curr -> x);
        curr = curr -> next;

    }

    for (node* curr = &root; curr != NULL; curr = curr->next) {
        printf("%d ", curr -> x);
    }

    free(root.next -> next);
    free(root.next);
    return 0;
}