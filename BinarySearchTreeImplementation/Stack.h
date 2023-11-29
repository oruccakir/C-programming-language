#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

typedef struct Node Node;

struct Stack{
    int size;
    Node *head;
};

typedef struct Stack Stack;

Node* createNode(int data){

    Node * newNode = (Node*)malloc(sizeof(Node));
    
    if(newNode == NULL)
        return NULL;
    
    newNode->data = data;
    newNode->next = NULL;

    return newNode;

}

void push(Stack *stack,int data){

    Node *newNode = createNode(data);

    if(newNode == NULL)
        return;
    
    if(stack->head == NULL){
        stack->head = newNode;
    }
    else{
        newNode->next = stack->head;
        stack->head = newNode;
    }

    stack->size++;

}

int pop(Stack *stack){

    if(stack->head == NULL)
        return -1;
    
    Node *removedNode = stack->head;

    int returned_data = removedNode->data;

    stack->head = stack->head->next;

    free(removedNode);

    stack->size--;

    return returned_data;
}

void printStack(Stack *stack){
    printf("[ ");
    Node *curr = stack->head;
    while (curr != NULL)
    {
        printf("%d ",curr->data);
        curr = curr->next;
    }
    printf("]\n");
}
