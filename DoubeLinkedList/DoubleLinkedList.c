#include<stdio.h>
#include "DoubleLinkedList.h"

int main(){

    struct DoubleLinkedList lis;
    struct DoubleLinkedList* list = &lis;
    list->header = constructor(0);
    list->tailer = constructor(0);
    list->header->next = list->tailer;
    list->tailer->prev = list->header;
    list->size = 0;
    

    addFirst(list,5);
    addFirst(list,7);
    addLast(list,12);
    addLast(list,21);
    add(list,108,1);
    add(list,17,0);


    removeFirst(list);
    removeLast(list);
    delete(list,1);
    delete(list,1);

    removeFirst(list);
    removeLast(list);

    printList(list);
    reversePrintList(list);

    printf("%d",list->size);

    return 0;
}