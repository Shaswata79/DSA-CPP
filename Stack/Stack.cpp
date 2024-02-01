#include <iostream>
#include "Stack.h"

Stack::Stack() {
    top = nullptr;
}

void Stack::push(int x) {
    Node *t = new Node();   // t could be NULL if not enough space on heap
    t->data = x;
    t->next = top;
    top = t;
}

int Stack::pop(){
    int x = -1;
    if(top == nullptr){
        std::cout << "Stack is empty!" << std::endl;
    }else{
        x = top->data;
        Node *t = top;  // this is the node we remove
        top = top->next;
        delete t;
    }
    return x;
}

void Stack::print() {
    Node *p = top;
    while (p != nullptr){
        std::cout << p->data << ", ";
        p = p->next;
    }
    std::cout << std::endl;
}

void Stack::run() {
    Stack *s = new Stack();

    s->push(10);
    s->push(20);
    s->push(30);

    s->print();

    std::cout << s->pop() << std::endl;
}


