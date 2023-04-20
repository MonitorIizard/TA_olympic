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
    if (*root == NULL) {
        return length;
    }

    while(curr -> next != NULL) {
        length++;
        curr = curr -> next;
    }
    if (curr == NULL) {
        return length = 0;
    }
    length++;
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
    //printf("index = %d\n", index);
    return index;
}

void insertBefore(Node** root, char* value, int index) {
    Node* next_node = malloc(sizeof(Node));
    if (next_node == NULL) {
        exit(1);
    }

    strcpy(next_node -> x, value);
    next_node -> next = NULL;

    int length = 0;
    length = findLength(&(*root));

    if (index > length) {
        return;
    }

    if (index < 0) {
        return;
    }

    Node *curr = *root;

    if (*root == NULL) {
        *root = next_node;
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
    if (*root == NULL) {
        return;
    }
    Node *toRemove;
    int i = 0;
    int length = 0;
    length = findLength(&(*root));

    //printf("index = %d\n", index);
    if (index < 0 || index >= length || length == 1) {
        return;
    }

    //printf("%d", length);

    if (index == 0) {
        toRemove = *root;
        *root = (*root) -> next;
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
    if (*root == NULL) {
        printf("NO\n");
        return;
    }
    
    if (! strcmp((*root) -> x, input)) {
        
        printf("NO\n");
        return;
    }

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
    if (*root == NULL) {
        printf("NO\n");
        return;
    }

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
    if (*root == NULL) {
        printf("NO\n");
        return;
    }
    
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

    if ((*root) == NULL) {
        return;
    }
    //printf("%d", curr -> x);
    while(curr -> next != NULL) {
        printf("_%s -> ", curr -> x);
        curr = curr -> next;
    }
    printf("%s_\n", curr -> x);
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
    Node* root = NULL;
    // if (root == NULL) {
    //     printf("Invalid allocation");
    //     exit(1);
    // }
    
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

        if (command == 'f') {
            printAllElement(&root);
        }

        if (command == 'a') {
            scanf(" %s", input);
            printAfterTarget(&root, input);
        }

        if (command == 'l') {
            int length = findLength(&root);
            printf("length = %d\n", length);
        }
    }

    //printAllElement(&root);
    deAllocation(&root);
    return 0;
}
