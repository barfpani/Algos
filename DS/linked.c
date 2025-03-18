#include <stdio.h>
#include <stdlib.h>

/*This is the basic struct of a linked list, it has a data 
variable which will store the value of this node, and "next"
is the pointer to the next node, it points to another node
that's why it is "Node*" */

typedef struct Node{
    int data;
    struct Node* next;
}Node;

/*In this function we're using malloc to allocate
a specific amount of memory to use, it's data type is Node*
aswell bcz it's returning the memory address of the
allocated mode.*/

Node* createnode(int data){
    Node* newNode = malloc(sizeof(Node));        //"newNode" variable stores the address of the allocated node.
        if(!newNode){                            // <--- this statemetn is used as a failsafe if the allocation fails.  
            printf("Memomry allocation failed"); //further explaination is in my handwritten notes(Only I have them :) ).
            return 0;
        }

        newNode -> data = data;
        newNode -> next = NULL;   
        return newNode; 
}

/*we have used the concept of double pointes
to change the value of the head pointer, */

int insert_at_front(Node** head, int data){
    Node* newNode = createnode(data);
    if(!newNode){
        return 0;
    }
    newNode -> next = *head;           //Here, we're assigning the "newNode's" next variable the address of the current head.
    *head = newNode;                   //And here we're decalring the "newNode" as the new head of the linked list.
    return 0;
}

int insert_at_back(Node** head,int data){
    Node* newNode = createnode(data);
    if(!newNode)return 0;
    if(*head == NULL){
        *head = newNode;
        return 0;
    }
    Node* temp = *head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
    return 0;
}

void delete_by_value(Node** head, int value){
    if(*head == NULL){
        printf("List is empty\n");
        return;
    }
    
    Node* temp = *head;
    if(temp -> data == value){
        *head = temp -> next;
        free(temp);
        return;
    }
    
    Node *prev = NULL;

    while(temp != NULL && temp -> data != value){
        prev = temp;
        temp = temp -> next;
    }
    if(temp == NULL){
        printf("Element not found\n");
        return;
    }
    prev -> next = temp -> next;
    free(temp);
    return;
}

void traverse_list(Node** head){
    Node* temp = *head;
    while(temp != NULL){
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

int main(){
    
    Node* head = NULL;

    insert_at_front(&head, 50);
    insert_at_front(&head, 20);
    insert_at_front(&head, 40);
    insert_at_back(&head, 30);

    traverse_list(&head);

    delete_by_value(&head, 20);

    traverse_list(&head);
    
    return 0;
}