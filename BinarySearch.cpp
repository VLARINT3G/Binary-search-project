#include "BinarySearch.h"

BinarySearch::BinarySearch(const SearchArray& arr)
    : searchArray_(arr) {
}

IndexType BinarySearch::search(ValueType target) {
    IndexType left = 0;
    IndexType right = searchArray_.size() - 1;

    while (left < right) {
        IndexType mid = left + (right - left) / 2;

        if (target <= searchArray_[mid]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    if (searchArray_[left] == target) {
        return left;
    }

    return left;
}

void BinarySearch::setArray(const SearchArray& arr) {
    searchArray_ = arr;
}
