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
    if(*head == NULL){
        *head = *tail = newnode;
        newnode -> next = newnode;
    }
    else{
        newnode -> next = *head;
        (*tail) -> next = newnode;
        *head = newnode;
    }
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
        printf("List is already empty\n");
        return -1;
    }

    Node* temp = *head;
    // Case: value is in head
    if(temp->data == value){
        // Only one node
        if(*head == *tail){
            free(temp);
            *head = *tail = NULL;
            return 0;
        }
        *head = temp->next;
        (*tail)->next = *head;
        free(temp);
        return 0;
    }

    Node* prev = NULL;
    while(temp->next != *head && temp->data != value){
        prev = temp;
        temp = temp->next;
    }

    // If value not found
    if(temp->data != value){
        printf("Element not found\n");
        return -1;
    }

    // Case: deleting tail
    if(temp == *tail){
        prev->next = *head;
        *tail = prev;
        free(temp);
        return 0;
    }

    // General case
    prev->next = temp->next;
    free(temp);
    return 0;
}

void traverse_list(Node* head, Node* tail){
    if(head == NULL){
        printf("list is empty\n");
        return;
    }
    Node* temp = head;
    printf("NULL ");
    while(temp -> next == head && temp == tail){
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