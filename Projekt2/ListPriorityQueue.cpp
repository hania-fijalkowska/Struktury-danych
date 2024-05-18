#include "ListPriorityQueue.h"
#include <stdexcept>
#include <iostream>
template class ListPriorityQueue<int>;

/*template<typename T>
ListPriorityQueue<T>::ListPriorityQueue(ListNode<T> *head, int size) {
    assignedHead = head;
    assignedSize = size;
}*/

template<typename T>
ListPriorityQueue<T>::ListPriorityQueue(){
    assignedHead = nullptr;
    assignedSize = 0;
}

template<typename T>
ListPriorityQueue<T>::~ListPriorityQueue() = default;

template<typename T>
void ListPriorityQueue<T>::enqueue(T data, int priority) {
    auto newNode = std::make_shared<ListNode<T>>(data, priority); //creates new Node with data and priority

    if (assignedHead == nullptr) { //checks if the queue is empty
        assignedHead = newNode; //assignedHead points to the newNode
    } else if (assignedHead->getPriority() < priority) { //queue is not empty and newNode has higher priority than assignedHead (first node in queue)
        newNode->setNextNode(assignedHead); //nextNode of the newNode becomes assignedHead (second in queue)
        assignedHead = newNode; //assignedHead becomes newNode (first node in queue)
    } else {
        auto current = assignedHead;
        while (current->getNextNode() != nullptr && current->getNextNode()->getPriority() > priority) { //while current is not the last node and nextNode of current has higher priority than priority
            current = current->getNextNode(); //moves current until finding correct position
        }
        newNode->setNextNode(current->getNextNode());
        current->setNextNode(newNode);
    }
    assignedSize++;
}

template<typename T>
std::shared_ptr<ListNode<T>> ListPriorityQueue<T>::dequeue() {
    if (assignedHead == nullptr) {
        throw std::runtime_error("Queue is empty");
    } else {
        std::shared_ptr<ListNode<T>> dequeuedNode = assignedHead;
        assignedHead = assignedHead->getNextNode(); //move assignedHead to the next Node
        assignedSize--; //reduce the size of list (queue)
        return dequeuedNode;
    }
}

template<typename T>
void ListPriorityQueue<T>::modifyPriority(T data, int priority) {
    std::shared_ptr<ListNode<T>> current = assignedHead;
    std::shared_ptr<ListNode<T>> prev = nullptr;

    while (current != nullptr && current->getData() != data) { //while current is not the nast node and current data is not equal to data
        prev = current;
        current = current->getNextNode();
    }
    //out of the while loop so the current points to nullptr or current data is equal to data
    if (current != nullptr) { //current points to valid Node, Node with specified data has been found
        if (prev != nullptr) { //prev points to valid Node so the current is not the first Node in the queue
            prev->setNextNode(current->getNextNode()); //skips the current Node
        } else { //current is the first Node in the list (queue)
            assignedHead = current->getNextNode();
        }
        assignedSize--;
        enqueue(data, priority); //enqueue increases the size by 1
    } else {
        throw std::runtime_error("Data not found");
    }
}

template<typename T>
int ListPriorityQueue<T>::getSize() const {
    return assignedSize;
}

template<typename T>
std::shared_ptr<ListNode<T>> ListPriorityQueue<T>::peek() const {
    if (assignedHead == nullptr) {
        throw std::runtime_error("Queue is empty");
    } else {
        return assignedHead;
    }
}

template<typename T>
void ListPriorityQueue<T>::printQueue() const {
    std::shared_ptr<ListNode<T>> current = assignedHead;
    while (current != nullptr) {
        std::cout << "(priority: " << current->getPriority() << ")" << "(data: " << current->getData() << ")";
        if (current->getNextNode() != nullptr) {
            std::cout << "->";
        }
        current = current->getNextNode();
    }
}