# include<stdio.h>

/*
	A Global variable in C is a variable that is declared outside the function or a block of code. 
	Its scope is the whole program i.e. we can access the global variable anywhere in the C program after it is declared.

	for accessing global variable in this case, we can use the method mention here.

*/

int x = 50;

int global(){
	
	int x=12;
	{
		extern int x;
		printf("%d\n",x);
	}
		printf("%d\n",x);
	
	return 0;
}

/*

	3. Static Variables in C

	A static variable in C is a variable that is defined using the static keyword. It can be defined only once in a C program and its scope depends upon the region where it is declared (can be global or local).
	The default value of static variables is zero.
*/


int x;

void autoStorageClass()
{

	printf("\nDemonstrating auto class\n\n");

	// declaring an auto variable (simply
	// writing "int a=32;" works as well)
	auto int a = 32;

	// printing the auto variable 'a'
	printf("Value of the variable 'a'"
		" declared as auto: %d\n",
		a);

	printf("--------------------------------");
}

void registerStorageClass()
{

	printf("\nDemonstrating register class\n\n");

	// declaring a register variable
	register char b = 'G';

	// printing the register variable 'b'
	printf("Value of the variable 'b'"
		" declared as register: %d\n",
		b);

	printf("--------------------------------");
}

void externStorageClass()
{

	printf("\nDemonstrating extern class\n\n");

	// telling the compiler that the variable
	// x is an extern variable and has been
	// defined elsewhere (above the main
	// function)
	extern int x;

	// printing the extern variables 'x'
	printf("Value of the variable 'x'"
		" declared as extern: %d\n",
		x);

	// value of extern variable x modified
	x = 2;

	// printing the modified values of
	// extern variables 'x'
	printf("Modified value of the variable 'x'"
		" declared as extern: %d\n",
		x);

	printf("--------------------------------");
}

void staticStorageClass()
{
	int i = 0;

	printf("\nDemonstrating static class\n\n");

	// using a static variable 'y'
	printf("Declaring 'y' as static inside the loop.\n"
		"But this declaration will occur only"
		" once as 'y' is static.\n"
		"If not, then every time the value of 'y' "
		"will be the declared value 5"
		" as in the case of variable 'p'\n");

	printf("\nLoop started:\n");

	for (i = 1; i < 5; i++) {

		// Declaring the static variable 'y'
		static int y = 5;

		// Declare a non-static variable 'p'
		int p = 10;

		// Incrementing the value of y and p by 1
		y++;
		p++;

		// printing value of y at each iteration
		printf("\nThe value of 'y', "
			"declared as static, in %d "
			"iteration is %d\n",
			i, y);

		// printing value of p at each iteration
		printf("The value of non-static variable 'p', "
			"in %d iteration is %d\n",
			i, p);
	}

	printf("\nLoop ended:\n");

	printf("--------------------------------");
}

/*
C Storage Classes are used to describe the features of a variable/function. 
These features basically include the scope, visibility, and lifetime which help us to trace the existence of a particular variable during the runtime of a program.

C language uses 4 storage classes, namely:

storage classes in c
1. auto

	This is the default storage class for all the variables declared inside a function or a block. 
	Hence, the keyword auto is rarely used while writing programs in C language.
	Auto variables can be only accessed within the block/function they have been declared and not outside them (which defines their scope). 
	Of course, these can be accessed within nested blocks within the parent block/function in which the auto variable was declared.

	However, they can be accessed outside their scope as well using the concept of pointers given here by pointing to the very exact memory location 
	where the variables reside. They are assigned a garbage value by default whenever they are declared.  

2. extern

	Extern storage class simply tells us that the variable is defined elsewhere and not within the same block where it is used. 
	Basically, the value is assigned to it in a different block and this can be overwritten/changed in a different block as well. 
	So an extern variable is nothing but a global variable initialized with a legal value where it is declared in order to be used elsewhere. 
	It can be accessed within any function/block.

	Also, a normal global variable can be made extern as well by placing the ‘extern’ keyword before its declaration/definition in any function/block. 
	This basically signifies that we are not initializing a new variable but instead, we are using/accessing the global variable only. The main purpose of using extern variables is that they can be accessed between two different files 
	which are part of a large program.

3. static

	This storage class is used to declare static variables which are popularly used while writing programs in C language. 
	Static variables have the property of preserving their value even after they are out of their scope! Hence, static variables preserve the value of their 
	last use in their scope. So we can say that they are initialized only once and exist till the termination of the program. Thus, no new memory is allocated 
	because they are not re-declared.

	Their scope is local to the function to which they were defined. 
	Global static variables can be accessed anywhere in the program. 
	By default, they are assigned the value 0 by the compiler. 

4. register

	This storage class declares register variables that have the same functionality as that of the auto variables. 
	The only difference is that the compiler tries to store these variables in the register of the microprocessor if a free register is available. 

	This makes the use of register variables to be much faster than that of the variables stored in the memory during the runtime of the program.

	If a free registration is not available, these are then stored in the memory only. Usually, 
	a few variables which are to be accessed very frequently in a program are declared with the register keyword which improves the running time of the program. 
	An important and interesting point to be noted here is that we cannot obtain the address of a register variable using pointers. 
	Syntax

*/

