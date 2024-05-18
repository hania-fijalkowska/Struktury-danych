#include "HeapPriorityQueue.h"
#include <stdexcept>
template class HeapPriorityQueue<int>;

template<typename T>
HeapPriorityQueue<T>::HeapPriorityQueue() = default; //constructor

template<typename T>
HeapPriorityQueue<T>::~HeapPriorityQueue() = default; //destructor

template<typename T>
int HeapPriorityQueue<T>::returnParent(int i) const{
    return ((i - 1) / 2);
}

template<typename T>
int HeapPriorityQueue<T>::returnRightChild(int i) const{
    return ((2 * i) + 2);
}

template<typename T>
int HeapPriorityQueue<T>::returnLeftChild(int i) const{
    return ((2 * i) + 1);
}

template<typename T>
void HeapPriorityQueue<T>::shiftDown(int i) {
    int largest = i;
    int leftChild = returnLeftChild(i);
    int rightChild = returnRightChild(i);
    int size = assignedQueue.size();

    if(leftChild < size && assignedQueue.at(largest).getPriority() < assignedQueue.at(leftChild).getPriority()){
        largest = leftChild;
    }

    if(rightChild < size && assignedQueue.at(largest).getPriority() < assignedQueue.at(rightChild).getPriority()){
        largest = rightChild;
    }

    if(i != largest){
         std::swap(assignedQueue.at(largest), assignedQueue.at(i));
         shiftDown(largest);
    }
}

template<typename T>
void HeapPriorityQueue<T>::shiftUp(int i) { //i is the index of the added Node in the assignedQueue vector
    while(i > 0 && assignedQueue.at(returnParent(i)).getPriority() < assignedQueue.at(i).getPriority()){
        std::swap(assignedQueue.at(returnParent(i)), assignedQueue.at(i));
        i = returnParent(i);
    }
}

template <typename T>
void HeapPriorityQueue<T>::enqueue(T data, int priority) {
    HeapNode<T> newNode(data, priority); //creates new Node
    assignedQueue.push_back(newNode); //adds newNode to the end of assignedQueue vector
    shiftUp(assignedQueue.size() - 1); //calls shiftUp on the added Node (takes index of the added Node in the assignedQueue vector)
}

template <typename T>
HeapNode<T> HeapPriorityQueue<T>::dequeue() {\
    if(assignedQueue.empty()){
        throw std::out_of_range("Queue is empty");
    }

    HeapNode<T> dequeuedNode = assignedQueue.front();
    assignedQueue.front() = assignedQueue.back();
    assignedQueue.pop_back();

    if(!assignedQueue.empty()){
        shiftDown(0);
    }
    return dequeuedNode;
}

template <typename T>
typename std::vector<HeapNode<T>>::iterator HeapPriorityQueue<T>::findData(T data) {
    for(auto it = assignedQueue.begin(); it != assignedQueue.end(); it++){ //iterates through assignedQueue vector
        if(it->getData() == data ){
            return it; //data found - returns the iterator of the found data Node
        }
    }
    return assignedQueue.end(); //data not found - returns the end iterator
}

template <typename T>
void HeapPriorityQueue<T>::modifyPriority(T data, int priority) {
    auto it = findData(data); //iterator pointing to the Node whose priority is being changed
    if(it != assignedQueue.end()){ //data found
        int oldPriority = it->getPriority();
        it->setPriority(priority);
        int index = std::distance(assignedQueue.begin(), it);

        if(priority > oldPriority){
            shiftUp(index);
        }
        if(priority < oldPriority){
            shiftDown(index);
        }
    }
}

template <typename T>
HeapNode<T> HeapPriorityQueue<T>::peek() const{
    if(assignedQueue.empty()){
        throw std::out_of_range("Queue is empty");
    }
    return assignedQueue.front();;
}

template <typename T>
int HeapPriorityQueue<T>::getSize() const{
    return assignedQueue.size();
}