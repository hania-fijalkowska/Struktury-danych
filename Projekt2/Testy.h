#ifndef PROJEKT2_TESTY_H
#define PROJEKT2_TESTY_H
#include <chrono>
#include <iostream>
#include <fstream>
#include <random>

template <typename T>
void generateDataFile(const std::string& filename, int num_lines) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<T> value_dist(-1000, 1000); //generate random T value in range 1-1000 - data
    std::uniform_int_distribution<int> priority_dist(-100, 100); //generate random int value in range 1-1000 - priority

    for (int i = 0; i < num_lines; i++) {
        T value = value_dist(gen);
        int priority = priority_dist(gen);
        file << value << " " << priority << "\n"; //writes data and priority in one line
    }
    file.close();
}

template <typename T>
void fillQueuesTests(int numberOfTestToRepeat, int queueSize){
    std::chrono::microseconds timeToFillListQueue(0);
    std::chrono::microseconds timeToFillHeapQueue(0);

    for(int i = 0; i < numberOfTestToRepeat; i++){
        generateDataFile<T>("DataFile.txt", queueSize);
        ListPriorityQueue<T> listQueue;
        HeapPriorityQueue<T> heapQueue;

        std::ifstream file("DataFile.txt");
        if(file.is_open()){
            T data;
            int priority;
            auto startClockListQueue = std::chrono::high_resolution_clock::now();
            while(file >> data >> priority){
                listQueue.enqueue(data, priority);
            }
            auto endClockListQueue = std::chrono::high_resolution_clock::now();
            timeToFillListQueue += std::chrono::duration_cast<std::chrono::microseconds>(endClockListQueue - startClockListQueue);
            file.close();
        } else {
            std::cerr << "Unable to open file." << std::endl;
            return;
        }

        std::ifstream file2("DataFile.txt");
        if(file2.is_open()){
            T data2;
            int priority2;
            auto startClockHeapQueue = std::chrono::high_resolution_clock::now();
            while(file2 >> data2 >> priority2){
                heapQueue.enqueue(data2, priority2);
            }
            auto endClockHeapQueue = std::chrono::high_resolution_clock::now();
            timeToFillHeapQueue += std::chrono::duration_cast<std::chrono::microseconds>(endClockHeapQueue - startClockHeapQueue);
            file2.close();

        } else {
            std::cerr << "Unable to open file." << std::endl;
            return;
        }
    }

    double averageTimeToFillListQueue = timeToFillListQueue.count() / static_cast<double>(numberOfTestToRepeat);
    double averageTimeToFillHeapQueue = timeToFillHeapQueue.count() / static_cast<double>(numberOfTestToRepeat);
    std::cout << averageTimeToFillHeapQueue << std::endl;
    std::cout << averageTimeToFillListQueue <<std::endl;
}

#endif //PROJEKT2_TESTY_H
