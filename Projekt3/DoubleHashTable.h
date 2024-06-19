#ifndef PROJEKT3_DOUBLEHASHTABLE_H
#define PROJEKT3_DOUBLEHASHTABLE_H

#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

class DoubleHashTable {
    struct Node {
        int key = INT_MIN;
        int value = 0;
        bool isDeleted = false;
    };

    static const int INITIAL_SIZE = 10;
    int size;
    int count;
    std::vector<Node> hashtable;

    int prime; // largest prime number smaller than size
    std::vector<bool> isPrime;

    int hash1(int key) const;
    int hash2(int key) const;
    void rehash();

    void sieveOfEratosthenes(int size);
    bool isFull() const;

public:
    DoubleHashTable();
    ~DoubleHashTable();

    void insert(int key, int value);
    void remove(int key);
    int getSize() const;
    int getCount() const;
    void print() const;
};

#endif //PROJEKT3_DOUBLEHASHTABLE_H
