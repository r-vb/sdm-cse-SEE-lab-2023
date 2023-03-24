/* 12. */
/* To concatenate two singly linked lists. Display the results */

#include <stdio.h>
#include <stdlib.h>

// Define singly linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* create_node(int value) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

// Function to append a node to the end of a linked list
void append(Node** head_ref, int value) {
    Node* new_node = create_node(value);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    Node* current_node = *head_ref;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    current_node->next = new_node;
}

// Function to concatenate two linked lists
void concatenate(Node** list1_ref, Node** list2_ref) {
    if (*list1_ref == NULL) {
        *list1_ref = *list2_ref;
    } else {
        Node* current_node = *list1_ref;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = *list2_ref;
    }
}

// Function to print a linked list
void print_list(Node* head) {
    Node* current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

int main() {
    int choice, value;
    Node* list1 = NULL;
    Node* list2 = NULL;

    while (1) {
        printf("Choose an option:\n");
        printf("1. Create list 1\n");
        printf("2. Create list 2\n");
        printf("3. Concatenate lists\n");
        printf("4. Print concatenated list\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to add to list 1: ");
                scanf("%d", &value);
                append(&list1, value);
                break;
            case 2:
                printf("Enter a value to add to list 2: ");
                scanf("%d", &value);
                append(&list2, value);
                break;
            case 3:
                concatenate(&list1, &list2);
                printf("Lists concatenated.\n");
                break;
            case 4:
                printf("The concatenated list is: ");
                print_list(list1);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}