#include<stdio.h>
#include<stdlib.h> 
  
# define SIZE 5 
  
// A wrapper for array to make sure that array 
// is passed by value. 
struct ArrayWrapper 
{ 
    int arr[SIZE]; 
};

// An array is passed by value wrapped in temp 
void modify(struct ArrayWrapper temp) 
{ 
    int *ptr = temp.arr; 
    int i; 
  
    // Display array contents 
    printf("In 'modify()', before modification\n"); 
    for (i = 0; i < SIZE; ++i) 
        printf("%d ", ptr[i]); 
  
    printf("\n"); 
  
    // Modify the array 
    for (i = 0; i < SIZE; ++i) 
        ptr[i] = 100; // OR *(ptr + i) 
  
    printf("\nIn 'modify()', after modification\n"); 
    for (i = 0; i < SIZE; ++i) 
        printf("%d ", ptr[i]); // OR *(ptr + i) 
} 

/*
    A whole array cannot be passed as an argument to a function in C++. 
    You can, however, pass a pointer to an array without an index by specifying the array’s name.
    Therefore in C, we must pass the size of the array as a parameter. Size may not be needed only in the case of ‘\0’ terminated character arrays, 
    size can be determined by checking the end of string character.
*/

void print(int arr[],int n){

    for(int i=0; i<n; i++)
        printf("%d ",arr[i]);
    
    printf("\n");

}

void print_with_pointer(int *arr,int n){

    for(int i=0; i<n; i++)
        printf("%d ",arr[i]);
    
    printf("\n");

}

/*
    In C, array name represents address and when we pass an array,
     we actually pass address and the parameter receiving function always accepts them as pointers (even if we use [],
      refer this for details).

How to pass array by value, i.e., how to make sure that we have a new copy of array when we pass it to function?
This can be done by wrapping the array in a structure and creating a variable of type of that structure and assigning values to that array.
 After that, passing the variable to some other function and modifying it as per requirements. Note that array members are copied when passed as parameter,
  but dynamic arrays are not. So this solution works only for non-dynamic arrays (created without new or malloc).
*/

void array(int *p,int size){

    int *end = &p[size];

    while (p != end)
    {
        printf("%d ",*p);
        p++;
    }
    
}

void printMatrix(int mat[][5],int row_size, int col_size){

    int *start=&mat[0][0];
    int *row_ptr=start;
    int *end = &mat[row_size-1][col_size];

    while(start != end){
        start=row_ptr;
        while (start != row_ptr+col_size)
        {
            printf("%d ",*start);
            start++;
        }
        printf("\n");
        row_ptr+=col_size;
    }

}


int main(){

    int mat[3][5]={{1,2,3,4,5},{4,5,6,2,2},{1,8,8,8,8}};
    printMatrix(mat,3,5);

    printf("\n");

    int arr[] = {1,4,7,5,6,25,14,5,5,5,5,5,1,1};
    int *p=arr;

    array(p,14);

/*
    printf("\n");

    int n = sizeof(arr)/sizeof(arr[0]);

    print_with_pointer(arr,n);

    int i; 
    struct ArrayWrapper obj; 
    for (i=0; i<SIZE; i++) 
        obj.arr[i] = 10; 
  
    modify(obj); 
  
    // Display array contents 
    printf("\n\nIn 'Main', after calling modify() \n"); 
    for (i = 0; i < SIZE; ++i) 
        printf("%d ", obj.arr[i]); // Not changed 
  
    printf("\n"); 
    */

    return 0;
}