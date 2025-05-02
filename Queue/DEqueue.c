#include <stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node * f = NULL;
struct Node * r = NULL;

void linkedListTraversal()
{
    struct Node * ptr = f;
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(){
    if(f == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int dequeueF(){
    int val = -1;
    struct Node*  ptr = f;
    if(isEmpty()){
        printf("Empty00");
    }
    else{
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

int dequeueR(){
    int val = -1;
    struct Node* p = f;
    struct Node* q = f->next;
    if(isEmpty()){
        printf("Empty00");
    }
    
    else if (f->next == NULL)
    {
        val = f->data;
        free(f);
        f = r = NULL;
    }
    
    else{
        while(q->next != NULL){
            p = p->next;
            q = q->next;
        }
        p->next = NULL;
        val = q->data;
        free(q);
        r = p;
    }
    return val;
}

void enqueueR(int val){
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    if(n == NULL){
        printf("Overflow");
    }
    else{
        n->data = val;
        n->next = NULL;
        if(f == NULL){
            f = r = n;
        }
        else{
            r->next = n;
            r = n;
        }
    }
}

void enqueueF(int val){
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    if(n == NULL){
        printf("Overflow");
    }
    else{
        n->data = val;
        n->next = f;
        if(f == NULL){
            r = n;
        }
        f = n;
    }
}

int main() {

    enqueue(5);
    enqueue(7);
    linkedListTraversal();
    dequeue();
    linkedListTraversal();  
    return 0;
}