#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define BLOOM_SIZE 1024  // Size of the bit array in bits

// Define the bit array
uint8_t bloom[BLOOM_SIZE / 8];  // 1 byte = 8 bits

// Set and check bit macros
#define SET_BIT(arr, index) (arr[index / 8] |= (1 << (index % 8)))
#define GET_BIT(arr, index) (arr[index / 8] &  (1 << (index % 8)))

// Simple hash functions (you can use better ones like MurmurHash in production)
unsigned int djb2(const char *str) {
    unsigned int hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;  // hash * 33 + c
    return hash % BLOOM_SIZE;
}

unsigned int sdbm(const char *str) {
    unsigned int hash = 0;
    int c;
    while ((c = *str++))
        hash = c + (hash << 6) + (hash << 16) - hash;
    return hash % BLOOM_SIZE;
}

// Insert a string into the Bloom filter
void bloom_insert(const char *str) {
    unsigned int h1 = djb2(str);
    unsigned int h2 = sdbm(str);
    SET_BIT(bloom, h1);
    SET_BIT(bloom, h2);
}

// Check if a string is possibly in the Bloom filter
int bloom_check(const char *str) {
    unsigned int h1 = djb2(str);
    unsigned int h2 = sdbm(str);
    return GET_BIT(bloom, h1) && GET_BIT(bloom, h2);
}

int main() {
    bloom_insert("apple");
    bloom_insert("banana");

    printf("Check 'apple': %s\n", bloom_check("apple") ? "Possibly in set" : "Definitely not in set");
    printf("Check 'banana': %s\n", bloom_check("banana") ? "Possibly in set" : "Definitely not in set");
    printf("Check 'grape': %s\n", bloom_check("grape") ? "Possibly in set" : "Definitely not in set");

    return 0;
}
