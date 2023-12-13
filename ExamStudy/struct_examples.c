#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Human{
    char name[50];
    int age;
};

typedef struct Human Human;

void printHumans(Human humans[],int size){

    Human hm1;
    strcpy(hm1.name,"erdem");
    hm1.age=20;
    humans[0] = hm1;

    humans[5].age = 52;


    for(int i=0; i<size; i++){
        printf("Name : %s  ",humans[i].name);
        printf("Age : %d\n",humans[i].age);
    }
    
}

int main(){

    char *names[6] = {"oruç","haile","yasemin","melik","yadigar","hamza"};
    int ages[6] = {21,36,31,25,51,72};
    Human humans[6];
    for(int i=0; i<6; i++){
        strcpy(humans[i].name,names[i]);
        humans[i].age = ages[i];
    }

    printHumans(humans,6);


    return 0;
}