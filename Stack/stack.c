#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *array;
};

int isStackFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isStackEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->array = (int *)malloc(s->size * (sizeof(int)));

    s->array[0] = 0;
    s->top++;

    if (isStackEmpty(s))
    {
        printf("IS empty brooo");
    }
    else
    {
        printf("Not empty bruh");
    }
}