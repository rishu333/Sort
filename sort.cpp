#include <vector>
#include <cstdlib>
#include <string>
#include "sort.h"

namespace kgk {

template <typename T>
bool isSorted(std::vector<T> v, int low, int high) {
    T prev = v[low];
    for (int i = 1+low; i <= high; i++) {
        if (v[i] < prev) {
            return false;
        }
        prev = v[low];
    }
    return true;

}

template <typename T>
void quicksort(std::vector<T> & V, int lo, int hi) {
    
    /*
    // Not working properly
    if (isSorted(V, lo, hi)) {
        return;
    }
    */

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

template <typename T>
int partition(std::vector<T> & V, int lo, int hi) {
    T pivot = V[hi];
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

template <typename T>
void insertionsort(std::vector<T> & V, int lo, int hi) {
    int j;
    int tmp;
    for (int i = lo; i < hi; i++) {
        j = i;
        while ((j > 0) && (V[j-1] > V[j])) {
            tmp = V[j];
            V[j] = V[j-1];
            V[j-1] = tmp;
            j--;
        }
    }
}

template <typename T>
void insertionsort(std::vector<T> & V) {
    unsigned int j;
    T tmp;
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

template <typename T>
std::vector<T> sort(std::vector<T> V) {
    if (V.size() > 65) {
        quicksort(V, 0, V.size()-1);
    } else {
        insertionsort(V);
    }
    return V;
}

template <typename T>
std::vector<T> sort(std::vector<T> V, std::string algo) {
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
