#ifndef DSA_HASHING_H
#define DSA_HASHING_H

#include "../LinkedList/LinkedList.h"
#include "../Node.h"

using namespace std;

class HashTable {
private:
    Node** HT;
public:
    HashTable();
    int hash(int key);
    void insert(int key);
    int search(int key);
    ~HashTable();

    static void run();
};


#endif //DSA_HASHING_H
