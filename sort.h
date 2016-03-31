#ifndef SORT_H
#define SORT_H

#include <vector>
#include <string>
namespace kgk {

template <typename T>
void quicksort(std::vector<T>&, int, int);

template <typename T>
int partition(std::vector<T>&, int, int);

template <typename T>
std::vector<T> sort(std::vector<T>, std::string);

template <typename T>
std::vector<T> sort(std::vector<T>);

template <typename T>
void insertionsort(std::vector<T>&);

template <typename T>
void insertionsort(std::vector<T>&, int, int);

template <typename T>
bool isSorted(std::vector<T>);

} // namespace kgk
#include "sort.cpp"
#endif
