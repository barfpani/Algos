#include<stdio.h>

//Initialization of function

int linear_search(int arr[], int size, int target){
    for(int i = 0 ; i <= size; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

int main(){
    
    int arr[] = {9, 5, 8, 7, 3, 4};
    int target = 3;

    int size = sizeof(arr) / sizeof(arr[0]);

    int result = linear_search(arr, size, target);

    if(result != -1){
        printf("Element found at index: %d\n", result);
    }
    else{
        printf("Element not found");
    }
    return 0;

}