#include<stdio.h>
#include<string.h>

typedef struct card Card;

/* Equivalent 
typedef struct {
    char *suit;
    char *face;
}   Card;
    Card deck[52];
*/

struct card{
    char *suit;
    char *face;
    int age;

} card1 = {"Heart", "Ace",12},*cardPtr = &card1,deck[52];

/*
You can use a structure to pass an array by value.
• To do so, create a structure with the array as a member.
• Structures are passed by value, so the array is passed by value

VERY IMPORTANT POINT
*/

int main(){

    Card card1;

    
    return 0;
}