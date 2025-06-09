#include<stdio.h>
#include<stdlib.h>

// Function to merge two sorted array.

void merge(int arr[], int left, int mid, int right){
  int n1 = mid - left + 1;
  int n2 = right - mid;

  // Temporary arry to copy elements in.
  int L[n1], R[n2];

  for(int i = 0; i < n1 ; i++){
    L[i] = arr[left + i];
  }
  for(int j = 0; j < n2 ;j++){
    R[j] = arr[mid + 1 + j];  
  }

  //Merging two two sorted arrays into one'
  int i = 0; int j = 0; int k = left;
  while(i < n1 && j < n2){
    if(L[i] <= R[j]){
      arr[k++] = L[i++];
    }
    else{
      arr[k++] = R[j++];
    }
  }
  //Now copying remaining elements of L[], if any
  while(i < n1){
    arr[k++] = L[i++];
  }

  // Copying remaining elements of R[], if any
  while(j < n2){
    arr[k++] = L[j++];
  }
}

// Implementation of Merge Sort Algo now.
void merge_sort(int arr[], int left, int right){
  if(left < right){
    int mid = left + (right - left) / 2;
    
  
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);

    //merge the sorted arrays
    merge(arr, left, mid, right);
  }
}

// Printing array function 
void print_array(int arr[], int size){
  for(int i = 0; i < size; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main(){

  int arr[] = {38, 27, 43, 3, 9, 82, 10};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Orginal Array\n");
  print_array(arr, size);

  merge_sort(arr, 0, size - 1);

  printf("Sorted Array\n");
  print_array(arr, size);
  
  return 0;
}
