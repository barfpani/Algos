#include <stdio.h>
#include <stdlib.h>

// Basic structer implementation for our "Binary Search Tree"
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST
Node* insert(Node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to search for a value in the BST
int search(Node *root, int key) {
    if (root == NULL) {
        return 0; // Key not found
    }
    if (key == root->data) {
        return 1; // Key found
    } else if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// Function for in-order traversal of the BST
void inOrderTraversal(Node *root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Free the BST
void freeTree(Node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    Node *root = NULL;

    // Insert elements into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    // Print the in-order traversal (sorted order)
    printf("In-order Traversal: ");
    inOrderTraversal(root);
    printf("\n");

    // Search for values
    int key = 40;
    if (search(root, key)) {
        printf("Key %d found in BST.\n", key);
    } else {
        printf("Key %d not found in BST.\n", key);
    }

    key = 25;
    if (search(root, key)) {
        printf("Key %d found in BST.\n", key);
    } else {
        printf("Key %d not found in BST.\n", key);
    }

    // Free allocated memory
    freeTree(root);

    return 0;
}
