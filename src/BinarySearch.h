#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <vector>
#include <cstdint>

template <typename T>
using SearchArray = std::vector<T>;

using IndexType = std::size_t;

template <typename T>
class BinarySearch {
public:
    explicit BinarySearch(const SearchArray<T>& arr);
    IndexType search(const T& target);
    void setArray(const SearchArray<T>& arr);

private:
    SearchArray<T> _searchArray;
};

template <typename T>
BinarySearch<T>::BinarySearch(const SearchArray<T>& arr)
    : _searchArray(arr) {
}

template <typename T>
IndexType BinarySearch<T>::search(const T& target) {
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

template <typename T>
void BinarySearch<T>::setArray(const SearchArray<T>& arr) {
    _searchArray = arr;
}

// Экземпляры шаблонов
template class BinarySearch<int32_t>;
template class BinarySearch<std::string>;

#endif  // BINARY_SEARCH_H
