#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct Node{
    void *data;
    struct Node *next;
};

typedef struct Node Node;

Node *createNode(void *data){

    Node *newNode = (Node *) malloc(sizeof(Node));
    
    if(newNode == NULL)
        return NULL;
    
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


int getsize(Node *head){
    int size=0;
    while (head != NULL)
    {
        head = head->next;
        size++;
    }
    return size;
}

void printList(Node *head){
    Node *temp = head;
    printf("[ ");
    
    while (head != NULL)
    {
        printf("%p ",head->data);
        head = head->next;
    }
    
    printf(" ]\n");
    printf("Size : %d\n",getsize(temp));
    
}

int isInsertedSafely(Node *head,void *data){
    
    while (head != NULL)
    {
        if(head->data == data)
            return 1;
        
        head = head->next;

    }

    return 0;
    
}


void insert(Node **head_ptr,void *data,int index){

    if(head_ptr == NULL)
        return;

    Node *newNode = createNode(data);
    

    if(index == 0){
        if(*head_ptr == NULL){
            *head_ptr = newNode;
        }
        else{
            newNode->next = *head_ptr;
            *head_ptr = newNode;
        }
    }
    else{
        int i=0; 
        Node *curr = *head_ptr;
        while(i != index -1 && curr != NULL){
            curr = curr->next;
            i++;
        }
        if(curr != NULL){
            newNode->next = curr->next;
            curr->next = newNode;
        }
    }
    

}

struct Student{
    int age;
    char name[20];
};

typedef struct Student Student;

int main(){

    Node *head = NULL;
    Node **head_ptr = &head;
    int *a = (int*)malloc(sizeof(int));
    *a = 21;
    char *b = (char*)malloc(sizeof(char));
    *b = 'c';
    Node *c = (Node*)malloc(sizeof(Node)); 

    Student *d = (Student*)malloc(sizeof(Student));
    d->age = 19;

    int arr[20] = {1,5,6,65,5,5465,496,494649,61616};

    strcpy(d->name,"Oruç");
    insert(head_ptr,a,0);
    insert(head_ptr,b,0);
    insert(head_ptr,c,1);
    insert(head_ptr,d,2);
    insert(head_ptr,arr,0);

    printf("%p\n",arr);
    
    printList(head);

    printf("%d\n",isInsertedSafely(head,a));
    printf("%d\n",isInsertedSafely(head,b));
    printf("%d\n",isInsertedSafely(head,c));
    printf("%d\n",isInsertedSafely(head,d));

    return 0;
}