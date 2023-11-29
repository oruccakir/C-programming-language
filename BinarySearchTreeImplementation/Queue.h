#include <stdio.h>
#include<stdlib.h>

struct QuNode{
    int data;
    struct QuNode *next;
    struct QuNode *prev;
};

typedef struct QuNode QuNode;

struct Queue{
    int size;
    QuNode *head;
    QuNode *tail;
};

typedef struct Queue Queue;

QuNode* create_Node(int data){

    QuNode * newNode = (QuNode*)malloc(sizeof(QuNode));
    
    if(newNode == NULL)
        return NULL;
    
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;

}

void printQueue(Queue * qu){

    printf("[ ");
    QuNode *curr = qu->head;
    while (curr != NULL)
    {
        printf("%d ",curr->data);
        curr = curr->next;
    }
    printf("]\n");
    
}

void enque(Queue *qu_ptr,int data){

    QuNode *newNode = create_Node(data);

    if(newNode == NULL)
        return;
    
    if(qu_ptr->head == NULL){
        qu_ptr->head = newNode;
        qu_ptr->tail = newNode;
    }
    else{
        qu_ptr->tail->next= newNode;
        newNode->prev = qu_ptr->tail;
        qu_ptr->tail = newNode;
    }

    qu_ptr->size++;

}

int deque(Queue *qu_ptr){

    if(qu_ptr->head == NULL)
        return -1;
    
    QuNode *removedNode = qu_ptr->tail;

    int returned_data = removedNode->data;

    if(qu_ptr->tail->prev == NULL){
        qu_ptr->head = qu_ptr->tail = NULL;
    }
    else{

        qu_ptr->tail->prev->next = NULL;
        qu_ptr->tail = qu_ptr->tail->prev;

    }
    
    free(removedNode);

    qu_ptr->size--;

    return returned_data;

}


