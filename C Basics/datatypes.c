#include<stdio.h>
//#include<stdbool.h> // we include this because in stdio.h there is no bool dataype

// without importing stdbool file we can create bool datatype
// using typedef and enumeration

//typedef enum {false,true} bool;

// another way is to use Define to Declare Boolean Values

#define bool int
#define false 0
#define true 1


/*
    Types
	

Description
Primitive Data Types :
    Primitive data types are the most basic data types that are used for representing simple values such as integers, float, characters, etc.

User Defined Data Types	:
    The user-defined data types are defined by the user himself.

Derived Types :
    The data types that are derived from the primitive or built-in datatypes are referred to as Derived Data Types.
*/

int main(){

    bool flag = true;

    printf("%d \n",flag);

    return 0;
}


/*
Some data types like char , short int take less number of bytes than int, these data types are automatically promoted to int or unsigned int when an operation is performed on them. 
This is called integer promotion. For example no arithmetic calculation happens on smaller types like char, short and enum. They are first converted to int or unsigned int, 
and then arithmetic is done on them. If an int can represent all values of the original type, the value is converted to an int . 
Otherwise, it is converted to an unsigned int. 
*/

/*
As already known character range is between -128 to 127 or 0 to 255. This point has to be kept in mind while doing character arithmetic. 

What is Character arithmetic ?

Character arithmetic is used to implement arithmetic operations like addition, subtraction ,multiplication ,division on characters in C and C++ language. 
In character arithmetic character converts into integer value to perform task. For this ASCII value is used.
It is used to perform action the strings.
*/



/*
    Advantages of Type Conversion

    Type safety: Type conversions can be used to ensure that data is being stored and processed in the correct data type, avoiding potential type mismatches and type errors.
    Improved code readability: By explicitly converting data between different types, you can make the intent of your code clearer and easier to understand.
    Improved performance: In some cases, type conversions can be used to optimize the performance of your code by converting data to a more efficient data type for processing.
    Improved compatibility: Type conversions can be used to convert data between different types that are not compatible, allowing you to write code that is compatible with a wider range of APIs and libraries.
    Improved data manipulation: Type conversions can be used to manipulate data in various ways, such as converting an integer to a string, converting a string to an integer, or converting a floating-point number to an integer.
    Improved data storage: Type conversions can be used to store data in a more compact form, such as converting a large integer value to a smaller integer type, or converting a large floating-point value to a smaller floating-point type.

 Disadvantages of type conversions in C programming:

    Loss of precision: Converting data from a larger data type to a smaller data type can result in loss of precision, as some of the data may be truncated.
    Overflow or underflow: Converting data from a smaller data type to a larger data type can result in overflow or underflow if the value being converted is too large or too small for the new data type.
    Unexpected behavior: Type conversions can lead to unexpected behavior, such as when converting between signed and unsigned integer types, or when converting between floating-point and integer types.
    Confusing syntax: Type conversions can have confusing syntax, particularly when using typecast operators or type conversion functions, making the code more difficult to read and understand.
    Increased complexity: Type conversions can increase the complexity of your code, making it harder to debug and maintain.
    Slower performance: Type conversions can sometimes result in slower performance, particularly when converting data between complex data types, such as between structures and arrays.
*/