#include<stdio.h>

//Initialization of "linear_search" function

int linear_search(int arr[], int size, int target){        //basic logic, traversing the array unit the value is found
    for(int i = 0 ; i <= size; i++){                       // if the value is not found then that element is not in this list 
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
