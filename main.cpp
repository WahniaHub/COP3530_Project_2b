#include <iostream>
#include <vector>

#include "merge_sort.cpp"
#include "quick_sort.cpp"

void printValues(const std::vector<int>& values) {
    for (int i = 0; i < static_cast<int>(values.size()); ++i) {
        if (i > 0) {
            std::cout << ' ';
        }
        std::cout << values[i];
    }
    std::cout << std::endl;
}

int main() {

    return 0;
}