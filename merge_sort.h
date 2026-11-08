#pragma once
#include "track.h"
#include <vector>

// Sort values using merge sort and count element comparisons.
void merge(std::vector<int>& left, std::vector<int>& right,
           std::vector<int>& result, long long& comparisons);
std::vector<int> mergeSort(std::vector<int> list, long long& comparisons);

void merge(std::vector<Track>& left, std::vector<Track>& right,
           std::vector<Track>& result, TrackComparator comparator,
           long long& comparisons);
std::vector<Track> mergeSort(std::vector<Track> list,
                             long long& comparisons,
                             TrackComparator comparator = compareTracksByPopularity);