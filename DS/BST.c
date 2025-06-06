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

//root , left , right

void inorder_traversal(Node* root){                             //   |"Recursive Funtion" is again used here, the understanding of a call stack is important here
    if(root == NULL){                                           //   | 
        return;                                                 //   |      The Explaination of this traversal function is in my handwritten notes,
    }                                                           // <-|      as it includes step by step diagrams for better understading, for a 
    printf("%d ", root -> data);                                //   |      a  basic idea? it's like a nested loop, or a good analogy, you're always 
    inorder_traversal(root -> left);                            //   |      in a bigger loop. (Watch the video explanation in the recyce bin of WP).
    inorder_traversal(root -> right);                           //   | 
}

//left , root , right                                           //   | This function takes "root" as it's parameter, inside the function, if root is equal to NULL?
void preorder_traversal(Node* root){                            //   | then it will return. In a hypothetical tree, let's say "10" is the root node. "10" is the input 
    if(root == NULL){                                           //   | for this function, and "10" is != NULL so the function call itself after not entering the "if" 
        return;                                                 //   | code block, while calling itself, it will take the "left" node of the "10" and again check if it 
    }                                                           // <-| is == NULL or not, when it reaches the last node by keep doing this , it will again call itself 
    preorder_traversal(root -> left);                           //   | and send the "left" of that last "node", but this time it has sent "NULL", as it's the "Last" 
    printf("%d ", root -> data);                                //   | Node. The "if" statement will execute and the flow of execution will go from "52" -> "53", till
    preorder_traversal(root -> right);                          //   | then it was going "52" -> "48", at line "53" it will print the "Root" node wiz the "Last" node,
}                                                               //   | then again call itself and this time send "right" of that "Root" Node. This is the 1st pass.

// left , right , root

void postorder_traversal(Node* root){
    if(root == NULL){
        return;
    }
    postorder_traversal(root -> left);
    postorder_traversal(root -> right);
    printf("%d ",root -> data);
}

int search(Node* root, int key){                                //   |
    if(root == NULL){                                           //   | After understanding how "Recursive Functions" work in traversal? Then all of this becomes 
        return 0;                                               //   | piece ofc cake. the logic is simple like a "Linear Search" visit every element until we 
    }                                                           //   | find the "key". What's changed is that the data is not in linear form. 
    if (root -> data == key){                                   //   | WORKING -> A return based function, if the root == to NULL it'll return "0", and if the
        return 1;                                               // <-| element is found then it will return "1". the traversal will be in the logic that if the
    }                                                           //   | Key is smaller than the "data" of that node? it will move to the left tree, and if the 
    if(key < root -> data){                                     //   | "key" is larger than the "head's " "data"? it ill move to the right tree. The "root == NULL"
        return search(root -> left, key);                       //   | is the termination statement,for when the pointer reach the end of the tree.
    }                                                           //   | 
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

    // Inserting elements into the "Tree"

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

    // Traversal Block

    //In-Order Traversal

    printf("In-Order Traversal: ");
    inorder_traversal(root);
    printf("\n");

    //Pre-Order Traversal

    printf("Pre-Order Traversal: ");
    preorder_traversal(root);
    printf("\n");

    //Post-Order Traversal

    printf("Post-Order Traversal: ");
    postorder_traversal(root);
    printf("\n");

    int key = 96;

    //Searching Block

    if(search(root, key)){
        printf("Element was found in the list.\n");
    }
    else{
        printf("Element not found.\n");
    }

    return 0;
}   


