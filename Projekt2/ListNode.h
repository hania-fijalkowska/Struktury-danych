#ifndef PROJEKT2_LISTNODE_H
#define PROJEKT2_LISTNODE_H
#include <iostream>
#include <memory>

template <typename T>
class ListNode {
public:
private:
    T assignedData;
    int assignedPriority;
    std::shared_ptr<ListNode<T>> assignedNextNode;
public:
    ListNode(T data, int priority);
    ListNode();
    ~ListNode();

    void setData(T data);
    void setPriority(int priority);
    void setNextNode(std::shared_ptr<ListNode<T>> nextNode);

    T getData() const;
    int getPriority() const;
    std::shared_ptr<ListNode<T>> getNextNode() const;
};

#endif //PROJEKT2_LISTNODE_H