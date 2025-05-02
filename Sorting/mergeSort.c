#include <stdio.h>

void printArray(int *A, int n){
    for ( int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int A[], int mid, int low, int high){
    int i = low;
    int j = mid + 1;
    int k = low;
    int B[100];

    while(i <= mid && j <= high){
        if(A[i] < A[j]){
            B[k] = A[i];
            i++;
            k++;
        }
        else{
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while(i <= mid){
        B[k] = A[i];
            i++;
            k++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        j++;
        k++;
    }
    for(int x = low; x <= high; x++){
        A[x] = B[x];
    }
}

void mergeSort(int A[], int low, int high){
    int mid;
    if(low < high){
        mid = (low + high)/2;
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge(A, mid, low, high);
    }
}

int main() {

    int A[] = {3, 6, 34, 77, 4, 24};
    int n = 6;

    printArray(A, n);
    mergeSort(A, 0, n-1);
    printArray(A, n);

    return 0;
}