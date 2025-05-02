#include <stdio.h>
#include<stdlib.h>
struct queue {
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct queue *q){
    if (q->r == q->size-1){
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

void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("The queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
        printf("Enqueued: %d\n", val);
    }
}

void dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("The queue is empty\n");
    }
    else{
        q->f++;
        a = q->arr[q->f];
        printf("Dequeued: %d\n", a);
    }
}

int main() {

    struct queue q;
    q.size = 2;
    q.f = -1;
    q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueue(&q,24);
    enqueue(&q,96);
    enqueue(&q, 3);
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