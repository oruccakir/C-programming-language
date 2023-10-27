#include<stdio.h>

/*
    C Storage Classes are used to describe the features of a variable/function. These features basically include the scope, 
    visibility, and lifetime which help us to trace the existence of a particular variable during the runtime of a program
*/

/*
    1. auto
This is the default storage class for all the variables declared inside a function or a block.
Hence, the keyword auto is rarely used while writing programs in C language. Auto variables can be only accessed within the block/function
they have been declared and not outside them (which defines their scope). Of course,
these can be accessed within nested blocks within the parent block/function in which the auto variable was declared.

However, they can be accessed outside their scope as well using the concept of pointers given here by pointing to the very exact memory location where the variables reside.
They are assigned a garbage value by default whenever they are declared
*/

/*
    2. extern
Extern storage class simply tells us that the variable is defined elsewhere and not within the same block where it is used.
Basically, the value is assigned to it in a different block and this can be overwritten/changed in a different block as well.
So an extern variable is nothing but a global variable initialized with a legal value where it is declared in order to be used elsewhere. It can be accessed within any function/block.

Also, a normal global variable can be made extern as well by placing the ‘extern’ keyword before its declaration/definition in any function/block.
This basically signifies that we are not initializing a new variable but instead, we are using/accessing the global variable only. The main purpose of using extern variables is that they can be accessed between two different files which are part of a large program.

*/


/*
    3. static
This storage class is used to declare static variables which are popularly used while writing programs in C language.
Static variables have the property of preserving their value even after they are out of their scope!
Hence, static variables preserve the value of their last use in their scope. So we can say that they are initialized only once and exist till the termination of the program. Thus, no new memory is allocated because they are not re-declared.

Their scope is local to the function to which they were defined.
Global static variables can be accessed anywhere in the program. By default,
they are assigned the value 0 by the compiler. 
*/

/*
    4. register
This storage class declares register variables that have the same functionality as that of the auto variables.
The only difference is that the compiler tries to store these variables in the register of the microprocessor if a free register is available. This makes the use of register variables to be much faster than that of the variables stored in the memory during the runtime of the program.

If a free registration is not available,
these are then stored in the memory only. Usually, a few variables which are to be accessed very frequently in a program are declared with the register keyword which improves the running time of the program. An important and interesting point to be noted here is that we cannot obtain the address of a register variable using pointers
*/

// declaring the variable which is to be made extern 
// an initial value can also be initialized to x 
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

