#include<stdio.h>
#include<stdlib.h>

struct SingleLinkedList{

    struct Node* head;
    int size;

};

struct Node{
    
    int data;
    struct Node * next;
};

struct Node* constructor(int data){

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if(newNode == NULL){
        printf("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;

}

void printList(struct SingleLinkedList *list){

    struct Node* temp = list->head;

    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");

}

void addFirst(struct SingleLinkedList *list,int data){

    struct Node* newNode = constructor(data);
    newNode->next = list->head;
    list->head = newNode;

    list->size++;

}


void addLast(struct SingleLinkedList *list,int data){

    if(list->head == NULL)
        addFirst(list,data);
    else{

        struct Node* newNode = constructor(data);

        struct Node* temp = list->head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
    
        temp->next = newNode;

        list->size++;

    }

}

void add(struct SingleLinkedList* list,int data,int index){

    if(index > list->size)
        return;

    if(index == 0)
        addFirst(list,data);
    else if(index == list->size)
        addLast(list,data);
    else{

        struct Node* newNode = constructor(data);

        struct Node *temp = list->head;

        int idx = 0;

        while (idx != index -1)
        {
            temp = temp->next;
            idx++;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        list->size++;
        
    }

}
