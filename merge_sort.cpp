#include "merge_sort.h"

void merge(std::vector<int>& left, std::vector<int>& right,
           std::vector<int>& result, long long& comparisons) {
    const int leftSize = static_cast<int>(left.size());
    const int rightSize = static_cast<int>(right.size());
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < leftSize && j < rightSize) {
        comparisons++;
        if (left[i] <= right[j]) {
            result[k] = left[i];
            i++;
            k++;
        } else {
            result[k] = right[j];
            j++;
            k++;
        }
    }

    while (i < leftSize) {
        result[k] = left[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        result[k] = right[j];
        j++;
        k++;
    }
}

std::vector<int> mergeSort(std::vector<int> list, long long& comparisons) {
    if (list.size() <= 1) {
        return list;
    }

    const int mid = static_cast<int>(list.size()) / 2;
    std::vector<int> left(list.begin(), list.begin() + mid);
    std::vector<int> right(list.begin() + mid, list.end());

    left = mergeSort(left, comparisons);
    right = mergeSort(right, comparisons);

    std::vector<int> result(left.size() + right.size());
    merge(left, right, result, comparisons);
    return result;
}

void merge(std::vector<Track>& left, std::vector<Track>& right,
           std::vector<Track>& result, TrackComparator comparator,
           long long& comparisons) {
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;

    while (i < left.size() && j < right.size()) {
        ++comparisons;
        if (!comparator(right[j], left[i])) {
            result[k++] = left[i++];
        } else {
            result[k++] = right[j++];
        }
    }

    while (i < left.size()) {
        result[k++] = left[i++];
    }
    while (j < right.size()) {
        result[k++] = right[j++];
    }
}

std::vector<Track> mergeSort(std::vector<Track> list,
                             long long& comparisons,
                             TrackComparator comparator) {
    if (list.size() <= 1) {
        return list;
    }

    const size_t mid = list.size() / 2;
    std::vector<Track> left(list.begin(), list.begin() + mid);
    std::vector<Track> right(list.begin() + mid, list.end());

    left = mergeSort(left, comparisons, comparator);
    right = mergeSort(right, comparisons, comparator);

    std::vector<Track> result(left.size() + right.size());
    merge(left, right, result, comparator, comparisons);
    return result;
}