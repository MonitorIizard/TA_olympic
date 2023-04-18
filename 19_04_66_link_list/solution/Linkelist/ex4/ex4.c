#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* previous;
} Node;

// this pointer point to first
Node *head = NULL;

// this pointer point to trail
Node *trail = NULL;
Node *current = NULL;

bool isHeadEmpty();
void printAll();
void insertLast(Node **new_node);

bool insert (int data, int idToInsertBefore) {
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        //printf("allocation is invalid\n");
        exit(1);
    }

    new_node -> data = data;

    if (isHeadEmpty()) {
        trail = new_node;
        new_node -> next = head;
        head = new_node;

        //printf("case 1 : head NULL\n");

        printAll();
        return true;
    } 

    Node *curr = head;

    while (curr != NULL) {
        if (curr -> data == data) {
            //printf("Skip\n\n");
            return false;
        }

        curr = curr -> next;
    }

    curr = head;

    while (curr -> data != idToInsertBefore) {
        if (curr -> next == NULL) {
            insertLast(&new_node);

            //printf("case 2 : No Id Insert Last\n");
            printAll();

            return true;
            
        } else {
            curr = curr -> next;
        }
    } 

    

    //printf("curr -> data = %d", curr -> data);
    //printf("\n");

    if (curr -> previous == NULL) {

        head -> previous = new_node;
        new_node -> next = head;
        head = new_node;

        //printf("case 4 : insert before first node (head -> previous) \n");
        printAll();

        return true;

    }
    
    new_node -> next = curr;
    new_node -> previous = curr -> previous;
    curr -> previous -> next = new_node;
    curr -> previous = new_node;

    //printf("case 3 : previous normal case\n");
    //printf("current previous -> data %d\n" ,curr -> previous -> data);
    printAll();

    return true;

}

bool isHeadEmpty() {
    return head == NULL;
}

void insertLast(Node **new_node) {

    if (isHeadEmpty()) {
        trail = *new_node;

    } else {
        trail -> next = *new_node;

        (*new_node) -> previous = trail;
    }

    trail = *new_node;
}

void removeData(int data) {
    
    if (head == NULL) {
        return;
    }

    Node *curr = head;

    if (curr -> next == NULL || head == NULL) {
            //printf("remove case 1 : nothing to delete\n");
            return;
    }

    while (curr -> data != data)
    {
        if (curr -> next == NULL) {
            //printf("remove case 1 : nothing to delete\n");
            return;
        } else {
            curr = curr -> next;
        }
    }

    
    Node *toRemove = curr;

    if (curr == trail) {
        trail -> previous -> next = NULL;
        trail = trail -> previous;

        //printf("remove case 1 : trail delete\n");

    } else if (curr == head) {
        head = head -> next;
        head -> previous = NULL;
        //printf("remove case 2 : head delete head = %d\n", head -> data);

    } else {
        curr -> previous -> next = curr -> next;
        curr -> next -> previous = curr -> previous;
        //printf("remove case 3 : normal case\n");
    }

    free(toRemove);
    printAll();
    return;
}

void deAllocation(){
    Node *curr = head;

    while (curr != NULL) {
        Node *toRemove = curr;
        curr = curr -> next;
        free(toRemove);
    }
}

void printAll() {
    Node *curr = head;
    // printf("linked list : ");
    while (curr != NULL) {
        if (curr -> next == NULL) {
            printf("%d\n", curr -> data);
            return;
        }
        printf("%d ", curr -> data);

        curr = curr -> next;

        
    }
}

void printReverse() {
    Node *curr = trail;

    printf("Linked list in reverse : ");

    while (curr != NULL) {

        if (curr -> previous == NULL) {
            printf("%d\n\n", curr -> data);
            return;
        }

        printf("%d->", curr -> data);

        curr = curr -> previous;
    }
}

int main () {
    
    char command;
    int data, idToInsertBefore;

    while (command != 'E') {

        scanf("%c", &command);

        if (command == 'I') {
            scanf(" %d %d", &data, &idToInsertBefore);
            insert(data, idToInsertBefore);
        }

        if (command == 'D') {
            scanf(" %d", &data);
            removeData(data);
        }

        if (command == '-') {
            printReverse();
        }
    }

    deAllocation();
    //printAll();
    return 0;
}