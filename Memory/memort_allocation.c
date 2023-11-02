#include<stdio.h>
#include<stdlib.h>

/*
    C Dynamic Memory Allocation can be defined as a procedure in which the size of a data structure (like Array) is changed during the runtime.
        C provides some functions to achieve these tasks. There are 4 library functions provided by C defined under <stdlib.h> header file to facilitate dynamic memory allocation in C programming. They are: 

        malloc()
        calloc()
        free()
        realloc()
*/

/*
    C malloc() method
    The “malloc” or “memory allocation” method in C is used to dynamically allocate a single large block of memory with the specified size.
    It returns a pointer of type void which can be cast into a pointer of any form. It doesn’t Initialize memory at execution time
    so that it has initialized each block with the default garbage value initially.

    ptr = (int*) malloc(100 * sizeof(int));
    Since the size of int is 4 bytes, this statement will allocate 400 bytes of memory.
    And, the pointer ptr holds the address of the first byte in the allocated memory.

*/


/*
    C calloc() method
        “calloc” or “contiguous allocation” method in C is used to dynamically allocate the specified number of blocks of memory of the specified type. it is very much similar to malloc() but has two different points and these are:
        It initializes each block with a default value ‘0’.
        It has two parameters or arguments as compare to malloc().
        Syntax of calloc() in C
        ptr = (cast-type*)calloc(n, element-size);
        here, n is the no. of elements and element-size is the size of each element.
*/


/*
    C free() method
    “free” method in C is used to dynamically de-allocate the memory.
    The memory allocated using functions malloc() and calloc() is not de-allocated on their own.
    Hence the free() method is used, whenever the dynamic memory allocation takes place.
    It helps to reduce wastage of memory by freeing it.
*/

/*
    C realloc() method
    “realloc” or “re-allocation” method in C is used to dynamically change the memory allocation of a previously allocated memory.
    In other words, if the memory previously allocated with the help of malloc or calloc is insufficient,
    realloc can be used to dynamically re-allocate memory. re-allocation of memory maintains the already present value
    and new blocks will be initialized with the default garbage value.
*/

void reallocation();

void freeing();

int main(){

    // This pointer will hold the
    // base address of the block created
    int* ptr;
    int n, i;
 
    // Get the number of elements for the array
    printf("Enter number of elements:");
    scanf("%d",&n);
    printf("Entered number of elements: %d\n", n);
 
    // Dynamically allocate memory using malloc()
    ptr = (int*)malloc(n * sizeof(int));
 
    // Check if the memory has been successfully
    // allocated by malloc or not
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
 
        // Memory has been successfully allocated
        printf("Memory successfully allocated using malloc.\n");
 
        // Get the elements of the array
        for (i = 0; i < n; ++i) {
           ptr[i] = i + 1;
        }
 
        // Print the elements of the array
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i) {
            printf("%d, ", *(ptr + i));
        }
    }

    printf("\n");

    // Get the number of elements for the array
    n = 5;
    printf("Enter number of elements: %d\n", n);
 
    // Dynamically allocate memory using calloc()
    ptr = (int*)calloc(n, sizeof(int));
 
    // Check if the memory has been successfully
    // allocated by calloc or not
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
 
        // Memory has been successfully allocated
        printf("Memory successfully allocated using calloc.\n");
 
        // Get the elements of the array
        for (i = 0; i < n; ++i) {
            ptr[i] = i + 1;
        }
 
        // Print the elements of the array
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i) {
            printf("%d, ", ptr[i]);
        }

        reallocation();

        printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\n");

        freeing();
    }

    return 0;
}

void freeing(){
    // This pointer will hold the
    // base address of the block created
    int *ptr, *ptr1;
    int n, i;
 
    // Get the number of elements for the array
    n = 5;
    printf("Enter number of elements: %d\n", n);
 
    // Dynamically allocate memory using malloc()
    ptr = (int*)malloc(n * sizeof(int));
 
    // Dynamically allocate memory using calloc()
    ptr1 = (int*)calloc(n, sizeof(int));
 
    // Check if the memory has been successfully
    // allocated by malloc or not
    if (ptr == NULL || ptr1 == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
 
        // Memory has been successfully allocated
        printf("Memory successfully allocated using malloc.\n");
 
        // Free the memory
        free(ptr);
        printf("Malloc Memory successfully freed.\n");
 
        // Memory has been successfully allocated
        printf("\nMemory successfully allocated using calloc.\n");
 
        // Free the memory
        free(ptr1);
        printf("Calloc Memory successfully freed.\n");
    }
}

void reallocation(){

    // This pointer will hold the
    // base address of the block created
    int* ptr;
    int n, i;
 
    // Get the number of elements for the array
    n = 5;
    printf("Enter number of elements: %d\n", n);
 
    // Dynamically allocate memory using calloc()
    ptr = (int*)calloc(n, sizeof(int));
 
    // Check if the memory has been successfully
    // allocated by malloc or not
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
 
        // Memory has been successfully allocated
        printf("Memory successfully allocated using calloc.\n");
 
        // Get the elements of the array
        for (i = 0; i < n; ++i) {
            ptr[i] = i + 1;
        }
 
        // Print the elements of the array
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i) {
            printf("%d, ", ptr[i]);
        }
 
        // Get the new size for the array
        n = 10;
        printf("\n\nEnter the new size of the array: %d\n", n);
 
        // Dynamically re-allocate memory using realloc()
        ptr = (int*)realloc(ptr, n * sizeof(int));
 
        // Memory has been successfully allocated
        printf("Memory successfully re-allocated using realloc.\n");
 
        // Get the new elements of the array
        for (i = 5; i < n; ++i) {
            ptr[i] = i + 1;
        }
 
        // Print the elements of the array
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i) {
            printf("%d, ", ptr[i]);
        }
 
        free(ptr);
    }


}

