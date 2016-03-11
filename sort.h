#ifndef SORT_H
#define SORT_H

#include <vector>

//std::vector<int> quicksort(std::vector<int>&, int, int);
void quicksort(std::vector<int>&, int, int);

int partition(std::vector<int>&, int, int);

std::vector<int> sort(std::vector<int>);

#endif
