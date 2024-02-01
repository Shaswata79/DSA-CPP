#ifndef DSA_LINKEDLIST_H
#define DSA_LINKEDLIST_H

#include "../Node.h"

class LinkedList {

private:
    Node* first;

public:
    LinkedList();
    LinkedList(int A[], int n);     // create LinkedList from array
    ~LinkedList();

    void display();
    void insertNode(int index, int x);
    int deleteNode(int index);
    int length();
    static void run();
};


#endif //DSA_LINKEDLIST_H
