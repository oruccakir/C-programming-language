#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
    The typedef is a keyword that is used to provide existing data types with a new name.
    The C typedef keyword is used to redefine the name of already existing data types.

When names of datatypes become difficult to use in programs,
typedef is used with user-defined datatypes, which behave similarly to defining an alias for commands.

C typedef Syntax
typedef existing_name alias_name;
After this declaration, we can use the alias_name as if it were the real existing_name in out C program.

Example of typedef in C
typedef long long ll;

*/

/*
    Use of typedef in C
Following are some common uses of the typedef in C programming:

The typedef keyword gives a meaningful name to the existing data type which helps other users to understand the program more easily.
It can be used with structures to increase code readability and we don’t have to type struct repeatedly.
The typedef keyword can also be used with pointers to declare multiple pointers in a single statement.
It can be used with arrays to declare any number of variables.
*/

/*
    1. typedef struct
typedef can also be used with structures in the C programming language.
A new data type can be created and used to define the structure variable.

Example 1: Using typedef to define a name for a structure
*/

// using typedef to define an alias for structure
typedef struct student {
    char name[50];
    char branch[50];
    int ID_no;
} student;

/*
    2. typedef with Pointers
typedef can also be used with pointers as it gives an alias name to the pointers.
Typedef is very efficient while declaring multiple pointers in a single statement
because pointers bind to the right on the simple declaration. 

Example:

typedef int* Int_ptr;
Int_ptr var, var1, var2;
In the above statement var, var1, and var2 are declared as pointers of type int
which helps us to declare multiple numbers of pointers in a single statement. 

Example 2: Using typedef to define a name for pointer type.
*/

typedef int* ptr;

/*
    3. typedef with Array
typedef can also be used with an array to increase their count. 

Example:

typedef int arr[20]
Here, arr is an alias for an array of 20 integer elements.

// it's same as Arr[20], two-Arr[20][23];
arr Arr, two-Arr[23]; 
Example 3: Using typedef to define an alias for Array.
*/

typedef int Arr[4];


/*
    C typedef vs #define
The following are the major difference between the typedef and #define in C:

#define is capable of defining aliases for values as well, for instance, you can define 1 as ONE, 3.14 as PI, etc.
Typedef is limited to giving symbolic names to types only.
Preprocessors interpret #define statements, while the compiler interprets typedef statements.
There should be no semicolon at the end of #define, but a semicolon at the end of typedef.
In contrast with #define, typedef will actually define a new type by copying and pasting the definition values.
*/

int main(){

    student st;
    strcpy(st.name, "Cakir oruc");
    strcpy(st.branch, "Computer Science And Engineering");
    st.ID_no = 108;
 
    printf("Name: %s\n", st.name);
    printf("Branch: %s\n", st.branch);
    printf("ID_no: %d\n", st.ID_no);

    ptr var;
    var = &st.ID_no;
    *var = 20;
 
    printf("Value of var is %d", *var);

    Arr temp = { 10, 20, 30, 40 };
    printf("typedef using an array\n");
 
    for (int i = 0; i < 4; i++) {
        printf("%d ", temp[i]);
    }


    return 0;
}