#include "ListNode.h"
template class ListNode<int>;

template <typename T>
ListNode<T>::ListNode(T data, int priority){
    assignedData = data;
    assignedPriority = priority;
    assignedNextNode = nullptr;
}

template<typename T>
ListNode<T>::ListNode() = default;

template<typename T>
ListNode<T>::~ListNode() = default;

template <typename T>
void ListNode<T>::setData(T data) {
    assignedData = data;
}

template <typename T>
void ListNode<T>::setPriority(int priority) {
    assignedPriority = priority;
}

template<typename T>
void ListNode<T>::setNextNode(std::shared_ptr<ListNode<T>>nextNode) {
    assignedNextNode = nextNode;
}

template <typename T>
T ListNode<T>::getData() const {
    return assignedData;
}

template <typename T>
int ListNode<T>::getPriority() const {
    return assignedPriority;
}

template<typename T>
std::shared_ptr<ListNode<T>> ListNode<T>::getNextNode() const {
    return assignedNextNode;
}