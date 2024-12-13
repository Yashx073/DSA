#include<stdio.h>
#include<stdlib.h>

struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myArray * a,int tSize,int uSize){

    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *)malloc(tSize * sizeof(int));

}

void setValues(struct myArray * a){

    int n;
    for (int i = 0 ; i < a->used_size; i++){
        printf("Enter the %dth element", i);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
}

void showValues(struct myArray * a){

    for (int i = 0 ; i < a->used_size ; i++){
        printf("%d\n", (a->ptr)[i]);
    }
}

int main(){

    struct myArray marks;
    createArray(&marks,10,2);
    setValues(&marks);
    showValues(&marks);

}