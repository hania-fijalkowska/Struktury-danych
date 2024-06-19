cmake_minimum_required(VERSION 3.25)
project(untitled2)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled2 main.cpp CuckooHashTable.h CuckooHashTable.cpp tests.h ChainingHashTable.h ChainingHashTable.cpp DoubleHashTable.h DoubleHashTable.cpp)
