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

void insertNode(SingleLinkedList *list,int data,int index){

    if(index <0 || index > list->size + 1)
        return;

    Node *newNode = createNode(data);

    if(newNode == NULL)
        return;
    
    if(index == 1)
        addFirst(list,data);
    else if(index == list->size+1)
        addLast(list,data);
    else{

        int trace = 1;
        Node* curr = list->head;
        while (trace != index-1){
            curr = curr->next;
            trace++;
        }
        
        newNode->next = curr->next;
        curr->next = newNode;

        list->size++;

    }

}

int removeNode(SingleLinkedList *list,int index){

    if(index <0 || index > list->size)
        return 0;
    
    int returned_data;
    
    if(index == 1)
        returned_data = removeFirst(list);
    else if(index == list->size)
        returned_data = removeLast(list);
    else{

        int trace = 1;
        Node *curr = list->head;
        while(trace != index -1){
            curr = curr->next;
            trace++;
        }

        Node *removedNode = curr->next;
        
        returned_data = removedNode->data;

        curr->next = curr->next->next;

        free(removedNode);

        list->size--;

    }

    return returned_data;

}

int search(SingleLinkedList *list,int goal){

    Node *curr = list->head;

    int index = 1;

    while(curr != NULL){

        if(curr->data == goal)
            return index;
        
        index++;

        curr = curr->next;

    }

    return -1;

}


int main(){

    SingleLinkedList list;
    list.head = NULL;
    list.tail = NULL;
    list.size = 0;
    SingleLinkedList *list_ptr = &list;
    addLast(list_ptr,12);
    addLast(list_ptr,21);
    removeLast(list_ptr);
    removeLast(list_ptr);
    insertNode(list_ptr,14,1);
    insertNode(list_ptr,15,2);

    for(int i=0; i<10; i++)
        addFirst(list_ptr,i);
    
    insertNode(list_ptr,21,5);
    removeNode(list_ptr,5);
    removeNode(list_ptr,7);
    removeNode(list_ptr,list_ptr->size);

    printf("%d\n",search(list_ptr,0));

    printInfo(list_ptr);
    printList(list_ptr);
    return 0;
}

