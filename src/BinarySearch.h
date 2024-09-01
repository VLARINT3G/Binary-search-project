/**
 * @file BinarySearch.h
 * @brief Заголовочный файл для класса BinarySearch.
 *
 * Этот файл содержит описание класса BinarySearch, который реализует
 * бинарный поиск в отсортированном массиве целых чисел.
 */

#pragma once

#include <vector>
#include <cstddef> // Для size_t и ptrdiff_t
#include <cstdint> // Для int32_t

using IndexType = std::size_t; ///< Тип индекса для массива.
using SearchArray = std::vector<int32_t>;  ///< Определение типа для использования вектора целых чисел.

/**
 * @class BinarySearch
 * @brief Класс, реализующий алгоритм бинарного поиска.
 *
 * Этот класс предоставляет методы для выполнения бинарного поиска
 * в отсортированном массиве целых чисел.
 */
class BinarySearch {
public:
    /**
     * @brief Конструктор класса BinarySearch.
     * @param arr Входной массив для инициализации объекта.
     */
    explicit BinarySearch(const SearchArray& arr);

    /**
     * @brief Метод для выполнения бинарного поиска.
     * @param target Число, которое необходимо найти в массиве.
     * @return Индекс числа в массиве или размер массива, если число не найдено.
     */
    IndexType search(int32_t target) const;

    /**
     * @brief Метод для установки нового массива.
     * @param arr Новый массив для поиска.
     */
    void setArray(const SearchArray& arr);

private:
    SearchArray _searchArray;  ///< Внутренний массив, используемый для выполнения бинарного поиска.
};
