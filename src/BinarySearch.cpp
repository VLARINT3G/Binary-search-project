/**
 * @file BinarySearch.cpp
 * @brief Реализация методов класса BinarySearch.
 *
 * Этот файл содержит реализацию методов класса BinarySearch,
 * который выполняет бинарный поиск в массиве целых чисел.
 */

#include "BinarySearch.h"
#include <algorithm>  // Для std::sort

/**
 * @brief Конструктор класса BinarySearch.
 *
 * Инициализирует объект бинарного поиска и сохраняет переданный массив.
 *
 * @param arr Массив целых чисел для поиска.
 */
BinarySearch::BinarySearch(const SearchArray& arr) : _searchArray(arr) {}

/**
 * @brief Метод поиска элемента в массиве.
 *
 * Выполняет бинарный поиск целевого значения в массиве.
 * Если значение найдено, возвращается его индекс; если не найдено,
 * возвращается размер массива, что означает, что элемент отсутствует.
 *
 * @param target Целевое значение для поиска.
 * @return IndexType Индекс найденного элемента или размер массива, если элемент не найден.
 */
IndexType BinarySearch::search(int32_t target) const {
    // Копируем и сортируем массив для бинарного поиска
    SearchArray sortedArray = _searchArray;
    std::sort(sortedArray.begin(), sortedArray.end());

    IndexType left = 0;
    IndexType right = sortedArray.size();  // Полуинтервал [left, right)

    // Основной цикл бинарного поиска
    while (left + 1 < right) {
        IndexType mid = (left + right) / 2;

        if (sortedArray[mid] <= target) {
            left = mid;  // Отсекаем правую часть
        } else {
            right = mid;  // Отсекаем левую часть
        }
    }

    // Проверяем, найден ли элемент на позиции left
    if (left < sortedArray.size() && sortedArray[left] == target) {
        return left;  // Возвращаем индекс найденного элемента
    }

    return sortedArray.size();  // Элемент не найден, возвращаем размер массива
}

/**
 * @brief Метод для установки нового массива.
 *
 * Заменяет текущий массив на новый, предоставленный пользователем.
 *
 * @param arr Новый массив целых чисел.
 */
void BinarySearch::setArray(const SearchArray& arr) {
    _searchArray = arr;
}
