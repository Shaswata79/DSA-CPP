cmake_minimum_required(VERSION 3.27)
project(DSA)

set(CMAKE_CXX_STANDARD 17)

add_executable(DSA
        LinkedList/LinkedList.cpp
        LinkedList/LinkedList.h
        Stack/Stack.cpp
        Stack/Stack.h
        main.cpp
        main.h
        Node.h
        Queue/ArrayQueue.cpp
        Queue/ArrayQueue.h
        Queue/Queue.h
        Queue/LinkedListQueue.cpp
        Queue/LinkedListQueue.h
        BinaryTree/BinaryTree.cpp
        BinaryTree/BinaryTree.h
        Heap/Heap.cpp
        Heap/Heap.h
        Graph/Graphs.cpp
        Graph/Graphs.h
        Graph/MST.cpp
        Graph/MST.cpp
)
