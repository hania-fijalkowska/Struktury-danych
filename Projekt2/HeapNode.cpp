#include "HeapNode.h"
template class HeapNode<int>;

template <typename T>
HeapNode<T>::HeapNode(T data, int priority) : assignedData(data), assignedPriority(priority) {}

template<typename T>
HeapNode<T>::HeapNode() = default;

template<typename T>
HeapNode<T>::~HeapNode() = default;

/*template <typename T>
void HeapNode<T>::setData(T data) {
    assignedData = data;
}*/

template <typename T>
void HeapNode<T>::setPriority(int priority) {
    assignedPriority = priority;
}

template <typename T>
T HeapNode<T>::getData() const{
    return assignedData;
}

template <typename T>
int HeapNode<T>::getPriority() const{
    return assignedPriority;
}

