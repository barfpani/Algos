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



int search (char *key, int *outvalue){
    unsigned int index = hash(key);
    Hashnode *node = hashtable[index];

    while (node != NULL){
        if(strcmp(node -> key, key) == 0){
            *outvalue = node -> value;
            return 1;
        }
        node = node -> next;
    }
    return 0;
}



void free_table(){
    for (int i = 0; i < TABLE_SIZE; i++){
        Hashnode *node = hashtable[i];
        while(node){
            Hashnode *temp = node;
            node = node -> next;
            free(temp -> key);
            free(temp);
        }
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
    if(search("Adya", &value)){
        printf("Found Adya: %d\n", value);
    }
    else{
        printf("Adya not found\n");
    }

    free_table();
    return 0;
}