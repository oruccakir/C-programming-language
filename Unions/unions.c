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



// C program to illustrate differences 
// between structure and Union 

#include <stdio.h> 
#include <string.h> 

// declaring structure 
struct struct_example { 
	int integer; 
	float decimal; 
	char name[20]; 
}; 

// declaring union 

union union_example { 
	int integer; 
	float decimal; 
	char name[20]; 
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


    // creating variable for structure 
	// and initializing values difference 
	// six 
	struct struct_example s = { 18, 38, "geeksforgeeks" }; 

	// creating variable for union 
	// and initializing values 
	union union_example u = { 18, 38, "geeksforgeeks" }; 

	printf("structure data:\n integer: %d\n"
		"decimal: %.2f\n name: %s\n", 
		s.integer, s.decimal, s.name); 
	printf("\nunion data:\n integer: %d\n"
		"decimal: %.2f\n name: %s\n", 
		u.integer, u.decimal, u.name); 

	// difference two and three 
	printf("\nsizeof structure : %d\n", sizeof(s)); 
	printf("sizeof union : %d\n", sizeof(u)); 

	// difference five 
	printf("\n Accessing all members at a time:"); 
	s.integer = 183; 
	s.decimal = 90; 
	strcpy(s.name, "geeksforgeeks"); 

	printf("structure data:\n integer: %d\n "
		"decimal: %.2f\n name: %s\n", 
		s.integer, s.decimal, s.name); 

	u.integer = 183; 
	u.decimal = 90; 
	strcpy(u.name, "geeksforgeeks"); 

	printf("\nunion data:\n integer: %d\n "
		"decimal: %.2f\n name: %s\n", 
		u.integer, u.decimal, u.name); 

	printf("\n Accessing one member at time:"); 

	printf("\nstructure data:"); 
	s.integer = 240; 
	printf("\ninteger: %d", s.integer); 

	s.decimal = 120; 
	printf("\ndecimal: %f", s.decimal); 

	strcpy(s.name, "C programming"); 
	printf("\nname: %s\n", s.name); 

	printf("\n union data:"); 
	u.integer = 240; 
	printf("\ninteger: %d", u.integer); 

	u.decimal = 120; 
	printf("\ndecimal: %f", u.decimal); 

	strcpy(u.name, "C programming"); 
	printf("\nname: %s\n", u.name); 

	// difference four 
	printf("\nAltering a member value:\n"); 
	s.integer = 1218; 
	printf("structure data:\n integer: %d\n "
		" decimal: %.2f\n name: %s\n", 
		s.integer, s.decimal, s.name); 

	u.integer = 1218; 
	printf("union data:\n integer: %d\n"
		" decimal: %.2f\n name: %s\n", 
		u.integer, u.decimal, u.name); 


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

/*
    Structures in C is a user-defined data type available in C that allows to combining of data items of different kinds. Structures are used to represent a record. 

Defining a structure: To define a structure, you must use the struct statement. The struct statement defines a new data type, with more than or equal to one member. The format of the struct statement is as follows:

   struct [structure name]
   {
       member definition;
       member definition;
       ...
       member definition;
   };
   
   (OR)

   struct [structure name]
   {
       member definition;
       member definition;
       ...
       member definition;
   }structure variable declaration;
Union in C is a special data type available in C that allows storing different data types in the same memory location. You can define a union with many members, but only one member can contain a value at any given time. Unions provide an efficient way of using the same memory location for multiple purposes. 

Defining a Union: To define a union, you must use the union statement in the same way as you did while defining a structure. The union statement defines a new data type with more than one member for your program. The format of the union statement is as follows: 

    union [union name]
    {
       member definition;
       member definition;
       ...
       member definition;
    };
   
    (OR) 

    union [union name]
    {
       member definition;
       member definition;
       ...
       member definition;
    }union variable declaration;
Similarities Between Structure and Union
Both are user-defined data types used to store data of different types as a single unit.
Their members can be objects of any type, including other structures and unions or arrays. A member can also consist of a bit field.
Both structures and unions support only assignment = and sizeof operators. The two structures or unions in the assignment must have the same members and member types.
A structure or a union can be passed by value to functions and returned by value by functions. The argument must have the same type as the function parameter. A structure or union is passed by value just like a scalar variable as a corresponding parameter.
‘.’ operator or selection operator, which has one of the highest precedences, is used for accessing member variables inside both the user-defined datatypes.
*/

/*  
    Note: Structures are better than unions since memory is shared in a union which results in a bit of ambiguity.
    But technically speaking, unions are better in that they help save a lot of memory,
    resulting in the overall advantage over structures in the long run.    
*/

/*
    In C11 standard of C, anonymous Unions and structures were added. 
Anonymous unions/structures are also known as unnamed unions/structures as they don’t have names. Since there is no names, direct objects(or variables) of them are not created and we use them in nested structure or unions. 
Definition is just like that of a normal union just without a name or tag. For example, 

// Anonymous union example
union 
{
   char alpha;
   int num;
};
// Anonymous structure example
struct 
{
   char alpha;
   int num;
};
Since there is no variable and no name, we can directly access members. This accessibility works only inside the scope where the anonymous union is defined. 
Following is a complete working example of anonymous union.
*/

// C Program to demonstrate working of anonymous union

struct Scope {
	// Anonymous union
	union {
		char alpha;
		int num;
	};
};

int m1()
{
	struct Scope x, y;
	x.num = 65;
	y.alpha = 'A';

	// Note that members of union are accessed directly
	printf("y.alpha = %c, x.num = %d", y.alpha, x.num);

	return 0;
}

/*
    Remember that we can only access one member of a union at a time.
    If another member is assigned the previous member will be wiped out from the union.
*/


// C Program to demonstrate working of anonymous struct

struct Scope1
{
	// Anonymous structure
	struct
	{
		char alpha;
		int num;
	};
};

int m1()
{
	struct Scope1 x;
	x.num = 65;
	x.alpha = 'B';

	// Note that members of structure are accessed directly
	printf("x.alpha = %c, x.num = %d", x.alpha, x.num);

	return 0;
}

