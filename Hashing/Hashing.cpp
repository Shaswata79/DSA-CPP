//
// Created by Shaswata on 01-Feb-2024.
//

#include <iostream>
#include "Hashing.h"

HashTable::HashTable() {
    HT = new Node* [10];
    for(int i = 0; i < 10; i++){
        HT[i] = nullptr;
    }
}

int HashTable::hash(int key) {
    return key % 10;
}

void HashTable::insert(int key) {
    int index = hash(key);
    Node* t = new Node();
    t->data = key;
    t->next = nullptr;

    if(HT[index] == nullptr){   // No nodes in the linked list
        HT[index] = t;
    } else{                     // Chaining
        Node* p = HT[index];
        Node* q = HT[index];

        while (p && p->data < key){     // Traverse to find insert position
            q = p;
            p = p->next;
        }

        if(q == HT[index]){     // Insert position is first
            t->next = HT[index];
            HT[index] = t;
        } else{
            t->next = q->next;
            q->next = t;
        }
    }
}

int HashTable::search(int key) {
    int index = hash(key);
    Node* p = HT[index];
    while (p){
        if(p->data == key){
            return p->data;
        }
        p = p->next;
    }
    return -1;
}

HashTable::~HashTable() {
    for(int i = 0; i < 10; i++){
        Node* p = HT[i];
        while(HT[i]){
            HT[i] = HT[i]->next;
            delete p;
            p = HT[i];
        }
    }
    delete [] HT;
}

void HashTable::run() {
    int A[] = {16, 12, 25, 39, 6, 122, 5, 68, 75};
    int n = sizeof(A)/sizeof(A[0]);

    /**
     * Objects on Heap vs Stack
     * HashTable H; --- This creates an object on the stack. When scope ends, object is automatically destroyed.
     * HashTable* H = new HashTable();  --- This creates an object on the heap using "new" keyword. We need to explicitly delete the object using "delete".
     */
    HashTable H;
    for (int i = 0; i < n; i++){
        H.insert(A[i]);
    }

    cout << "Successful Search" << endl;
    int key = 6;
    int value = H.search(key);
    cout << "Key: " << key << ", Value: " << value << endl;
    cout << "Unsuccessful Search" << endl;
    key = 95;
    value = H.search(key);
    cout << "Key: " << key << ", Value: " << value << endl;

}
