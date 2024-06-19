#ifndef PROJEKT3_TESTS_H
#define PROJEKT3_TESTS_H

#include <random>
#include <iostream>
#include <chrono>
#include <vector>
#include <climits>

#include "CuckooHashTable.h"
#include "ChainingHashTable.h"
#include "DoubleHashTable.h"

std::vector<int> generateSeeds(int size){
    std::vector<int> seedVector;
    seedVector.reserve(size);
    int a = 1000;
    int b = 10000;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> seeds_dist(a, b);

    for(int i = 0; i < size; i++){
        seedVector.push_back(seeds_dist(gen));
    }
    return seedVector;
}

std::vector<int> generateKey(int seed, int amount){
    std::vector<int> keysVector;
    keysVector.reserve(amount);

    int a = -100000000;
    int b = 100000000;

    std::mt19937 gen(seed);
    std::uniform_int_distribution<int> keys_dist(a, b);

    for(int i = 0; i < amount; i++){
        keysVector.push_back(keys_dist(gen));
    }

    return keysVector;
}

std::vector<int> generateValue(int seed, int amount){
    std::vector<int> valueVector;
    valueVector.reserve(amount);

    int a = -10000;
    int b = 10000;

    std::mt19937 gen(seed);
    std::uniform_int_distribution<int> values_dist(a, b);

    for(int i = 0; i < amount; i++){
        valueVector.push_back(values_dist(gen));
    }

    return valueVector;
}

void testCuckooHashTable(const std::vector<int>& seeds, int amount) {
    std::chrono::nanoseconds avgInsertCuckooSeed(0), avgRemoveCuckooSeed(0);
    int numberOfSeeds = seeds.size();
    int key = INT_MAX;

    for(int j = 0; j < numberOfSeeds; j++) {
        std::chrono::nanoseconds insertCuckoo(0), removeCuckoo(0);

        CuckooHashTable tempCuckoo;

        std::vector<int> keysVector = generateKey(seeds.at(j), amount);
        std::vector<int> valueVector = generateValue(seeds.at(j), amount);

        for(int i = 0; i < amount; i++) {
            tempCuckoo.insert(keysVector.at(i), valueVector.at(i));
        }

        int numberOfTests = 100;
        for(int i = 0; i < numberOfTests; i++) {
            auto startClockCuckoo = std::chrono::high_resolution_clock::now();
            tempCuckoo.insert(key, 10);
            auto endClockCuckoo = std::chrono::high_resolution_clock::now();
            tempCuckoo.remove(key);
            insertCuckoo += std::chrono::duration_cast<std::chrono::nanoseconds>(endClockCuckoo - startClockCuckoo);

            startClockCuckoo = std::chrono::high_resolution_clock::now();
            tempCuckoo.remove(keysVector.at(0));
            endClockCuckoo = std::chrono::high_resolution_clock::now();
            tempCuckoo.insert(keysVector.at(0), valueVector.at(0));
            removeCuckoo += std::chrono::duration_cast<std::chrono::nanoseconds>(endClockCuckoo - startClockCuckoo);
        }

        avgInsertCuckooSeed += insertCuckoo / numberOfTests;
        avgRemoveCuckooSeed += removeCuckoo / numberOfTests;
    }

    avgInsertCuckooSeed /= numberOfSeeds;
    avgRemoveCuckooSeed /= numberOfSeeds;

    std::cout << "Cuckoo Hash Table:" << std::endl;
    std::cout << "Average time to insert: " << avgInsertCuckooSeed.count() << " ns" << std::endl;
    std::cout << "Average time to remove: " << avgRemoveCuckooSeed.count() << " ns" << std::endl;
}

