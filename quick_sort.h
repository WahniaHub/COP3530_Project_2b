#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <vector>

// Sort values using quicksort and count element comparisons.
void quickSort(std::vector<int>& values, int low, int high, long long& comparisons);
int partition(std::vector<int>& values, int low, int high, long long& comparisons);

#endif