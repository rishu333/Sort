/*
 * Programmer: Kyle Kloberdanz
 */
#include <iostream>
#include <vector>
#include <ctime> 
#include <cstdint> 
#include <algorithm> // std::sort
#include "sort.h"    // kgk::sort

template <typename T>
void printVector(std::vector<T> V) {
    for (unsigned int i = 0; i < V.size(); i++) {
        (i < V.size()-1) ? std::cout << V[i] << ' ':
                           std::cout << V[i] << std::endl;
    }
}

void timeAnalysis() {

    srand(time(0));
    std::vector<int> V;
    std::vector<int> Vcopy;
    std::vector<int> sortedVector;

    const uint64_t MAX_LOOPS = 400000000;

    std::cout << "Size, ";
    //std::cout << "Insertion, ";
    std::cout << "Quick, ";
    std::cout << "std::sort\n";

    for (uint64_t j = 2; j < MAX_LOOPS; j = j * 2) {
        for (uint64_t i = 0; i < j; i++) {
            V.push_back(rand() % 100);
        }

        clock_t startTime = clock();
        std::cout << V.size() << ", ";
        /*
        sortedVector = kgk::sort(V, "insertion");
        std::cout << 
            1000*(double)(clock() - startTime)/CLOCKS_PER_SEC 
            << "ms, ";
        sortedVector.clear();
        //V.clear();
        */

        startTime = clock();
        std::cout << "Unsorted: ";
        printVector(V);
        std::cout << std::endl;
        sortedVector = kgk::sort(V, "quick");
        std::cout << 
            1000*(double)(clock() - startTime)/CLOCKS_PER_SEC
            << "ms, ";
        std::cout << "kgk::sort Sorted vector: ";
        printVector(sortedVector);
        sortedVector.clear();
        //V.clear();

        Vcopy = V;
        startTime = clock();
        std::sort(Vcopy.begin(), Vcopy.end());
        std::cout << 
            1000*(double)(clock() - startTime)/CLOCKS_PER_SEC
            << "ms " << std::endl;
        Vcopy.clear();
        V.clear();
    }
}

void test() {
    srand(time(0));
    std::vector<double> V;
    std::vector<double> Vcopy;
    std::vector<double> sortedVector;

    const int VECTOR_SIZE = 100;

    for (int i = 0; i < VECTOR_SIZE; i++) {
        V.push_back(rand() % 100);
    }

    std::cout << "unsorted\n";
    printVector(V);

    std::cout << "quick\n";
    printVector(kgk::sort(V, "quick"));

    std::cout << "insertion\n";
    printVector(kgk::sort(V, "insertion"));
}

void testIsSorted() {
    std::vector<int> V {0,1,1,1,3,3,5,6,6,7,8,8,6,8,10,10,11,11,11,12,17,17,17,17,17,19,19,20,20,21,22,22,22,23,24,24,25,25,25,26,27,27,28,28,28,30,31,33,34,36,37,40,41,42,42,43,44,44,44,45,47,47,48,49,54,54,55,55,55,57,57,57,57,58,59,59,59,59,61,62,62,63,63,64,65,65,68,68,69,70,70,72,72,72,73,73,74,76,78,78,78,79,80,80,82,84,84,85,86,87,87,89,89,90,90,90,91,91,92,93,93,93,95,98,99,99,99,39};

    std::cout << "size = " << V.size() << std::endl;
    if (kgk::isSorted(V, 0, V.size()-1)) {
        std::cout << "is sorted" << std::endl;
    } else {
        std::cout << "Not sorted" << std::endl;
    }
}

int main() {
    //testIsSorted();
    test();
    timeAnalysis();
    return 0;
}

