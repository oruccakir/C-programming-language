#include<stdio.h> // standard input and output library for c 

/*
	Note that : for char array which means str there is no need to 
	& sign because it is already address there is no need to use & here
*/

/*
	In C programming language, scanf is a function that stands for Scan Formatted String. It is used to read data from stdin 
	(standard input stream i.e. usually keyboard) and then writes the result into the given arguments.

    It accepts character, string, and numeric data from the user using standard input.
    scanf also uses format specifiers like printf.
*/

/*
	%d to accept input of integers.

    %ld to  accept input of long integers

    %lld to accept input of long long integers

    %f to accept input of real number.

    %c to accept input of character types.

    %s to accept input of a string.
*/

int main(){

	
	
	return 0;
}

/*
	Return Value of scanf

The scanf in C returns three types of values:

    >0: The number of values converted and assigned successfully.
      0: No value was assigned.
    <0: Read error encountered or end-of-file(EOF) reached before any assignment was made.

Why &?

While scanning the input, scanf needs to store that input data somewhere. To store this input data, 
scanf needs to known the memory location of a variable. And here comes the ampersand to rescue.

    & is also called as address of the operator.
    For example, &var is the address of var.
*/


/*
	Format Specifier
	

Description

%c
	For b type.

%d
	For signed integer type.

%e or %E
	For scientific notation of floats.

%f
	For float type.

%g or %G
	For float type with the current precision.

%i
	Unsigned integer

%ld or %li
	Long

%lf
	Double

%Lf
	Long double

%lu
	Unsigned int or unsigned long

%lli or %lld
	Long long

%llu
	Unsigned long long

%o
	Octal representation

%p
	Pointer

%s
	String

%u
	Unsigned int

%x or %X
	Hexadecimal representation

%n
	Prints nothing

%%
	Prints % character
*/



/*
	scanf family functions support scanset specifiers which are represented by %[]. 
	Inside scanset, we can specify single character or range of characters. While processing scanset, 
	scanf will process only those characters which are part of scanset. We can define scanset by putting characters inside square brackets. 
	Please note that the scansets are case-sensitive.

We can also use scanset by providing comma in between the character you want to add.

example: scanf(%s[A-Z,_,a,b,c]s,str);

This will scan all the specified character in the scanset.
*/

/*
Let us implement gets() 
function by using scan set. gets() function reads a line from stdin into the buffer pointed to by s until either a terminating newline or EOF found.
*/

/* implementation of gets() function using scanset */

int funct()
{
	char str[128];
	printf("Enter a string with spaces: ");
	scanf("%[^\n]s", str);

	printf("You entered: %s\n", str);

	return 0;
}


/*
	Never use gets(). Because it is impossible to tell without knowing the data in advance how many characters gets() will read, and because gets() will continue to store characters past the end of the buffer, it is extremely dangerous to use. It has been used to break computer security. Use fgets() instead. 
*/


void read()
{
	char str[20];
	gets(str);
	printf("%s", str);
	return;
}

/*
	The code looks simple, it reads string from standard input and prints the entered string, but it suffers from Buffer Overflow as gets() doesn’t do any array bound testing. gets() keeps on reading until it sees a newline character. 
To avoid Buffer Overflow, fgets() should be used instead of gets() as fgets() makes sure that not more than MAX_LIMIT characters are read.
*/

#define MAX_LIMIT 20
void read1()
{
	char str[MAX_LIMIT];
	fgets(str, MAX_LIMIT, stdin);
	printf("%s", str);

	getchar();
	return;
}

/*
	NOTE: fgets() stores the ‘\n’ character if it is read, so removing that has to be done explicitly by the programmer. It is hence, generally advised that your str can store 
	at least (MAX_LIMIT + 1) characters if your intention is to keep the newline character. This is done so there is enough space for the null terminating character ‘\0’ to be added at the end of the string.
*/

/*
	If keeping the newline character is not intended, then one can simply do the following-
*/

/*
int len = strlen(str);

// Remove the '\n' character and replace it with '\0'
str[len - 1] = '\0';
*/

/*
	sprintf stands for “string print”. This function is similar to printf() function 
	but this function prints the string into a character array instead of printing it on the console screen.
*/

int func_sprintf()
{
    char str[50];
    int a = 2, b = 8;
  
    // The string "2 and 8 are even number"
    // is now stored into str
    sprintf(str, "%d and %d are even number",
            a, b);
  
    // Displays the string
    printf("%s", str);
    return 0;
}

/*
	sscanf():

sscanf stands for “string scanf”. 
This function is similar to scanf() function but this function reads data from the string or character array instead of the console screen.
*/

int funct_sscanf()
{
    char str[50];
    int a = 2, b = 8, c, d;
  
    // The string "a = 2 and b = 8"
    // is now stored into str
    // character array
    sprintf(str, "a = %d and b = %d",
            a, b);
  
    // The value of a and b is now in
    // c and d
    sscanf(str, "a = %d and b = %d",
           &c, &d);
  
    // Displays the value of c and d
    printf("c = %d and d = %d", c, d);
    return 0;
}

/*
	Unformatted I/O functions are used only for character data type or character array/string and cannot be used for any other datatype.
	These functions are used to read single input from the user at the console
	and it allows to display the value at the console.

Why they are called unformatted I/O?  

These functions are called unformatted I/O functions because we cannot use format specifiers in these functions and hence, cannot format
these functions according to our needs.

The following unformatted I/O functions will be discussed in this section-

    getch()
    getche()
    getchar()
    putchar()
    gets()
    puts()
    putch()
*/

/*
getch():

getch() function reads a single character from the keyboard by the user but doesn’t display that character on the console screen and
immediately returned without pressing enter key. This function is declared in conio.h(header file). getch() is also used for hold the screen.
*/

/*
Formatted I/O functions                                                                               Unformatted I/O functions                       
1	These functions allow us to take input or display output in the user’s desired format.	           These functions do not allow to take input or display output in user desired format.
2	These functions support format specifiers.	                                                       These functions do not support format specifiers.
3	These are used for storing data more user friendly	                                               These functions are not more user-friendly.
4	Here, we can use all data types.	                                                               Here, we can use only character and string data types.
5	printf(), scanf, sprintf() and sscanf() are examples of these functions.	                       getch(), getche(), gets() and puts(), are some examples of these functions.
*/


/*
	2. To allocate a block of memory dynamically: sizeof is greatly used in dynamic memory allocation.
	For example, if we want to allocate memory that is sufficient to hold 10 integers and we don’t know the sizeof(int) in that particular machine. We can allocate with the help of sizeof. 

Syntax:

int* ptr = (int*)malloc(10 * sizeof(int));
*/