void testChainingHashTable(const std::vector<int>& seeds, int amount) {
    std::chrono::nanoseconds avgInsertChainSeed(0), avgRemoveChainSeed(0);
    int numberOfSeeds = seeds.size();
    int key = INT_MAX;

    for(int j = 0; j < numberOfSeeds; j++) {
        std::chrono::nanoseconds insertChain(0), removeChain(0);

        ChainingHashTable tempChain;

        std::vector<int> keysVector = generateKey(seeds.at(j), amount);
        std::vector<int> valueVector = generateValue(seeds.at(j), amount);

        for(int i = 0; i < amount; i++) {
            tempChain.insert(keysVector.at(i), valueVector.at(i));
        }

        int numberOfTests = 100;
        for(int i = 0; i < numberOfTests; i++) {
            auto startClockChain = std::chrono::high_resolution_clock::now();
            tempChain.insert(key, 10);
            auto endClockChain = std::chrono::high_resolution_clock::now();
            tempChain.remove(key);
            insertChain += std::chrono::duration_cast<std::chrono::nanoseconds>(endClockChain - startClockChain);

            startClockChain = std::chrono::high_resolution_clock::now();
            tempChain.remove(keysVector.at(0));
            endClockChain = std::chrono::high_resolution_clock::now();
            tempChain.insert(keysVector.at(0), valueVector.at(0));
            removeChain += std::chrono::duration_cast<std::chrono::nanoseconds>(endClockChain - startClockChain);
        }

        avgInsertChainSeed += insertChain / numberOfTests;
        avgRemoveChainSeed += removeChain / numberOfTests;
    }

    avgInsertChainSeed /= numberOfSeeds;
    avgRemoveChainSeed /= numberOfSeeds;

    std::cout << "Chaining Hash Table:" << std::endl;
    std::cout << "Average time to insert: " << avgInsertChainSeed.count() << " ns" << std::endl;
    std::cout << "Average time to remove: " << avgRemoveChainSeed.count() << " ns" << std::endl;
}

void testDoubleHashTable(const std::vector<int>& seeds, int amount) {
    std::chrono::nanoseconds avgInsertDoubleSeed(0), avgRemoveDoubleSeed(0);
    int numberOfSeeds = seeds.size();
    int key = INT_MAX;

    for(int j = 0; j < numberOfSeeds; j++) {
        std::chrono::nanoseconds insertDouble(0), removeDouble(0);

        DoubleHashTable tempDouble;

        std::vector<int> keysVector = generateKey(seeds.at(j), amount);
        std::vector<int> valueVector = generateValue(seeds.at(j), amount);

        for(int i = 0; i < amount; i++) {
            tempDouble.insert(keysVector.at(i), valueVector.at(i));
        }

        int numberOfTests = 100;
        for(int i = 0; i < numberOfTests; i++) {
            auto startClockDouble = std::chrono::high_resolution_clock::now();
            tempDouble.insert(key, 10);
            auto endClockDouble = std::chrono::high_resolution_clock::now();
            tempDouble.remove(key);
            insertDouble += std::chrono::duration_cast<std::chrono::nanoseconds>(endClockDouble - startClockDouble);

            startClockDouble = std::chrono::high_resolution_clock::now();
            tempDouble.remove(keysVector.at(0));
            endClockDouble = std::chrono::high_resolution_clock::now();
            tempDouble.insert(keysVector.at(0), valueVector.at(0));
            removeDouble += std::chrono::duration_cast<std::chrono::nanoseconds>(endClockDouble - startClockDouble);
        }

        avgInsertDoubleSeed += insertDouble / numberOfTests;
        avgRemoveDoubleSeed += removeDouble / numberOfTests;
    }

    avgInsertDoubleSeed /= numberOfSeeds;
    avgRemoveDoubleSeed /= numberOfSeeds;

    std::cout << "Double Hash Table:" << std::endl;
    std::cout << "Average time to insert: " << avgInsertDoubleSeed.count() << " ns" << std::endl;
    std::cout << "Average time to remove: " << avgRemoveDoubleSeed.count() << " ns" << std::endl;
}

#endif //PROJEKT3_TESTS_H
