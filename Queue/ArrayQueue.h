#ifndef DSA_ARRAYQUEUE_H
#define DSA_ARRAYQUEUE_H

#include "Queue.h"

class ArrayQueue : public Queue{
private:
    int head;
    int tail;
    int size;
    int *Q;
public:
    ArrayQueue();
    ArrayQueue(int size);
    void enqueue(int x) override;
    int dequeue() override;
    bool isEmpty() override;
    void print() override;
    static void run();
};


#endif //DSA_ARRAYQUEUE_H
