#include "quick_sort.h"
#include <algorithm>

void quickSort(std::vector<int>& values, int low, int high, long long& comparisons){
    if (low < high) {
        int pivot = partition(values, low, high, comparisons);
        quickSort(values, low, pivot - 1, comparisons);
        quickSort(values, pivot + 1, high, comparisons);
    }
}

int partition(std::vector<int>& values, int low, int high, long long& comparisons){
    int pivot = values[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; ++j) {
        comparisons++;
        if (values[j] <= pivot) {
            i++;
            std::swap(values[i], values[j]);
        }
    }
    std::swap(values[i + 1], values[high]);
    return i + 1;
}