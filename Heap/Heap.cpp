#include <iostream>
#include <vector>

void insertMaxHeap(std::vector<int>& heap, int x) {
    auto i = heap.size();
    heap.push_back(x);

    // Re-arrange elements
    // while current value is greater than parent, continue re-arranging
    // parent of element i is either at (i/2) or (i/2)-1
    while (i > 0 && x > heap[i%2 == 0 ? (i/2)-1 : (i/2)]){
        heap[i] = heap[i%2 == 0 ? (i/2)-1 : (i/2)];
        i = i%2 == 0 ? (i/2)-1 : (i/2);
    }
    heap[i] = x;
}


std::vector<int> createMaxHeap(int data[], int n) {
    std::vector<int> heap;
    for (int i=0; i<n; i++){
        insertMaxHeap(heap, data[i]);
    }
    return heap;
}

template <class T>
void printArrayOrVector(T& heap) {
    for (const auto& element : heap) {
        std::cout << element << ", ";
    }
    std::cout << std::endl;
}

void swap(int A[], int i, int j){
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void heapify(int* A, int n){
    // number of leaf elements: (n+1)/2
    // index of last leaf element's parent = (n/2)-1

    for(int i = (n/2)-1; i >= 0; i--){
        int x = 2*i + 1;    // Left child for current i
        int y = x+1;        // Right child for current i

        while(x < n-1){
            // Compare left and right children of current i
            if(A[x] < A[y]){
                x = y;  // x is the largest child
            }

            // Compare parent and largest child
            if(A[i] < A[x]){
                swap(A, i, x);
                i = x;
                x = 2*i + 1;
            }else{
                break;
            }
        }
    }
}


void heapSort(int arr[], int n) {
    // Build max heap
    heapify(arr, n);

    // Extract elements from the heap (sort)
    for (int i = n - 1; i >= 0; i--) {
        swap(arr, 0, i);          // Swap current root and last element
        heapify(arr, i);                    // Max heapify the reduced heap
    }
}


void runHeapExample() {
    int a[] = {10, 20, 30, 25, 5, 40, 35};
    std::vector<int> heap = createMaxHeap(a, sizeof(a)/sizeof(a[0]));
    printArrayOrVector(heap);

    int b[] = {5, 10, 30, 20};
    std::cout << "---- Array ----" << std::endl;
    printArrayOrVector(b);
    heapify(b, sizeof(b)/sizeof(b[0]));
    std::cout << "---- Heapified Array ----" << std::endl;
    printArrayOrVector(b);
}

void runHeapsortExample(){
    int a[] = {10, 20, 30, 25, 5, 40, 35};

    std::cout << "---- Array ----" << std::endl;
    printArrayOrVector(a);

    heapSort(a, sizeof(a)/sizeof(a[0]));

    std::cout << "---- Sorted Array ----" << std::endl;
    printArrayOrVector(a);
}
