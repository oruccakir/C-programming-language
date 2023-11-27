#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

typedef struct Node Node;

struct SingleLinkedList{
    int size;
    Node *head; 
    Node *tail;  
};

typedef struct SingleLinkedList SingleLinkedList;

void printList(SingleLinkedList *list){

    Node *curr = list->head;

    while (curr != NULL)
    {
        printf("%d ",curr->data);
        curr = curr->next;
    }

    printf("\n");
    
}

void printInfo(SingleLinkedList *list){
    printf("SIZE : %d\n",list->size);
    printf("HEAD : %d\n", list->head == NULL ? -1 : list->head->data);
    printf("TAIL : %d\n",list->tail == NULL ? -1 : list->tail->data);
}

Node* createNode(int data){

    Node *newNode = (Node*) malloc(sizeof(Node));

    if(newNode == NULL)
        return NULL;
    
    newNode->data = data;
    newNode->next = NULL;

    return newNode;

}

void addFirst(SingleLinkedList *list,int data){

    Node *newNode = createNode(data);

    if(newNode == NULL)
        return;
    

    if(list->head == NULL){
        list->head = newNode;
        list->tail = newNode;
        list->head->next = list->tail;
    }
    else{
        newNode->next = list->head;
        list->head = newNode;
    }

    list->size++;

}

void addLast(SingleLinkedList *list,int data){

    Node *newNode = createNode(data);

    if(newNode == NULL)
        return;
    
    if(list->head == NULL){
        list->head = newNode;
        list->tail = newNode;
        list->head->next = list->tail;
    }
    else{
        list->tail->next = newNode;
        list->tail = newNode;
    }
    
    list->size++;

}

int removeFirst(SingleLinkedList *list){

    if(list->size == 0)
        return -1;
    
    int return_data = list->head->data;

    Node *removedNode = list->head;

    list->head = list->head->next;

    free(removedNode);

    list->size--;
    
    return return_data;

}

int removeLast(SingleLinkedList *list){

    if(list->size == 0)
        return -1;

    int return_data = list->tail->data;

    Node *removedNode = list->tail;

    Node * curr = list->head;

    while (curr->next != NULL &&  curr->next != list->tail)
    {
        curr = curr->next;
    }

    if(curr->next == NULL){
        list->head = list->tail = NULL;
    }
    else{
        curr->next = NULL;
        list->tail = curr;
    }
    

    free(removedNode);

    list->size--;

    return return_data;

}


int main(){

    SingleLinkedList list;
    list.head = NULL;
    list.tail = NULL;
    list.size = 0;
    SingleLinkedList *list_ptr = &list;
    addLast(list_ptr,12);
    addLast(list_ptr,21);
    printInfo(list_ptr);
    printList(list_ptr);
    removeLast(list_ptr);
    removeLast(list_ptr);
    printList(list_ptr);
    printInfo(list_ptr);
    /*
    removeFirst(list_ptr);
    removeFirst(list_ptr);
    removeFirst(list_ptr);
    printList(list_ptr);
*/
    return 0;
}

