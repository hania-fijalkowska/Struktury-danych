#include "CuckooHashTable.h"
#include "DoubleHashTable.h"
#include "ChainingHashTable.h"
#include "tests.h"
#include <fstream>


int main () {

    std::vector<int> seeds = generateSeeds(100);
    int tab[] = {1000, 2000, 4000, 8000, 16000, 32000,64000, 128000};

    CuckooHashTable cuckooTable;
    ChainingHashTable chainTable;
    DoubleHashTable doubleTable;

   for(int i : tab){
        std::cout << "Cuckoo" << std::endl;
        std::cout << "Number of Nodes: " << i << std::endl;
        testCuckooHashTable(seeds, i);
        std::cout << std::endl;
    }

   for(int i : tab){
        std::cout << "Chain" << std::endl;
        std::cout << "Number of Nodes: " << i << std::endl;
        testChainingHashTable(seeds, i);
        std::cout << std::endl;
   }

   for(int i : tab){
        std::cout << "Double" << std::endl;
        std::cout << "Number of Nodes: " << i << std::endl;
        testDoubleHashTable(seeds, i);
        std::cout << std::endl;
   }
 }