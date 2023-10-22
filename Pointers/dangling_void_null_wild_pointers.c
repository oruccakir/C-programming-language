#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
    Dangling pointer

    A pointer pointing to a memory location that has been deleted (or freed) is called dangling pointer.
    There are three different ways where Pointer acts as dangling pointer
*/

/*
    int *ptr;
   .....
   .....
   {
       int ch;
       ptr = &ch;
   } 
   .....   
   // Here ptr is dangling pointer
*/

int *fun(){

    // x is local variable and goes out of
    // scope after an execution of fun() is
    // over
    static int x = 12;
    return &x;
}


/*
    Void pointer

    Void pointer is a specific pointer type – void * – a pointer that points to some data location in storage,
    which doesn’t have any specific type. Void refers to the type. Basically the type of data that it points to is can be any.
    If we assign address of char data type to void pointer it will become char Pointer,
    if int data type then int pointer and so on. Any pointer type is convertible to a void pointer hence it can point to any value. 

    Important Points

    void pointers cannot be dereferenced. It can however be done using typecasting the void pointer
    Pointer arithmetic is not possible on pointers of void due to lack of concrete value and thus size.
*/

/*
    NULL Pointer

    NULL Pointer is a pointer which is pointing to nothing. In case, if we don’t have address to be assigned to a pointer,
    then we can simply use NULL. 
*/

/*
    Important Points

    NULL vs Uninitialized pointer – An uninitialized pointer stores an undefined value.
    A null pointer stores a defined value, but one that is defined by the environment to not be a valid address for any member or object.
    NULL vs Void Pointer – Null pointer is a value, while void pointer is a type
*/

/*
    Wild pointer

    A pointer that has not been initialized to anything (not even NULL) is known as wild pointer.
    The pointer may be initialized to a non-NULL garbage value that may not be a valid address. 
*/

// Note that the purpose of restrict is to
// show only syntax. It doesn't change anything
// in output (or logic). It is just a way for
// programmer to tell compiler about an
// optimization
void use(int* a, int* b, int* restrict c)
{
    *a += *c;
 
    // Since c is restrict, compiler will
    // not reload value at address c in
    // its assembly code. Therefore generated
    // assembly code is optimized
    *b += *c;
}

int main(){

    int *ptr = (int *)malloc(sizeof(int));
 
    // After below free call, ptr becomes a 
    // dangling pointer
    free(ptr); 
     
    // No more dangling pointer
    ptr = NULL;

    int *p = fun(); // it works because the variable in fun function is static.
                    // If it were local varaible, the code would give error (segmentation fault)

    
    // Not a dangling pointer as it points to static variable.
    printf("%d",*p);

    int x = 4;
    float y = 5.5;
 
    // A void pointer
    void* ptr;
    ptr = &x;
 
    // (int*)ptr - does type casting of void
    // *((int*)ptr) dereferences the typecasted
    // void pointer variable.
    printf("Integer variable is = %d", *((int*)ptr));
 
    // void pointer is now float
    ptr = &y;
    printf("\nFloat variable is = %f", *((float*)ptr));

    int a = 50, b = 60, c = 70;
    use(&a, &b, &c);
    printf("%d %d %d", a, b, c);


    return 0;
}

/*
    In the C programming language (after the C99 standard), a new keyword is introduced known as restrict. 

restrict keyword is mainly used in pointer declarations as a type qualifier for pointers.
It doesn’t add any new functionality. It is only a way for the programmer to inform about an optimization that the compiler can make.
When we use restrict with a pointer ptr, it tells the compiler that ptr is the only way to access the object pointed by it, in other words,
there’s no other pointer pointing to the same object i.e. restrict keyword specifies that a particular pointer argument does not alias any other
 and the compiler doesn’t need to add any additional checks.
If a programmer uses restrict keyword and violates the above condition, the result is undefined behavior.
restrict is not supported by C++. It is a C-only keyword.
*/