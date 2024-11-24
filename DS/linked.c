#include <stdio.h>
#include <stdlib.h>

//Creating structure for our node.

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

//Inilizing out function which will create our node and setting it's "prev" and "next" to NULL.

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

//"insertAtEnd" function is pretty obvious, it will add elements into our linked list.

void insertAtEnd(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

//printlist function will print our list from the head.

void printlist(Node* head) {
    Node* temp = head;
    printf("Forward: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);


    printlist(head);

    return 0;
}
