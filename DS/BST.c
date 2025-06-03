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

//left , root , right

void inorder_traversal(Node* root){
    if(root == NULL){
        return;
    }
    inorder_traversal(root -> left);
    printf("%d ", root -> data);
    inorder_traversal(root -> right);
}

// root , left , right

void preorder_traversal(Node* root){
    if(root == NULL){
        return;
    }
    printf("%d ", root -> data);
    preorder_traversal(root -> left);
    preorder_traversal(root -> right);
}

// left , right , root

void postorder_traversal(Node* root){
    if(root == NULL){
        return;
    }
    postorder_traversal(root -> left);
    postorder_traversal(root -> right);
    printf("%d ",root -> data);
}

int searh (Node* root, int key){
    if(root == NULL){
        return;
    }
    if (root -> data == key){
        return 1;
    }
    if(key < root -> data){
        return(root -> left, key);
    }
    return(root -> right, key);
}

void freetree(Node* root){
    if(root == NULL){
        return;    
    }
    
    freetree(root -> left);
    freetree(root -> right);
    freetree(root);
}

int main(){
    
    Node* root = NULL;

    root = insert(root, 52);
    root = insert(root, 85);
    root = insert(root, 24);
    root = insert(root, 45);
    root = insert(root, 69);
    root = insert(root, 96);
    root = insert(root, 11);
    root = insert(root, 36);
    root = insert(root, 46);
    root = insert(root, 78);

    printf("In-Order Traversal: ");
    inorder_traversal(root);
    printf("\n");

    printf("Pre-Order Traversal: ");
    preorder_traversal(root);
    printf("\n");

    pritnf("Post-Order Traversal: ");
    postorder_traversal(root);
    printf("\n");

    int key = 96;

    if(search(root, key)){
        printf("Eleme was found in the list.\n");
    }
    else{
        printf("Element not found.\n");
    }

}   


