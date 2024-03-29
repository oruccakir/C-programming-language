#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Node{
    int data;
    int level;
    struct Node * right;
    struct Node *left;
};

typedef struct Node Node;

Node *createNode(int data){

    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->level = 1;
    newNode->data = data;
    
    return newNode;
}

void preOrder(Node *root){
    if(root == NULL)
        return;
    printf("V: %d L: %d ",root->data,root->level);
    preOrder(root->left);
    preOrder(root->right);
}

void insert(Node **root,int data){

    if(root == NULL)
        return;
    
    Node *newNode = createNode(data);
    
    if(*root == NULL){
        *root = newNode;
    }
    else{
        Node *prev = NULL;
        Node *curr = *root;
        int isFound = 0;
        int level = 1;
        while (curr != NULL && isFound == 0)
        {
            prev = curr;
            if(curr->data == data)
                isFound = 1;
            else if(curr->data > data)
                curr = curr->left;
            else
                curr = curr->right;
            
            level++;

        }

        if(isFound == 0){

            if(prev->data > data)
                prev->left = newNode;
            else
                prev->right = newNode;
            
            newNode->level = level;

        }
        
    }

}

int search(Node *head_ptr,int goal){

    if(head_ptr == NULL)
        return -1;
    
    Node *curr = head_ptr;
    int level = -1;
    int isFound = 0;
    
    while(curr != NULL && isFound == 0){
        if(curr->data == goal){
            isFound = 1;
            level = curr->level;
        }
        else if(curr->data > goal)
            curr = curr->left;
        else
            curr = curr->right;
    }

    return level;

}

int height(Node *root){
    if(root == NULL)
        return 0;
    int left_height = height(root->left);
    int right_height = height(root->right);
    return  1+((right_height >= left_height) ? right_height : left_height);
}

void size(Node *root,int *siz){
    if(root == NULL)
        return;
    
    *siz = *siz + 1;
    size(root->left,siz);
    size(root->right,siz);

}

int give_size(Node *root){

    int siz= 0;
    size(root,&siz);
    return siz;
}




int main(){

    Node *head = NULL;
    Node **head_ptr = &head;
    insert(head_ptr,15);
    insert(head_ptr,21);
    insert(head_ptr,11);
    insert(head_ptr,55);
    insert(head_ptr,69);
    insert(head_ptr,12);
    insert(head_ptr,58);
    insert(head_ptr,69);
    insert(head_ptr,69);
    preOrder(head);
    printf("\n");
    printf("%d",search(head,55));
    printf("\n %d\n",height(head));
    printf("%d",give_size(head));



    return 0;
}