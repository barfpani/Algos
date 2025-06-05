#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
}Node;

Node* createNode(int data){                                     // Similar "createNode" function using "malloc"
    Node* newNode = malloc(sizeof(Node));                       // just like is linked list implementation.
    if(!newNode){                                               // But instead of "next" we have "left" & "right"
        printf("Memory Allocation Failed");
        return 0;
    }
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}


Node* insert(Node* root, int data){
    if(root == NULL){                                           //   | We have used "recusive function" to insert element in a tree,
        return createNode(data);                                //   | the logic for insertion is, first reach the node which doesn't
    }                                                           //   | have childern, then then insert the new node to it's "left" or 
    if(data < root -> data){                                    //   | "right" based on the case. Working -> imagine a call stack of same 
        root -> left = insert(root -> left, data);              // <-| fucntions which will return differnt outputs, but there execution will 
    }                                                           //   | be in stack order. Ex: If the tree is like 45 -> 23(L), 55(R) 23 -> 12(L), 30(R)
    else{                                                       //   | 12  -> NULL(L), 26(R). and now if we insert "11", then it will validate the
        root -> right = insert(root -> right, data);            //   | first "if" condition and keeps on going to the left side of the until "root == NULL"
    }                                                           //   | when this condition is true? it will create and place a newNode at that NULL position.
    return root;
}

//left , root , right

void inorder_traversal(Node* root){                             //   |"Recursive Funtion" is again used here, the understanding of a call stack is important here
    if(root == NULL){                                           //   | 
        return;                                                 //   |      The Explainantio of this traversal function is in my handwritten notes,
    }                                                           // <-|      as it includes step by step diagrams for better under stading, for a 
    inorder_traversal(root -> left);                            //   |      a  basic idea? it's like a nested loop, or a good analogy, you're always 
    printf("%d ", root -> data);                                //   |      in a bigger loop.
    inorder_traversal(root -> right);                           //   | 
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

int search(Node* root, int key){
    if(root == NULL){
        return 0;
    }
    if (root -> data == key){
        return 1;
    }
    if(key < root -> data){
        return search(root -> left, key);
    }
    return search(root -> right, key);
}

void freetree(Node* root){
    if(root == NULL){
        return;    
    }

    freetree(root -> left);
    freetree(root -> right);
    free(root);
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

    printf("Post-Order Traversal: ");
    postorder_traversal(root);
    printf("\n");

    int key = 96;

    if(search(root, key)){
        printf("Element was found in the list.\n");
    }
    else{
        printf("Element not found.\n");
    }

    return 0;
}   


