#ifndef PROJEKT2_LISTPRIORITYQUEUE_H
#define PROJEKT2_LISTPRIORITYQUEUE_H
#include "ListNode.h"
#include <iostream>
#include <memory>

template <typename T>
class ListPriorityQueue {
private:
    std::shared_ptr<ListNode<T>> assignedHead; //(smart) pointer to the first node in queue
    int assignedSize;
public:
    //ListPriorityQueue(ListNode<T>* head, int size);
    ListPriorityQueue();
    ~ListPriorityQueue();

    //methods to test the time complexity
    void enqueue(T data, int priority);
    std::shared_ptr<ListNode<T>> dequeue();
    void modifyPriority(T data, int priority);
    std::shared_ptr<ListNode<T>> peek() const;
    int getSize() const;

    //additional methods
    void printQueue() const;
};

#endif //PROJEKT2_LISTPRIORITYQUEUE_H