#include<stdio.h>


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

int main(){

    int arr[] = {1,4,7,5,6,25,14,5,5,5,5,5,1,1};

    int n = sizeof(arr)/sizeof(arr[0]);

    print_with_pointer(arr,n);

    return 0;
}