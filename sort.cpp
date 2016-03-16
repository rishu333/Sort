#include <vector>
#include <cstdlib>
#include "sort.h"

/*
void printVector2(std::vector<int> V) {
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

void insertionsort(std::vector<int> & V) {
    unsigned int j;
    int tmp;
    for (unsigned int i = 1; i < V.size(); i++) {
        j = i;
        while ((j > 0) && (V[j-1] > V[j])) {
            tmp = V[j];
            V[j] = V[j-1];
            V[j-1] = tmp;
            j--;
        }
    }
}

std::vector<int> sort(std::vector<int> V) {
    if (V.size() > 100) {
        quicksort(V, 0, V.size()-1);
    } else {
        insertionsort(V);
    }
    return V;
}

std::vector<int> sort(std::vector<int> V, std::string algo) {
    if (algo == "quick") {
        quicksort(V, 0, V.size()-1);
    } else if (algo == "insertion") {
        insertionsort(V);
    } else {
        std::exit(EXIT_FAILURE);
    }
    return V;
}
