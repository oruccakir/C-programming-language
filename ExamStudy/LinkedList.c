#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node *next;
};

typedef struct Node Node;

void printList(Node *head){

    while(head != NULL){
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");

}

void deallocateTheList(Node **head_ptr){

    Node *curr = *head_ptr;
    Node *removedNode = NULL;
    while (curr != NULL)
    {
        removedNode = curr;
        curr = curr->next;
        removedNode->next = NULL;
        free(removedNode);
    }

    *head_ptr = NULL;

}

Node *createNode(int data){

    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = data;
    
    return newNode;
}

Node ** makeCopy(Node **head_ptr){

    Node **copy_head_ptr = NULL;

    if(*head_ptr == NULL)
        return copy_head_ptr;
    else{
        Node *newHead = createNode((*head_ptr)->data);
        copy_head_ptr = (Node **)malloc(sizeof(Node*));
        *copy_head_ptr = newHead;
        Node *curr_real = (*head_ptr)->next;
        Node *curr_copy = newHead;
        
        while(curr_real != NULL){
            curr_copy->next = createNode(curr_real->data);
            curr_copy = curr_copy->next;
            curr_real = curr_real->next;
        }

        return copy_head_ptr;
    }

}

void reverseList(Node **head_ptr){

    Node *temp = NULL;
    Node *prev = NULL;
    Node *curr = *head_ptr;
    while(curr != NULL){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    *head_ptr = prev;

}

void insert(Node **head_ptr,int data,int index){

    Node *newNode = createNode(data);

    if(index == 0){
        if(*head_ptr == NULL)
            *head_ptr = newNode;
        else{
            newNode->next = *head_ptr;
            *head_ptr = newNode;
        }
    }
    else{

        int i=0;
        Node *curr = *head_ptr;
        while (i != index -1 && curr != NULL)
        {
            curr = curr->next;
            i++;
        }

        if(curr != NULL){
            newNode->next = curr->next;
            curr->next = newNode;
        }
        
    }

}

void delete(Node **head_ptr,int index){

    Node *removedNode = NULL;

    if(index == 0){

        if(*head_ptr != NULL){
            removedNode = *head_ptr;
            *head_ptr = (*head_ptr)->next;
            free(removedNode);
        }

    }
    else{

        int i=0;
        Node *curr = *head_ptr;
        while (i != index -1 && curr != NULL)
        {
            curr = curr->next;
            i++;
        }

        if(curr != NULL){

            Node *removedNode = curr->next;
            curr->next = curr->next->next;
            free(removedNode);

        }
        

    }

}

void deleteKey(Node **head_ptr,int key){

    if(*head_ptr == NULL)
        return;

    Node  *removedNode = NULL;

    if((*head_ptr)->data == key){
        removedNode = *head_ptr;
        *head_ptr = (*head_ptr)->next;
        free(removedNode);
    }
    else{

        Node *prev = NULL;
        Node *curr = *head_ptr;
        int isFound = 0;
        while (curr != NULL && isFound == 0)
        {
            
            if(curr->data == key)
                isFound = 1;
            else
                prev = curr;

            curr = curr->next;
        }

        if(isFound){
            removedNode = prev->next;
            prev->next = prev->next->next;
            free(removedNode);
        }

    }


}

int main(){

    Node *head = NULL;
    Node **head_ptr = &head;
    insert(head_ptr,15,0);
    insert(head_ptr,12,1);
    insert(head_ptr,21,0);
    insert(head_ptr,11,1);
    reverseList(head_ptr);
    printList(head);

    /*
    deleteKey(head_ptr,21);
    printList(head);
    deleteKey(head_ptr,12);
    printList(head);
    deleteKey(head_ptr,11);
    printList(head);
    deleteKey(head_ptr,15);
    printList(head);
    */
    //deallocateTheList(head_ptr);
    //printList(head);

    Node **copy = makeCopy(head_ptr);
    printList(*copy);
    reverseList(copy);
    printList(*copy);




    return 0;
}