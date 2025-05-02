#include <stdio.h>
#include<stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct queue *q){
    if ((q->r+1)%q->size == q->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct queue *q){
    if (q->f == q->r){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct queue * q, int val){
    if(((q->r+1)%q->size) == q->f){
        printf("The queue is overflow");
    }
    else{
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue * q){
    int val = -1;
    if(q->f == q->r){
        printf("The queue is empty");
    }
    else{
        q->f = (q->f+1)%q->size;
        val = q->arr[q->f];
    }
    return val;
}


int main() {

    struct queue q;
    q.size = 5;
    q.r = q.f = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));
    
    enqueue(&q, 13);
    enqueue(&q, 3);
    enqueue(&q, 3);
    enqueue(&q, 3);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    
    if(isFull(&q)){
        printf("The queue is full\n");
    }
    if(isEmpty(&q)){
        printf("The queue is empty\n");
    }
    return 0;
}