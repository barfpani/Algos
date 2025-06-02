#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
}Node;

Node* createNode(int data){
    Node* newNode = malloc(sizeof(Node));
    if(!newNode){
        printf("Memory Allocation Failed");
        return 0;
    }
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
}

Node* insert(Node* root, int data){
    if(root == NULL){
        return createNode(data);
    }

    if(data < root -> data){
        root -> left = insert(root, data);
    }
    else{
        root -> right = insert(root, data);
    }
    return root;
}

void inorder_traversal(Node* root){
    if(root == NULL){
        return;
    }
    inorder_traversal(root -> left);
    printf("%d ", root -> data);
    inorder_traversal(root -> right);
}

void preorder_traversal(Node* root){
    if(root == NULL){
        return;
    }
    printf("%d ", root -> data);
    preorder_traversal(root -> left);
    preorder_traversal(root -> right);
}

void postorder_traversal(Node* root){
    if(root == NULL){
        return;
    }
    postorder_traversal(root -> left);
    postorder_traversal(root -> right);
    printf("%d ",root -> data);
}

