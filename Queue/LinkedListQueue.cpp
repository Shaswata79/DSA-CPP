#include <iostream>
#include "LinkedListQueue.h"

LinkedListQueue::LinkedListQueue() {
    head = nullptr;
    tail = nullptr;
}

void LinkedListQueue::enqueue(int x) {
    Node *t = new Node();   // t could be NULL if not enough space on heap
    t->data = x;
    t->next = nullptr;

    if(head == nullptr){
        // If the queue is empty, both head and tail pointers point to the new node
        head = tail = t;
    } else{
        // If the queue is not empty, tail.next points to new node and we update the tail
        tail->next = t;
        tail = t;
    }
}

int LinkedListQueue::dequeue() {
    int x = -1;
    Node *t = new Node();

    if(head == nullptr){
        std::cout << "Queue is empty!" << std::endl;
    }else{
        x = head->data;
        t = head;   // node we will delete
        head = head->next;
        delete t;
    }

    return x;
}

bool LinkedListQueue::isEmpty() {
    if (head == nullptr){
        return true;
    }
    return false;
}

void LinkedListQueue::print() {
    Node *t = head;
    while (t != nullptr){
        std::cout << t->data << std::flush;
        t = t->next;
        if (t != nullptr){
            std::cout << " <- " << std::flush;
        }
    }
    std::cout << std::endl;
}

void LinkedListQueue::run() {
    LinkedListQueue *q = new LinkedListQueue();

    q->enqueue(10);
    q->enqueue(20);
    q->enqueue(30);
    q->enqueue(40);

    q->print();

    int x = q->dequeue();
    std::cout << "Removed number: " << x << std::endl;

    q->print();

}
