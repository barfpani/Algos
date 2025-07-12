#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>

#define BLOOM_SIZE 1024

uint8_t Bloom[BLOOM_SIZE / 8]; 

#define SET_BIT(arr, index) (arr[index / 8] |= (1 << (index % 8)))
#define GET_BIT(arr, index) (arr[index / 8]  & (1 << (index % 8)))

unsigned int djb2(const char *str){
    unsigned int hash = 5381;
    int c;
    while((c = *str++)){
        hash = hash * 33 + c;
    }
    return hash % BLOOM_SIZE;
}

unsigned int sdbm(const char *str){
    unsigned int hash = 0;
    int c;
    while((c = *str++)){
        hash = hash * 65599 + c;
    }
    return hash % BLOOM_SIZE;
}

void bloom_add(const char *str){
    unsigned int h1 = djb2(str);
    unsigned int h2 = sdbm(str);
    SET_BIT(Bloom, h1);
    SET_BIT(Bloom, h2);
}

int bloom_check(const char *str){
    unsigned int h1 = djb2(str);
    unsigned int h2 = sdbm(str);
    return GET_BIT(Bloom, h1) && GET_BIT(Bloom, h2);
}

int main(){

    bloom_add("Apple");
    bloom_add("banana");

    printf("Check = Apple =");
    if(bloom_check("Apple\n")){
        printf("possibly in the set\n");
    }
    else{
        printf("definitely not in the set\n");
    }

    printf("Check = banana = %s\n", bloom_check("banana")? "Possibly in the set\n" : "Definitley not int the set\n");
    
    return 0;

}

