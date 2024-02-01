#ifndef DSA_QUEUE_H
#define DSA_QUEUE_H

class Queue {
public:
    virtual void enqueue(int x) = 0;    // Pure virtual function for enqueue operation
    virtual int dequeue() = 0;          // Pure virtual function for dequeue operation
    virtual bool isEmpty() = 0;         // Pure virtual function to check if the queue is empty
    virtual void print() = 0;       // Pure virtual function to get the current size
};

#endif //DSA_QUEUE_H
