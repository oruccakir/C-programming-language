#include<stdio.h>
#include "SingleLinkedList.h"




int main(){

    struct SingleLinkedList lis;
    lis.head = NULL;
    lis.size = 0;

    struct SingleLinkedList* list = &lis;

    addFirst(list,8);

    removeFirst(list);

    printList(list);

    printf("%d",list->size);

    /*
    addFirst(list,12);

    addLast(list,9);

    addLast(list,19);

    add(list,8,0);

    removeFirst(list);

    printList(list);

    printf("Size : %d \n",list->size);

    printf("%d",contains(list,12));
    */

    return 0;
}