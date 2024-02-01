//
// Created by Shaswata on 30-Jan-2024.
//

#ifndef DSA_HEAP_H
#define DSA_HEAP_H

#include <vector>

void insertMaxHeap(std::vector<int>& heap, int x);
std::vector<int> createMaxHeap(int data[], int n);
void heapify(int data[], int n);

template <class T>
void printArrayOrVector(T& heap);

template <class T>
void heapSort(T& heap);

void runHeapsortExample();
void runHeapExample();

#endif //DSA_HEAP_H
