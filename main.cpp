/*
 * Programmer: Kyle Kloberdanz
 */
#include <iostream>
#include <vector>
#include <ctime>
#include "sort.h"

void printVector(std::vector<int> V) {
    for (unsigned int i = 0; i < V.size(); i++) {
        (i < V.size()-1) ? std::cout << V[i] << ' ':
                           std::cout << V[i] << std::endl;
    }
}

void timeAnalysis() {

    std::vector<int> V;
    srand(time(0));
    std::vector<int> sortedVector;

    std::cout << "Size, ";
    std::cout << "Insertion, ";
    std::cout << "Quick\n";

    for (int j = 2; j < 1000000; j = j * 2) {
        for (int i = 0; i < j; i++) {
            V.push_back(rand() % 100);
        }

        clock_t startTime = clock();
        sortedVector = sort(V, "insertion");
        std::cout << V.size() << ", ";
        std::cout << 
            1000*(double)(clock() - startTime)/CLOCKS_PER_SEC 
            << "ms, ";
        sortedVector.clear();
        V.clear();

        startTime = clock();
        sortedVector = sort(V, "quick");
        std::cout << 
            1000*(double)(clock() - startTime)/CLOCKS_PER_SEC
            << "ms" << std::endl;
        sortedVector.clear();
        V.clear();
    }
}

int main() {
    timeAnalysis();
    return 0;
}

