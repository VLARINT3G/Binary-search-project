#include "gtest/gtest.h"
#include "BinarySearch.h"

TEST(BinarySearchTest, HandlesNegativeValues) {
    SearchArray arr = {-10, -5, 0, 5, 10};
    BinarySearch binarySearch(arr);

    EXPECT_EQ(binarySearch.search(-10), 0);
    EXPECT_EQ(binarySearch.search(-5), 1);
    EXPECT_EQ(binarySearch.search(0), 2);
    EXPECT_EQ(binarySearch.search(5), 3);
    EXPECT_EQ(binarySearch.search(10), 4);
}

TEST(BinarySearchTest, HandlesDuplicateValues) {
    SearchArray arr = {1, 2, 2, 2, 3, 4, 5};
    BinarySearch binarySearch(arr);

    EXPECT_EQ(binarySearch.search(2), 1);
    EXPECT_EQ(binarySearch.search(3), 4);
    EXPECT_EQ(binarySearch.search(5), 6);
    EXPECT_EQ(binarySearch.search(0), 0);
    EXPECT_EQ(binarySearch.search(6), 7);
}

TEST(BinarySearchTest, HandlesLargeArray) {
    const IndexType n = 1000000;
    SearchArray arr(n);
    for (IndexType i = 0; i < n; ++i) {
        arr[i] = i * 2;
    }
    BinarySearch binarySearch(arr);

    EXPECT_EQ(binarySearch.search(1999998), n - 1);
    EXPECT_EQ(binarySearch.search(0), 0);
    EXPECT_EQ(binarySearch.search(500000), 250000);
    EXPECT_EQ(binarySearch.search(1), 1);
}

TEST(BinarySearchTest, HandlesSingleValueRepeated) {
    SearchArray arr = {7, 7, 7, 7, 7};
    BinarySearch binarySearch(arr);

    EXPECT_EQ(binarySearch.search(7), 0);
    EXPECT_EQ(binarySearch.search(6), 0);
    EXPECT_EQ(binarySearch.search(8), 5);
}
