#include<stdio.h>
#include<string.h>

#define MAX 50

/*
    String literals can be assigned with a predefined size.
    But we should always account for one extra space which will be assigned to the null character.
    If we want to store a string of size n then we should always declare a string with a size equal to or greater than n+1.
*/

// IMPORTANT NOTE

/*
    Note: After declaration, if we want to assign some other text to the string,
     we have to assign it one by one or use built-in strcpy() function because the direct assignment of string literal to character arrray is only possible in declration.
*/


/*
    How to Read a String Separated by Whitespaces in C?
We can use multiple methods to read a string separated by spaces in C. The two of the common ones are:

We can use the fgets() function to read a line of string and gets() to read characters from the standard input  (stdin) 
and store them as a C string until a newline character or the End-of-file (EOF) is reached.
We can also scanset characters inside the scanf() function
*/

int main(){

    // Assigning a string literal without size
    char str[] = "oruç";

    // Assigning a string literal with a predefined size
    char str1[50] = "tobbetüüüü";

    // Assigning character by character with size
    char str2[] = { 'G','e','e','k','s','f','o','r','G','e','e','k','s','\0'};

    printf("%s\n",str);

    printf("%d",strlen(str));


    // declaring string
    char str3[50];
       
    // reading string
    scanf("%s",str3);
       
    // print string
    printf("%s",str3);


    char str4[MAX];
 
    // MAX Size if 50 defined
    fgets(str4, MAX, stdin);
 
    printf("String is: \n");
 
    // Displaying Strings using Puts
    puts(str4);


    char str5[20];
 
    // using scanset in scanf
    scanf("%[^\n]s", str5);
 
    // printing read string
    printf("%s", str5);


    char arr[3][10] = {"Geek", 
                     "Geeks", "Geekfor"};
    printf("String array Elements are:\n");
   
    for (int i = 0; i < 3; i++) 
    {
        printf("%s\n", arr[i]);
    }


    char *arr[] = {"Geek", "Geeks", "Geekfor"};
    printf("String array Elements are:\n");
   
    for (int i = 0; i < 3; i++) 
    {
        printf("%s\n", arr[i]);
    }
 

    char dest[50] = "This is an"; 
    char src[50] = " example"; 
  
    printf("dest Before: %s\n", dest); 
  
    // concatenating src at the end of dest 
    strcat(dest, src); 
  
    printf("dest After: %s", dest); 


    char str5[] = "GeeksforGeeks"; 
    char ch = 'e'; 
  
    // Search for the character 'e' in the string 
    // Use the strchr function to find the first occurrence 
    // of 'e' in the string 
    char* result = strchr(str5, ch); 
  
    // Character 'e' is found, calculate the index by 
    // subtracting the result pointer from the str pointer 
    if (result != NULL) { 
        printf("The character '%c' is found at index %ld\n", 
               ch, result - str5); 
    } 
    else { 
        printf("The character '%c' is not found in the "
               "string\n", 
               ch); 
    }



    char str6[] = "Geeks,for.Geeks"; 
    // Delimiters: space, comma, dot, 
    // exclamation mark 
    const char delimiters[] = ",."; 
  
    // Tokenize the string 
    char* token = strtok(str6, delimiters); 
    while (token != NULL) { 
        printf("Token: %s\n", token); 
        token = strtok(NULL, delimiters); 
    } 
    
    


    return 0;
}

/*
    In C we can use an Array of pointers. Instead of having a 2-Dimensional character array, 
    we can have a single-dimensional array of Pointers. 
    Here pointer to the first character of the string literal is stored.
*/

/*
    You can see in the above program that the string can also be read using a single scanf statement. 
    Also, you might be thinking that why we have not used the ‘&’ sign with the string name ‘str’ in scanf statement!
     To understand this you will have to recall your knowledge of scanf. 
We know that the ‘&’ sign is used to provide the address of the variable to the scanf() 
function to store the value read in memory. As str[] is a character array so using str without braces ‘[‘ and ‘]’ will give the base address of this string. 
That’s why we have not used ‘&’ in this case as we are already providing the base address of the string to scanf.
*/


/*
    Function Name	Description
strlen(string_name)	Returns the length of string name.
strcpy(s1, s2)	Copies the contents of string s2 to string s1.
strcmp(str1, str2)	Compares the first string with the second string. If strings are the same it returns 0.
strcat(s1, s2)	Concat s1 string with s2 string and the result is stored in the first string.
strlwr()	Converts string to lowercase.
strupr()	Converts string to uppercase.
strstr(s1, s2)	Find the first occurrence of s2 in s1.
*/

/*
    We have 3 rows and 10 columns specified in our Array of String but because of prespecifying, 
    the size of the array of strings the space consumption is high. So, 
    to avoid high space consumption in our program we can use an Array of Pointers in C.
*/

