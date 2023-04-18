#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int id;
    struct Node *next;
} Node;

void print_all_element(Node** root) {
    Node* curr = *root;
    if (root == NULL) {
        return;
    }

    while (curr != NULL) {
        if (curr -> next != NULL) {
            printf("%d ", curr -> id);
            curr = curr -> next;
        } else {
            printf("%d\n", curr -> id);
            curr = curr -> next;
        }
        
    }
}

int findLength(Node** root) {
    Node* curr = *root;
    int length = 0;
    if (*root == NULL) {
        return length;
    }

    while (curr -> next != NULL) {
        length++;
        curr = curr -> next;
    }
    if (curr -> next == NULL) {
        length++;
    }
    return length;
}

void insert(Node** root, int id, int id_to_insert) {
    Node* new_node = malloc(sizeof(Node));
    Node* curr = *root;
    
    new_node -> id = id;

    if (*root == NULL) {
        new_node -> next = NULL;
        *root = new_node;
        print_all_element(*(&root));
        return;
    }

    while (curr -> next != NULL) {
        if (curr -> id == id) {
            //printf("c1\n");
            return;
        }

        curr = curr ->next;

        if (curr -> next == NULL && curr -> id == id) {
            //printf("c2\n");
            return;
        } 
    }

    curr = *root;
    while (curr -> next != NULL)
    {
        //case it only have id 

        if (curr -> id == id_to_insert) {
            new_node -> next = curr -> next;
            curr -> next = new_node;
            //printf("c3\n");
            print_all_element(*(&root));
            return;
        }
        curr = curr -> next;
    }
    // last
    if (curr -> next == NULL && curr -> id == id_to_insert) {
        //printf("this last index case ");
        new_node -> next = NULL;
        curr -> next = new_node;
        //printf("c4\n");
        print_all_element(*(&root));
        return;
    }

    //insert_first : case no id_to_insert
    new_node -> next = *root;
    *root = new_node;
    //printf("c5\n");
    print_all_element(*(&root));
}

void remove_from_id(Node **root, int id_to_delete) {
    Node* curr = *root;
    if (curr == NULL) {
        return;
    }

    //printf("id to delete = %d\n", id_to_delete);

    // only one node case
    if (curr -> next == NULL) {
        //printf("wtf\n");
        return;   
    }

    //first node delete
    if ((*root) -> id == id_to_delete) {
        Node* to_remove = *root;
        *root  =  (*root) -> next;
        free(to_remove);
        print_all_element(&(*root));
        //printf("case root\n");
        return;
    }

    while (curr -> next != NULL)
    {
        if (curr -> next -> next == NULL && curr -> next -> id == id_to_delete) {
            Node* to_remove = curr -> next;
            curr -> next = NULL;
            free(to_remove);
            print_all_element(&(*root));
            //printf("\ncase target is a last index\n");
            return; 
        }

        if (curr -> next -> id == id_to_delete) {
            Node* to_remove = curr -> next;
            curr -> next  =  curr -> next -> next;
            free(to_remove);
            print_all_element(&(*root));
            //printf("\ncurr_ id = %d normal case_ \n", to_remove -> id);
            return;
        }

        curr = curr -> next;
    }

    
    //printf("NONe\n");
}

void de_allocation(Node** root) {
    Node *curr = *root;
    if (curr == NULL) {
        return;
    }

    Node* to_free = curr;

    while (curr -> next != NULL)
    {
        to_free = curr;
        curr = curr -> next;
        free(to_free);
    }
        to_free = curr;
        curr = curr -> next;
        free(to_free);
}

int main () {
    Node* root = NULL;
    
    char command;
    int id, id_to_insert, id_to_delete;
    while (command != '3') {
        scanf("%c", &command);
        if (command == '1') {
            scanf(" %d %d", &id, &id_to_insert);
            insert(&root, id, id_to_insert);
        }

        if (command == '0') {
            scanf(" %d", &id_to_delete);
            remove_from_id(&root, id_to_delete);
        }

    }
    de_allocation(&root);
    return 0;
}