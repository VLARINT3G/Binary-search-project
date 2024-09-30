/**
 * @file TestBinarySearch.cpp
 * @brief Юнит-тесты для проверки класса BinarySearch.
 *
 * Этот файл содержит тесты, которые проверяют корректную работу бинарного поиска
 * с использованием библиотеки GoogleTest.
 */

#include "BinarySearch.h"
#include "gtest/gtest.h"

/**
 * @brief Тестирует базовый бинарный поиск.
 *
 * Проверяется, что бинарный поиск корректно находит элементы в массиве.
 */
TEST(BinarySearchTest, HandlesBasicSearch) {
    SearchArray arr = {5, 2, 8, 1, 3};
    BinarySearch binarySearch(arr);

    // Массив будет отсортирован как [1, 2, 3, 5, 8]
    EXPECT_EQ(binarySearch.search(1), 0);  // Ожидаем, что 1 находится на индексе 0
    EXPECT_EQ(binarySearch.search(3), 2);  // Ожидаем, что 3 находится на индексе 2
    EXPECT_EQ(binarySearch.search(5), 3);  // Ожидаем, что 5 находится на индексе 3
    EXPECT_EQ(binarySearch.search(6), arr.size());  // Элемент 6 отсутствует, возвращаем размер массива
}

/**
 * @brief Тестирует бинарный поиск в пустом массиве.
 *
 * Проверяется, что при поиске в пустом массиве результатом будет возвращен размер массива.
 */
TEST(BinarySearchTest, HandlesEmptyArray) {
    SearchArray arr = {};
    BinarySearch binarySearch(arr);

    EXPECT_EQ(binarySearch.search(1), arr.size());  // Пустой массив, элемент не найден
}
