//Simplest static implementation of Queue.

#include<stdio.h>           
#include<stdlib.h>
#define MAX 100
#include<stdbool.h>

typedef struct Queue{
    int data[MAX];
    int front, back;
} Queue;

void initqueue(Queue *queue){
    queue -> front = -1;
    queue -> back = -1;
}

bool isfull(Queue *queue){
    return queue -> back == MAX - 1;
}

bool isempty(Queue *queue){
    return queue -> back == -1 || queue -> front > queue -> back;
}

int enqueue(int value, Queue *queue){
    if(isfull(queue)){
        printf("Queue Overflown");
        return 0;
    }
    if(isempty(queue)){
        queue -> front = 0;
    }
    queue -> data[++queue -> back] = value;
    return 0;
}

int dequeue(Queue *queue){
    if(isempty(queue)){
        printf("Queue underflown");
        return 1;
    }
    return queue -> data[queue -> front++];    
}

int Front(Queue *queue){
    if(isempty(queue)){
        printf("Queue is empty");
    }
    return queue -> data[queue -> front];
}

int main(){
    Queue queue;

    initqueue(&queue);

    enqueue(25, &queue);
    enqueue(74, &queue);
    enqueue(58, &queue);
    
    printf("Element at Front = %d\n", Front(&queue));
    printf("Removed element = %d\n", dequeue(&queue));
    printf("Element at Front = %d\n", Front(&queue));
    
    
    return 0;
}