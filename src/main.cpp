#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdint>
#include "BinarySearch.h"
#include "SimpleLogger.h"  // Подключаем логгер

/**
 * @brief Главная функция программы.
 * @return Код завершения программы.
 */
int main() {
    SimpleLogger::log("Program started.");

    std::cout << "Write down quantity of elements of massive: ";
    std::size_t n;
    std::cin >> n;

    SearchArray main_arr(n);
    SimpleLogger::log("Generated array with " + std::to_string(n) + " elements.");

    for (std::size_t i = 0; i < n; ++i) {
        main_arr[i] = std::rand() % 100;
    }

    std::cout << "Random massive of digits: ";
    for (const auto& num : main_arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    SimpleLogger::log("Array sorted.");
    std::sort(main_arr.begin(), main_arr.end());
    std::cout << "Sorted massive of digits: ";
    for (const auto& num : main_arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    BinarySearch binarySearch(main_arr);

    std::cout << "Write down a digit for search: ";
    int32_t target;
    std::cin >> target;

    SimpleLogger::log("User is searching for value: " + std::to_string(target));
    IndexType index = binarySearch.search(target);
    if (index < main_arr.size() && main_arr[index] == target) {
        std::cout << "Element is found on position: " << index + 1 << "-th place." << std::endl;
        SimpleLogger::log("Element found at position: " + std::to_string(index + 1));
    } else {
        std::cout << "Element is not found." << std::endl;
        SimpleLogger::log("Element not found.");
    }

    SimpleLogger::log("Program ended.");
    return 0;
}
