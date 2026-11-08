#include "merge_sort.h"
#include <iostream>

void merge(std::vector<int>& Left, std::vector<int>& Right, std::vector<int>& Result, long long& comparisons) {
    int leftSize = Left.size();
    int rightSize = Right.size();
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < leftSize and j < rightSize) {
        comparisons++;
        if (Left[i] <= Right[j]) {
            Result[k] = Left[i];
            i++;
            k++;
        } else {
            Result[k] = Right[j];
            j++;
            k++;
        }
    }

    while (i < leftSize) {
        Result[k] = Left[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        Result[k] = Right[j];
        j++;
        k++;
    }
}

std::vector<int> mergeSort(std::vector<int> list, long long& comparisons) {
    if (list.size() <= 1) {
        return list;
    }

    int mid = list.size() / 2;
    std::vector<int> Left(list.begin(), list.begin() + mid);
    std::vector<int> Right(list.begin() + mid, list.end());

    Left = mergeSort(Left, comparisons);
    Right = mergeSort(Right, comparisons);

    std::vector<int> Result(Left.size() + Right.size());
    merge(Left, Right, Result, comparisons);
    return Result;
}