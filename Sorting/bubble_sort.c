#include <stdio.h>

//Initializing functions which are going to be used in our algorithm.

//This function will take care of swapping elements.

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Main algorithm function, bubble sort takes compares two elements from the starting
//of the list, and swap them if the first one is bigger tha the second one.

void bubble_sort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                swap(&A[j], &A[j + 1]);
            }
        }
    }
}

int main() {

    //Initializing our list of numbers which we want to sort.

    int A[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(A) / sizeof(A[0]);

    //Printing out unsorted array.

    printf("Orignal Arrar: ");
    for(int k = 0; k < n; k++){
        printf("%d ", A[k]);
    }
    printf("\n");

    // Calling our sorting function and passing our list and it's size.

    bubble_sort(A, n);

    //Printing the sorted array.

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
