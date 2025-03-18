#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createnode(int data){
    Node* newNode = malloc(sizeof(Node));
        if(!newNode){
            printf("Memomry allocation failed");
            return 0;
        }

        newNode -> data = data;
        newNode -> next = NULL;   
        return newNode; 
}

int insert_at_front(Node** head, int data){
    Node* newNode = createnode(data);
    if(!newNode){
        return 0;
    }
    newNode -> next = *head;
    *head = newNode;
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