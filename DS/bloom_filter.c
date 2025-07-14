#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>

#define BLOOM_SIZE 1024                                                 

uint8_t Bloom[BLOOM_SIZE / 8];                                          // "uint8_t" is used instead of "uint" to get the better control of the bytes and the bits can be packed closely wihtout wastage of space

#define SET_BIT(arr, index) (arr[index / 8] |= (1 << (index % 8)))      // These are Macro function, this will set the bits inside the array to "1". "!=" is the "OR" operator,
#define GET_BIT(arr, index) (arr[index / 8]  & (1 << (index % 8)))      // "arr[index/8"]"" will get to the correct byte in the array, and "1 << index%8" will go to the correct bit inside that byte.

/*
void SET_BIT(const *char arr, int index){                   // This is the more simplified version or regular version of that macro fucntion, here the working of this function can be                      
    int byte_index = index / 8;                             // undertood much easily "byte_index" variable stores which byte inside the array must be changed. And "bit_index" variable 
    int bit_index = index % 8;                              // stores which bit inside that byte must be change. 
    arr[byte_index] != (1 << bit_index);                    // 
}                                                           // 
bool GET_BIT(const *char arr, int index)                    // 
    int byte_index = index / 8;                             // 
    int bit_index = index % 8;                              // 
    return (arr[byte_index] & (1 << bit_index)) != 0;       // 
*/

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

