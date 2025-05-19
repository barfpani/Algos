//Implementation of Doubly linked list.

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int Data;
    struct Node* next
    struct Node* back;
}Node;

Node* CreateNode(int data){
    Node* newnode = malloc(sizeof(Node));
    if(!newnode){
        printf("Memory Allocation failed\n");
        return 0;
    }
    newnode -> Data = data;
    newnode -> next = NULL;
    newnode -> back = NULL;
    return newnode;
}

int insert_at_front(Node** head, int data){
    Node* newnode = CreateNode(data);
    if(!newnode){
        return 0;
    }

    newnode -> next = *head;
    *head -> back = newnode;
    *head = newnode;
    return 0;
}

int insert_at_back(Node** head, int data){
    Node *newnode = CreateNode(data);
    if(!newnode){
        return 0;
    }
    if(*head == NULL){
        *head = newnode;
    }
    
    Node* temp = *head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newnode;
    newnode -> back = temp;
    return 0;
}

int delete_by_value(Node** head, int value){
    if(*head == NULL){
        printf("List is empty, Add some elements.\n");
        return -1;
    }
    Node* temp = *head;
    if(temp -> Data == value){
        *head = temp -> next;
        
        if(*head != NULL){
            (*head) -> back = NULL;
        }
        free(temp);
        return 0;
    }

    Node* prev = NULL;
    while(temp != NULL && temp -> Data != value){
        prev = temp;
        temp = temp -> next;
    }
    if(temp == NULL){
        printf("Value not found\n");
        return 0;
    }
    prev -> next = temp -> next;
    if(temp -> next != NULL){
        Node* temp2 = temp -> next;
        temp2 -> back = temp -> back;
    }
    
    free(temp);

    printf("%d Element Deleted\n", value);

    return 0;
}

void forward_traverse_list(Node** head){
    Node* temp = *head;
    while(temp != NULL){
        printf("%d -> ", temp -> Data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

void backward_traverse_list(Node** tail){
    Node* tempb = *tail;
    printf("NULL ");
    while( tempb != NULL){
        printf(" <- %d -> ", tempb -> Data);
        tempb = tempb -> back;
    }
    printf("NULL\n");
}

int main(){
    
    Node* head = NULL;
    Node* tail = NULL;

    insert_at_front(&head, 25);
    insert_at_front(&head, 26);
    insert_at_front(&head, 99);
    insert_at_front(&head, 44);
    insert_at_back(&head, 84);
    
    traverse_list(&head);
    
    delete_by_value(&head, 99);
    
    traverse_list(&head);
    
    
    
    return 0;
}