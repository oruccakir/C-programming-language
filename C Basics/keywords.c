#include <stdio.h>

/*
    register

    Register variables tell the compiler to store variables in the CPU register instead of memory.

    Frequently used variables are kept in the CPU registers for faster access. 
*/

/*
    static 

    The static keyword is used to create static variables. 
    A static variable is not limited by a scope and can be used throughout the program. It’s value is preserved even after it’s  scope.

*/

static int num=15;

/*
    struct 

T   he struct keyword in C programming language is used to declare a structure. A structure is a list of variables, 
    (they can be of different data types), which are grouped together under one data type.
*/

struct student{

    char name[20];
    int age;
};


/*
    typedef 

    The typedef keyword in C programming language is used to define a data type with a new name in the program. 
    typedef keyword is used to make our code more readable.
*/

typedef long num;

/*
    The extern keyword is used to declare a variable or a function that has an external linkage outside of the file declaration.
*/

extern int a;

/*
    union 

    The union is a user-defined data type. 
    All data members which are declared under the union keyword share the same memory location.
*/

union book
{
    int year;
    int page;
};

/*
    volatile

    The volatile keyword is used to create volatile objects. 
    Objects which are declared volatile are omitted from optimization as their values can be changed 
    by code outside the scope of the current code at any point in time.

*/

const volatile marks = 98;

/*
    are declared constant so they can’t be changed by the program. But hardware can change it as they are volatile objects.
*/



int main(){

    register char ch = 'c';

    union book bk;

    strcpy(bk.page=500,bk.year=2001);



    return 0;
}


