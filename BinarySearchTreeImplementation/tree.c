#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"

struct Tree{

    int size;
    TreeNode *root;

};


typedef struct Tree Tree;

TreeNode *create_node(int data){

    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if(newNode == NULL)
        return NULL;
    
    newNode->data = data;
    newNode->left = newNode->right = newNode->parent = NULL;

    return newNode;

}


void insertNode(Tree *tree_ptr,int data){

    TreeNode *newNode = create_node(data);

    if(newNode == NULL)
        return;

    if(tree_ptr->root == NULL){
        tree_ptr->root = newNode;
    }
    else{
        Queue qu;
        qu.head = qu.tail = NULL;
        qu.size = 0;
        Queue *qu_ptr = &qu;

        enque(qu_ptr,tree_ptr->root);

        TreeNode *temp = NULL;

        int isInserted = 0;

        while(qu_ptr->size > 0 && isInserted == 0){

            temp = deque(qu_ptr);

            if(temp->left == NULL){
                temp->left = newNode;
                newNode->parent = temp;
                isInserted = 1;
            }
            else if(temp->right == NULL){
                temp->right = newNode;
                newNode->parent = temp;
                isInserted = 1;
            }

            if(isInserted == 0){

                if(temp->left != NULL)
                    enque(qu_ptr,temp->left);
                
                if(temp->right != NULL)
                    enque(qu_ptr,temp->right);

            }

        }


    }

    tree_ptr->size++;

}




int heightUtil(TreeNode *root){

    if(root == NULL)
        return 0;
    
    int left_height = heightUtil(root->left);
    int right_height = heightUtil(root->right);

    if(left_height >= right_height)
        return left_height + 1;
    else
        return right_height + 1;

}

int height(Tree *tree_ptr){
    return heightUtil(tree_ptr->root);
}

void printPreOrderUtil(TreeNode *root){

    if(root == NULL)
        return;
    
    printf("%d ",root->data);
    printPreOrderUtil(root->left);
    printPreOrderUtil(root->right);

}

void printPreOrder(Tree *tree_ptr){
    printPreOrderUtil(tree_ptr->root);
    printf("\n");
}

void printPostOrderUtil(TreeNode *root){

    if(root == NULL)
        return;

    printPostOrderUtil(root->left);
    printPostOrderUtil(root->right);
    printf("%d ",root->data);

}

void printPostOrder(Tree *tree_ptr){
    printPostOrderUtil(tree_ptr->root);
    printf("\n");
}

void printInOrderUtil(TreeNode *root){

    if(root == NULL)
        return;

    printInOrderUtil(root->left);
    printf("%d ",root->data);
    printInOrderUtil(root->right);
    

}

void printInOrder(Tree *tree_ptr){
    printInOrderUtil(tree_ptr->root);
    printf("\n");
}


void printLevelOrder(Tree *tree_ptr){

    if(tree_ptr->root == NULL)
        return;
    
    Queue qu;
    qu.head=qu.tail = NULL;
    qu.size=0;
    Queue *qu_ptr = &qu;

    TreeNode *temp = NULL;

    enque(qu_ptr,tree_ptr->root);

    int size=0;

    while(qu_ptr->size >0){
        size = qu_ptr->size;
        for(int i=0; i<size; i++){
            temp = deque(qu_ptr);
            printf("%d ",temp->data);
            if(temp->left != NULL)
                enque(qu_ptr,temp->left);
            if(temp->right != NULL)
                enque(qu_ptr,temp->right);
        }
        printf("\n");
        
    }
    printf("\n");

}



int main(){
    Tree tree;
    tree.root = NULL;
    tree.size =0;
    Tree *tree_ptr = &tree;


    insertNode(tree_ptr,48);
    insertNode(tree_ptr,52);
    insertNode(tree_ptr,57);
    insertNode(tree_ptr,87);
    insertNode(tree_ptr,89);
    insertNode(tree_ptr,12);
    insertNode(tree_ptr,21);
    printLevelOrder(tree_ptr);
    printPreOrder(tree_ptr);


    
    return -1;
}