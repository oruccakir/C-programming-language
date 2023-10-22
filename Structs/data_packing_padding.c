#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
    In C, the structures are used as data packs. They don’t provide any data encapsulation or data hiding features.

In this article, we will discuss the property of structure padding in C along with data alignment and structure packing.

Data Alignment in Memory
Every data type in C will have alignment requirements (in fact it is mandated by processor architecture, not by language).
A processor will have processing word length as that of data bus size. On a 32-bit machine, the processing word size will be 4 bytes.

32 bit data bus memory layout
 

Historically memory is byte addressable and arranged sequentially. If the memory is arranged as a single bank of one-byte width,
the processor needs to issue 4 memory read cycles to fetch an integer. It is more economical to read all 4 bytes of an integer in one memory cycle.
To take such advantage, the memory will be arranged as a group of 4 banks as shown in the above figure.

The memory addressing still be sequential. If bank 0 occupies an address X, bank 1, bank 2 and bank 3 will be at (X + 1), (X + 2), and (X + 3) addresses.
If an integer of 4 bytes is allocated on X address (X is a multiple of 4), the processor needs only one memory cycle to read the entire integer. Whereas,
if the integer is allocated at an address other than a multiple of 4, it spans across two rows of the banks as shown in the below figure.
Such an integer requires two memory read cycles to fetch the data.

misalign data in memory
 

A variable’s data alignment deals with the way the data is stored in these banks.
For example, the natural alignment of int on a 32-bit machine is 4 bytes. When a data type is naturally aligned, the CPU fetches it in minimum read cycles.

Similarly, the natural alignment of a short int is 2 bytes. It means a short int can be stored in bank 0 – bank 1 pair or bank 2 – bank 3 pair.
A double requires 8 bytes and occupies two rows in the memory banks. Any misalignment of double will force more than two read cycles to fetch double data.

Note that a double variable will be allocated on an 8-byte boundary on a 32-bit machine and requires two memory read cycles
 On a 64-bit machine, based on a number of banks, a double variable will be allocated on the 8-byte boundary and requires only one memory read cycle.
*/

// C Program to demonstrate the structure packing 
#pragma pack(1) 

// structure A 
typedef struct structa_tag { 
	char c; 
	short int s; 
} structa_t; 

// structure B 
typedef struct structb_tag { 
	short int s; 
	char c; 
	int i; 
} structb_t; 

// structure C 
typedef struct structc_tag { 
	char c; 
	double d; 
	int s; 
} structc_t; 

// structure D 
typedef struct structd_tag { 
	double d; 
	int s; 
	char c; 
} structd_t; 

/*
    In GCC, we can use the following code for structure packing:

#pragma pack(1)
or

struct name {
    ...
}__attribute__((packed));
*/

int main() 
{ 
	printf("sizeof(structa_t) = %lu\n", sizeof(structa_t)); 
	printf("sizeof(structb_t) = %lu\n", sizeof(structb_t)); 
	printf("sizeof(structc_t) = %lu\n", sizeof(structc_t)); 
	printf("sizeof(structd_t) = %lu\n", sizeof(structd_t)); 

	return 0; 
}

