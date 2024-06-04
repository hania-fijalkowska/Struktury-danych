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
    ListNode<T>* assignedNextNode;
public:
    ListNode(T data, int priority);
    //ListNode();
    ~ListNode();

    void setData(T data);
    void setPriority(int priority);
    void setNextNode(ListNode<T>* nextNode);

    T getData() const;
    int getPriority() const;
    ListNode<T>* getNextNode() const;
};

#endif //PROJEKT2_LISTNODE_H