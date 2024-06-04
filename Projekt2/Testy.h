#ifndef PROJEKT2_TESTY_H
#define PROJEKT2_TESTY_H
#include "HeapPriorityQueue.h"
#include "ListPriorityQueue.h"
#include <chrono>
#include <iostream>
#include <fstream>
#include <random>
#include <memory>

template <typename T>
void generateDataFile(const std::string& filename, int queueSize, int howManyTimesRangeGreaterThanQueueSize) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }

    //calculate the range of priority and data from a to b
    int b = (queueSize * howManyTimesRangeGreaterThanQueueSize) - 1;
    int a = 0;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<T> data_dist(a, b); //generate random T value in range a-b - data
    std::uniform_int_distribution<int> priority_dist(a, b); //generate random int value in range a-b - priority

    for (int i = 0; i < queueSize; ++i) {
        T value = data_dist(gen);
        int priority = priority_dist(gen);
        file << value << " " << priority << "\n"; //writes data and priority in one line
    }
    file.close();
}

template <typename T>
void grandTest(int numberOfTestToRepeat, int howManyTimesRangeGreaterThanQueueSize){
    std::chrono::nanoseconds

    fillListQueue(0),
    enqueueTheBiggestPriorityListQueue(0),
    enqueueTheSmallestPriorityListQueue(0),
    enqueueRandomPriorityListQueue(0),
    modifyTheBiggestPriorityListQueue(0),
    modifyTheSmallestPriorityListQueue(0),
    modifyRandomPriorityListQueue(0),
    dequeueListQueue(0),
    getSizeListQueue(0),
    peekListQueue(0),

    fillHeapQueue(0),
    enqueueTheBiggestPriorityHeapQueue(0),
    enqueueTheSmallestPriorityHeapQueue(0),
    enqueueRandomPriorityHeapQueue(0),
    modifyTheBiggestPriorityHeapQueue(0),
    modifyTheSmallestPriorityHeapQueue(0),
    modifyRandomPriorityHeapQueue(0),
    dequeueHeapQueue(0),
    getSizeHeapQueue(0),
    peekHeapQueue(0);

    int tabQueueSizes[] = {1000, 2000, 4000, 8000, 16000, 32000, 64000};

    for (int queueSize: tabQueueSizes) {

        int b = (queueSize * howManyTimesRangeGreaterThanQueueSize) - 1;
        int a = 0;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<T> data_dist(a, b);
        std::uniform_int_distribution<int> priority_dist(a, b);

        T data;
        int priority;
        int theSmallestPriority = -1;
        int theBiggestPriority = queueSize * howManyTimesRangeGreaterThanQueueSize;

        for (int i = 0; i < numberOfTestToRepeat; ++i){
            generateDataFile<T>("DataFile.txt", queueSize, howManyTimesRangeGreaterThanQueueSize); //generates file
            std::vector<T> dataVector;
            std::vector<int> priorityVector;

            std::ifstream file("DataFile.txt");
            if (file.is_open()) {
                while (file >> data >> priority) {
                    dataVector.push_back(data);
                    priorityVector.push_back(priority);
                }
                file.close();
            } else {
                std::cerr << "Unable to open file." << std::endl;
                return;
            }

            std::uniform_int_distribution<size_t> index_dist(0, dataVector.size() - 1);
            T randomData = dataVector[index_dist(gen)];
            int randomPriority = priorityVector[index_dist(gen)];

            {
                ListPriorityQueue<T> listQueue;

                //fill queue
                auto startClock = std::chrono::high_resolution_clock::now();
                for (size_t j = 0; j < dataVector.size(); ++j) {
                    listQueue.enqueue(dataVector[j], priorityVector[j]);
                }
                auto endClock = std::chrono::high_resolution_clock::now();
                fillListQueue += std::chrono::duration_cast<std::chrono::nanoseconds>(endClock - startClock);

                //enqueue the biggest priority
                {
                    ListPriorityQueue<T> tempQueue = listQueue;
                    startClock = std::chrono::high_resolution_clock::now();
                    tempQueue.enqueue(randomData, theBiggestPriority);
                    endClock = std::chrono::high_resolution_clock::now();
                    enqueueTheBiggestPriorityListQueue += std::chrono::duration_cast<std::chrono::nanoseconds>(endClock - startClock);
                }

                //enqueue the smallest priority
                {
                    ListPriorityQueue<T> tempQueue = listQueue;
                    startClock = std::chrono::high_resolution_clock::now();
                    tempQueue.enqueue(randomData, theSmallestPriority);
                    endClock = std::chrono::high_resolution_clock::now();
                    enqueueTheSmallestPriorityListQueue += std::chrono::duration_cast<std::chrono::nanoseconds>(endClock - startClock);
                }


                //enqueue random priority
                {
                    ListPriorityQueue<T> tempQueue = listQueue;
                    startClock = std::chrono::high_resolution_clock::now();
                    tempQueue.enqueue(randomData, randomPriority);
                    endClock = std::chrono::high_resolution_clock::now();
                    enqueueRandomPriorityListQueue += std::chrono::duration_cast<std::chrono::nanoseconds>(endClock - startClock);
                }

                //modify the biggest priority
                {
                    ListPriorityQueue<T> tempQueue = listQueue;
                    tempQueue.dequeue();
                    tempQueue.enqueue(randomData, theBiggestPriority);
                    startClock = std::chrono::high_resolution_clock::now();
                    tempQueue.modifyPriority(randomData, theBiggestPriority);
                    endClock = std::chrono::high_resolution_clock::now();
                    modifyTheBiggestPriorityListQueue += std::chrono::duration_cast<std::chrono::nanoseconds>(endClock - startClock);
                }


                //modify the smallest priority
                {
                    ListPriorityQueue<T> tempQueue = listQueue;
                    tempQueue.dequeue();
                    tempQueue.enqueue(randomData, theSmallestPriority);
                    startClock = std::chrono::high_resolution_clock::now();
                    tempQueue.modifyPriority(randomData, theSmallestPriority);
                    endClock = std::chrono::high_resolution_clock::now();
                    modifyTheSmallestPriorityListQueue += std::chrono::duration_cast<std::chrono::nanoseconds>(endClock - startClock);
                }


                //modify random priority
                {
                    ListPriorityQueue<T> tempQueue = listQueue;
                    startClock = std::chrono::high_resolution_clock::now();
                    tempQueue.modifyPriority(randomData, randomPriority);
                    endClock = std::chrono::high_resolution_clock::now();
                    modifyRandomPriorityListQueue += std::chrono::duration_cast<std::chrono::nanoseconds>(endClock - startClock);
                }


                //dequeue
                {
                    ListPriorityQueue<T> tempQueue = listQueue;
                    startClock = std::chrono::high_resolution_clock::now();
                    tempQueue.dequeue();
                    endClock = std::chrono::high_resolution_clock::now();
                    dequeueListQueue += std::chrono::duration_cast<std::chrono::nanoseconds>(endClock - startClock);
                }

                //get size
                {
                    ListPriorityQueue<T> tempQueue = listQueue;
                    startClock = std::chrono::high_resolution_clock::now();
                    tempQueue.getSize();
                    endClock = std::chrono::high_resolution_clock::now();
                    getSizeListQueue += std::chrono::duration_cast<std::chrono::nanoseconds>(endClock - startClock);
                }

                //peek
                {
                    ListPriorityQueue<T> tempQueue = listQueue;
                    startClock = std::chrono::high_resolution_clock::now();
                    tempQueue.peek();
                    endClock = std::chrono::high_resolution_clock::now();
                    peekListQueue += std::chrono::duration_cast<std::chrono::nanoseconds>(endClock - startClock);
                }
            }

            {
                HeapPriorityQueue<T> heapQueue;

                // Fill heapQueue
                auto startClock = std::chrono::high_resolution_clock::now();
                for (size_t j = 0; j < dataVector.size(); ++j) {
                    heapQueue.enqueue(dataVector[j], priorityVector[j]);
                }
                auto endClock = std::chrono::high_resolution_clock::now();
                fillHeapQueue += std::chrono::duration_cast<std::chrono::nanoseconds>(endClock - startClock);


                //enqueue the biggest priority
                {
                    HeapPriorityQueue<T> tempQueue = heapQueue;
                    startClock = std::chrono::high_resolution_clock::now();
                    tempQueue.enqueue(randomData, theBiggestPriority);
                    endClock = std::chrono::high_resolution_clock::now();
                    enqueueTheBiggestPriorityHeapQueue += std::chrono::duration_cast<std::chrono::nanoseconds>(endClock - startClock);
                }

                //enqueue the smallest priority
                {
                    HeapPriorityQueue<T> tempQueue = heapQueue;
                    startClock = std::chrono::high_resolution_clock::now();
                    tempQueue.enqueue(randomData, theSmallestPriority);
                    endClock = std::chrono::high_resolution_clock::now();
                    enqueueTheSmallestPriorityHeapQueue += std::chrono::duration_cast<std::chrono::nanoseconds>(endClock - startClock);
                }

                //enqueue random priority
                {
                    HeapPriorityQueue<T> tempQueue = heapQueue;
                    startClock = std::chrono::high_resolution_clock::now();
                    tempQueue.enqueue(randomData, randomPriority);
                    endClock = std::chrono::high_resolution_clock::now();
                    enqueueRandomPriorityHeapQueue += std::chrono::duration_cast<std::chrono::nanoseconds>(endClock - startClock);
                }

                //modify the biggest priority
                {
                    HeapPriorityQueue<T> tempQueue = heapQueue;
                    tempQueue.dequeue();
                    tempQueue.enqueue(randomData, theBiggestPriority);
                    startClock = std::chrono::high_resolution_clock::now();
                    tempQueue.modifyPriority(randomData, theBiggestPriority);
                    endClock = std::chrono::high_resolution_clock::now();
                    modifyTheBiggestPriorityHeapQueue += std::chrono::duration_cast<std::chrono::nanoseconds>(endClock - startClock);
                }

                //modify the smallest priority
                {
                    HeapPriorityQueue<T> tempQueue = heapQueue;
                    tempQueue.dequeue();
                    tempQueue.enqueue(randomData, theSmallestPriority);
                    startClock = std::chrono::high_resolution_clock::now();
                    tempQueue.modifyPriority(randomData, theSmallestPriority);
                    endClock = std::chrono::high_resolution_clock::now();
                    modifyTheSmallestPriorityHeapQueue += std::chrono::duration_cast<std::chrono::nanoseconds>(endClock - startClock);
                }

                //modify random priority
                {
                    HeapPriorityQueue<T> tempQueue = heapQueue;
                    startClock = std::chrono::high_resolution_clock::now();
                    tempQueue.modifyPriority(randomData, randomPriority);
                    endClock = std::chrono::high_resolution_clock::now();
                    modifyRandomPriorityHeapQueue += std::chrono::duration_cast<std::chrono::nanoseconds>(endClock - startClock);
                }

                //dequeue
                {
                    HeapPriorityQueue<T> tempQueue = heapQueue;
                    startClock = std::chrono::high_resolution_clock::now();
                    tempQueue.dequeue();
                    endClock = std::chrono::high_resolution_clock::now();
                    dequeueHeapQueue += std::chrono::duration_cast<std::chrono::nanoseconds>(endClock - startClock);
                }

                //get size
                {
                    HeapPriorityQueue<T> tempQueue = heapQueue;
                    startClock = std::chrono::high_resolution_clock::now();
                    tempQueue.getSize();
                    endClock = std::chrono::high_resolution_clock::now();
                    getSizeHeapQueue += std::chrono::duration_cast<std::chrono::nanoseconds>(endClock - startClock);
                }

                //peek
                {
                    HeapPriorityQueue<T> tempQueue = heapQueue;
                    startClock = std::chrono::high_resolution_clock::now();
                    tempQueue.peek();
                    endClock = std::chrono::high_resolution_clock::now();
                    peekHeapQueue += std::chrono::duration_cast<std::chrono::nanoseconds>(endClock - startClock);
                }
            }
        }

        std::chrono::nanoseconds averageTimeToFillListQueue = fillListQueue / numberOfTestToRepeat;
        std::chrono::nanoseconds averageTimeToEnqueueTheBiggestPriorityListQueue = enqueueTheBiggestPriorityListQueue / numberOfTestToRepeat;
        std::chrono::nanoseconds averageTimeToEnqueueTheSmallestPriorityListQueue = enqueueTheSmallestPriorityListQueue / numberOfTestToRepeat;
        std::chrono::nanoseconds averageTimeToEnqueueRandomPriorityListQueue = enqueueRandomPriorityListQueue / numberOfTestToRepeat;
        std::chrono::nanoseconds averageTimeToModifyTheBiggestPriorityListQueue = modifyTheBiggestPriorityListQueue / numberOfTestToRepeat;
        std::chrono::nanoseconds averageTimeToModifyTheSmallestPriorityListQueue = modifyTheSmallestPriorityListQueue / numberOfTestToRepeat;
        std::chrono::nanoseconds averageTimeToModifyRandomPriorityListQueue = modifyRandomPriorityListQueue / numberOfTestToRepeat;
        std::chrono::nanoseconds averageTimeToDequeueListQueue = dequeueListQueue / numberOfTestToRepeat;
        std::chrono::nanoseconds averageTimeToGetSizeListQueue = getSizeListQueue / numberOfTestToRepeat;
        std::chrono::nanoseconds averageTimeToPeekListQueue = peekListQueue / numberOfTestToRepeat;

        std::chrono::nanoseconds averageTimeToFillHeapQueue = fillHeapQueue/ numberOfTestToRepeat;
        std::chrono::nanoseconds averageTimeToEnqueueTheBiggestPriorityHeapQueue = enqueueTheBiggestPriorityHeapQueue / numberOfTestToRepeat;
        std::chrono::nanoseconds averageTimeToEnqueueTheSmallestPriorityHeapQueue = enqueueTheSmallestPriorityHeapQueue / numberOfTestToRepeat;
        std::chrono::nanoseconds averageTimeToEnqueueRandomPriorityHeapQueue = enqueueRandomPriorityHeapQueue / numberOfTestToRepeat;
        std::chrono::nanoseconds averageTimeToModifyTheBiggestPriorityHeapQueue = modifyTheBiggestPriorityHeapQueue / numberOfTestToRepeat;
        std::chrono::nanoseconds averageTimeToModifyTheSmallestPriorityHeapQueue = modifyTheSmallestPriorityHeapQueue / numberOfTestToRepeat;
        std::chrono::nanoseconds averageTimeToModifyRandomPriorityHeapQueue = modifyRandomPriorityHeapQueue / numberOfTestToRepeat;
        std::chrono::nanoseconds averageTimeToDequeueHeapQueue = dequeueHeapQueue / numberOfTestToRepeat;
        std::chrono::nanoseconds averageTimeToGetSizeHeapQueue = getSizeHeapQueue / numberOfTestToRepeat;
        std::chrono::nanoseconds averageTimeToPeekHeapQueue = peekHeapQueue / numberOfTestToRepeat;

        std::cout << "Queue size: " << queueSize << std::endl;
        std::cout << std::endl;

        std::cout << "List Queue" << std::endl;
        std::cout << "Time to fill: " << averageTimeToFillListQueue.count() << std::endl;
        std::cout << "Enqueue the biggest priority: " << averageTimeToEnqueueTheBiggestPriorityListQueue.count() << std::endl;
        std::cout << "Enqueue the smallest priority: " << averageTimeToEnqueueTheSmallestPriorityListQueue.count() << std::endl;
        std::cout << "Enqueue random priority: " << averageTimeToEnqueueRandomPriorityListQueue.count() << std::endl;
        std::cout << "Modify the biggest priority: " << averageTimeToModifyTheBiggestPriorityListQueue.count() << std::endl;
        std::cout << "Modify the smallest priority: " << averageTimeToModifyTheSmallestPriorityListQueue.count() << std::endl;
        std::cout << "Modify random priority: " << averageTimeToModifyRandomPriorityListQueue.count() << std::endl;
        std::cout << "Dequeue: " << averageTimeToDequeueListQueue.count() << std::endl;
        std::cout << "Get size: " << averageTimeToGetSizeListQueue.count() << std::endl;
        std::cout << "Peek: " << averageTimeToPeekListQueue.count() << std::endl;
        std::cout << std::endl;

        std::cout << "Heap Queue" << std::endl;
        std::cout << "Time to fill: " << averageTimeToFillHeapQueue.count() << std::endl;
        std::cout << "Enqueue the biggest priority: " << averageTimeToEnqueueTheBiggestPriorityHeapQueue.count() << std::endl;
        std::cout << "Enqueue the smallest priority: " << averageTimeToEnqueueTheSmallestPriorityHeapQueue.count() << std::endl;
        std::cout << "Enqueue random priority: " << averageTimeToEnqueueRandomPriorityHeapQueue.count() << std::endl;
        std::cout << "Modify the biggest priority: " << averageTimeToModifyTheBiggestPriorityHeapQueue.count() << std::endl;
        std::cout << "Modify the smallest priority: " << averageTimeToModifyTheSmallestPriorityHeapQueue.count() << std::endl;
        std::cout << "Modify random priority: " << averageTimeToModifyRandomPriorityHeapQueue.count() << std::endl;
        std::cout << "Dequeue: " << averageTimeToDequeueHeapQueue.count() << std::endl;
        std::cout << "Get size: " << averageTimeToGetSizeHeapQueue.count() << std::endl;
        std::cout << "Peek: " << averageTimeToPeekHeapQueue.count() << std::endl;
        std::cout << std::endl;
    }
}

#endif //PROJEKT2_TESTY_H