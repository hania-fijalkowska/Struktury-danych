#ifndef PROJEKT3_CUCKOOHASHTABLE_H
#define PROJEKT3_CUCKOOHASHTABLE_H

#include <iostream>
#include <vector>
#include <climits>


class CuckooHashTable {
private:
    struct Node{
        int key = INT_MIN;
        int value = 0;
    };

    static const int INITIAL_SIZE = 10;
    int size;
    int count;
    std::vector<std::vector<Node>> hashtable;

    int hash1(int key) const;
    int hash2(int key) const;
    void rehash();
    void replace(int key, int value);
    int find(int key) const;

    void initHashTable();

public:
    CuckooHashTable();
    ~CuckooHashTable();

    void insert(int key, int value);
    void remove(int key);
    int getSize() const;
    int getCount() const;
    void print() const;
};


#endif //PROJEKT3_CUCKOOHASHTABLE_H
