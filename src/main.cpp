/**
 * @file main.cpp
 * @brief Основной файл программы, демонстрирующий использование класса BinarySearch.
 *
 * Этот файл содержит пример использования класса BinarySearch
 * для выполнения бинарного поиска в массиве целых чисел.
 */

#include <iostream>
#include <vector>
#include <algorithm> // Для std::sort
#include <cstdlib>   // Для std::rand()
#include <cstdint>   // Для int32_t
#include "BinarySearch.h"

/**
 * @brief Главная функция программы.
 * @return Код завершения программы.
 */
int main() {
    std::cout << "Write down quantity of elements of massive: ";
    std::size_t n;
    std::cin >> n;

    SearchArray main_arr(n);  ///< Массив случайных чисел

    for (std::size_t i = 0; i < n; ++i) {
        main_arr[i] = std::rand() % 100;
    }

    std::cout << "Random massive of digits: ";
    for (const auto& num : main_arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

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

    IndexType index = binarySearch.search(target);
    if (index < main_arr.size() && main_arr[index] == target){
        std::cout << "Element is found on position: " << index + 1 << "-th place. " << std::endl;
    } else{
        std::cout << "Element is not found.";
    }
    return 0;
}
