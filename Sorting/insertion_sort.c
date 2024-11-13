#include <stdio.h>

    //Initializtion of the function

void insertion_sort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        // shifts neighboring elements of the key which are greater than the key.

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        //placing the key in its correct position after the comparison

        arr[j + 1] = key; 
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    //Calling our function

    insertion_sort(arr, size);

    //Printing our sorting array
    
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
