// Implementation of Circular linked list using "Tail" pointer

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* CreateNode(int value){
    Node* newnode = malloc(sizeof(Node));
    if(!newnode){
        printf("Memory Allocation faile\n");
        return 0;
    }

    newnode -> data = value;
    newnode -> next = NULL;
    return newnode;
}

int insert_at_front(Node** head, Node** tail, int value){
    Node* newnode = CreateNode(value);
    if(!newnode){
        return -1; 
    }
    newnode -> next = *head;
    *head = newnode;
    *tail = newnode;
    
    return 0;
}

int insert_at_back(Node** head, Node** tail, int value){
    Node* newnode = CreateNode(value);
    if(!newnode){
        return -1;
    }

    if(*head == NULL){
        *head = *tail = newnode;
        newnode -> next = newnode;
    }
    else{
        
        newnode -> next (*tail) -> next;
        (*tail) -> next = newnode;
        *tail = newnode;
    }
    return 0;

    (*tail) -> next = newnode;
    *tail = newnode;
    newnode -> next = *head;
    return 0;

}