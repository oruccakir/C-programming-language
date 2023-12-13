#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

typedef struct Node Node;

Node *createNode(int data){

    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = data;
    
    return newNode;
}

void printStack(Node *head){

    printf("[ ");
    while (head != NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
    printf("]\n");

}

void printQueue(Node *head){

    printf("[ ");
    while (head != NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
    printf("]\n");

}

void push(Node **head_ptr,int data){

    if(head_ptr == NULL)
        return;

    Node *newNode = createNode(data);
    
    if(*head_ptr == NULL){
        *head_ptr = newNode;
    }
    else{
        newNode->next = *head_ptr;
        *head_ptr = newNode;
    }
    
}

int pop(Node **head_ptr){

    if(head_ptr == NULL || *head_ptr == NULL)
        return 0;
    
    Node *removedNode = *head_ptr;
    int returned_data = removedNode->data;
    *head_ptr = (*head_ptr)->next;
    free(removedNode);
    return returned_data;
}

void enque(Node **head_ptr,Node **tail_ptr,int data){
     if(head_ptr == NULL)
        return;
    
    Node *newNode = createNode(data);
    
    if(*head_ptr == NULL){
        *head_ptr = newNode;
        *tail_ptr = newNode;
    }
    else{
        (*tail_ptr)->next = newNode;
        *tail_ptr = newNode;
    }

}

int deque(Node **head_ptr,Node **tail_ptr){

    if(head_ptr == NULL || *head_ptr == NULL)
        return 0;
    
    Node *removedNode = NULL;
    int retured_data = 0;

    *head_ptr = (*head_ptr)->next;
    free(removedNode);

    if(*head_ptr == NULL){
        removedNode = *tail_ptr;
        free(removedNode);
    }


}

int main(){

    Node *head = NULL;
    Node **head_ptr = &head;
    printStack(head);
    push(head_ptr,12);
    push(head_ptr,28);
    printStack(head);
    pop(head_ptr);
    printStack(head);
    pop(head_ptr);
    printStack(head);
    printf("\n");
    printf("QUEUE\n");
    Node *head1 = NULL;
    Node *tail = NULL;
    Node **head1_ptr = &head1;
    Node **tail_ptr = &tail;
    printQueue(head1);
    enque(head1_ptr,tail_ptr,15);
    enque(head1_ptr,tail_ptr,18);
    printQueue(head1);
    deque(head1_ptr,tail_ptr);
    printQueue(head1);
     deque(head1_ptr,tail_ptr);
    printQueue(head1);

    return 0;
}