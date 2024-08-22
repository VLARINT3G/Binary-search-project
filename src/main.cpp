#include "BinarySearch.h"

BinarySearch::BinarySearch(const SearchArray& arr)
    : _searchArray(arr) {
}

IndexType BinarySearch::search(int32_t target) {
    IndexType left = 0;
    IndexType right = _searchArray.size() - 1;

    while (left < right) {
        IndexType mid = left + (right - left) / 2;

        if (target <= _searchArray[mid]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    if (_searchArray[left] == target) {
        return left;
    }

    return left;
}

void BinarySearch::setArray(const SearchArray& arr) {
    _searchArray = arr;
}
