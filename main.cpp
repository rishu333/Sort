/*
 * Programmer: Kyle Kloberdanz
 */
#include <iostream>
#include <vector>
#include <ctime> 
#include <algorithm> // std::sort
#include "sort.h"    // kgk::sort

void printVector(std::vector<int> V) {
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

    std::cout << "Size, ";
    //std::cout << "Insertion, ";
    std::cout << "Quick ";
    std::cout << "std::sort\n";

    for (int j = 2; j < 1000000; j = j * 2) {
        for (int i = 0; i < j; i++) {
            V.push_back(rand() % 100);
        }

        clock_t startTime = clock();
        /*
        sortedVector = kgk::sort(V, "insertion");
        std::cout << V.size() << ", ";
        std::cout << 
            1000*(double)(clock() - startTime)/CLOCKS_PER_SEC 
            << "ms, ";
        sortedVector.clear();
        //V.clear();
        */

        startTime = clock();
        sortedVector = kgk::sort(V, "quick");
        std::cout << 
            1000*(double)(clock() - startTime)/CLOCKS_PER_SEC
            << "ms ";
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
    std::vector<int> V;
    std::vector<int> Vcopy;
    std::vector<int> sortedVector;

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

int main() {
    timeAnalysis();
    //test();
    return 0;
}

