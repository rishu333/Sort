#include <vector>
#include <cstdlib>
#include "sort.h"

namespace kgk {

bool isSorted(std::vector<int> v, int low, int high) {
    int prev = v[low];
    for (int i = low; i <= high; i++) {
        if (v[i] < prev) {
            return false;
        }
        prev = v[low];
    }
    return true;

}

void quicksort(std::vector<int> & V, int lo, int hi) {
    if (isSorted(V, lo, hi)) {
        return;
    }

    if (hi - lo < 100) {
        insertionsort(V, lo, hi);
    }

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

void insertionsort(std::vector<int> & V, int lo, int hi) {
    unsigned int j;
    int tmp;
    for (unsigned int i = lo; i < hi; i++) {
        j = i;
        while ((j > 0) && (V[j-1] > V[j])) {
            tmp = V[j];
            V[j] = V[j-1];
            V[j-1] = tmp;
            j--;
        }
    }
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
    if (V.size() > 65) {
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
} // namespace kgk
