#ifndef SORT_H
#define SORT_H

#include <vector>
#include <string>
namespace kgk {

void quicksort(std::vector<int>&, int, int);
int partition(std::vector<int>&, int, int);
std::vector<int> sort(std::vector<int>, std::string);
std::vector<int> sort(std::vector<int>);
void insertionsort(std::vector<int>&);
void insertionsort(std::vector<int>&, int, int);
bool isSorted(std::vector<int>);
} // namespace kgk

#endif
