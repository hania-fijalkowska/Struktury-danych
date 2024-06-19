#ifndef PROJEKT3_CHAININGHASHTABLE_H
#define PROJEKT3_CHAININGHASHTABLE_H

#include <iostream>
#include <list>
#include <climits>

class ChainingHashTable {
private:
    struct Node{
        int key = INT_MIN;
        int value = 0;
    };

    static const int INITIAL_SIZE = 10;
    int size;
    int count;
    std::list<Node>* hashtable;

    int hash(int key) const;
    void rehash();
    void replace(int key, int value);
    int find(int key) const;

public:
    ChainingHashTable();
    ~ChainingHashTable();

    void insert(int key, int value);
    void remove(int key);
    int getSize() const;
    int getCount() const;
    void print() const;
};


#endif //PROJEKT3_CHAININGHASHTABLE_H
