#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int x;
    struct Node* next;
} Node;

void insertAfter(Node** root ,int value, int index) {
    Node* next_node = malloc(sizeof(Node));
    if (next_node == NULL) {
        exit(1);
    }
    
    int i = 0;
    
    next_node -> x = value;

    if ((*root) == NULL) {    
        next_node -> next = NULL;
        *root = next_node;
        //printf("root -> value = %d",(*root) -> x);
        return;
    }

    if (index == 0) {
        next_node -> next = *root;
        *root = next_node;
    } else {
        Node* curr = *root;
        
        while(i < index - 1 && curr != NULL) {
            curr = curr -> next;
            i++;
        }

        next_node -> next = curr -> next;    
        curr -> next = next_node;
    }
    
 }

void move(Node** root, int* index, int distance) {
    Node* curr = *root;
    int i = 1;
    while (curr -> next != NULL) {
        curr = curr -> next;
        i++;
    }
    if (i < distance) {
        *index = i;
        return;
    }

    if (*index + distance < 0 ) {
        *index = 0;
        return;
    }

    *(index) += distance;    
}

void removeElement(Node** root, int index) {
    if (*root == NULL) {
        return; // cant remove anything from empty list
    }

    int i = 0;

    if (i == index) {
        Node* to_remove = *root;
        *root = (*root) -> next;
        free(to_remove);
        return;
    }

    for (Node* curr = *root; curr -> next != NULL; curr = curr -> next) {
        if (i == index - 1) {
            Node* toRemove = curr -> next;
            curr -> next = curr -> next -> next;
            free(toRemove);
            return;
        }
        i++;
    }
}

void printAllElement(Node** root) {
    Node* curr = *root;
    
    while(curr -> next != NULL) {
        printf("%d\n", curr -> x);
        curr = curr -> next;
    }
}

void deAllocation(Node** root) { 
        Node* curr = *root;
    while(curr -> next != NULL) {
        Node* temp = curr;
        curr = curr -> next;
        free(temp);
    }
}

int main () {
    Node* root = malloc(sizeof(Node));

    int index = 0;
    int round = 0;

    scanf("%d", &round);

    for (int i = 0; i < round ; i++) {
        int command = 1;
        int value = 3;
        scanf("%d", &command);

        if (command == 0) {
            scanf(" %d", &value);
            insertAfter(&root, value, index);
        }
         
        if (command == 1) {
            scanf(" %d", &value);
            move(&root, &index, value);
        }
       
        if (command == 2) {
            removeElement(&root, index);
        }
    }
    printAllElement(&root);

    deAllocation(&root);
    return 0;
}