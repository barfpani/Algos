#include <stdio.h>

/*In heap sort, we use the concept of Trees 
to sort any array, the time complexity is 
n(log n, for all worst, best and average case.)*/


void heapify(int arr[], int n, int i) {                 // This is our main heapify function which will turn any array in a max heap, 
    int largest = i;                                    // or a min heap. We're generation a max heap. In a max heap tree, the root has   
    int left = 2 * i + 1;                               // the highest element and it's childs are equal or smaller. We've supposed that 
    int right = 2 * i + 2;                              // the largest element is at the first [i], and its child's will be at[2*i+1]L

//                                                      // and [2*i+2]R, then we check if the largest element is at the root or not,
    if (left < n && arr[left] > arr[largest])           // if not? it swaps the largest element with the root. Heapify begins from the last
        largest = left;                                 // leaf node, in this case [1]. The concept of recursive function is used here

    if (right < n && arr[right] > arr[largest])         // Working - if the left child is larger than the root? swap them. And if the right
        largest = right;                                // child is larger than the root? Swap it with root aswell.

    if (largest != i) {                                 // This "if" statement is crucial here, how? this is our breakout statement for our
        int temp = arr[i];                              // recursion. if the current root is not the largest? then it will swap with the 
        arr[i] = arr[largest];                          // current largest (from its childs) and call heapify again. If the root is the 
        arr[largest] = temp;                            // largest then it won't go into the if statement and exit the function.

        heapify(arr, n, largest);                       
    }
}

void heap_sort(int arr[], int n){

    for(int i = n / 2 - 1; i >= 0; i--){                // The for loops starts at the non leaf node of the tree, and it decrementing so that
        heapify(arr, n, i);                             // max heaps are formed from the bottom up of the tree. The first for loop will create 
    }                                                   // a max heap of our array. 
    for(int i = n - 1; i >= 0; i--){                    // 
        int temp = arr[0];                              // Inside the second for loop, we'll replace the first (largest) element with the last 
        arr[0] = arr[i];                                // element, to move it into it's sorted position and then again call the heapify on the
        arr[i] = temp;                                  // reduced heap. And the for loop is running on the bases of size of the heap? Then it will      
        heapify(arr, i, 0);                             // terminate automatically and retunrn the sorted array.
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