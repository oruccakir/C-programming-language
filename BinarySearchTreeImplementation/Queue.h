#include <stdio.h>
#include<stdlib.h>
#include"Treenode.h"    

typedef struct TreeNode TreeNode;

struct QuNode{
    TreeNode *data;
    struct QuNode *next;
};


typedef struct QuNode QuNode;

struct Queue{
    int size;
    QuNode *head;
    QuNode *tail;
};

typedef struct Queue Queue;

QuNode* create_Node(TreeNode *data){

    QuNode * newNode = (QuNode*)malloc(sizeof(QuNode));
    
    if(newNode == NULL)
        return NULL;
    
    newNode->data = data;
    newNode->next = NULL;
    
    
    return newNode;

}

void printQueue(Queue * qu){

    printf("[ ");
    QuNode *curr = qu->head;
    while (curr != NULL)
    {
        printf("%d ",curr->data->data);
        curr = curr->next;
    }
    printf("]\n");
    
}

void enque(Queue *qu_ptr,TreeNode *data){

    QuNode *newNode = create_Node(data);

    if(newNode == NULL)
        return;
    
    if(qu_ptr->head == NULL){
        qu_ptr->head = newNode;
        qu_ptr->tail = newNode;
    }
    else{
        qu_ptr->tail->next= newNode;
        qu_ptr->tail = newNode;
    }

    qu_ptr->size++;

}

TreeNode* deque(Queue *qu_ptr){

    if(qu_ptr->head == NULL)
        return NULL;
    
    QuNode *removedNode = qu_ptr->head;

    TreeNode* returned_data = removedNode->data;

    qu_ptr->head = qu_ptr->head->next;

    if(qu_ptr->head == NULL)
        qu_ptr->tail == NULL;
    
    free(removedNode);

    qu_ptr->size--;

    return returned_data;

}


