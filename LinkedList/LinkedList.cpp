#include <iostream>
#include "LinkedList.h"

/*
* Default constructor
*/
LinkedList::LinkedList() {
    first = NULL;
}

/*
* Create linked list from array
*/
LinkedList::LinkedList(int A[], int n) {
    Node *last, *t;
    int i = 0;

    first = new Node();
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++) {
        t = new Node();
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }

}

/*
* Destructor
*/
LinkedList::~LinkedList() {
    Node* p = first;
    while (first) {
        first = first->next;
        delete p;
        p = first;
    }
}

/*
* Display linked list
*/
void LinkedList::display() {
    Node* p = first;
    while (p) {
        std::cout << p->data << "->";
        p = p->next;
    }
    std::cout << std::endl;
}

/*
* Get length of linked list
*/
int LinkedList::length() {
    Node* p = first;
    int len = 0;

    while (p) {
        len++;
        p = p->next;
    }
    return len;
}

/*
* Insert node at given index
*/
void LinkedList::insertNode(int index, int x) {
    Node *t, *p = first;
    if (index < 0 || index > length()) {
        return;
    }
    t = new Node();
    t->data = x;
    t->next = NULL;

    if (index == 0) {   // insert as first node
        t->next = first;
        first = t;
    }
    else {              // insert at specific index besides first
        for (int i = 0; i < index - 1; i++) {   // go to correct index
            p = p->next;
        }
        // insert t between p and p->next
        t->next = p->next;
        p->next = t;
    }
}

/*
* Delete node at index and return value
*/
int LinkedList::deleteNode(int index) {
    Node *p, *q = NULL;
    int x = -1;

    if (index < 0 || index > length()-1) {
        return -1;
    }
    if (index == 1) {   // delete first node
        p = first;
        first = first->next;
        x = p->data;
        delete p;
    }
    else {      // delete node at specific index besides first
        p = first;
        for (int i = 0; i < index; i++) {   // go to correct index
            q = p;
            p = p->next;
        }
        // q is pointing to the node before the target node (p), q -> p -> p.next, we delete p
        q->next = p->next;
        x = p->data;
        delete p;
    }
    return x;
}

void LinkedList::run()
{
    int a[] = { 1, 2, 3, 4, 5 };

    //static memory allocation
    //LinkedList l(a, 5);

    //dynamic memory allocation
    LinkedList *l = new LinkedList(a, 5);

    l->display();

    l->insertNode(3, 10);
    l->display();

    int val = l->deleteNode(3);
    std::cout << "Deleted node: " << val << std::endl;
    l->display();

}


