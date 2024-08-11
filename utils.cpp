#include "utils.h"
#include <cstdlib>   // для std::rand и std::srand
#include <ctime>     // для std::time

std::vector<int> createRandomVector(int n) {
    std::vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        vec[i] = std::rand() % 100; // случайные числа в диапазоне от 0 до 99
    }
    return vec;
}

int bin_reach(const std::vector<int>& bin_reach_arr, int target) {
    int left = 0;
    int right = bin_reach_arr.size() - 1;

    while (left < right) { 
        int mid = left + (right - left) / 2; 

        if (target <= bin_reach_arr[mid]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    if (bin_reach_arr[left] == target) {
        return left;
    }

    return left; 
}
