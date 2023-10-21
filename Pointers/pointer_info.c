#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
    As the pointers store the memory addresses, their size is independent of the type of data they are pointing to.
    This size of pointers only depends on the system architecture.
*/

/*
    Note: It is recommended that the pointers should always be initialized to some value before starting using it.
    Otherwise, it may lead to number of errors.
*/

/*
    Wild Pointers
    The Wild Pointers are pointers that have not been initialized with something yet.
    These types of C-pointers can cause problems in our programs and can eventually cause them to crash.
*/


/*
    Double Pointers
    In C language, we can define a pointer that stores the memory address of another pointer.
    Such pointers are called double-pointers or pointers-to-pointer.
    Instead of pointing to a data value, they point to another pointer.
*/

/*
    Void Pointer
    The Void pointers in C are the pointers of type void. It means that they do not have any associated data type.
    They are also called generic pointers as they can point to any type and can be typecasted to any type

    // One of the main properties of void pointers is that they cannot be dereferenced.
*/

/*
     Constant Pointers
    In constant pointers, the memory address stored inside the pointer is constant and cannot be modified once it is defined.
    It will always point to the same memory address.

Syntax

data_type * const pointer_name;
*/

/*
    Pointer to Constant
    The pointers pointing to a constant value that cannot be modified are called pointers to a constant.
    Here we can only access the data pointed by the pointer, but cannot modify it. Although, we can change the address stored in the pointer to constant.

Syntax

const data_type * pointer_name;
*/

/*
    Note: In C, we can create multi-level pointers with any number of levels
    such as – ***ptr3, ****ptr4, ******ptr5 and so on.
*/

// It is said to be good practice to assign NULL to the pointers currently not in use.

/*
    Pointer Arithmetic
    The Pointer Arithmetic refers to the legal or valid arithmetic operations that can be performed on a pointer.
    It is slightly different from the ones that we generally use for mathematical calculations as only a limited set of operations can be performed on pointers.
    These operations include:

    Increment in a Pointer
    Decrement in a Pointer
    Addition of integer to a pointer
    Subtraction of integer to a pointer
    Subtracting two pointers of the same type
    Comparison of pointers of the same type.
    Assignment of pointers of the same type.
*/

/*
    Uses of Pointers
The C pointer is a very powerful tool that is widely used in C programming to perform various useful operations. It is used to achieve the following functionalities in C:

Pass Arguments by Reference
Accessing Array Elements
Return Multiple Values from Function
Dynamic Memory Allocation
Implementing Data Structures
In System-Level Programming where memory addresses are useful.
In locating the exact value at some memory location.
To avoid compiler confusion for the same variable name.
To use in Control Tables.
Advantages of Pointers
Following are the major advantages of pointers in C:

Pointers are used for dynamic memory allocation and deallocation.
An Array or a structure can be accessed efficiently with pointers
Pointers are useful for accessing memory locations.
Pointers are used to form complex data structures such as linked lists, graphs, trees, etc.
Pointers reduce the length of the program and its execution time as well.
Disadvantages of Pointers
Pointers are vulnerable to errors and have following disadvantages:

Memory corruption can occur if an incorrect value is provided to pointers.
Pointers are a little bit complex to understand.
Pointers are majorly responsible for memory leaks in C.
Pointers are comparatively slower than variables in C.
Uninitialized pointers might cause a segmentation fault.
Conclusion
In conclusion, pointers in C are very capable tools and provide C language with its distinguishing features,
such as low-level memory access, referencing, etc. But as powerful as they are,
they should be used with responsibility as they are one of the most vulnerable parts of the language.
*/

int main(){

    int *ptr; // called as wild pointer





    return 0;
}


/*
    Other Types of Pointers in C:
    There are also the following types of pointers available to use in C apart from those specified above:

    Far pointer: A far pointer is typically 32-bit that can access memory outside the current segment.
    Dangling pointer: A pointer pointing to a memory location that has been deleted (or freed) is called a dangling pointer.
    Huge pointer: A huge pointer is 32-bit long containing segment address and offset address.
    Complex pointer: Pointers with multiple levels of indirection.
    Near pointer: Near pointer is used to store 16-bit addresses means within the current segment on a 16-bit machine.
    Normalized pointer: It is a 32-bit pointer, which has as much of its value in the segment register as possible.
    File Pointer: The pointer to a FILE data type is called a stream pointer or a file pointer.
*/

/*
    Size of Pointers in C
    The size of the pointers in C is equal for every pointer type.
    The size of the pointer does not depend on the type it is pointing to.
    It only depends on the operating system and CPU architecture. The size of pointers in C is 

    8 bytes for a 64-bit System
    4 bytes for a 32-bit System
    The reason for the same size is that the pointers store the memory addresses,
    no matter what type they are. As the space required to store the addresses of the different memory locations is the same,
    the memory required by one pointer type will be equal to the memory required by other pointer types.

    Now, one may wonder that if the size of all the pointers is the same, then why do we need to declare the pointer type in the declaration?
    The type declaration is needed in the pointer for dereferencing and pointer arithmetic purposes.
*/


/*
    Pointer

Array

A pointer is a derived data type that can store the address of other variables.

An array is a homogeneous collection of items of any type such as int, char, etc.

Pointers are allocated at run time.

Arrays are allocated at runtime.

The pointer is a single variable.

An array is a collection of variables of the same type.

Dynamic in Nature

Static in Nature.
*/