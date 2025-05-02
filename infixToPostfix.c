#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
    int top;
    int size;
    char *arr;
};

char stackTop(struct stack *s) {
    return s->arr[s->top];    
}

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
        char val = s->arr[s->top];
        s->top--;
        return val;
    }
}

int precedence(char ch){
    if(ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else 
        return 0;
}

int isOperator(char ch){
    if(ch == '*' || ch == '/' || ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

char * infixToPostfix(char * infix){
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * (sizeof(char)));
    char * postfix = (char *)malloc((strlen(infix)+1) * (sizeof(char)));
    int i = 0;
    int j = 0;
    while(infix[i] != '\0'){
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else{
            if(precedence(infix[i]) > precedence(stackTop(sp))){
                push(sp, infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while(!isEmpty(sp)){
        postfix [j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    free(sp->arr);
    free(sp);
    return postfix;
}   

int main()
{
    char *infix = "a+b*c/6";
    char *postfix = infixToPostfix(infix);
    printf("Postfix is %s\n", postfix);
    free(postfix); 
    return 0;
}