// defining constant using #define

/*
	Preprocessor

	We can also define a constant in C using #define preprocessor. T
	The constant defined using #define are macros that behaves like a constant. These constants are not handled by the compiler, 
	they are handled by the preprocessor and 
	are replaced by their value before complication.
*/

#define pi = 3.14;

/*
	Yes, we can take advantage of the loophole created by 
	pointers to change the value of a variable declared as a constant in C. 

*/

void loophole(){

	const int number = 15;

	printf("Before change %d \n",number);

	//int*ptr = &number;

	//*ptr = 21;

	printf("After change %d\n",number);

}

/*
	Pointer to constant

	We can change the pointer to point to any other integer variable,
	but cannot change the value of the object (entity) pointed using pointer ptr. 
	he pointer is stored in the read-write area (stack in the present case). The object pointed may be in the read-only or read-write area.
*/

/*
	Below you can not change the value of sample_num via ptr1
	However, you can change the address that ptr1 points
*/

int sample_num=15;
int sample_number=19;

// pointer to constant
const int* ptr1 = &sample_num;

// or
int const* ptr2= &sample_num;

// invalid
*ptr1 = 100; 

// valid
ptr1 = &sample_number;

// constant pointer to variable
int* const ptr = &sample_num;

// invalid
ptr = &sample_number;

// valid
*ptr = 100;

// constant pointer to constant

const int* const ptr3 = &sample_num;

/*	
	The above declaration is a constant pointer to a constant variable which means 
	we cannot change the value pointed
	by the pointer as well as we cannot point the pointer to other variables
*/





int main()
{
	pointer_to_constant();

	printf("A program to demonstrate"
		" Storage Classes in C\n\n");

	// To demonstrate auto Storage Class
	autoStorageClass();

	// To demonstrate register Storage Class
	registerStorageClass();

	// To demonstrate extern Storage Class
	externStorageClass();

	// To demonstrate static Storage Class
	staticStorageClass();

	// exiting
	printf("\n\nStorage Classes demonstrated");

	return 0;
}


/*
	Advantages of const Qualifiers in C

The const qualifier in C has the following advantages:

    Improved Code Readability: By marking a variable as const, you indicate to other programmers that its value should not be changed, making your code easier to understand and maintain.
    Enhanced Type Safety: By using const, you can ensure that values are not accidentally modified, reducing the chance of bugs and errors in your code.
    Improved Optimization: Compilers can optimize const variables more effectively, as they know that their values will not change during program execution. This can result in faster and more efficient code.
    Better Memory Usage: By declaring variables as const, you can often avoid having to make a copy of their values, which can reduce memory usage and improve performance.
    Improved Compatibility: By declaring variables as const, you can make your code more compatible with other libraries and APIs that use const variables.
    Improved Reliability: By using const, you can make your code more reliable, as you can ensure that values are not modified unexpectedly, reducing the risk of bugs and errors in your code.
*/

/*
	Summary
Type					Declaration			Pointer Value Change (*ptr = 100)			Pointing Value Change (ptr  = &a)
                                           	

Pointer to Variable		int * ptr						Yes												Yes

Pointer to Constant		const int * ptr
						int const * ptr					No												Yes

Constant Pointer to Variable	int * const ptr			Yes												No

Constant Pointer to Constant	const int * const ptr	No												No
*/


/*
// C program to demonstrate that the pointer to point to
// any other integer variable, but the value of the object
// (entity) pointed can not be changed

#include <stdio.h>

int main(void)
{
	i is stored in read only area
	int const i = 10;
	int j = 20;

	pointer to integer constant. Here i
	is of type "const int", and &i is of
	type "const int *". And p is of type
	"const int", types are matching no issue
	int const* ptr = &i;

	printf("ptr: %d\n", *ptr);

	error 
	*ptr = 100;

	 valid. We call it up qualification. In
	C/C++, the type of "int *" is allowed to up
	qualify to the type "const int *". The type of
	&j is "int *" and is implicitly up qualified by
	the compiler to "const int *" 

	ptr = &j;
	printf("ptr: %d\n", *ptr);

	return 0;
}

*/



/*
// C program to demonstrate the down qualification

#include <stdio.h>

int main(void)
{
	int i = 10;
	int const j = 20;

	 ptr is pointing an integer object 
	int* ptr = &i;

	printf("*ptr: %d\n", *ptr);

	The below assignment is invalid in C++, results in
	error In C, the compiler *may* throw a warning, but
	casting is implicitly allowed
	ptr = &j;

	In C++, it is called 'down qualification'. The type
	of expression &j is "const int *" and the type of ptr
	is "int *". The assignment "ptr = &j" causes to
	implicitly remove const-ness from the expression &j.
	C++ being more type restrictive, will not allow
	implicit down qualification. However, C++ allows
	implicit up qualification. The reason being, const
	qualified identifiers are bound to be placed in
	read-only memory (but not always). If C++ allows
	above kind of assignment (ptr = &j), we can use 'ptr'
	to modify value of j which is in read-only memory.
	The consequences are implementation dependent, the
	program may fail
	at runtime. So strict type checking helps clean code.

	printf("*ptr: %d\n", *ptr);

	return 0;
}


*/


// To restrict access to the current file only global variables can be marked as static

