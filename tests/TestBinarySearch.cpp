#include "gtest/gtest.h"
#include "../src/BinarySearch.h"

/**
 * @brief Тест проверяет, как бинарный поиск работает с массивом, содержащим отрицательные числа.
 * 
 */
TEST(BinarySearchTest, HandlesNegativeValues) {
    SearchArray<int32_t> arr = {-10, -5, 0, 5, 10};
    BinarySearch<int32_t> binarySearch(arr);

    EXPECT_EQ(binarySearch.search(-10), 0);
    EXPECT_EQ(binarySearch.search(-5), 1);
    EXPECT_EQ(binarySearch.search(0), 2);
    EXPECT_EQ(binarySearch.search(5), 3);
    EXPECT_EQ(binarySearch.search(10), 4);
}
/**
 * @brief Тест проверяет работу бинарного поиска с массивом, содержащим дубликаты.
 * 
 */
TEST(BinarySearchTest, HandlesDuplicateValues) {
    SearchArray<int32_t> arr = {1, 2, 2, 2, 3, 4, 5};
    BinarySearch<int32_t> binarySearch(arr);

    EXPECT_EQ(binarySearch.search(2), 1); // Первый индекс с элементом 2
    EXPECT_EQ(binarySearch.search(3), 4);
    EXPECT_EQ(binarySearch.search(5), 6);
    EXPECT_EQ(binarySearch.search(0), 0); // 0 мог бы быть вставлен на индекс 0
    EXPECT_EQ(binarySearch.search(6), 7); // 6 мог бы быть вставлен на индекс 7
}
/**
 * @brief Тест проверяет работу бинарного поиска на большом массиве, содержащем миллион элементов
 * 
 */
TEST(BinarySearchTest, HandlesLargeArray) {
    const IndexType n = 1000000;
    SearchArray<int32_t> arr(n);
    for (IndexType i = 0; i < n; ++i) {
        arr[i] = i * 2; // Четные числа от 0 до 1999998
    }
    BinarySearch<int32_t> binarySearch(arr);

    EXPECT_EQ(binarySearch.search(1999998), n - 1); // Последний элемент
    EXPECT_EQ(binarySearch.search(0), 0);           // Первый элемент
    EXPECT_EQ(binarySearch.search(500000), 250000); // Элемент в середине
    EXPECT_EQ(binarySearch.search(1), 1);           // Нечетное число не в массиве, должно вернуть индекс 1
}
/**
 * @brief Тест проверяет работу бинарного поиска на массиве, где все элементы одинаковы.
 * 
 */
TEST(BinarySearchTest, HandlesSingleValueRepeated) {
    SearchArray<int32_t> arr = {7, 7, 7, 7, 7};
    BinarySearch<int32_t> binarySearch(arr);

    EXPECT_EQ(binarySearch.search(7), 0);  // Все элементы равны 7, так что 7 найдется на индексе 0
    EXPECT_EQ(binarySearch.search(6), 0);  // 6 мог бы быть вставлен на индекс 0
    EXPECT_EQ(binarySearch.search(8), 5);  // 8 мог бы быть вставлен на индекс 5
}
/**
 * @brief Тест проверяет работу бинарного поиска с массивом строк.
 * 
 */
TEST(BinarySearchTest, HandlesStrings) {
    SearchArray<std::string> arr = {"apple", "banana", "cherry", "date", "fig", "grape"};
    BinarySearch<std::string> binarySearch(arr);

    EXPECT_EQ(binarySearch.search("apple"), 0);
    EXPECT_EQ(binarySearch.search("cherry"), 2);
    EXPECT_EQ(binarySearch.search("grape"), 5);
    EXPECT_EQ(binarySearch.search("banana"), 1);
    EXPECT_EQ(binarySearch.search("orange"), 4); // "orange" нет в массиве, но его можно вставить на место "fig"
}
