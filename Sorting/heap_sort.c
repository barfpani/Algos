#include <stdio.h>

/*In heap sort, we use the concept of Trees 
to sort any array, the time complexity is 
n(log n, for all worst, best and average case.)*/


void heapify(int arr[], int n, int i) {                 // This is our main heapify function which will turn any array in a max heap, 
    int largest = i;                                    // or a min heap. We're generation a max heap.  
    int left = 2 * i + 1;                               // 
    int right = 2 * i + 2;                              // 

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than current largest
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n){

    for(int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }
    for(int i = n - 1; i >= 0; i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

void print_array(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){

    int arr[] = {4, 10, 3, 5, 1};
    int n = sizeof(arr)/ sizeof(arr[0]);

    print_array(arr, n);

    heap_sort(arr, n);

    printf("Sorted Array -> ");
    print_array(arr, n);

    return 0;
}