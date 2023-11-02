#include<stdio.h>
#include<stdlib.h>


/*

The functions malloc() and calloc() are library functions that allocate memory dynamically.
Dynamic means the memory is allocated during runtime (execution of the program) from the heap segment.

Initialization
malloc() allocates a memory block of given size (in bytes) and returns a pointer to the beginning of the block.
malloc() doesn’t initialize the allocated memory. If you try to read from the allocated memory without first initializing it,
then you will invoke undefined behavior,
which usually means the values you read will be garbage values.

calloc() allocates the memory and also initializes every byte in the allocated memory to 0.
If you try to read the value of the allocated memory without initializing it, you’ll get 0 as it has already been initialized to 0 by calloc().

Parameters
malloc() takes a single argument, which is the number of bytes to allocate.

Unlike malloc(), calloc() takes two arguments:

Number of blocks to be allocated. 
Size of each block in bytes.
Return Value
After successful allocation in malloc() and calloc(), a pointer to the block of memory is returned otherwise NULL is returned which indicates failure.
    
*/


/*
    Difference between malloc() and calloc() in C
Let us see the differences in a tabular form:

S.No. 

malloc()

calloc()

1.

malloc() is a function that creates one block of memory of a fixed size.	calloc() is a function that assigns a specified number of blocks of memory to a single variable.
2.

malloc() only takes one argument	calloc() takes two arguments.
3.

malloc() is faster than calloc.	calloc() is slower than malloc()
4.

malloc() has high time efficiency	calloc() has low time efficiency
5.

malloc() is used to indicate memory allocation	calloc() is used to indicate contiguous memory allocation
6.

Syntax : void* malloc(size_t size);	Syntax : void* calloc(size_t num, size_t size);
8.

malloc() does not initialize the memory to zero	calloc() initializes the memory to zero
9.

malloc() does not add any extra memory overhead	calloc() adds some extra memory overhead
*/

int main(){


    return 0;
}


/*
    Memory leak occurs when programmers create a memory in a heap and forget to delete it.

The consequence of the memory leak is that it reduces the performance of the computer by reducing the amount of available memory. Eventually, in the worst case, too much of the available memory may become allocated and all or part of the system or device stops working correctly, the application fails, or the system slows down vastly.

Memory leaks are particularly serious issues for programs like daemons and servers which by definition never terminate.
*/

// you can check whether you free the memory or not by checking null value
// because after free thet pointer address become null