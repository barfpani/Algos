#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Hashnode{
    char* key;
    int value;
    struct Hashnode *next;

}Hashnode;

Hashnode *hashtable[TABLE_SIZE];

unsigned int hash(char *str){
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)){
        hash = hash * 33 + c;
    }
    return hash % TABLE_SIZE;
}

void insert (char *key, int value){
    unsigned int index = hash(key);

    Hashnode *newnode = malloc(sizeof(Hashnode));
    newnode -> key = strdup(key);
    newnode -> value = value;
    newnode -> next = hashtable[index];

    //Now moving this newnode at the front of that index if there are already elements present.
    hashtable[index] = newnode;
}

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