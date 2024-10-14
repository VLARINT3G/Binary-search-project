#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdint>
#include <BinarySearch.h>
#include <SimpleLogger.h>

/**
 * @brief Главная функция программы.
 *
 * Выполняет создание случайного массива, его сортировку и поиск заданного элемента
 * с использованием бинарного поиска. Все ключевые события логируются.
 *
 * @return Код завершения программы.
 */
int main() {
    SimpleLogger::log("Program started.", LogLevel::INFO);

    std::cout << "Enter the number of elements in the array: ";
    std::size_t n;
    std::cin >> n;

    IntArray mainArray(n);
    SimpleLogger::log("Generated array with " + std::to_string(n) + " elements.", LogLevel::INFO);

    for (std::size_t i = 0; i < n; ++i) {
        mainArray[i] = std::rand() % 100;
    }

    std::cout << "Random array of numbers: ";
    for (const auto& num : mainArray) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::sort(mainArray.begin(), mainArray.end());
    SimpleLogger::log("Array sorted.", LogLevel::INFO);

    std::cout << "Sorted array of numbers: ";
    for (const auto& num : mainArray) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    BinarySearch binarySearch(mainArray);

    std::cout << "Enter a number to search for: ";
    int32_t target;
    std::cin >> target;

    SimpleLogger::log("User is searching for value: " + std::to_string(target), LogLevel::INFO);
    IndexType index = binarySearch.search(target);

    if (index < mainArray.size() && mainArray[index] == target) {
        std::cout << "Element found at position: " << index + 1 << "-th place." << std::endl;
        SimpleLogger::log("Element found at position: " + std::to_string(index + 1), LogLevel::INFO);
    } else {
        std::cout << "Element not found." << std::endl;
        SimpleLogger::log("Element not found.", LogLevel::WARNING);
    }

    SimpleLogger::log("Program ended.", LogLevel::INFO);
    return 0;
}
