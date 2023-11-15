#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
    int (*ptr)[10];
    Here ptr is pointer that can point to an array of 10 integers.
    Since subscript have higher precedence than indirection,
    it is necessary to enclose the indirection operator and pointer name inside parentheses.
    Here the type of ptr is ‘pointer to an array of 10 integers’. 
    Note : The pointer that points to the 0th element of array and the pointer that points to the whole array are totally different.
    The following program shows this: 
*/

/*
    On dereferencing a pointer expression we get a value pointed to by that pointer expression.
    Pointer to an array points to an array, so on dereferencing it, we should get the array, and the name of array denotes the base address.
    So whenever a pointer to an array is dereferenced, we get the base address of the array to which it points. 

    execute below sample method
 
*/

void sample(){
    int arr[] = { 3, 5, 6, 7, 9 };
    int *p = arr;
    int (*ptr)[5] = &arr;
     
    printf("p = %p, ptr = %p\n", p, ptr);
    printf("*p = %d, *ptr = %p\n", *p, *ptr);
     
    printf("sizeof(p) = %lu, sizeof(*p) = %lu\n",
                          sizeof(p), sizeof(*p));
    printf("sizeof(ptr) = %lu, sizeof(*ptr) = %lu\n", 
                        sizeof(ptr), sizeof(*ptr));

    printf("size of the p %d", sizeof(p));
}

/*
    Most of the time, pointer and array accesses can be treated as acting the same, the major exceptions being: 
 

1. the sizeof operator

sizeof(array) returns the amount of memory used by all elements in the array 
sizeof(pointer) only returns the amount of memory used by the pointer variable itself 
2. the & operator 

array is an alias for &array[0] and returns the address of the first element in the array 
&pointer returns the address of the pointer 
3. a string literal initialization of a character array 

char array[] = “abc” sets the first four elements in array to ‘a’, ‘b’, ‘c’, and ‘\0’ 
char *pointer = “abc” sets the pointer to the address of the “abc” string (which may be stored in read-only memory and thus unchangeable) 
4. Pointer variable can be assigned a value whereas an array variable cannot be.

int a[10];
int *p; 
p=a; legal
a=p; illegal
5. Arithmetic on pointer variable is allowed. 

p++; Legal
a++; illegal
6. Array is a collection of similar data types while the pointer variable stores the address of another variable.
*/

int main(){

    // Pointer to an integer
    int *p; 
     
    // Pointer to an array of 5 integers
    int (*ptr)[5]; 
    int arr[5];
     
    // Points to 0th element of the arr.
    p = arr;
     
    // Points to the whole array arr.
    ptr = &arr; 
     
    printf("p = %p, ptr = %p\n", p, ptr);
     
    p++; 
    ptr++;
     
    printf("p = %p, ptr = %p\n", p, ptr);

    sample();

    return 0;
}

/*
    p: is pointer to 0th element of the array arr, while ptr is a pointer that points to the whole array arr. 
*/

/*
    The base type of p is int while base type of ptr is ‘an array of 5 integers’.
    We know that the pointer arithmetic is performed relative to the base size, so if we write ptr++,
    then the pointer ptr will be shifted forward by 20 bytes.
*/

/*


On dereferencing a pointer expression we get a value pointed to by that pointer expression. 
Pointer to an array points to an array, so on dereferencing it, we should get the array, 
and the name of array denotes the base address. So whenever a pointer to an array is dereferenced,
 we get the base address of the array to which it points. 
 
Pointers and two dimensional Arrays: In a two dimensional array, 
we can access each element by using two subscripts, where first subscript represents the row number and second subscript represents the column number.
The elements of 2-D array can be accessed with the help of pointer notation also. Suppose arr is a 2-D array,
we can access any element arr[i][j] of the array using the pointer expression *(*(arr + i) + j). Now we’ll see how this expression can be derived. 
Let us take a two dimensional array arr[3][4]: 
 
int arr[3][4] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };


Since memory in a computer is organized linearly it is not possible to store the 2-D array in rows and columns.
The concept of rows and columns is only theoretical, actually, a 2-D array is stored in row-major order i.e rows are placed next to each other.
The following figure shows how the above 2-D array will be stored in memory.
 



Each row can be considered as a 1-D array, so a two-dimensional array can be considered as a collection of one-dimensional arrays that are placed one after another.
In other words, we can say that 2-D dimensional arrays that are placed one after another. So here arr is an array of 3 elements where each element is a 1-D array of 4 integers. 
We know that the name of an array is a constant pointer that points to 0th 1-D array and contains address 5000.
Since arr is a ‘pointer to an array of 4 integers’, according to pointer arithmetic the expression arr + 1 will represent the address 5016 and expression arr + 2 will represent address 5032. 
So we can say that arr points to the 0th 1-D array, arr + 1 points to the 1st 1-D array and arr + 2 points to the 2nd 1-D array. 
 

In general we can write: 

arr + i  Points to ith element of arr ->
Points to ith 1-D array
 

Since arr + i points to ith element of arr, on dereferencing it will get ith element of arr which is of course a 1-D array.
Thus the expression *(arr + i) gives us the base address of ith 1-D array.
We know, the pointer expression *(arr + i) is equivalent to the subscript expression arr[i]. So *(arr + i) which is same as arr[i] gives us the base address of ith 1-D array.
To access an individual element of our 2-D array, we should be able to access any jth element of ith 1-D array.
Since the base type of *(arr + i) is int and it contains the address of 0th element of ith 1-D array,
we can get the addresses of subsequent elements in the ith 1-D array by adding integer values to *(arr + i).
For example *(arr + i) + 1 will represent the address of 1st element of 1stelement of ith 1-D array and *(arr+i)+2 will represent the address of 2nd element of ith 1-D array.
Similarly *(arr + i) + j will represent the address of jth element of ith 1-D array. On dereferencing this expression we can get the jth element of the ith 1-D array.
*/