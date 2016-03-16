#ifndef SORT_H
#define SORT_H

#include <vector>
#include <string>

void quicksort(std::vector<int>&, int, int);
int partition(std::vector<int>&, int, int);
std::vector<int> sort(std::vector<int>, std::string);
std::vector<int> sort(std::vector<int>);
void insertionsort(std::vector<int>&);

#endif
