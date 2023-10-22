#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
    The Union is a user-defined data type in C language that can contain elements of the different data types just like structure.
    But unlike structures, all the members in the C union are stored in the same memory location.
    Due to this, only one member can store data at the given instance.
*/

/*  
    The syntax of the union in C can be divided into three steps which are as follows:

C Union Declaration
In this part, we only declare the template of the union, i.e., we only declare the members’ names and data types along with the name of the union.
No memory is allocated to the union in the declaration.

union union_name {
    datatype member1;
    datatype member2;
    ...
};
Keep in mind that we have to always end the union declaration with a semi-colon.
*/

/*
    Different Ways to Define a Union Variable
We need to define a variable of the union type to start using union members. There are two methods using which we can define a union variable.

With Union Declaration
After Union Declaration
1. Defining Union Variable with Declaration
union union_name {
    datatype member1;
    datatype member2;
    ...
} var1, var2, ...;
2. Defining Union Variable after Declaration
union union_name var1, var2, var3...;
where union_name is the name of an already declared union.
*/

/*
    The initialization of a union is the initialization of its members by simply assigning the value to it.

var1.member1 = some_value;
One important thing to note here is that only one member can contain some value at a given instance of time.
*/

// union template or declaration
union un {
    int member1;
    char member2;
    float member3;
};
 
// declaring multiple unions
union test1 {
    int x;
    int y;
} Test1;
 
union test2 {
    int x;
    char y;
} Test2;
 
union test3 {
    int arr[10];
    char y;
} Test3;


/*
    2. Can we store data in multiple union members at the same time?
No. We can only store data in a single member at the same time. For example in the following C program, both x and y share the same location.
If we change x, we can see the changes being reflected in y. 
*/

// Declaration of union is same as structures
union test {
    int x, y;
};

int main(){

    // defining a union variable
    union un var1;
 
    // initializing the union member
    var1.member1 = 15;
 
    printf("The value stored in member1 = %d\n",
           var1.member1);
    

    // finding size using sizeof() operator
    int size1 = sizeof(Test1);
    int size2 = sizeof(Test2);
    int size3 = sizeof(Test3);
 
    printf("Sizeof test1: %d\n", size1);
    printf("Sizeof test2: %d\n", size2);
    printf("Sizeof test3: %d", size3);


    // A union variable t
    union test t;
 
    t.x = 2; // t.y also gets value 2
    printf("After making x = 2:\n x = %d, y = %d\n\n", t.x,
           t.y);
 
    t.y = 10; // t.x is also updated to 10
    printf("After making y = 10:\n x = %d, y = %d\n\n", t.x,
           t.y);


    return 0;
}

/*
    Difference between C Structure and C Union
The following table lists the key difference between the structure and union in C:

Structure	Union
The size of the structure is equal to or greater than the total size of all of its members.	The size of the union is the size of its largest member.
The structure can contain data in multiple members at the same time.	Only one member can contain data at the same time.
It is declared using the struct keyword.	It is declared using the union keyword.
*/