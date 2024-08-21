/**
 * @file main.cpp
 * @author Vladislav (VLARINT3G@vk.com)
 * @brief Этот файл производить бинарный поиск
 * @version 0.1
 * @date 2024-08-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "BinarySearch.h"

/**
 * @brief Основная функция, в которой происходит поиск масива string методом бинарного поиска 
 */

int main() {

    /**
     * @brief Вначале происходит Инициализация генератора случайных чисел, после формировние массива случайных чисел от 0 до 99 с последющим выводом
     * 
     */
    std::srand(std::time(0)); 

    int n = 10; // Длина вектора
    std::vector<int32_t> main_arr(n);
    for (int i = 0; i < n; ++i) {
        main_arr[i] = std::rand() % 100; // Случайные числа в диапазоне от 0 до 99
    }

    /**
     * @brief 
     * 
     */
    std::cout << "Original vector: ";
    for (const auto& num : main_arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    /**
     * @brief Далее происходит сортировака массива и вывод отсортированного массива
     * 
     */
    std::sort(main_arr.begin(), main_arr.end());

    std::cout << "Sorted vector: ";
    for (const auto& num : main_arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    /**
     * @brief Ицициализация значения, вводимого значения с клавиатуры
     * 
     */
    int user_target;
    std::cout << "Type down a digit for search: ";
    std::cin >> user_target;

    /**
     * @brief Использование объект класса BinarySearch и выполнение поиска

     * 
     */
    BinarySearch<int32_t> binary_search(main_arr);
    int result = binary_search.search(user_target);

    if (result < main_arr.size() && main_arr[result] == user_target) {
        std::cout << "Your element is in " << result + 1 << "-th place" << std::endl;
    } else {
        std::cout << "Your element is not found. It could be placed at position " << result + 1 << std::endl;
    }

    return 0;
}
