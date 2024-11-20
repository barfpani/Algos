//In this file, I have implemented stack and Queue both, Queue was quite difficult to implement as compared to stack
//so i have done another implementation exactly like this, but only for queue and with notes.

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

//Creating stack and queue with the help of arrays. (static Implementation) 
typedef struct stack {
    int data[MAX];
    int top;
} Stack;

typedef struct Queue{
    int data[MAX];
    int front;
    int rear;
}Queue;

//Initializing our stack and setting the top at -1, and for queue setting front and rear at -1 too.

void initStack(Stack* stack) {
    stack->top = -1;
}

void initQueue(Queue* queue){
    queue->front = -1;
    queue->rear = -1;
}

//This function checks if stack is full or not

int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

int isQFull(Queue* queue){
    return queue->rear == MAX -1;
}

//This one checks if the stack is empty or not

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isQEmpty(Queue* queue){
    return queue->front == -1 || queue->front > queue->rear;
}

//Push function is used to add elements into the stack.
//and Enqueue function is used to add elements in queue.

void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->data[++stack->top] = value;
}

void Enqueue(Queue* queue, int value ){
    if(isQFull(queue)){
        printf("Queue overflow\n");
        return;
    }
    if (isQEmpty(queue)) queue->front = 0;
    queue->data[++queue->rear] = value;
}

//The pop function is used to delete element from the stack
//and Dequeue function is used to delete element from the queue.

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->data[stack->top--];
}
int dequeue(Queue* queue){
    if(isQEmpty(queue)){
        printf("Queue underflow\n");
        return -1;
    }
    return queue->data[queue->front++];
}

//Peek funtion is special...its like our "Pop" function but 
//it returns the top most element without removing it,
//Same goes for Front fucntion...but it is used for Queues.

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->data[stack->top];
}

int front (Queue* queue){
    if(isQEmpty(queue)){
        printf("Queue is empty.\n");
        return -1;
    }
    else{
        return queue->data[queue->front];
    }

}

int main() {

    Stack stack;
    Queue queue;

    //Initialzing our stack and queue using our own function

    initStack(&stack);

    initQueue(&queue);
    
    //Adding 10 and 20 into the stack...after pushing the 10 will be on bottom
    //and 20 on the top, bcz Stacks follows the principle of FILO and LIFO
    
    push(&stack, 10);
    push(&stack, 20);

    Enqueue(&queue, 15);
    Enqueue(&queue, 25);

    //Peeking the topmost element and removing that element from the stack
    //in the next step. 

    printf("STACK\n");
    printf("Top Element: %d\n", peek(&stack));
    printf("Popped Element: %d\n", pop(&stack));
    
    printf("\nQUEUE\n");
    printf("Top most Element: %d\n", front(&queue));
    printf("Removed Element: %d\n", dequeue(&queue));

    return 0;
}
