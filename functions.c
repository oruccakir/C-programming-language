#include <stdio.h>
#include <stdarg.h>

/*
Variadic functions are functions that can take a variable number of arguments.
In C programming, a variadic function adds flexibility to the program.
It takes one fixed argument and then any number of arguments can be passed.
The variadic function consists of at least one fixed variable and then an ellipsis(…) as the last parameter.

Syntax:

int function_name(data_type variable_name, ...);

Values of the passed arguments can be accessed through the header file named as:

#include <stdarg.h>

<stdarg.h> includes the following methods:
*/



/*
    Methods
	

Description
va_start(va_list ap, argN) 	

This enables access to variadic function arguments.

where *va_list* will be the pointer to the last fixed argument in the variadic function

*argN* is the last fixed argument in the variadic function. 

From the above variadic function (function_name (data_type variable_name, …);), variable_name is the last fixed argument making it the argN. Whereas *va_list ap* will be a pointer to argN (variable_name)
va_arg(va_list ap, type) 	

This one accesses the next variadic function argument.

*va_list ap* is the same as above i.e a pointer to argN

*type* indicates the data type  the *va_list ap* should expect (double, float, int etc.)
va_copy(va_list dest, va_list src) 	This makes a copy of the variadic function arguments.
va_end(va_list ap) 	This ends the traversal of the variadic function arguments.
*/

int add_numbers(int n,...){

    int sum = 0;

    // declarşng pointer to argument list
    va_list ptr;

    // initializing the pointer to the list pointer
    va_start(ptr,n);

    for(int i=0; i<n; i++)
        sum += va_arg(ptr,int);

    // Ending the list traversal

    return sum;


}

/*
    Note: C and C++ both support call by value as well as call by reference whereas Java doesn’t support call by reference.
*/

int main(){

    printf("Sum %d",add_numbers(3,5,5,3));

    return 0;
}

/*
    New programmers are usually in the search of ways to return multiple values from a function. Unfortunately,
    C and C++ do not allow this directly. But fortunately, with a little bit of clever programming,
    we can easily achieve this. Below are the methods to return multiple values from a function in C:

    By using pointers.
    By using structures.
    By using Arrays.
*/