/**
 * @file BinarySearch.h
 * @author Vladislav
 * @brief Класс BinarySearch для бинарного поиска в массиве целых чисел
 * @version 0.1
 * @date 2024-08-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <vector>
#include <cstdint>

using SearchArray = std::vector<int32_t>;
using IndexType = std::size_t;

/**
 * @brief Класс BinarySearch реализует алгоритм бинарного поиска в массиве целых чисел.
 */
class BinarySearch {
public:
    explicit BinarySearch(const SearchArray& arr);
    IndexType search(int32_t target);
    void setArray(const SearchArray& arr);

private:
    SearchArray _searchArray;
};

#endif  // BINARY_SEARCH_H
