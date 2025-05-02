#include <stdio.h>
#include<stdlib.h>

struct stack
{
    int top;
    int size;
    char *arr;
};

int isEmpty(struct stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *s, char exp)
{
    if (isFull(s))
    {
        printf("Stack Overflow");
    }
    else
    {
        s->top++;
        s->arr[s->top] = exp;
    }
}

char pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("The stack is Underflow");
        return '\0';
    }else{
        int val = s->arr[s->top];
        s->top--;
        return val;
    }
}

int parenthesisMatching(char *exp)
{
    struct stack * s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 8;
    s->top = -1;
    s->arr = (char *)malloc(s->size * (sizeof(char)));
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(s, exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(s))
            {
                return 0;
            }
            else
            {
                pop(s);
            }
        }
    }
    if (isEmpty(s))
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
    char exp[] = "(3+5)*()";
    if(parenthesisMatching(exp)){
        printf("Parenthesis is balanced");
    }else{
        printf("Parenthesis are not balanced");
    }
    return 0;
}