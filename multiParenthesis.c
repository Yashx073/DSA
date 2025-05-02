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

int match(char a, char b){
    if (a == '(' && b == ')'){
        return 1;
    }
    if (a == '[' && b == ']'){
        return 1;
    }
    if (a == '{' && b == '}'){
        return 1;
    }
    return 0;
}

int parenthesisMatching(char *exp)
{
    struct stack * s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 8;
    s->top = -1;
    s->arr = (char *)malloc(s->size * (sizeof(char)));
    int popped_ch;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            push(s, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (isEmpty(s))
            {
                return 0;
            }
            else
            {
                popped_ch = pop(s);
                if(!match(popped_ch, exp[i])){
                    return 0;
                }
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
    char exp[] = "(3+5)[*](){{}}";
    if(parenthesisMatching(exp)){
        printf("Parenthesis is balanced");
    }else{
        printf("Parenthesis are not balanced");
    }
    return 0;
}