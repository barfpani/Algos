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
        root -> left = createNode(data);
    }
    else{
        root
    }
}