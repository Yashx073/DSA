#include<stdio.h>

int linearSearch(int arr[],int size,int element){
    for (int i; i < size ; i++){
        if(arr[i] == element){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[] = {2,3,4,2,5,6,8,9,45,75,43,24,46,7,355,53};
    int size = sizeof(arr)/sizeof(int);
    int element = 45;
    int Search = linearSearch(arr, size, element);
    printf("The element is %d in index %d", element, Search);
    return 0;
}

