#ifndef DSA_LINKEDLISTQUEUE_H
#define DSA_LINKEDLISTQUEUE_H

#include "Queue.h"
#include "../Node.h"

class LinkedListQueue : public Queue{
private:
    Node *head;
    Node *tail;
public:
    LinkedListQueue();
    void enqueue(int x) override;
    int dequeue() override;
    bool isEmpty() override;
    void print() override;
    static void run();
};


#endif //DSA_LINKEDLISTQUEUE_H