/*
    Invalid Operations in Arrays of Strings 
We can’t directly change or assign the values to an array of strings in C.

    char arr[3][10] = {"Geek", "Geeks", "Geekfor"};

    Here, arr[0] = “GFG”; // This will give an Error 
    that says assignment to expression with an array type.

    To change values we can use strcpy() function in C

    strcpy(arr[0],"GFG"); // This will copy the value to the arr[0].

*/


/*
    In C/C++, when a character array is initialized with a double quoted string and array size is not specified, 
    compiler automatically allocates one extra space for string terminator ‘\0’. For example, 
    following program prints 6 as output.

    // size of arr[] is 6 as it is '\0' terminated  
    char arr[] = "geeks"; 
  
    printf("%lu", sizeof(arr)); 


    If array size is specified as 5 in the above program then the program works without any warning/error and prints 5 in C, 
    but causes compilation error in C++.

    char arr[5] = "geeks";  
    
    printf("%lu", sizeof(arr));


    When character array is initialized with comma separated list of characters and array size is not specified, 
    compiler doesn’t create extra space for string terminator ‘\0’. 
    For example, following program prints 5.

    // arr[] is not terminated with '\0'  
    // and its size is 5  
    char arr[]= {'g', 'e', 'e', 'k', 's'};  
  
    printf("%lu", sizeof(arr)); 

*/

/*
    String Functions in C
Some of the commonly used string functions in C are as follows:

1. strcat() Function
The strcat() function in C is used for string concatenation. It will append a copy of the source string to the end of the destination string.

Syntax

char* strcat(char* dest, const char* src);
The terminating character at the end of dest is replaced by the first character of src.

Parameters

dest: Destination string
src: Source string
Return value

The strcat() function returns a pointer to the dest string.


This function is used for string handling. 
This function appends not more than n characters from the string pointed to by src to the end of the string pointed to by dest plus a terminating Null-character.

Syntax of strncat()

char* strncat(char* dest, const char* src, size_t n);
where n represents the maximum number of characters to be appended. size_t is an unsigned integral type.

2. strlen() Function
The strlen() function calculates the length of a given string. It doesn’t count the null character ‘\0’.

Syntax

int strlen(const char *str);

Parameters

str: It represents the string variable whose length we have to find.
Return Value

strlen() function in C returns the length of the string.


3. strcmp() Function
The strcmp() is a built-in library function in C. This function takes two strings as arguments and compares these two strings lexicographically.

Syntax

int strcmp(const char *str1, const char *str2);
Parameters

str1: This is the first string to be compared.
str2: This is the second string to be compared.
Return Value

If str1 is less than str2, the return value is less than 0.
If str1 is greater than str2, the return value is greater than 0.
If str1 is equal to str2, the return value is 0.


strncmp()

This function lexicographically compares the first n characters from the two null-terminated strings and returns an integer based on the outcome.

Syntax

int strncmp(const char* str1, const char* str2, size_t num);
Where num is the number of characters to compare.

4. strcpy
The strcpy() is a standard library function in C and is used to copy one string to another. In C, it is present in <string.h> header file.

Syntax

char* strcpy(char* dest, const char* src);
Parameters

dest: Pointer to the destination array where the content is to be copied. 
src: string which will be copied.
Return Value

strcpy() function returns a pointer pointing to the output string.

strncpy()

The function strncpy() is similar to strcpy() function, except that at most n bytes of src are copied.

If there is no NULL character among the first n character of src, the string placed in dest will not be NULL-terminated. If the length of src is less than n, strncpy() writes an additional NULL character to dest to ensure that a total of n characters are written.

Syntax

char* strncpy( char* dest, const char* src, size_t n );
Where n is the first n characters to be copied from src to dest

5. strchr()
The strchr() function in C is a predefined function used for string handling. This function is used to find the first occurrence of a character in a string.

Syntax

char *strchr(const char *str, int c);
Parameters

str: specifies the pointer to the null-terminated string to be searched in.
ch: specifies the character to be searched for.
Here, str is the string and ch is the character to be located. It is passed as its int promotion, but it is internally converted back to char.

Return Value

It returns a pointer to the first occurrence of the character in the string.

strrchr() Function

In C, strrchr() function is similar to strchr() function. This function is used to find the last occurrence of a character in a string.

Syntax

char* strchr(const char *str, int ch);



6. strstr()
The strstr() function in C is used to search the first occurrence of a substring in another string.

Syntax

char *strstr (const char *s1, const char *s2);
Parameters

s1: This is the main string to be examined.
s2: This is the sub-string to be searched in the s1 string.
Return Value

If the s2 is found in s1, this function returns a pointer to the first character of the s2 in s1, otherwise, it returns a null pointer.
It returns s1 if s2 points to an empty string.



7. strtok()
The strtok() function is used to split the string into small tokens based on a set of delimiter characters.

Syntax

char * strtok(char* str, const char *delims);
Parameters

str: It is the string to be tokenized.
delims: It is the set of delimiters

*/