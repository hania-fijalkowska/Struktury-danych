#include "ListPriorityQueue.h"
#include <stdexcept>
template class ListPriorityQueue<int>;

template<typename T>
ListPriorityQueue<T>::ListPriorityQueue() : assignedHead(nullptr), assignedSize(0) {}

template<typename T>
ListPriorityQueue<T>::~ListPriorityQueue() = default;

template<typename T>
void ListPriorityQueue<T>::enqueue(T data, int priority) {
    auto* newNode = new ListNode<T>(data, priority); //creates new Node with data and priority

    if (!assignedHead || assignedHead->getPriority() < priority) { //list is empty or priority at head is less than priority
        newNode->setNextNode(assignedHead); //nextNode of the newNode becomes assignedHead (second in queue)
        assignedHead = newNode; //assignedHead becomes newNode (first node in queue)
    } else {
        ListNode<T>* current = assignedHead;
        while (current->getNextNode() && current->getNextNode()->getPriority() >= priority) { //while current is not the last node and nextNode of current has higher priority than priority
            current = current->getNextNode(); //moves current until finding correct position
        }
        newNode->setNextNode(current->getNextNode());
        current->setNextNode(newNode);
    }
    assignedSize++;
}

template<typename T>
ListNode<T>* ListPriorityQueue<T>::dequeue() {
    if (!assignedHead) { //if list is empty
        throw std::runtime_error("Queue is empty");
    } else {
        ListNode<T>* dequeuedNode = assignedHead;
        assignedHead = assignedHead->getNextNode(); //move assignedHead to the next Node
        assignedSize--; //reduce the size of list (queue)
        return dequeuedNode;
    }
}

template<typename T>
void ListPriorityQueue<T>::modifyPriority(T data, int priority) {
    if (!assignedHead) {
        throw std::runtime_error("Queue is empty");
    } else {
        ListNode<T>* current = assignedHead;
        ListNode<T>* prev = nullptr;

        while (current && current->getData() != data) {
            prev = current;
            current = current->getNextNode();
        }

        if (!current) {
            throw std::runtime_error("Data not found");
        } else {
            if (prev) {
                prev->setNextNode(current->getNextNode());
            } else {
                assignedHead = current->getNextNode();
            }

            delete current;
            enqueue(data, priority);
        }
    }
}


template<typename T>
int ListPriorityQueue<T>::getSize() const {
    return assignedSize;
}

template<typename T>
ListNode<T>* ListPriorityQueue<T>::peek() const {
    if (!assignedHead) {
        throw std::runtime_error("Queue is empty");
    } else {
        return assignedHead;
    }
}