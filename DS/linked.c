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

/*Insert at back is quiet simple in singly linked list
we just have to traverse the list until "next" variable gets NULL
adn after that, add the address of the newnode into the "next"
and set the "newNode's" next at NULL*/

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

/*In Delete_by_value method there are two cases,
1) if the element is the head
2) element is not in the list*/

void delete_by_value(Node** head, int value){
    if(*head == NULL){
        printf("List is empty\n");
        return;
    }
    
    Node* temp = *head;                         //here is the 1st case, we have created a temp pointer which stores the
    if(temp -> data == value){                  //address of the head Node, the logic is if the "data" of the head node
        *head = temp -> next;                   //is the value which we want to delete? then the next node is assigned 
        free(temp);                             // as the new head node and the old node which is accessible by the "temp"
        return;                                 // is freed from the memory using free() function.
    }
    
    Node *prev = NULL;                                  //here we have created a NULL pointer 

    while(temp != NULL && temp -> data != value){       // we have two pointers, "temp" and "prev" they both will traverse 
        prev = temp;                                    // alongside the entire list, ex = if the "prev" is at node 3,
        temp = temp -> next;                            // then "temp" will be at node 4, 
    }
    if(temp == NULL){
        printf("Element not found\n");                  // if the temp reaches at NULL and the element is still not found?
        return;                                         // then the element is not present in the list
    }
    prev -> next = temp -> next;                        // After finding the element, logic = set the "next" variable of the node at which
    free(temp);                                         // "prev" pointer points, equal to the "next" variable of the node at which "temp"
    return;                                             // pointer points, after this, free the node at which "temp" points using freee function.
}

/*A very simple fucntion, using while loop.
Logic = Print evemry element until temp is Equal to NULL*/

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