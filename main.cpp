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

int main() {
    std::vector<int> V;

    srand(time(0));
    for (int i = 0; i < 50; i++) {
        V.push_back(rand() % 100);
    }
 
    std::vector<int> sortedV = sort(V);
    printVector(sortedV);
    return 0;
}

