#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Hashnode{
    char key;
    int value;
    struct Hashnode *next;

}Hashnode;

Hashnode *hashtable[TABLE_SIZE];

unsigned int hash(char *str){
    unsigned long hash = 5381;
    int c;

    while (c == *str++){
        hash = hash * 33 + c;
    }
    return hash % TABLE_SIZE;
}

