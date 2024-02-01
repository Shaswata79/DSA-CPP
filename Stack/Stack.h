#ifndef DSA_STACK_H
#define DSA_STACK_H

#include "../Node.h"

class Stack{
private:
    Node *top;
public:
    Stack();
    void push(int x);
    int pop();
    void print();
    static void run();
};


#endif //DSA_STACK_H