int main() 
{ 

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
    Properties of extern Variable in C
When we write extern some_data_type some_variable_name;  no memory is allocated. Only the property of the variable is announced.
Multiple declarations of extern variable is allowed within the file. This is not the case with automatic variables.
The extern variable says to the compiler  “Go outside my scope and you will find the definition of the variable that I declared.”
The compiler believes that whatever that extern variable said is true and produces no error. Linker throws an error when it finds no such variable exists.
When an extern variable is initialized, then memory for this is allocated and it will be considered defined.
A variable or function can be declared any number of times, but it can be defined only once. (Remember the basic principle that you can’t have two locations of the same variable or function).
Now back to the extern keyword. First, Let’s consider the use of extern in functions. It turns out that when a function is declared or defined, the extern keyword is implicitly assumed. When we write.

int foo(int arg1, char arg2);
The compiler treats it as:

extern int foo(int arg1, char arg2);
Since the extern keyword extends the function’s visibility to the whole program, the function can be used (called) anywhere in any of the files of the whole program, provided those files contain a declaration of the function. (With the declaration of the function in place, the compiler knows the definition of the function exists somewhere else and it goes ahead and compiles the file). So that’s all about extern and functions.
Now let’s consider the use of extern with variables. To begin with, how would you declare a variable without defining it? You would do something like this:

extern int var;
Here, an integer-type variable called var has been declared (it hasn’t been defined yet, so no memory allocation for var so far). And we can do this declaration as many times as we want.
Now, how would you define var? You would do this:

int var = 10;
In this line, an integer type variable called var has been both declared and defined (remember that definition is the superset of declaration).
Since this is a definition, the memory for var is also allocated. Now here comes the surprise. When we declared/defined a function, we saw that the extern keyword was present implicitly.
But this isn’t the case with variables. If it were, memory would never be allocated for them. Therefore,
we need to include the extern keyword explicitly when we want to declare variables without defining them.
Also, as the extern keyword extends the visibility to the whole program, by using the extern keyword with a variable, we can use the variable anywhere in the program provided we include its declaration the variable is defined somewhere.
Now let us try to understand extern with examples.

Example 1:

int var; 
int main(void) 
{ 
   var = 10; 
   return 0; 
} 
This program compiles successfully. var is defined (and declared implicitly) globally.

Example 2: 

extern int var; 
int main(void) 
{ 
  return 0; 
} 
This program compiles successfully. Here var is declared only. Notice var is never used so no problems arise.

Example 3: 

extern int var; 
int main(void) 
{ 
  var = 10; 
  return 0; 
} 
This program throws an error in the compilation(during the linking phase, more info here) because var is declared but not defined anywhere. Essentially, the var isn’t allocated any memory. And the program is trying to change the value to 10 of a variable that doesn’t exist at all.

Example 4: 
// As we are importing the file and henceforth the 
// defination 
#include "somefile.h" 
  
// Declaring the same variable 
extern int var; 
    // int var; 
    // It will throw compiler error as compiler will get 
    // confused where the variable is defined 
  
int main(void) 
{ 
    var = 10; 
    return 0; 
} 
  
// Now it will compile and run successfully
Output:

10
Note: Here arises another scenario what if we do not declare with extern in the above code snippet,?

Considering an assumption that somefile.h contains the definition of var, this program will compile successfully. ‘extern’ keyword is used for a variable when we declare the variable in one file and define it in another file.
But here when we import the same file in the file where it is declared, here compiler error will be generated. 

It is because we still have to use the extern keyword in the file where we have declared that variable so as to tell our compiler that
this variable is been defined somewhere else than only new memory space will not be allocated else it will create another memory block which usage of ‘extern’ keyword useless.

Example 5: 

extern int var = 0; 
int main(void) 
{ 
 var = 10; 
 return 0; 
} 
Do you think this program will work? Well, here comes another surprise from C standards. They say that..if a variable is only declared and an initializer is also provided with that declaration, then the memory for that variable will be allocated–in other words, that variable will be considered as defined. Therefore, as per the C standard, this program will compile successfully and work.
So that was a preliminary look at the extern keyword in C.

In short, we can say:

A declaration can be done any number of times but defined only once.
the extern keyword is used to extend the visibility of variables/functions.
Since functions are visible throughout the program by default, the use of the extern is not needed in function declarations or definitions. Its use is implicit.
When extern is used with a variable, it’s only declared, not defined.
As an exception, when an extern variable is declared with initialization, it is taken as the definition of the variable as well.
*/


/*
    Static Variables in C
Read
Discuss(20+)
Courses
Practice
Static variables have the property of preserving their value even after they are out of their scope! Hence, a static variable preserves its previous value in its previous scope and is not initialized again in the new scope. 

Syntax:

static data_type var_name = var_value;
Following are some interesting facts about static variables in C:

1) A static int variable remains in memory while the program is running. A normal or auto variable is destroyed when a function call where the variable was declared is over. 
For example, we can use static int to count the number of times a function is called, but an auto variable can’t be used for this purpose.

Example


// C Program to illustrate the static variable lifetime
#include <stdio.h>
 
// function with static variable
int fun()
{
    static int count = 0;
    count++;
    return count;
}
 
int main()
{
    printf("%d ", fun());
    printf("%d ", fun());
    return 0;
}
Output
1 2 
The above program prints 1 2 because static variables are only initialized once and live till the end of the program. That is why they can retain their value between multiple function calls.

Let’s try the same code for the local auto variable.

Example


// C Program to illustrate local auto variable in comparison
// of static variable.
#include <stdio.h>
 
// Function
int fun()
{
    int count = 0;
    count++;
    return count;
}
 
// Driver Code
int main()
{
    printf("%d ", fun());
    printf("%d ", fun());
    return 0;
}
Output
1 1 
2) Static variables are allocated memory in the data segment, not the stack segment. See the memory layout of C programs for details.

3) Static variables (like global variables) are initialized as 0 if not initialized explicitly. For example in the below program, the value of x is printed as 0, while the value of y is something garbage. See this for more details. 

Example


// C program to illustrate the default value of static
// variables
#include <stdio.h>
 
int main()
{
    static int x;
    int y;
    printf("%d \n%d", x, y);
}
Output

0 
[some_garbage_value] 
4) In C, static variables can only be initialized using constant literals. For example, the following program fails in the compilation. See this for more details.

Example


#include<stdio.h>
int initializer(void)
{
    return 50;
}
  
int main()
{
    static int i = initializer();
    printf(" value of i = %d", i);
    getchar();
    return 0;
}
Output

In function 'main':
9:5: error: initializer element is not constant
     static int i = initializer();
     ^
Note: Please note that this condition doesn’t hold in C++. So if you save the program as a C++ program, it would compile and run fine.

5) Static global variables and functions are also possible in C/C++. The purpose of these is to limit the scope of a variable or function to a file. Please refer to Static functions in C for more details.

6) Static variables should not be declared inside a structure. The reason is C compiler requires the entire structure elements to be placed together (i.e.) memory allocation for structure members should be contiguous. It is possible to declare structure inside the function (stack segment) or allocate memory dynamically(heap segment) or it can be even global (BSS or data segment). Whatever might be the case, all structure members should reside in the same memory segment because the value for the structure element is fetched by counting the offset of the element from the beginning address of the structure. Separating out one member alone to a data segment defeats the purpose of structure and it is possible to have an entire structure as static.
*/

/*
    In C, functions are global by default. The “static” keyword before a function name makes it static.
*/


/*
    The volatile keyword is intended to prevent the compiler from applying any optimizations on objects that can change in ways that cannot be determined by the compiler. 

Objects declared as volatile are omitted from optimization because their values can be changed by code outside the scope of current code at any time. The system always reads the current value of a volatile object from the memory location rather than keeping its value in a temporary register at the point it is requested, even if a previous instruction asked for the value from the same object. So the simple question is, how can the value of a variable change in such a way that the compiler cannot predict? Consider the following cases for an answer to this question: 

1) Global variables modified by an interrupt service routine outside the scope: For example, a global variable can represent a data port (usually a global pointer, referred to as memory mapped IO) which will be updated dynamically. The code reading the data port must be declared as volatile in order to fetch the latest data available at the port. Failing to declare the variable as volatile will result in the compiler optimizing the code in such a way that it will read the port only once and keep using the same value in a temporary register to speed up the program (speed optimization). In general, an ISR is used to update these data ports when there is an interrupt due to the availability of new data. 

 
2) Global variables within a multi-threaded application: There are multiple ways for threads’ communication, viz., message passing, shared memory, mail boxes, etc. A global variable is weak form of shared memory. When two threads are sharing information via global variables, those variables need to be qualified with volatile. Since threads run asynchronously, any update of global variables due to one thread should be fetched freshly by the other consumer thread. The compiler can read the global variables and place them in temporary variables of the current thread context. To nullify the effect of compiler optimizations, such global variables need to be qualified as volatile.

If we do not use volatile qualifier, the following problems may arise: 
1) Code may not work as expected when optimization is turned on. 
2) Code may not work as expected when interrupts are enabled and used.

Let us see an example to understand how compilers interpret volatile keyword. Consider the below code. We are changing the value of a const object using a pointer and we are compiling code without optimization option. Hence the compiler won’t do any optimization and will change the value of the const object.
*/

