#include<stdio.h>

// Iniatialization of function and variables which are required in this algoithm.

int binary_search(int arr[], int size, int target){
    int low = 0;
    int high = size - 1;

        while(low <= high){
            int mid = (low + high)/ 2;                                      // Spliting up array in half
        
            if (arr[mid] == target){                                        // If the target element is at mid then ending 
                printf("Target: %d was found at: %d\n", target, mid);       // the loop and returning pos of taget in that array.
                return mid;                                                              
            }                                                                           
            else if (arr[mid] < target){                                    // Searching the element in right half
                low = mid + 1;
            }
            else{
                high = mid - 1;                                             // Searching the element in left half
            }
        } 
    return -1; 
}
int main(){

    // Initialzation of variables

    int arr[] = {2, 5, 7, 9, 12};
    int target = 9;
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = binary_search(arr, size, target);                           //calling out the function

    if(result == -1){
        printf("Targeted element: %d is not in this array\n ", target);
    }
    return 0;
}
