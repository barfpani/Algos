#include<stdio.h>
#include<stdlib.h>
#define MAX 100

//Making a struct for our queue, Using lists inside the struct for our data to store in our queue

typedef struct Queue{
    int data[MAX];
    int front;
    int rear;
}Queue;                 //We're using just "Queue" instead of using "struct queue" to increase readanility

//Initqueue function will initialize our queue and set its front and rear to -1

void initQueue(Queue* queue){
    queue->front = -1;                  //there's a difference between "Queue" and "queue".
    queue->rear = -1;                   //"Queue" is our type, just like int or float and "queue" is our variable.
}                                       //we can use anything instead of "queue" variable which is initiliazed in the 
                                        //beginning of the main function. The code will still run without errors. 


//This function checks if the rear of he queue is at MAX or not...and it returns true or false.

int isfull(Queue* queue){
    return queue->rear == MAX - 1;
}

//Same goes for this fucntion...the conditions are differernt but it also returns true or false.

int isempty(Queue* queue){
    return queue->rear == -1 || queue->front > queue->rear;
}

//isfull and isempty functions mow can be used in Enqueue and Dequeue fucntions

int enqueue(Queue* queue, int value){
    if(isfull(queue)){                  //<-- this condition states that, if the "isfull" funtions returns true? 
        printf("Queue Overflown\n");    //which will only happen if "rear" is at MAX, then it will print "Queue Overflown"
        return 0;
    }                                   
    if(isempty(queue)){                 //Otherwise it will set front at 1
        queue->front = 0;
    }           
    queue->data[++queue->rear] = value;     //<-- In this statment we are doing pre-incrementation which means,
    return 1;                               //it will move the rear by 1 first and then it will add element in it, this reduces the chance of errors.
                                        
    
}
int dequeue(Queue* queue){
    if(isempty(queue)){
        printf("Queue Underflown\n");
        return -1;
    }
    return queue->data[queue->front++];     // We are using post-incrementaton here bcz we have to print the element which we are removing,
}                                           // if we do put "++" operator first, then it will give us the element which is at front after removal.

int main(){
    Queue queue;

    initQueue(&queue);

    enqueue(&queue, 52);
    enqueue(&queue, 25);

    printf("1st Removed element: %d\n", dequeue(&queue));
    printf("2nd Removed Element: %d\n", dequeue(&queue));

    return 0;
}
