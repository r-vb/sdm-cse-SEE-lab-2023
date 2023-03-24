/* 15. */
/* Write a C program to construct a binary search tree and display the following values:
i. Total number of nodes.
ii. Minimum node.
iii. Maximum node. */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* create_node(int data) 
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node* insert(struct node *root, int data) {
    if (root == NULL) {
        root = create_node(data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
return root;
}

int count_nodes(struct node *root) {
    if (root == NULL) {
        return 0;
    }
return 1 + count_nodes(root->left) + count_nodes(root->right);
}

int minimum_node(struct node *root) {
    if (root == NULL) {
        printf("Tree is empty.");
        return -1;
    }
    while (root->left != NULL) {
        root = root->left;
    }
return root->data;
}

int maximum_node(struct node *root) {
    if (root == NULL) {
        printf("Tree is empty.");
        return -1;
    }
    while (root->right != NULL) {
        root = root->right;
    }
return root->data;
}

int main() 
{
    struct node *root = NULL;
    int n, data;

    printf("Enter the number of nodes to insert: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter node data: ");
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("Total number of nodes: %d\n", count_nodes(root));
    printf("Minimum node: %d\n", minimum_node(root));
    printf("Maximum node: %d\n", maximum_node(root));
return 0;
}