/* 10. */
/* To create and display an ordered singly linked list. */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Node* insert_node(Node* head, int data) {
    Node* new_node = create_node(data);
    if (head == NULL || data < head->data) {
        new_node->next = head;
        head = new_node;
    } else {
        Node* current_node = head;
        while (current_node->next != NULL && data >= current_node->next->data) {
            current_node = current_node->next;
        }
        new_node->next = current_node->next;
        current_node->next = new_node;
    }
    return head;
}

void display_list(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
    } else {
        printf("The list is: ");
        Node* current_node = head;
        while (current_node != NULL) {
            printf("%d ", current_node->data);
            current_node = current_node->next;
        }
        printf("\n");
    }
}

int main() 
{
    Node* head = NULL;
    int choice = 0;
    int data = 0;

    while (1) {
        printf("1. Insert element\n");
        printf("2. Display list\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                head = insert_node(head, data);
                break;
            case 2:
                display_list(head);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}