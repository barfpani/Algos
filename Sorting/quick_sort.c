#include<stdio.h>

//Initialization of functions which are going to be used in this algorithm

void swap(int* a,  int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

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

void quick_sort(int arr[], int low, int high){
    if(low < high) {
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int main(){
    
    int arr[] = {5, 9, 7, 3, 7, 6, 1, 8};
    int n = sizeof(arr)/ sizeof(arr[0]);

    quick_sort(arr, 0, n - 1);

    printf("Sorted arrary: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
return 0;
}