#include"Deque.h"


int main(){
    
    ArrayDeque dq;
    ArrayDeque *dq_ptr = &dq;
    initialize(dq_ptr);
    addFirst(dq_ptr,12);
    addFirst(dq_ptr,1);
    addLast(dq_ptr,55);
    addFirst(dq_ptr,21);
    
    printf("%d\n\n",pollFirst(dq_ptr));

    printf("%d\n\n",pollLast(dq_ptr));

    printDeque(dq_ptr);
    printDequeReverse(dq_ptr);
}