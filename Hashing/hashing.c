// Hash Table implementiation for string-interger pair

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10                                        // Defining the hash table size.

typedef struct Hashnode{
    char* key;                                              // We are using "chaining" method to handle collision,
    int value;                                              // the struct contains "key" which'll hold the string,
    struct Hashnode *next;                                  // "value" which holds the int value, and a next pointer                                                            
}Hashnode;                                                  // which points to a similar "Hashnode" struct.

Hashnode *hashtable[TABLE_SIZE];



unsigned int hash(char* str){                               //  | This is our "Hash Function", and we have used the most popular and efficient hash function
    unsigned long hash = 5381;                              //  | for stings, which is the "djb2". The type of our "hash" fxn is unsigned bcz we know that it
    int c;                                                  //  | won't return any negative values. The value of Hash is fixed from the djb2. inside our while loop,
    while ((c = *str++)){                                   //<-| we are storing each letter's ASCII value from the given string, hashing it and storing it into our
        hash = hash * 33 + c;                               //  | hash variable, and this loops continues until it encounter /0, wiz end of string, after reaching 
    }                                                       //  | the end of the string, it returns the index at which the string should be placed, by performing this,
    return hash % TABLE_SIZE;                               //  | hash % TABLE_SIZE, which will give value between 0 - 9.
}           



void insert (char *key, int value){                         //  | This function will insert elements into our "Hashtable", the chaining method will use the concept of 
    unsigned int index = hash(key);                         //  | linked lists, so the heap memory will be used. It takes 2 parameters, a string and a value for it, we 
    Hashnode *newnode = malloc(sizeof(Hashnode));           //  | calculate it's index using our "hash" function, The logic is simple, allocate a memory for a newnode   
    newnode -> key = strdup(key);                           //<-| place it on the correct index and fill it's varirables. Line 30 duplicates the given string to the
    newnode -> value = value;                               //  | newnode's "key" variable. we could've used "strcpy" but then we would've to manually allocate memory
    newnode -> next = hashtable[index];                     //  | for it. But in "strdup", it uses alocated heap memory. Line 32 & 33 are crucial. We set the newNode's 
    hashtable[index] = newnode;                             //  | "next" to point at the head node of that index, (it can be NULL as well) and then set the newnode 
}                                                           //  | as the new head of the index. (Same logic and operation of addind elements a front in a linked list).



int search (char *key, int *outvalue){                      //  | 
    unsigned int index = hash(key);                         //  | 
    Hashnode *node = hashtable[index];                      //  | The Search function's logic is very simple, it takes a string and a value pointer, which will return 
    while (node != NULL){                                   //  | the value of the key if founf in the table, and to finf elements in the chain, we have implememted a 
        if(strcmp(node -> key, key) == 0){                  //  | simple while loop and it will run until it encounter NULL. inside if statement, if the strcmp (which
            *outvalue = node -> value;                      //<-| compares two differnet strings) is true? which is 0, then the outvalue pointer will store the address of 
            return 1;                                       //  | the value which is associated with that string and returns 1. else the node pointer will move forward.
        }                                                   //  | and if the string is now found? it will return 0, This is a return type based function.  
        node = node -> next;                                //  | 
    }                                                       //  | 
    return 0;                                               
}



void free_table(){                                          
    for (int i = 0; i < TABLE_SIZE; i++){                   //  | The logic is simple, visit every index of the Table and Free is one by one, A simple "For", to traverse 
        Hashnode *node = hashtable[i];                      //  | the table, node pointer which will access the nodes at the indexes, While loop's conditions is only "node"
        while(node){                                        //  | bcz node will point to every index of the table, and at the end it traverse the linked list at that index,
            Hashnode *temp = node;                          //  | so it will encounter a NULL, That's the while loop's termiantion logic. Nested loop logic is used here.
            node = node -> next;                            //<-| inside while loop, a temp pointer is initialized to free the "key" and the entire node, the "temp" variable   
            free(temp -> key);                              //  | is initialized again at every iteration, and gets free aswell. After the entire linked list is freed from 
            free(temp);                                     //  | a paticular index? Them that index is initialized as NULL.
        }                                                   //  | 
        hashtable[i] = NULL;
    }
}



void print_table(){
    for(int i = 0; i < TABLE_SIZE; i++){
        printf("[%d]: ", i);
        Hashnode *node = hashtable[i];
        while(node){
            printf("(%s: %d) -> ", node -> key, node -> value);
            node = node -> next;
        }
        printf("NULL\n");
    }
}

int main(){
    insert("Sanchit", 20);
    insert("Rachit", 19);
    insert("Saad", 22);
    insert("Adya", 21);
    insert("Divyam", 20);

    print_table();

    int value = 0;
    if(search("Rachit", &value)){
        printf("Found Rachit: %d\n", value);
    }
    else{
        printf("Rachit not found\n");
    }

    free_table();
    return 0;
}