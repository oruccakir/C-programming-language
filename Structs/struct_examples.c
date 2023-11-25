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


char man_names[5][50] = {"Smith","Jack","Oruç","Mehmet","Orhan"};
char girl_names[4][50] = {"Ayşe","Jennifer","Ayla","Safiye"};


typedef struct Person Person;

struct Person{

    char name[50];
    int age;
    char gender[50];

    struct Person* father;
    struct Person* mother;
    struct Person* child;

};


void printPerson(Person *person){

    printf("Name : %s\n",person->name);
    printf("Age : %d\n",person->age);
    printf("Gender : %s\n",person->gender);
    if(person->father != NULL)
        printf("Father : %s\n",person->father->name);
    if(person->mother != NULL)
        printf("Father : %s\n",person->mother->name);
    if(person->child != NULL)
        printf("Child : %s\n",person->child->name);

    printf("\n");
}

void createPerson(Person *person, char name[],int age,char *gender,Person *father,Person *mother,Person *child){
    person->age = age;
    strcpy(person->name,name);
    strcpy(person->gender,gender);
    person->father = father;
    person->mother = mother;
    person->child = child;
}

/*
You can use a structure to pass an array by value.
• To do so, create a structure with the array as a member.
• Structures are passed by value, so the array is passed by value

VERY IMPORTANT POINT
*/

int main(){

    Person father;
    Person *father_ptr = &father;
    char name[50] = "Smith";
    char gender[50] = "Man";
    createPerson(father_ptr,name,48,gender,NULL,NULL,NULL);
    printPerson(father_ptr);

    Person mother;
    Person *mother_ptr = &mother;
    char name1[50] = "Jennifer";
    char gender1[50] = "Girl";
    createPerson(mother_ptr,name1,47,gender1,NULL,NULL,NULL);
    printPerson(mother_ptr);


    return 0;
}