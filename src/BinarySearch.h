/**
 * @file BinarySearch.h
 * @brief Заголовочный файл для реализации бинарного поиска.
 * @version 0.1
 * @date 2024-08-21
 *
 * Данный файл содержит определение класса BinarySearch, который реализует алгоритм бинарного поиска
 * для массива целых чисел (int32_t). Класс позволяет искать элемент в отсортированном массиве и получать
 * его индекс.
 */

#pragma once

#include <vector>
#include <cstdint>

/**
 * @typedef SearchArray
 * @brief Определение типа для массива поиска.
 */
using SearchArray = std::vector<int32_t>;

/**
 * @typedef IndexType
 * @brief Определение типа для индексов в массиве.
 */
using IndexType = std::size_t;

/**
 * @class BinarySearch
 * @brief Класс для выполнения бинарного поиска в массиве целых чисел.
 *
 * Класс предоставляет методы для установки массива и поиска элемента
 * с использованием бинарного поиска. Поиск осуществляется без использования итераторов.
 */
class BinarySearch {
public:
    /**
     * @brief Конструктор класса BinarySearch.
     * @param arr Массив целых чисел для поиска.
     */
    explicit BinarySearch(const SearchArray& arr);

    /**
     * @brief Выполняет бинарный поиск заданного элемента в массиве.
     *
     * @param target Целое число, которое нужно найти.
     * @return IndexType Индекс найденного элемента или ближайшего к нему.
     */
    IndexType search(int32_t target) const;

    /**
     * @brief Устанавливает новый массив для поиска.
     *
     * @param arr Новый массив целых чисел.
     */
    void setArray(const SearchArray& arr);

private:
    SearchArray _searchArray; ///< Внутренний массив для хранения данных.
};
