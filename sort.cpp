#include <vector>
//#include <iostream>
#include "sort.h"

/*
void printVector(std::vector<int> V) {
    for (unsigned int i = 0; i < V.size(); i++) {
        (i < V.size()-1) ? std::cout << V[i] << ' ':
                           std::cout << V[i] << std::endl;
    }
}
*/

//std::vector<int> quicksort(std::vector<int> & V, int lo, int hi) {
void quicksort(std::vector<int> & V, int lo, int hi) {
    unsigned int p;
    if (lo < hi) {
        p = partition(V, lo, hi);
        quicksort(V, lo, p-1);
        quicksort(V, p+1, hi);
    }
}

int partition(std::vector<int> & V, int lo, int hi) {
    int pivot = V[hi];
    int i = lo;
    int tmp;
    for (int j = lo; j < hi; j++) {
        if (V[j] <= pivot) {
            tmp = V[i];
            V[i] = V[j];
            V[j] = tmp;
            i++;
        }
    }

    tmp = V[i];
    V[i] = V[hi];
    V[hi] = tmp;

    return i;
}

std::vector<int> sort(std::vector<int> V) {
    quicksort(V, 0, V.size()-1);
    return V;
}
