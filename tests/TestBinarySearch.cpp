/**
 * @file TestBinarySearch.cpp
 * @brief Юнит-тесты для класса BinarySearch.
 *
 * Этот файл содержит юнит-тесты для проверки корректности работы класса
 * BinarySearch с использованием библиотеки Google Test.
 */

#include "BinarySearch.h"
#include "gtest/gtest.h"

/**
 * @brief Тест проверяет корректную работу поиска с отрицательными значениями.
 */
TEST(BinarySearchTest, HandlesNegativeValues) {
    SearchArray arr = {-10, -5, 0, 5, 10};
    BinarySearch binarySearch(arr);
    EXPECT_EQ(binarySearch.search(-10), 0);  // Первый элемент
    EXPECT_EQ(binarySearch.search(-5), 1);   // Второй элемент
    EXPECT_EQ(binarySearch.search(0), 2);    // Третий элемент
    EXPECT_EQ(binarySearch.search(5), 3);    // Четвертый элемент
    EXPECT_EQ(binarySearch.search(10), 4);   // Пятый элемент
}

/**
 * @brief Тест проверяет работу бинарного поиска с дубликатами в массиве.
 */
TEST(BinarySearchTest, HandlesDuplicateValues) {
    SearchArray arr = {1, 2, 2, 2, 3, 4, 5};
    BinarySearch binarySearch(arr);
    // Текущая реализация может вернуть любое вхождение дубликата (не обязательно первое)
    EXPECT_TRUE(binarySearch.search(2) >= 1 && binarySearch.search(2) <= 3);  // Допускается любое из вхождений
    EXPECT_EQ(binarySearch.search(3), 4);  // Для элемента 3 ожидаем индекс 4
    EXPECT_EQ(binarySearch.search(5), 6);  // Для элемента 5 ожидаем индекс 6
}

/**
 * @brief Тест проверяет работу бинарного поиска на большом массиве.
 */
TEST(BinarySearchTest, HandlesLargeArray) {
    const IndexType n = 1000000;
    SearchArray arr(n);
    for (IndexType i = 0; i < n; ++i) {
        arr[i] = i * 2;  // Заполняем массив четными числами
    }
    BinarySearch binarySearch(arr);

    EXPECT_EQ(binarySearch.search(1999998), n - 1);  // Последний элемент
    EXPECT_EQ(binarySearch.search(0), 0);  // Первый элемент
    EXPECT_EQ(binarySearch.search(500000), 250000);  // Элемент в середине
    EXPECT_EQ(binarySearch.search(1), arr.size());  // Элемент отсутствует
}

/**
 * @brief Тест проверяет работу бинарного поиска на массиве с повторяющимися значениями.
 */
TEST(BinarySearchTest, HandlesSingleValueRepeated) {
    SearchArray arr = {7, 7, 7, 7, 7};
    BinarySearch binarySearch(arr);

    // Любой индекс от 0 до 4 допустим, так как элемент повторяется
    EXPECT_TRUE(binarySearch.search(7) >= 0 && binarySearch.search(7) <= 4);
    // Для отсутствующих элементов 6 и 8 ожидаем, что их нет в массиве
    EXPECT_EQ(binarySearch.search(6), arr.size());  // Элемент отсутствует
    EXPECT_EQ(binarySearch.search(8), arr.size());  // Элемент отсутствует
}
