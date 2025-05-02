#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node * deletionAtFirst(struct Node * head){
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
};

struct Node * deletiongANodeInBetween(struct Node * head, int index){
    struct Node * p = head;
    int i = 0;
    while(i != index - 1){
        p = p->next;
        i++;
    }
    struct Node  * q = p->next;
    p->next = q->next;
    free(q);
    return head;
};

struct Node * deleteLastNode(struct Node * head){
    struct Node * p = head;
    struct Node * q = head->next;
    while(q->next != NULL){
        p = p->next;
        q = q->next;
    }
    p -> next = NULL;
    free(q);
    return head;
};

struct Node * deleteAtIndex(struct Node * head, int value){
    struct Node * p = head;
    struct Node * q = head->next;
    while(q->data != value && q->next != NULL){
        p = p->next;
        q = q->next;
    }
    if (q->data = value){
        p -> next = q -> next;
        free(q);
        return head;
    }
};

int main()
{

    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 8;
    head->next = second;

    second->data = 9;
    second->next = third;

    third->data = 453;
    third->next = fourth;

    fourth->data = 89;
    fourth->next = NULL;

    head = deleteAtIndex(head, 453);
    linkedListTraversal(head);

    return 0;
}   