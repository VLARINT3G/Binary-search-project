#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "BinarySearch.h"

int main() {
    std::srand(std::time(0)); // Инициализация генератора случайных чисел

    int n = 10; // Длина вектора
    std::vector<int32_t> main_arr(n);
    for (int i = 0; i < n; ++i) {
        main_arr[i] = std::rand() % 100; // Случайные числа в диапазоне от 0 до 99
    }

    // Вывод случайного вектора длиной 10
    std::cout << "Original vector: ";
    for (const auto& num : main_arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Сортировка вектора
    std::sort(main_arr.begin(), main_arr.end());

    // Печать отсортированного вектора
    std::cout << "Sorted vector: ";
    for (const auto& num : main_arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Значение для поиска
    int user_target;
    std::cout << "Type down a digit for search: ";
    std::cin >> user_target;

    // Создаем объект класса BinarySearch и выполняем поиск
    BinarySearch<int32_t> binary_search(main_arr);
    int result = binary_search.search(user_target);

    if (result < main_arr.size() && main_arr[result] == user_target) {
        std::cout << "Your element is in " << result + 1 << "-th place" << std::endl;
    } else {
        std::cout << "Your element is not found. It could be placed at position " << result + 1 << std::endl;
    }

    return 0;
}
