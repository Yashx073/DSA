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
    return -1;
}

int peek(struct stack *ptr, int position) {
    int index = ptr->top - position + 1;
    if (index < 0 || index > ptr->top) {
        printf("Not a valid position: %d\n", position);
        return -1;
    } else {
        return ptr->arr[index];
    }
}

int main() {

    struct stack * s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 8;
    s->top = -1;
    s->arr = (int *)malloc(s->size * (sizeof(int)));

    push(s,34);
    push(s,96);
    push(s,83);
    push(s,37);
    push(s,45);

    printf("%d\n",s->top);

    for (int j = 1; j <= s->top+1; j++){
        printf("The no's are %d\n", peek(s,j));
    }
    
    free(s->arr);
    free(s);
    return 0;
}