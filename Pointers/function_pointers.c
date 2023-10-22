#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// as a normal function
void fun(int a){
    printf("The value of variable : %d\n",a);
}

/*
    Why do we need an extra bracket around function pointers like fun_ptr in above example?
    If we remove bracket, then the expression “void (*fun_ptr)(int)” becomes “void *fun_ptr(int)” 
    which is declaration of a function that returns void pointer.
*/

/*
    Following are some interesting facts about function pointers.

 
1) Unlike normal pointers, a function pointer points to code, not data. Typically a function pointer stores the start of executable code.

2) Unlike normal pointers, we do not allocate de-allocate memory using function pointers.

 
3) A function’s name can also be used to get functions’ address. For example, in the below program, 
we have removed address operator ‘&’ in assignment. We have also changed function call by removing *, the program still works.

4) Like normal pointers, we can have an array of function pointers.

5) Function pointer can be used in place of switch case. 

6) Like normal data pointers, a function pointer can be passed as an argument and can also be returned from a function.
For example, consider the following C program where wrapper() receives a void fun() as parameter and calls the passed function.

*/

// Two simple functions 
void fun1() { printf("Fun1\n"); } 
void fun2() { printf("Fun2\n"); } 

// A function that receives a simple function 
// as parameter and calls the function 
void wrapper(void (*fun)()) 
{ 
    fun(); 
} 

/*
    This point in particular is very useful in C. 
    In C, we can use function pointers to avoid code redundancy. 
    For example a simple qsort() function can be used to sort arrays in ascending order or descending or by any other order in case of array of structures. 
    Not only this, with function pointers and void pointers, it is possible to use qsort for any data type.
*/

// A sample comparator function that is used 
// for sorting an integer array in ascending order. 
// To sort any array for any other data type and/or 
// criteria, all we need to do is write more compare 
// functions.  And we can use the same qsort() 
int compare1 (const void * a, const void * b) 
{ 
  return ( *(int*)a - *(int*)b ); 
}


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

// A compare function that is used for searching an integer 
// array 
bool compare (const void * a, const void * b) 
{ 
return ( *(int*)a == *(int*)b ); 
} 

// General purpose search() function that can be used 
// for searching an element *x in an array arr[] of 
// arr_size. Note that void pointers are used so that 
// the function can be called by passing a pointer of 
// any type. ele_size is size of an array element 
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

int main(){

    void (*fun_ptr)(int) = &fun; // & can be removed

    (*fun_ptr)(5); 

    fun_ptr(10);  // * removed 


    // fun_ptr_arr is an array of function pointers 
    void (*fun_ptr_arr[])(int, int) = {add, subtract, multiply}; 
    unsigned int ch, a = 15, b = 10; 
  
    printf("Enter Choice: 0 for add, 1 for subtract and 2 "
            "for multiply\n"); 
    scanf("%d", &ch); 
  
    if (ch > 2) return 0; 
  
    (*fun_ptr_arr[ch])(a, b); 

    wrapper(fun1); 
    wrapper(fun2);

    int arr[] = {10, 5, 15, 12, 90, 80}; 
    int n = sizeof(arr)/sizeof(arr[0]), i; 
  
    qsort (arr, n, sizeof(int), compare1); 
  
    for (i=0; i<n; i++) 
        printf ("%d ", arr[i]); 


    int arr[] = {2, 5, 7, 90, 70}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	int x = 7; 
	printf ("Returned index is %d ", search(arr, n, 
							sizeof(int), &x, compare)); 

    return 0;

}

/*
    The above search function can be used for any data type by writing a separate customized compare().
*/

/*
    The above search function can be used for any data type by writing a separate customized compare().
*/


