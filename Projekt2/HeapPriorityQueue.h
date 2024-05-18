#ifndef PROJEKT2_HEAPPRIORITYQUEUE_H
#define PROJEKT2_HEAPPRIORITYQUEUE_H

#include <vector>
#include "HeapNode.h"

template <typename T>
class HeapPriorityQueue{
private:
    std::vector<HeapNode<T>> assignedQueue;

    //additional methods
    typename std::vector<HeapNode<T>>::iterator findData(T data); //finds node with specific data in queue and returns its iterator
    int returnParent(int i) const; //returns parent of the i (assignedQueue vectors index)
    int returnLeftChild(int i) const; //returns left child of the i (assignedQueue vectors index)
    int returnRightChild(int i) const; //returns right child of the i (assignedQueue vectors index)
    void shiftUp(int i); //shifts up the node if its priority is higher than its parents priority
    void shiftDown(int i); //shifts down the node if its priority is lower than one of its children priorities

public:
    HeapPriorityQueue(); //constructor
    ~HeapPriorityQueue(); //destructor

    //methods to test the time complexity
    void enqueue(T data, int priority); //adds node to the queue and organizes the queue
    HeapNode<T> dequeue(); //removes and returns the highest priority node from queue and organizes the queue
    void modifyPriority(T data, int priority); //modifies priority of the node with specific data
    HeapNode<T> peek() const; //returns the highest priority node
    int getSize() const; //returns size of the queue (number of nodes)
};

#endif //PROJEKT2_HEAPPRIORITYQUEUE_H