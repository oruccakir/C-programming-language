#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

    list->size = list->size + 1;

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

        list->size = list->size + 1;

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

        list->size = list->size + 1;
        
    }

}


int removeFirst(struct SingleLinkedList* list){

    if(list->size == 0)
        return -1;
    else{

        int data = 0;

        struct Node* temp = list->head;

        data = temp->data;

        list->head = list->head->next;

        free(temp);

        list->size --;

        return data;

    }
    
}

int removeLast(struct SingleLinkedList* list){
    
    if(list->size == 0){
        return -1;
    }
    else if(list->size == 1){
        removeFirst(list);
    }
    else{

        int data = 0;

        struct Node *temp = list->head;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        struct Node* deletedNode = temp->next;

        data = deletedNode->data;

        temp->next = NULL;

        free(deletedNode);

        list->size--;

        return data;

    }
    
}

int delete(struct SingleLinkedList* list,int index){

    if(index >= list->size)
        return -1;
    else if(index == 0){
        removeFirst(list);
    }
    else if(index == list->size-1){
        removeLast(list);
    }
    else{

        int idx = 0,data = 0;

        struct Node* temp = list->head;

        while(idx != index -1){
            temp = temp->next;
            idx++;
        }

        struct Node* deletedNode = temp->next;

        temp->next = deletedNode->next;

        data = deletedNode->data;

        free(deletedNode);

        list->size--;

        return data;

    }

}

bool contains(struct SingleLinkedList* list, int goal){

    struct Node *temp = list->head;

    while (temp != NULL)
    {
        if(temp->data == goal)
            return true;
        
        temp = temp->next;

    }

    return false;

}