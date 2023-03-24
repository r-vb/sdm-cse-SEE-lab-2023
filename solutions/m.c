/* 13. */
/* Write a C program to implement the following on doubly linked list:
i. Insert at the front end of the list.
ii. Insert an element at the rear end of the list
iii. Insert an element after key element of the list.
iv. Insert an element before key element of the list.
v. Delete at the front end of the list.
vi. Delete at the rear end of the list.
vii. Display the elements of the list. */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

// Function to create a new node
struct node* create_node(int data) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the front of the list
void insert_front(int data) {
    struct node *new_node = create_node(data);
    if (head == NULL) {
        head = new_node;
    } else {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
}

// Function to insert a node at the rear of the list
void insert_rear(int data) {
    struct node *new_node = create_node(data);
    if (head == NULL) {
        head = new_node;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
}

// Function to insert a node after a key element
void insert_after(int key, int data) {
    struct node *new_node = create_node(data);
    struct node *temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element not found in the list.\n");
    } else {
        new_node->prev = temp;
        new_node->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = new_node;
        }
        temp->next = new_node;
    }
}

// Function to insert a node before a key element
void insert_before(int key, int data) {
    struct node *new_node = create_node(data);
    struct node *temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element not found in the list.\n");
    } else {
        new_node->next = temp;
        new_node->prev = temp->prev;
        if (temp->prev != NULL) {
            temp->prev->next = new_node;
        } else {
            head = new_node;
        }
        temp->prev = new_node;
    }
}

// Function to delete a node at the front of the list
void delete_front() {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        struct node *temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
    }
}

// Function to delete a node at the rear of the list
void delete_rear() {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        if (temp == head) {
            head = NULL;
        } else {
            temp->prev->next = NULL;
        }
        free(temp);
    }
}

// Function to display the elements of the list
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        struct node *temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    printf("\n");
    }
}

int main() {
    int choice, data, key;
    while (1) {
        printf("1. Insert at front\n");
        printf("2. Insert at rear\n");
        printf("3. Insert after key\n");
        printf("4. Insert before key\n");
        printf("5. Delete at front\n");
        printf("6. Delete at rear\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insert_front(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insert_rear(data);
                break;
            case 3:
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter data: ");
                scanf("%d", &data);
                insert_after(key, data);
                break;
            case 4:
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter data: ");
                scanf("%d", &data);
                insert_before(key, data);
                break;
            case 5:
                delete_front();
                break;
            case 6:
                delete_rear();
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exiting...");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
