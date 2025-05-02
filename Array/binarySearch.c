#include<stdio.h>

int binarySearch(int arr[], int size,int element){
    int low, mid, high;
    low = 0;
    high = size - 1;
    
    while(low <= high){
        mid = (low + high)/2;
        if(arr[mid] == element){
            
            return mid;
        }
        if (element < mid){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {2,3,4,5,7,9,23,45,67,89};
    int size = sizeof(arr)/sizeof(int);
    int element = 45;
    int Search = binarySearch(arr, size, element);
    printf("The element is %d in index %d", element, Search);
    return 0;
}

