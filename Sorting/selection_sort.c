#include<stdio.h>

void selection_sort(int arr[], int size){
    for(int i = 0; i < size; i++){
        int min_ele = i;

        for(int j = i + 1; j < size; j++){
            if(arr[j] < arr[min_ele]){
                min_ele = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_ele];
        arr[min_ele] = temp;
    }
}
void print_array(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){

    int arr[] = {54, 87, 65, 12, 352, 78, 9, 45, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("OG Array\n");
    print_array(arr, size);

    selection_sort(arr, size);

    printf("Sorted Array\n");
    print_array(arr, size);

    return 0;
}