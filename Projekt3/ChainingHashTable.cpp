#include "ChainingHashTable.h"

ChainingHashTable::ChainingHashTable() {
    size = INITIAL_SIZE;
    hashtable = new std::list<Node>[size];
    count = 0;
}

ChainingHashTable::~ChainingHashTable() {
    delete[] hashtable;
}

int ChainingHashTable::hash(int key) const {
    return std::abs(key) % size;
}

void ChainingHashTable::rehash() {
    size *= 2;
    count = 0;

    auto* newArray = new std::list<Node>[size];

    for(int i = 0; i < size / 2; i++){
        for(auto& node : hashtable[i]){
            newArray[hash(node.key)].push_front(node);
            count++;
        }
    }
    delete[] hashtable;
    hashtable = newArray;
}

void ChainingHashTable::replace(int key, int value) {
    if(find(key) == INT_MIN){
        std::cout << "Key not found" << std::endl;
        return;
    }

    int position = hash(key);
    for(auto& node : hashtable[position]){
        if(node.key == key){
            node.value = value;
        }
    }
}

int ChainingHashTable::find(int key) const{
    int position = hash(key);
    if(!hashtable[position].empty()) {

        for (auto &node: hashtable[position]) {
            if (node.key == key) {
                return node.value;
            }
        }
    }
    return INT_MIN;
}

void ChainingHashTable::insert(int key, int value) {
    if(count >= size/2){
        rehash();
    }

    if(find(key) == INT_MIN){
        int position = hash(key);
        Node node = {key, value};
        hashtable[position].push_front(node);
        count++;
    } else {
        replace(key, value);
    }
}

void ChainingHashTable::remove(int key) {
    int position = hash(key);
    auto& chain = hashtable[position];
    for(auto i = chain.begin(); i != chain.end(); i++){
        if(i -> key == key){
            chain.erase(i);
            count--;
            return;
        }
    }
}

int ChainingHashTable::getSize() const {
    return size;
}

int ChainingHashTable::getCount() const {
    return count;
}

void ChainingHashTable::print() const {
    for(int i = 0; i < size; ++i){
        std::cout << "Bucket " << i << ":";
        for(auto& node : hashtable[i]){
            std::cout << " (" << node.key << ", " << node.value << ")";
        }
        std::cout << std::endl;
    }
}
