#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>

#define BLOOM_SIZE 1024

uint8_t Bloom_filter[BLOOM_SIZE / 8]; 

#define SET_BIT(arr, index) (arr[index / 8] |= (1 << (index % 8)))
#define GET_BIT(arr, index) (arr[index / 8]  & (1 << (index % 8)))

