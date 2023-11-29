#include<stdio.h>
#include<stdlib.h>


struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *parent;
};

typedef struct TreeNode TreeNode;

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



int search(BinarySearchTree *tree_ptr,int goal){

    if(tree_ptr->root == NULL)
        return 0;
    
    TreeNode *curr = tree_ptr->root;
    while (curr != NULL)
    {
        if(curr->data == goal)
            return 1;
        else if(goal > curr->data)
            curr = curr->right;
        else
            curr = curr->left;
    }
    
    return 0;
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







int main(){


    BinarySearchTree tree;
    tree.size=0;
    tree.root=NULL;
    BinarySearchTree *tree_ptr = &tree;
    insertNode(tree_ptr,15);
    insertNode(tree_ptr,20);
    insertNode(tree_ptr,40);
    insertNode(tree_ptr,8);
    printPreOrder(tree_ptr);
    printPostOrder(tree_ptr);
    printInOrder(tree_ptr);
    printf("%d\n",search(tree_ptr,20));
    printf("%d",height(tree_ptr));











}