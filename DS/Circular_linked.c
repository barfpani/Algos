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
        printf("Memory Allocation fail\n");
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
        
        newnode -> next = (*tail) -> next;
        (*tail) -> next = newnode;
        *tail = newnode;
    }
    return 0;
}

int delete_by_value(Node** head, Node** tail, int value){
    if(*head == NULL){
        printf("list is already empty");
        return -1;
    }

    Node* temp = *head;
    if(temp -> data == value){
        *head = temp -> next;
        temp -> next = NULL;
       free(temp);
    }
    Node* prev = NULL;
    while(temp != NULL && temp -> data != value){
        prev = temp;
        temp = temp ->next;
    }
    Node* temp_tail = *tail;
    if(temp_tail -> data == value){
        temp -> next = temp_tail -> next;
        *tail = temp;
        free(temp_tail);
    }
    if(temp == NULL){
        printf("Element Not Found\n");
        return -1;
    }
    prev -> next = temp -> next;
    temp -> next = NULL;
    free(temp);
}

void traverse_list(Node* head, Node* tail){
    if(head == NULL){
        printf("list is empty\n");
        return;
    }
    Node* temp = head;
    printf("NULL ");
    while(temp != NULL && temp == tail){
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf(" Head\n");
}

int main(){
    
    Node* head = NULL;
    Node* tail = NULL;

    insert_at_front(&head,& tail, 25);
    insert_at_front(&head,& tail, 26);
    insert_at_front(&head,& tail, 99);
    insert_at_front(&head,& tail, 44);
    insert_at_back(&head,&tail,  84);
    
    traverse_list(head, tail);
    

    delete_by_value(&head,& tail, 99);

    traverse_list(head, tail);
    

    return 0;
}