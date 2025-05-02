#include <stdio.h>
#include <stdlib.h>

struct stack {
    int top;
    int size;
    int *arr;
};

int stackTop(struct stack *s) {
    return s->arr[s->top];    
}

int stackBottom(struct stack *s) {
    return s->arr[0];    
}   

int main() {
    struct stack s;
    s.size = 5;
    s.top = -1;
    s.arr = (int *)malloc(s.size * sizeof(int));

    // Pushing elements into the stack
    s.arr[++s.top] = 10;
    s.arr[++s.top] = 20;
    s.arr[++s.top] = 30;
    s.arr[++s.top] = 40;
    s.arr[++s.top] = 50;

    // Printing top and bottom elements
    printf("Top element: %d\n", stackTop(&s));
    printf("Bottom element: %d\n", stackBottom(&s));

    // Free allocated memory
    free(s.arr);

    return 0;
}
