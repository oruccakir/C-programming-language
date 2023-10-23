#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
    In C, we can specify the size (in bits) of the structure and union members.
    The idea of bit-field is to use memory efficiently when we know that the value of a field or group of fields will never exceed a limit or is within a small range.
    C Bit fields are used when the storage of our program is limited.

Need of Bit Fields in C
Reduces memory consumption.
To make our program more efficient and flexible.
Easy to Implement.
Declaration of C Bit Fields
Bit-fields are variables that are defined using a predefined width or size. Format and the declaration of the bit-fields in C are shown below:

Syntax of C Bit Fields
struct
{
    data_type member_name : width_of_bit-field;
};
where,

data_type: It is an integer type that determines the bit-field value which is to be interpreted. The type may be int, signed int, or unsigned int.
member_name: The member name is the name of the bit field.
width_of_bit-field: The number of bits in the bit-field. The width must be less than or equal to the bit width of the specified type.
Applications of C Bit Fields
If storage is limited, we can go for bit-field.
When devices transmit status or information encoded into multiple bits for this type of situation bit-field is most efficient.
Encryption routines need to access the bits within a byte in that situation bit-field is quite useful.
*/

// C program to demonstrate use of Bit-fields
#include <stdio.h>

// Space optimized representation of the date
struct date {
	// d has value between 0 and 31, so 5 bits
	// are sufficient
	int d : 5;

	// m has value between 0 and 15, so 4 bits
	// are sufficient
	int m : 4;

	int y;
};

int main()
{
	printf("Size of date is %lu bytes\n",
		sizeof(struct date));
	struct date dt = { 31, 12, 2014 };
	printf("Date is %d/%d/%d", dt.d, dt.m, dt.y);
	return 0;
}
