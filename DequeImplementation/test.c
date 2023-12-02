#include"Deque.h"


int main(){
    
    ArrayDeque dq;
    ArrayDeque *dq_ptr = &dq;
    initialize(dq_ptr);
    int a = 10, b = 20, c = 30;
    addFirst(dq_ptr,a);
    addFirst(dq_ptr,b);
    addLast(dq_ptr,c);
    addFirst(dq_ptr,a);
    
    /*
    printf("%d\n\n",pollFirst(dq_ptr));

    printf("%d\n\n",pollLast(dq_ptr));
    */
    printDeque(dq_ptr);
    printDequeReverse(dq_ptr);
    
}