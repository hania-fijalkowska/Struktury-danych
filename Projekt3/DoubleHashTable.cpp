#include "DoubleHashTable.h"

DoubleHashTable::DoubleHashTable() {
    size = INITIAL_SIZE;
    count = 0;
    hashtable.resize(size);
    sieveOfEratosthenes(size * 2);
    prime = size - 1;
    while (!isPrime.at(prime)) {
        prime--;
    }
}

DoubleHashTable::~DoubleHashTable() = default;

int DoubleHashTable::hash1(int key) const{
    return std::abs(key) % size;
}

int DoubleHashTable::hash2(int key) const{
    return prime - (std::abs(key) % prime);
}

void DoubleHashTable::rehash() {
    size *= 2;
    sieveOfEratosthenes(size * 2);

    //size is incremented till the prime number is found
    //this ensures that the new size of the hash table is a prime number, which helps in reducing collisions.
    while (!isPrime.at(size)) {
        size++;
    }

    //finds the largest prime number smaller than the new size
    prime = size - 1;
    while (!isPrime[prime]) {
        prime--;
    }

    std::vector<Node> oldTable = hashtable;
    hashtable.clear(); //all nodes are removed
    hashtable.resize(size);
    count = 0;

    //reinsert Nodes from oldTable to new resized table
    for (const auto &node : oldTable) {
        if (node.key != INT_MIN && !node.isDeleted) {
            insert(node.key, node.value);
        }
    }
}

//sets non-prime numbers to false in isPrime vector
void DoubleHashTable::sieveOfEratosthenes(int n) {
    isPrime.resize(n + 1, true); // Resize the vector if necessary
    isPrime.at(0) = false;
    isPrime.at(1) = false;

    for (int p = 2; p * p <= n; p++) {
        if (isPrime.at(p)) {
            for (int i = p * p; i <= n; i += p)
                isPrime.at(i) = false;
        }
    }
}

bool DoubleHashTable::isFull() const {
    if(size == count){
        return true;
    } else {
        return false;
    }
}

void DoubleHashTable::insert(int key, int value) {
    if (isFull()) { //if the hashtable is full rehash (and increment the size)
        rehash();
    }

    int index = hash1(key);
    int offset = hash2(key);

    //if the key exists replace existing value with the new value
    int it = 0;
    while (hashtable.at(index).key != INT_MIN && !hashtable.at(index).isDeleted) {
        if (it == size){
            rehash();
        }

        if (hashtable.at(index).key == key) {
            hashtable.at(index).value = value;
            return;
        }
        index = (index + offset) % size;
        it++;
    }

    //insert new node if the key does not exist
    hashtable.at(index).key = key;
    hashtable.at(index).value = value;
    hashtable.at(index).isDeleted = false;
    count++;
}

void DoubleHashTable::remove(int key) {
    int index = hash1(key);
    int offset = hash2(key);

    while (hashtable.at(index).key != INT_MIN) {
        if (hashtable.at(index).key == key && !hashtable.at(index).isDeleted) {
            hashtable.at(index).isDeleted = true;
            count--;
            return;
        }
        index = (index + offset) % size;
    }
}

int DoubleHashTable::getSize() const {
    return size;
}

int DoubleHashTable::getCount() const {
    return count;
}

void DoubleHashTable::print() const{
    for (const auto &node : hashtable) {
        if (node.key != INT_MIN && !node.isDeleted) {
            std::cout << "Key: " << node.key << ", Value: " << node.value << "\n";
        }
    }
}
