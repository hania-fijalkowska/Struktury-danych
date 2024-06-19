#include "CuckooHashTable.h"

CuckooHashTable::CuckooHashTable() {
    size = INITIAL_SIZE;
    count = 0;
    hashtable.resize(2, std::vector<Node>(size));
    initHashTable();
}

CuckooHashTable::~CuckooHashTable() = default;

void CuckooHashTable::initHashTable() {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < size; j++) {
            hashtable.at(i).at(j) = {INT_MIN, 0};
        }
    }
}

int CuckooHashTable::hash1(int key) const {
    return std::abs(key) % size;
}

int CuckooHashTable::hash2(int key) const {
    return (std::abs(key) / 7) % size;
}


void CuckooHashTable::rehash() {

    size *= 2; // doubles the size
    count = 0; // resets the number of elements

    std::vector<std::vector<Node>> oldHashTable = hashtable;

    hashtable.resize(2, std::vector<Node>(size));
    hashtable.at(0).resize(size);
    hashtable.at(1).resize(size);
    initHashTable();

    for (const auto& table : oldHashTable) {
        for (const auto& node : table) {
            if (node.key != INT_MIN) {
                insert(node.key, node.value);
            }
        }
    }

}

void CuckooHashTable::replace(int key, int value) {
    if(find(key) == INT_MIN){
        std::cout << "Key not found" << std::endl;
        return;
    }

    int pos1 = hash1(key);
    if(hashtable.at(0).at(pos1).key == key){
        hashtable.at(0).at(pos1).value = value;
        return;
    }

    int pos2 = hash2(key);
    if(hashtable.at(1).at(pos2).key == key){
        hashtable.at(1).at(pos2).value = value;
        return;
    }
}

int CuckooHashTable::find(int key) const{
    int pos1 = hash1(key); //computes the position in the first hash-table using hash1
    if(hashtable.at(0).at(pos1).key == key){
        return hashtable.at(0).at(pos1).value;
    }

    int pos2 = hash2(key); //computes the position in the second hash-table using hash2
    if(hashtable.at(1).at(pos2).key == key){
        return hashtable.at(1).at(pos2).value;
    }

    return INT_MIN; //when key not found return INT_MIN
}

void CuckooHashTable::insert(int key, int value) {

    if (find(key) != INT_MIN) {
        replace(key, value);
        return;
    }

    Node temp_node = {key, value};
    for (int i = 0; i < size; ++i) {
        int pos1 = hash1(temp_node.key);
        if (hashtable.at(0).at(pos1).key == INT_MIN) {
            hashtable.at(0).at(pos1) = temp_node;
            count++;
            return;
        }
        std::swap(hashtable.at(0).at(pos1), temp_node);

        int pos2 = hash2(temp_node.key);
        if (hashtable.at(1).at(pos2).key == INT_MIN) {
            hashtable.at(1).at(pos2) = temp_node;
            count++;
            return;
        }
        std::swap(hashtable.at(1).at(pos2), temp_node);
    }

    rehash();
    insert(temp_node.key, temp_node.value);
}

void CuckooHashTable::remove(int key) {
    int pos1 = hash1(key);
    if(hashtable.at(0).at(pos1).key == key){
        hashtable.at(0).at(pos1) = {INT_MIN, 0};
        count--;
        return;
    }

    int pos2 = hash2(key);
    if(hashtable.at(1).at(pos2).key == key){
        hashtable.at(1).at(pos2) = {INT_MIN, 0};
        count--;
        return;
    }

    //std::cout << "Key not found" << std::endl;
}

int CuckooHashTable::getSize() const {
    return size;
}

int CuckooHashTable::getCount() const {
    return count;
}

void CuckooHashTable::print() const {
    std::cout << "Table 1:" << std::endl;
    for (const auto &node : hashtable[0]) {
        if (node.key != INT_MIN) {
            std::cout << "Key: " << node.key << " Value: " << node.value << std::endl;
        }
    }

    std::cout << "Table 2:" << std::endl;
    for (const auto &node : hashtable[1]) {
        if (node.key != INT_MIN) {
            std::cout << "Key: " << node.key << " Value: " << node.value << std::endl;
        }
    }
}

