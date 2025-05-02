#include <stdio.h>
#include<stdlib.h>

struct stack{
    int *arr;
    int top;
    int size;
};

int isFull(struct stack * ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }else{
        return 0;
    }
}

int isEmpty(struct stack * ptr){
    if(ptr->top == -1){
        return 1;
    }else{
        return 0;
    }
}

void push(struct stack * ptr, int val){
    if(isFull(ptr)){
        printf("Stack Overflow!\n Cannot push %d to the stack\n", val);
    }else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack * ptr){
    if(isEmpty(ptr)){
        printf("Stack Empty");
    }else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int main() {

    struct stack * s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 8;
    s->top = -1;
    s->arr = (int *)malloc(s->size * (sizeof(int)));
    push(s,78);
    push(s,78);
    push(s,78);
    push(s,78);
    push(s,78);
    push(s,78);
    push(s,78);
    push(s,56);
    printf("The element %d is popped out",pop(s));

    return 0;
}