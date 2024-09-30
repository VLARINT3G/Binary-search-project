#pragma once

#include <vector>
#include <cstdint>

/**
 * @typedef SearchArray
 * @brief Тип данных для массива поиска.
 */
using SearchArray = std::vector<int32_t>;

/**
 * @typedef IndexType
 * @brief Тип для индексов в массиве.
 */
using IndexType = std::size_t;

/**
 * @class BinarySearch
 * @brief Класс, реализующий бинарный поиск в массиве целых чисел.
 *
 * Этот класс предоставляет методы для бинарного поиска в массиве целых чисел.
 * Метод автоматически сортирует массив при выполнении поиска.
 */
class BinarySearch {
public:
    /**
     * @brief Класс BinarySearch.
     * @param arr Массив целых чисел для поиска.
     */
    explicit BinarySearch(const SearchArray& arr);

    /**
     * @brief Выполняет бинарный поиск заданного элемента в массиве.
     * 
     * Если элемент найден, возвращается его индекс;
     * если не найден, возвращается размер массива.
     * 
     * @param target Целевое значение для поиска.
     * @return IndexType Индекс найденного элемента или размер массива, если элемент не найден.
     */
    IndexType search(int32_t target) const;

    /**
     * @brief Устанавливает новый массив для поиска.
     * 
     * @param arr Новый массив целых чисел.
     */
    void setArray(const SearchArray& arr);

private:
    SearchArray _searchArray;  ///< Внутренний массив для хранения данных.
};
