//Implementation of Doubly linked list.

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{                                 //<--- This is a basic struct for our doubly linked queue
    int data;                                        // whic means it has "next" pointer as well as "back" pointer.   
    struct Node* next;
    struct Node* back;
}Node;

Node* CreateNode(int value){
    Node* newnode = malloc(sizeof(Node));
    if(!newnode){
        printf("Memory Allocation failed\n");
        return 0;                                    // <-- "createnode" function is same as that regular linked lists
    }                                                // we only have to set the "back" pointer to NULL.
    newnode -> data = value;
    newnode -> next = NULL;
    newnode -> back = NULL;
    return newnode;
}

int insert_at_front(Node** head, int value){
    Node* newnode = CreateNode(value);
    if(!newnode){
        return 0;
    }

    newnode -> next = *head;                        // <-- The addition of the new node at the front is done using
    if(*head != NULL){                              // the "back" pointer instead of the front, In this case if the 
        (*head) -> back = newnode;                  // list already have existing elements then the "back" pointer of
    }                                               // current head points to the new node and that new node is declared as the new head.
    *head = newnode;
    return 1;
}

int insert_at_back(Node** head, int value){
    Node *newnode = CreateNode(value);
    if(!newnode){
        return 0;
    }
    if(*head == NULL){                              // <-- this is the case in which the list is empty, so it doesn't matter
        *head = newnode;                            // if we insert the element at the back or at the front
        return 0;
    }
    
    Node* temp = *head;                         
    while(temp -> next != NULL){                    // <-- here we're traversing to the end of the list to add the element at the back
        temp = temp -> next;
    }
    temp -> next = newnode;                         // <-- we set the last node's "next" pointer to point the new node
    newnode -> back = temp;                         // and set the newnode's "back" pointer to point the old last node.
    return 0;
}

int delete_by_value(Node** head, int value){
    if(*head == NULL){                                      
        printf("List is empty, Add some elements.\n");
        return -1;
    }
    Node* temp = *head;                             // <-- this is the case in which the element we want to delete is the head node.
    if(temp -> data == value){                      // <-- this right here is a basic if statement used in singly linked_list too.
        *head = temp -> next;
        
        if(*head != NULL){                          // <-- this is the exclusive condition in the doubly linked_list wiz, if the 
            (*head) -> back = NULL;                 // list is not empty after deletion (if list only had one element) then
        }                                           // "back" pointer of the new "head" is set as a NULL pointer. 
        free(temp);
        return 0;
    }

    Node* prev = NULL;
    while(temp != NULL && temp -> data != value){   //    |   
        prev = temp;                                //    |  
        temp = temp -> next;                        //    | this right here is the exact same logic and code 
    }                                               //    | which was in the singly linked list, two pointers 
    if(temp == NULL){                               // <--| moving forward alongside each other and then
        printf("Value not found\n");                //    | after reaching the element which they have to delete
        return 0;                                   //    | they just join the pointers and free the desired one
    }                                               //    |  
    prev -> next = temp -> next;                    //    |  

    if(temp -> next != NULL){                       // <-- in this case, if the element we want to delete is 
        Node* temp2 = temp -> next;                 // not the last element, the we set the "back" pointer of 
        temp2 -> back = temp -> back;               // the next element same as the "back" pointer of the
    }                                               // element we want to delete.
    
    free(temp);

    printf("%d Element Deleted\n", value);

    return 0;
}

void forward_traverse_list(Node* head){
    
    if(head == NULL){
        printf("List is empty\n");
    }

    Node* temp = head;                              // <-- This function is same as that of the singly linked list

    printf("NULL ");

    while(temp != NULL){
        printf(" <- %d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

void backward_traverse_list(Node* head){
    
    if(head == NULL){
        printf("List is Empty.\n");
        return;
    }

    Node* temp = head;                              // <-- the logic for backward traversing is to first reach
    while(temp != NULL && temp -> next != NULL){    //  at the end of the list and then move forward and print 
        temp = temp -> next;                        //  the elements until temp != NULL. this is a very unefficient
    }                                               //  approach as we dont have the "Tail" ptr which points to the last node
    printf("NULL ");                                //  otherwise we would've traversed directly.

    while(temp != NULL){                            //  Now when we reached at the end of the list, now we will move forward
        printf(" <- %d -> ", temp -> data);         //  and print the elements until "temp != NULL"
        temp = temp -> back;                        //  <-- to move backwards we use "back" pointer. 
    }
    printf("NULL\n");
}

int main(){
    
    Node* head = NULL;

    insert_at_front(&head, 25);
    insert_at_front(&head, 26);
    insert_at_front(&head, 99);
    insert_at_front(&head, 44);
    insert_at_back(&head, 84);
    
    forward_traverse_list(head);
    backward_traverse_list(head);

    delete_by_value(&head, 99);

    forward_traverse_list(head);
    backward_traverse_list(head);
    
    
    
    return 0;
}
