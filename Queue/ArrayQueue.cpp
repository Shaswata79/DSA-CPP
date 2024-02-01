#include <iostream>
#include "ArrayQueue.h"

ArrayQueue::ArrayQueue() {
    this->head = this->tail = -1;
    this->size = 10;  // default size;
    this->Q = new int[this->size];
}

ArrayQueue::ArrayQueue(int size) {
    this->head = tail = -1;
    this->size = size;  // default size;
    this->Q = new int[this->size];
}

void ArrayQueue::enqueue(int x) {
    if(tail == size-1){
        std::cout << "ArrayQueue is full!" << std::endl;
    }else{
        tail++;
        Q[tail] = x;
    }
}

bool ArrayQueue::isEmpty() {
    if(head == tail){
        return true;
    }
    return false;
}

int ArrayQueue::dequeue() {
    int x = -1;
    if(head == tail){
        std::cout << "ArrayQueue is empty!" << std::endl;
    }else{
        x = Q[head+1];
        head++;
    }
    return x;
}

void ArrayQueue::print() {
    for(int i = head+1; i <= tail; i++){
        std::cout << Q[i] << ", ";
    }
    std::cout << std::endl;
}

void ArrayQueue::run() {
    ArrayQueue *q = new ArrayQueue(10);

    q->enqueue(10);
    q->enqueue(20);
    q->enqueue(30);

    q->print();

    std::cout << q->dequeue() << std::endl;
}
