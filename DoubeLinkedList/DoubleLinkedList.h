#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct DoubleLinkedList{

    struct Node* header;
    struct Node* tailer;
    int size;


};

struct Node{

    int data;
    struct Node* next;
    struct Node* prev;
    
};


struct Node* constructor(int data){

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if(newNode == NULL){
        printf("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;

}

void addBetweeen(int data,struct Node* first, struct Node* last){

    struct Node* newNode = constructor(data);

    first->next = newNode;
    newNode->prev = first;

    newNode->next = last;
    last->prev = newNode;
}

int removeBetweeen(struct Node* first, struct Node* last){

    struct Node* deletedNode = first->next;

    int data = deletedNode->data;

    first->next = last;
    last->prev = first;

    free(deletedNode);

    return data;

}

void addFirst(struct DoubleLinkedList* list,int data){

    addBetweeen(data,list->header,list->header->next);

    list->size++;

}

int removeFirst(struct DoubleLinkedList* list){

    if(list->size == 0)
        return -1;
    
    list->size--;
    
    return removeBetweeen(list->header,list->header->next->next);

}

void addLast(struct DoubleLinkedList* list,int data){

    addBetweeen(data,list->tailer->prev,list->tailer);

    list->size++;

}

int removeLast(struct DoubleLinkedList* list){

    if(list->size == 0)
        return -1;
    
    list->size--;
    
    return removeBetweeen(list->tailer->prev->prev,list->tailer);

}

void add(struct DoubleLinkedList* list,int data, int index){

    if(index > list->size)
        return;
    
    else if(index == 0)
        addFirst(list,data);
    else if(index == list->size)
        addLast(list,data);
    else{
        int idx = 0;
        struct Node* temp = list->header->next;
        while (idx != index)
        {
            temp = temp->next;
            idx++;
        }

        addBetweeen(data,temp->prev,temp);

        list->size++;
        
    }

}

int delete(struct DoubleLinkedList* list,int index){

    if(index >= list->size)
        return -1;
    else if(index == 0)
        return removeFirst(list);
    else if(index == list->size-1)
        return removeLast(list);
    else{

        int idx = 0;

        struct Node* temp = list->header->next;

        while(idx != index){
            temp = temp->next;
            idx++;
        }

        list->size--;

        return removeBetweeen(temp->prev,temp->next);
    }
}

void printList(struct DoubleLinkedList* list){

    struct Node* temp = list->header->next;

    while(temp != list->tailer){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");

}

void reversePrintList(struct DoubleLinkedList* list){

    struct Node* temp = list->tailer->prev;

    while(temp != list->header){
        printf("%d ",temp->data);
        temp = temp->prev;
    }
    printf("\n");

}


