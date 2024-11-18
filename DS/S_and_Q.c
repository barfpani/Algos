#include <stdio.h>
#include <stdlib.h>
#define MAX 100

//Creating stack with the help of arrays. (static Implementation) 
typedef struct Stack {
    int data[MAX];
    int top;
} Stack;

//Initializing out stack and setting the top at -1

void initStack(Stack* stack) {
    stack->top = -1;
}

//This function checks if stack is full or not

int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

//This one checks if the stack is empty or not

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

//Push function is used to add elements into the stack.

void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->data[++stack->top] = value;
}

//The pop function is used to delete function from the stack

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->data[stack->top--];
}

//Peek funtion is special...its like our "Pop" function but 
//it returns the top most element without removing it

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->data[stack->top];
}

int main() {
    Stack stack;
    
    //Initialzing our stack using our own function

    initStack(&stack);
    
    //Adding 10 and 20 into the stack...after pushing the 10 will be on bottom
    //and 20 on the top, bcz Stacks follows the principle of FILO and LIFO
    
    push(&stack, 10);
    push(&stack, 20);

    //Peeking the topmost element and removing that element from the stack
    //in the nect step

    printf("Top Element: %d\n", peek(&stack));
    printf("Popped Element: %d\n", pop(&stack));
    return 0;
}
