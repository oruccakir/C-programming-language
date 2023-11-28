#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

typedef struct Node Node;

struct Queue{
    int size;
    Node *head;
    Node *tail;
};

typedef struct Queue Queue;

Node* createNode(int data){

    Node * newNode = (Node*)malloc(sizeof(Node));
    
    if(newNode == NULL)
        return NULL;
    
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;

}

void printQueue(Queue * qu){

    printf("[ ");
    Node *curr = qu->head;
    while (curr != NULL)
    {
        printf("%d ",curr->data);
        curr = curr->next;
    }
    printf("]\n");
    
}

void enque(Queue *qu_ptr,int data){

    Node *newNode = createNode(data);

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
    
    Node *removedNode = qu_ptr->tail;

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

int main(){

    Queue qu;
    qu.head = NULL;
    qu.size = 0;
    Queue *qu_ptr = &qu;
    for(int i=0; i<10; i++)
        enque(qu_ptr,i+1);


    printQueue(qu_ptr);

    for(int i=0; i<10; i++)
        deque(qu_ptr);

    printQueue(qu_ptr);

    return 0;
}
