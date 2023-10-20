#include<stdio.h>
#include "SingleLinkedList.h"




int main(){

    struct SingleLinkedList lis;
    lis.head = NULL;

    struct SingleLinkedList* list = &lis;

    addFirst(list,8);

    addFirst(list,12);

    addLast(list,9);

    addLast(list,19);

    add(list,8,0);

    printList(list);

    printf("Size : %d",list->size);


    return 0;
}