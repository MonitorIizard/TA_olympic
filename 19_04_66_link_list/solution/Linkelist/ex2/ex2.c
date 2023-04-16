#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char x[100];
    struct Node* next; 
} Node;

int findLength(Node **root) {
    Node *curr = *root;
    int length = 0;

    while(curr -> next != NULL) {
        length++;
        curr = curr -> next;
    }
    if (!strcmp((*root) -> x, "")) {
        return length = 0;
    }
    length++;
    //printf("length out from findLength = %d\n", length);
    return length;
}

int cleanIndex(int index, int length) {
    // printf("index_in = %d\n", index);
    // printf("length in = %d\n", length);
     if (index > length) {
            index = length;
    }

    if (index < 0) {
        index = 0;
    }
    // printf("index = %d\n", index);
    return index;
}

void insertBefore(Node** root, char* value, int index) {
    Node* next_node = malloc(sizeof(Node));
    if (next_node == NULL) {
        exit(1);
    }

    Node *curr = *root;
    
    int length = 0;
    length = findLength(&(*root));

    index = cleanIndex(index, length);

    strcpy(next_node -> x, value);

    if (!strcmp((*root) -> x, "")) {
        strcpy((*root) -> x, next_node -> x);
        (*root) -> next = NULL;
        return;
    }

    if (index == 0) {
        next_node -> next = (*root);
        (*root) = next_node;
        //printf("root -> x = %s\n", (*root) -> x);

    } else {
        curr = *root;
        int i = 0;
        while (i < index - 1 && curr != NULL) {
            curr = curr -> next; 
            i++;
        }

        next_node -> next = curr -> next;
        curr -> next = next_node;
        //printf("index = %d cur -> x = %s\n", index, curr -> x);
    }
}

void removeElementSpecificIndex (Node** root, int index) {

    Node *curr = *root;
    Node *toRemove;
    int i = 0;
    int length = 0;
    length = findLength(&(*root));

    index = cleanIndex(index, length);

    //printf("index = %d\n", index);

    if (index == 0) {
        toRemove = curr;
        curr = curr -> next;
        free(toRemove);
    } else {
        while (i <= index) {
            if (i == index - 1) {
                toRemove = curr -> next;
                curr -> next = curr -> next -> next;
                free(toRemove);
                return;
            }
            curr = curr -> next;
            i++; 
        }
    }
}

void printBeforeTarget(Node** root, char* input) {
    Node *curr = *root;
    while (curr -> next != NULL) {
        if (! strcmp(curr -> next -> x, input)) {
            printf("%s\n", curr -> x);
            return;
        }
        curr = curr -> next;
    }
    printf("NO\n");

}

void printTarget(Node** root, char* input) {
    Node *curr = *root;
    while (curr -> next != NULL) {
        if (! strcmp(curr -> x, input)) {
            printf("%s\n", curr -> x);
            return;
        }
        curr = curr -> next;
    }
    if (! strcmp(curr -> x, input)) {
            printf("%s\n", curr -> x);
            return;
    }

    printf("NO\n");
}

void printAfterTarget(Node** root, char* input) {
    Node *curr = *root;
    while (curr -> next != NULL) {
        if (! strcmp(curr -> x, input)) {
            printf("%s\n", curr -> next -> x);
            return;
        }
        curr = curr -> next;
    }
    printf("NO\n");
}

void printAllElement(Node** root) {
    Node* curr = *root;
    //printf("%d", curr -> x);
    while(curr -> next != NULL) {
        printf("%s ", curr -> x);
        curr = curr -> next;
    }
    printf("%s ", curr -> x);
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
    Node* root;
    root = malloc(sizeof(Node));
    if (root == NULL) {
        printf("Invalid allocation");
        exit(1);
    }
    
    int index = 0;
    char input[100];
    char command;
    
    while (command != 'e') {
        scanf("%c", &command);
        if (command == 'i') {
            scanf(" %s %d", input, &index);
            insertBefore(&root, input, index);
        }

        if (command == 'r') {
            scanf(" %d", &index);
            removeElementSpecificIndex(&root, index);
        }

        if (command == 'b') {
            scanf(" %s", input);
            printBeforeTarget(&root, input);
        }

        if (command == 'p') {
            scanf(" %s", input);
            printTarget(&root, input);
        }

        if (command == 'a') {
            scanf(" %s", input);
            printAfterTarget(&root, input);
        }
    }

    
    //printAllElement(&root);
    deAllocation(&root);
    return 0;
}