// Implementation of Circular linked list using "Tail" pointer

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

// "CreateNode" function is same just like the regular linked list.

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

// "insert_at_front" is a bit different tho.

int insert_at_front(Node** head, Node** tail, int value){
    Node* newnode = CreateNode(value);
    if(!newnode){
        return -1; 
    }

    // The case if the list is empty
    if(*head == NULL){
        *head = *tail = newnode;
        newnode -> next = newnode;
    }
        
    else{
        newnode -> next = *head;                // General case, if the list already has elements, after addinf the element at the front
        (*tail) -> next = newnode;              // the "head" of the list's changes, so we have to update the "tail" node to point 
        *head = newnode;                        // to the new "head".
    }
    return 0;
}

int insert_at_back(Node** head, Node** tail, int value){
    Node* newnode = CreateNode(value);
    if(!newnode){
        return -1;
    }

    if(*head == NULL){                          // This is again the case, if the list is empty.
        *head = *tail = newnode;
        newnode -> next = newnode;
    }
    else{
        
        (*tail) -> next = newnode;              // <-- here we assign the current "tail" node's "next" pointer to point to the new node 
        *tail = newnode;                        // as the element is added at the back, it's declared as the new "tail" and it's "next" pointer
        newnode -> next = *head;                // is set to point the "head" node to maintain the cycle
    }
    return 0;
}

int delete_by_value(Node** head, Node** tail, int value){
    if(*head == NULL){
        printf("List is already empty\n");
        return -1;
    }

    Node* temp = *head;
                        
    if(temp->data == value){                                    // <-- Here is the first case in which, if the element
        if(*head == *tail){                                     // we want to delete is the head node, and it's structured 
            free(temp);                                         // in an nested "if" to counter the case if the list only have  
            printf("%d -> Deleted Element.\n", temp -> data);   // one element, then after deleting that node, "head" and "tail"
            *head = *tail = NULL;                               // are set as NULL.
            return 0;                                           
        }
        
        *head = temp->next;                                     // General case of deletion of head element,
        (*tail)->next = *head;                                  // almost like the regular linked list case,  
        printf("%d -> Deleted Element.\n", temp -> data);       // but after deleting the "head" node ,the "tail"
        free(temp);                                             // node is updated to point the new "head" node.
        return 0;
    }

    Node* prev = NULL;                                          // Using two pointers to traverse throught the list 
    while(temp->next != *head && temp->data != value){          // just like the regular linked list. 
        prev = temp;
        temp = temp->next;
    }

    if(temp->data != value){                                    // <-- Case of "Value not found"
        printf("Element not found\n");
        return -1;
    }

    if(temp == *tail){                                          // <-- Deletion of tail node, using a simple logic and    
        prev->next = *head;                                     // using our two pointers for deletion, the "prev" pointer
        *tail = prev;                                           // is just behind the "temp" pointer and "temp" needs to be freed,
        printf("%d -> Deleted Element.\n", temp -> data);       // so we're just gonna change the "prev" node's "next" to point to 
        free(temp);                                             // the "head" node and assign the "prev" as the new "tail" and free
        return 0;                                               // the "temp =" node
    }

    
    prev->next = temp->next;                                    // <-- This is for the general case, to delete any element, 
    printf("%d -> Deleted Element.\n", temp -> data);           // from anywhere from the list, except head and tail, these cases are
    free(temp);                                                 // taken care of above.
    return 0;                                                   
}

void traverse_list(Node* head){
    if(head == NULL){
        printf("list is empty\n");
        return;
    }
    Node* temp = head;                                          //  
    printf("Head-> ");                                          //   
    while(temp -> next != head){                                // 
        printf("%d -> ", temp -> data);                         //   
        temp = temp -> next;                                    // 
    }                                                           // 
    printf("%d -> Head\n", temp -> data);                       //
}                                                               // 

int main(){
    
    Node* head = NULL;
    Node* tail = NULL;

    insert_at_front(&head, &tail, 25);
    insert_at_front(&head, &tail, 26);
    insert_at_front(&head, &tail, 99);
    insert_at_front(&head, &tail, 44);
    insert_at_back(&head, &tail, 84);
    
    traverse_list(head);

    delete_by_value(&head,& tail, 26);
    traverse_list(head);
    
    delete_by_value(&head,& tail, 44);
    traverse_list(head);
    
    delete_by_value(&head,& tail, 84);
    traverse_list(head);
    
    delete_by_value(&head,& tail, 25);
    traverse_list(head);
    
    delete_by_value(&head,& tail, 99);
    traverse_list(head);

    delete_by_value(&head, &tail, 10);
    traverse_list(head);

    

    return 0;
}
