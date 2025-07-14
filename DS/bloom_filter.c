#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>

#define BLOOM_SIZE 1024                                                 

uint8_t Bloom[BLOOM_SIZE / 8];                                          // "uint8_t" is used instead of "uint" to get the better control of the bytes and the bits can be packed closely wihtout wastage of space

#define SET_BIT(arr, index) (arr[index / 8] |= (1 << (index % 8)))      // These are Macro function, this will set the bits inside the array to "1". "!=" is the "OR" operator,
#define GET_BIT(arr, index) (arr[index / 8]  & (1 << (index % 8)))      // "arr[index/8"]"" will get to the correct byte in the array, and "1 << index%8" will go to the correct bit inside that byte.

/*
void SET_BIT(const *char arr, int index){                               // This is the more simplified version or regular version of that macro fucntion, here the working of this function can be                      
    int byte_index = index / 8;                                         // undertood much easily "byte_index" variable stores which byte inside the array must be changed. And "bit_index" variable 
    int bit_index = index % 8;                                          // stores which bit inside that byte must be change. The concept of masking is used here. "arr[byte_index] != (1 << bit_index);"
    arr[byte_index] != (1 << bit_index);                                // this line is crucial, as it is changing the value of the bits without touching the rest of the bits. How? using he "OR" bit-wise
}                                                                       // operator, "!=" compares arr[byte_size] and (1 << bit_size). In bit terms -> 01011001 != 00000100 this will be 01011101. How?
bool GET_BIT(const *char arr, int index)                                // just use the simple OR operator logic 0 | 0 = 0, 1 | 0 = 1, 0 | 1 = 1, 1 | 1 = 1. In simple terms, "arr[byte_index] != (1 << bit_index);" 
    int byte_index = index / 8;                                         // is nothing just "arr[byte_size] = arr[byte_size] | (1 << bit_index);". We created a mask of the bit we wanted to change and then
    int bit_index = index % 8;                                          // performed operations with it to change the bit in our main "Bit Array". Same goes for the "get_bit" function, except it returns 
    return (arr[byte_index] & (1 << bit_index)) != 0;                   // bool value, but the macro one returns "1" and "0".
*/

unsigned int djb2(const char *str){
    unsigned int hash = 5381;                                           
    int c;                                                              
    while((c = *str++)){                                                // The djb2 hash function was used in my hashing code as well, so no needs to explain here.                         
        hash = hash * 33 + c;
    }
    return hash % BLOOM_SIZE;
}

unsigned int sdbm(const char *str){
    unsigned int hash = 0;
    int c;
    while((c = *str++)){                                                // The "sdbm" has function is same as that of "djb2", only the difference is the operation performed on the hash.
        hash = hash * 65599 + c;
    }
    return hash % BLOOM_SIZE;
}

void bloom_add(const char *str){
    unsigned int h1 = djb2(str);                                        // This function will change values of the bits, in our bloom according to the string,  
    unsigned int h2 = sdbm(str);                                        // First our string goes through two hash function and are set is two different places,
    SET_BIT(Bloom, h1);                                                 // which increases the possibility of the bits was changes only happens for this this 
    SET_BIT(Bloom, h2);                                                 // specific string. 
}

int bloom_check(const char *str){
    unsigned int h1 = djb2(str);                                        // The "bloom_check" follows the same principle as well, and it checks both places to 
    unsigned int h2 = sdbm(str);                                        // increses the chances of checking the existence of that string.
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

