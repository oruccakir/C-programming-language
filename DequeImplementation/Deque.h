#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include"Node.h"

struct ArrayDeque{
    int size;
    Node *head;
    Node *tail;
};
typedef struct ArrayDeque ArrayDeque;

Node* createNewNode(int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL)
        return NULL;
    newNode->data = data;
    newNode->nextNode = newNode->prevNode = NULL;
    return newNode;
}

void initialize(ArrayDeque *deq){
    deq->size = 0;
    deq->head = deq->tail = NULL;
}

int pollFirst(ArrayDeque *deq){

    if(deq->size == 0)
        return -1;
    
    Node *removedNode;
    int returned_data=0;
    
    if(deq->size == 1){
        removedNode = deq->head;
        returned_data = removedNode->data;
        free(removedNode);
        deq->head = deq->tail = NULL;
    }
    else{
        removedNode = deq->head;
        returned_data = removedNode->data;

        deq->head->nextNode->prevNode = NULL;
        deq->head = deq->head->nextNode;

        free(removedNode);
    }

    deq->size--;

    return returned_data;
}
void addFirst(ArrayDeque *deq,int data){

    Node *newNode = createNewNode(data);

    if(newNode == NULL)
        return;

    if(deq->head == NULL){
        deq->head = newNode;
        deq->tail = newNode;
    }
    else{
        newNode->nextNode = deq->head;
        deq->head->prevNode = newNode;
        deq->head = newNode;
    }

    deq->size++;

}

int pollLast(ArrayDeque *deq){

    if(deq->size == 0)
        return -1;
    
    Node *removedNode;
    int returned_data=0;
    
    if(deq->size == 1){
        removedNode = deq->head;
        returned_data = removedNode->data;
        free(removedNode);
        deq->head = deq->tail = NULL;
    }
    else{
        removedNode = deq->tail;
        returned_data = removedNode->data;

        deq->tail->prevNode->nextNode = NULL;
        deq->tail = deq->tail->prevNode;

        free(removedNode);
    }

    deq->size--;

    return returned_data;
}
void addLast(ArrayDeque *deq,int data){

    Node *newNode = createNewNode(data);

    if(newNode == NULL)
        return;

    if(deq->head == NULL){
        deq->head = newNode;
        deq->tail = newNode;
    }
    else{
        deq->tail->nextNode = newNode;
        newNode->prevNode = deq->tail;
        deq->tail = newNode;
    }

    deq->size++;

}

void printDeque(ArrayDeque *deq){
    printf("[ ");
    Node *curr = deq->head;
    while (curr != NULL)
    {
        printf("%d ",curr->data);
        curr = curr->nextNode;
    }
    printf("]\n\n");
}

void printDequeReverse(ArrayDeque *deq){
    printf("[ ");
    Node *curr = deq->tail;
    while (curr != NULL)
    {
        printf("%d ",curr->data);
        curr = curr->prevNode;
    }
    printf("]\n\n");
}



