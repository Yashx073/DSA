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

int dequeue(){
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

void enqueue(int val){
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

int main() {

    enqueue(5);
    enqueue(7);
    linkedListTraversal();
    dequeue();
    linkedListTraversal();  
    return 0;
}