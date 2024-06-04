#ifndef PROJEKT2_HEAPNODE_H
#define PROJEKT2_HEAPNODE_H

template <typename T>
class HeapNode {
private:
    T assignedData;
    int assignedPriority;
public:
    HeapNode(T data, int priority);
    HeapNode();
    ~HeapNode();

    //void setData(T data);
    void setPriority(int priority);

    T getData() const;
    int getPriority() const;
};

#endif //PROJEKT2_HEAPNODE_H