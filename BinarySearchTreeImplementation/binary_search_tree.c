#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"

struct BinarySearchTree{

    int size;
    TreeNode *root;

};

typedef struct BinarySearchTree BinarySearchTree;

TreeNode *create_node(int data){

    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if(newNode == NULL)
        return NULL;
    
    newNode->data = data;
    newNode->left = newNode->right = newNode->parent = NULL;

    return newNode;

}

void insertNode(BinarySearchTree *tree_ptr,int data){

    TreeNode *newNode = create_node(data);


    if(newNode == NULL)
        return;

    if(tree_ptr->root == NULL){
        tree_ptr->root = newNode;
        tree_ptr->size++;
    }
    else{

        TreeNode *prev = NULL;
        TreeNode *curr = tree_ptr->root;

        while(curr != NULL){

            prev = curr;

            if(newNode->data > curr->data)
                curr = curr->right;
            else if(newNode->data < curr->data)
                curr = curr->left;
            
        }

        if(newNode->data > prev->data){
            prev->right = newNode;
            newNode->parent = prev;
            tree_ptr->size++;
        }
        else if(newNode->data < prev->data){
            prev->left = newNode;
            newNode->parent = prev;
            tree_ptr->size++;
        }

    }
    
}



TreeNode* search(BinarySearchTree *tree_ptr,int goal){

    if(tree_ptr->root == NULL)
        return NULL;
    
    TreeNode *curr = tree_ptr->root;
    while (curr != NULL)
    {
        if(curr->data == goal)
            return curr;
        else if(goal > curr->data)
            curr = curr->right;
        else
            curr = curr->left;
    }
    
    return NULL;
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

int height(BinarySearchTree *tree_ptr){
    return heightUtil(tree_ptr->root);
}

void printPreOrderUtil(TreeNode *root){

    if(root == NULL)
        return;
    
    printf("%d ",root->data);
    printPreOrderUtil(root->left);
    printPreOrderUtil(root->right);

}

void printPreOrder(BinarySearchTree *tree_ptr){
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

void printPostOrder(BinarySearchTree *tree_ptr){
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

void printInOrder(BinarySearchTree *tree_ptr){
    printInOrderUtil(tree_ptr->root);
    printf("\n");
}


void printLevelOrder(BinarySearchTree *tree_ptr){

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

void printFromChildToParent(BinarySearchTree *tree_ptr,int child_data){

    TreeNode *child = search(tree_ptr,child_data);

    if(child == NULL)
        return;

    TreeNode *temp = child;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->parent;
    }
    printf("\n");
}


int pollFirst(BinarySearchTree *tree_ptr){

    if(tree_ptr == NULL)
        return -1;
    
    TreeNode *removedNode;
    int returned_data=0;
    
    if(tree_ptr->size == 1){

        removedNode = tree_ptr->root;
        returned_data = removedNode->data;
        free(removedNode);
        tree_ptr->root = NULL;
        
    }
    else{

        TreeNode *curr = tree_ptr->root;

        while(curr->left != NULL){
            curr = curr->left;
        }

        removedNode = curr;
        if(removedNode == tree_ptr->root){

            returned_data = removedNode->data;

            if(tree_ptr->root->right != NULL){

                tree_ptr->root->right->parent = NULL;
                tree_ptr->root = tree_ptr->root->right;

            }
            else{
                tree_ptr->root = NULL;
            }

        }
        else{

            removedNode->parent->left = removedNode->right;
            if(removedNode->right != NULL)
                removedNode->right->parent = removedNode->parent;
            returned_data = removedNode->data;
            free(removedNode);
        }

    }

    tree_ptr->size--;

    return returned_data;

}






int main(){


    BinarySearchTree tree;
    tree.size=0;
    tree.root=NULL;
    BinarySearchTree *tree_ptr = &tree;
    
    int arr[20] = {89,78,45,12,54,65,21,31,25};
    for(int i=0; i<9; i++)
        insertNode(tree_ptr,arr[i]);

    
    
    printFromChildToParent(tree_ptr,25);

    

    printf("TESTING\n");
    printf("%d \n",pollFirst(tree_ptr));
    printf("%d \n",pollFirst(tree_ptr));
    printf("%d \n",pollFirst(tree_ptr));
    printf("%d \n",pollFirst(tree_ptr));
    printf("%d \n",pollFirst(tree_ptr));
    printf("%d \n",pollFirst(tree_ptr));
    printf("%d \n",pollFirst(tree_ptr));
    printf("%d \n",pollFirst(tree_ptr));
    printf("%d \n",pollFirst(tree_ptr));
    printFromChildToParent(tree_ptr,25);



    printPreOrder(tree_ptr);
    printPostOrder(tree_ptr);
    printInOrder(tree_ptr);



    printLevelOrder(tree_ptr);

    printf("Height : %d\n",height(tree_ptr));
    printf("Size : %d \n",tree.size);


    printf("Tesssssss");

    int arr1[20] = {55,78,45,52,54,65,21,31,25};
    for(int i=0; i<9; i++)
        insertNode(tree_ptr,arr1[i]);
    

    printf("POLLING\n");
    printf("%d \n",pollFirst(tree_ptr));
    printf("%d \n",pollFirst(tree_ptr));
    printf("%d \n",pollFirst(tree_ptr));
    printf("%d \n",pollFirst(tree_ptr));
    printf("%d \n",pollFirst(tree_ptr));
    printf("%d \n",pollFirst(tree_ptr));
    printf("%d \n",pollFirst(tree_ptr));
    printf("%d \n",pollFirst(tree_ptr));
    
    printf("\n\n");
    
    printf("TRAVERSAL\n");
    printPreOrder(tree_ptr);
    printPostOrder(tree_ptr);
    printInOrder(tree_ptr);
    printf("\n\n");

    printf("Head data\n");
    printf("%d\n",tree_ptr->root->data);

    printf("LEVEL ORDER\n");
    printLevelOrder(tree_ptr);

    printf("Height : %d\n",height(tree_ptr));
    printf("Size : %d \n",tree.size);

    printFromChildToParent(tree_ptr,78);



}