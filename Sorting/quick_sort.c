#include<stdio.h>

//INITIALIZATION OF THE FUNCTIONS WHICH ARE GOING TO BE USED IN THIS ALGORITHM.


//Swap function...which will swap the elements based on the pivot

void swap(int* a,  int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


//Partition function, which will divide the array into two parts, and those two in two more.

int partition(int arr[], int low, int high){
    int pivot = arr[high]; 
    int i = low - 1;

    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}


//Quicksort function which will handle all the sorting.

void quick_sort(int arr[], int low, int high){
    if(low < high) {
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int main(){
    
    //Initializing array and other variables

    int arr[] = {10, 16, 8, 12, 15, 6, 3, 9, 5};
    int n = sizeof(arr)/ sizeof(arr[0]);

    
    //Calling the function
    
    quick_sort(arr, 0, n - 1);

    //Printing the sorted array 
    
    printf("Sorted arrary: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
return 0;
}