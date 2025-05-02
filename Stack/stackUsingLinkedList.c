#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *push(struct Node *top, int data)
{
    if (isFull())
    {
        printf("The stack is overflow\n");
        return top;
    }
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = top;
    top = ptr;
    return top;
}

int pop(struct Node **top)
{
    if (isEmpty(*top))
    {
        printf("The stack is underflow\n");
        return -1; // Returning -1 to indicate stack underflow
    }
    struct Node *n = *top;
    int x = n->data;
    *top = (*top)->next;
    free(n);
    return x;
}

void Traversal(struct Node *ptr)
{
    if (ptr == NULL)
    {
        printf("The stack is Empty\n");
    }
    else
    {
        printf("The elements are:\n");
        while (ptr != NULL)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}

int isFull()
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        return 1; // Stack is full
    }
    else
    {
        free(ptr);
        return 0; // Stack is not full
    }
}

int isEmpty(struct Node *top)
{
    return top == NULL ? 1 : 0;
}

int stackTop(struct Node *top){
    return top->data;
}

int Peek(struct Node *top,int pos){
    struct Node *ptr = top;
    for(int i = 0; (i <= pos-1 && ptr != NULL); i++){
       ptr =ptr->next;
    }
    if(ptr != NULL){
        return ptr->data;
    }else{
        return -1;
    }
}

int stackBottom(struct Node *top){
    struct Node *ptr = top;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    return ptr->data;
}

int main()
{
    struct Node *top = NULL;

    top = push(top, 7);
    top = push(top, 8);
    top = push(top, 9);
    top = push(top, 78);

    Traversal(top);

    int h = pop(&top);
    printf("The popped element is %d\n", h);
    Traversal(top);

    printf("Emptying the stack...\n");
    
    while (!isEmpty(top))
    {
        h = pop(&top);
        printf("Popped element: %d\n", h);
    }
    printf("The stack is now empty.\n");

    printf("%d",stackBottom(top));

    return 0;
}
