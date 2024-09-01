/**
 * @file BinarySearch.cpp
 * @brief Реализация методов класса BinarySearch.
 *
 * Этот файл содержит реализацию методов класса BinarySearch,
 * который выполняет бинарный поиск в массиве целых чисел.
 */

#include "BinarySearch.h"
#include <algorithm> // Для std::sort
#include <cstdint>   // Для int32_t

BinarySearch::BinarySearch(const SearchArray& arr) : _searchArray(arr) {}

IndexType BinarySearch::search(int32_t target) const {
    // Реализация бинарного поиска
    auto it = std::lower_bound(_searchArray.begin(), _searchArray.end(), target);
    if (it != _searchArray.end() && *it == target) {
        return std::distance(_searchArray.begin(), it);
    }
    return _searchArray.size(); // Если не найдено
}

void BinarySearch::setArray(const SearchArray& arr) {
    _searchArray = arr;
}
