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

/*
    New programmers are usually in the search of ways to return multiple values from a function. Unfortunately,
    C and C++ do not allow this directly. But fortunately, with a little bit of clever programming,
    we can easily achieve this. Below are the methods to return multiple values from a function in C:

    By using pointers.
    By using structures.
    By using Arrays.
*/

/*
    CALLBACKS IN C

    callbacks are implemented using function pointers

    A callback is any executable code that is passed as an argument to another code,
    which is expected to call back (execute) the argument at a given time.
    In simple language, If a reference of a function is passed to another function as an argument to call it, then it will be called a Callback function.


*/

void A(){
    printf("I am a function A \n");
}

// callback function
void B(void (*ptr)()){
    (*ptr)();
}

void fun(int a){
    printf("Value of a is %d \n",a);
}

int sum(int a,int b){return a+b;}

/*
    Why do we need an extra bracket around function pointers like fun_ptr in above example?
If we remove bracket, then the expression “void (*fun_ptr)(int)” becomes “void *fun_ptr(int)” 
which is declaration of a function that returns void pointer. 
*/

// 1) Unlike normal pointers, a function pointer points to code, not data. 
// Typically a function pointer stores the start of executable code.

// 2) Unlike normal pointers, we do not allocate de-allocate memory using function pointers

// 3) A function’s name can also be used to get functions’ address.
// We have also changed function call by removing *, the program still works

// 4) Like normal pointers, we can have an array of function pointers

// 5) Function pointer can be used in place of switch case. 
//For example, in below program, user is asked for a choice between 0 and 2 to do different tasks.

void add(int a, int b) 
{ 
    printf("Addition is %d\n", a+b); 
} 
void subtract(int a, int b) 
{ 
    printf("Subtraction is %d\n", a-b); 
} 
void multiply(int a, int b) 
{ 
    printf("Multiplication is %d\n", a*b); 
} 

void calculator() 
{ 
    // fun_ptr_arr is an array of function pointers 
    void (*fun_ptr_arr[])(int, int) = {add, subtract, multiply}; 
    unsigned int ch, a = 15, b = 10; 
  
    printf("Enter Choice: 0 for add, 1 for subtract and 2 "
            "for multiply\n"); 
    scanf("%d", &ch); 
  
    if (ch > 2) return; 
  
    (*fun_ptr_arr[ch])(a, b); 
    
} 

/*
6) Like normal data pointers, a function pointer can be passed as an argument and can also be returned from a function.
and it is named as function callbacks
*/

// Two simple functions 
void fun1() { printf("Fun1\n"); } 
void fun2() { printf("Fun2\n"); } 
  
void wrapper(void (*fun)()) 
{ 
    fun(); 
} 

// A sample comparator function that is used 
// for sorting an integer array in ascending order. 
// To sort any array for any other data type and/or 
// criteria, all we need to do is write more compare 
// functions.  And we can use the same qsort() 

int compare (const void * a, const void * b) 
{ 
  return ( *(int*)a - *(int*)b ); 
} 

// import stdlib for sort function
#include<stdlib.h>

// import bool library
#include<stdbool.h>


/*
Similar to qsort(), 
we can write our own functions that can be used for any data type and 
can do different tasks without code redundancy. Below is an example search function that can be used for any data type. 
In fact we can use this search function to find close elements (below a threshold) by writing a customized compare function.
*/

// A compare function that is used for searching an integer 
// array 
bool compareTo (const void * a, const void * b) 
{ 
  return ( *(int*)a == *(int*)b ); 
} 
  
// General purpose search() function that can be used 
// for searching an element *x in an array arr[] of 
// arr_size. Note that void pointers are used so that 
// the function can be called by passing a pointer of 
// any type.  ele_size is size of an array element 
int search(void *arr, int arr_size, int ele_size, void *x, 
           bool compare (const void * , const void *)) 
{ 
    // Since char takes one byte, we can use char pointer 
    // for any type/ To get pointer arithmetic correct, 
    // we need to multiply index with size of an array 
    // element ele_size 
    char *ptr = (char *)arr; 
  
    int i; 
    for (i=0; i<arr_size; i++) 
        if (compare(ptr + i*ele_size, x)) 
           return i; 
  
    // If element not found 
    return -1; 
} 

// The above search function can be used for any data type by writing a separate customized compare()


int main(){

    void (*ptr)() = &A;

    // calling function B and passing
    // address of the function A as argument
    B(ptr);


     // fun_ptr is a pointer to function fun()  
    void (*fun_ptr)(int) = &fun; 
  
    /* The above line is equivalent of following two 
       void (*fun_ptr)(int); 
       fun_ptr = &fun;  
    */
  
    // Invoking fun() using fun_ptr 
    (*fun_ptr)(10); 

    int (*add_ptr)(int,int) = &sum;

    int res = (*add_ptr)(12,15);
    printf("Result : %d\n",res);

    calculator();

    wrapper(fun1); 
    wrapper(fun2); 

    int arr[] = {10, 5, 15, 12, 90, 80}; 
    int n = sizeof(arr)/sizeof(arr[0]), i; 

    qsort (arr, n, sizeof(int), compare); 

    for (i=0; i<n; i++) 
	    printf ("%d ", arr[i]); 

    printf("\n");

    int arr1[] = {2, 5, 7, 90, 70}; 
	n = sizeof(arr1)/sizeof(arr1[0]); 
	int x = 7; 
	printf ("Returned index is %d \n", search(arr1, n, 
							sizeof(int), &x, compareTo));


    printf("%s \n",__func__);

    printf("In file:%s, function:%s() and line:%d\n",
                   __FILE__, __func__, __LINE__);

    return 0;
}


/*
The _Noreturn keyword appears in a function declaration and specifies that the function does not return by executing the return statement or by reaching the end of the function body. 
If the function declared _Noreturn returns, the behavior is undefined. A compiler diagnostic is recommended if this can be detected.

The _Noreturn specifier may appear more than once in the same function declaration, the behavior is the same as if it appeared once.

This specifier is typically used through the convenience macro noreturn, which is provided in the header stdnoreturn.h.
*/

/*
    Predefined identifier __func__
    The identifier __func__ shall be implicitly declared by the translator as if, 
    immediately following the opening brace of each function definition, the declaration

    static const char __func__[] = "function-name";

    appeared, where function-name is the name of the lexically-enclosing function.”

    It means that the C compiler implicitly adds __func__ in every function so that it can be used in that function to get the function name.
*/


/*
    The math.h header defines various C mathematical functions and one macro. 
    All the functions available in this library take double as an argument and return double as the result. 
*/
#include<math.h>