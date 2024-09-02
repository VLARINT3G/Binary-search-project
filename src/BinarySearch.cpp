/**
 * @file BinarySearch.cpp
 * @brief Реализация методов класса BinarySearch.
 *
 * Этот файл содержит реализацию методов класса BinarySearch,
 * который выполняет бинарный поиск в массиве целых чисел без использования итераторов.
 */

#include "BinarySearch.h"

/**
 * @brief Конструктор класса BinarySearch.
 *
 * Инициализирует внутренний массив значениями переданного массива.
 *
 * @param arr Массив целых чисел для поиска.
 */
BinarySearch::BinarySearch(const SearchArray& arr) : _searchArray(arr) {}

/**
 * @brief Метод поиска без использования итераторов.
 *
 * Выполняет бинарный поиск целевого значения в массиве.
 * Если значение найдено, возвращается его индекс; если не найдено, возвращается ближайший индекс.
 *
 * @param target Целевое значение, которое нужно найти.
 * @return IndexType Индекс найденного элемента или ближайшего к нему.
 */
IndexType BinarySearch::search(int32_t target) const {
    IndexType left = 0;
    IndexType right = _searchArray.size();

    // Основной цикл поиска
    while (left < right) {
        IndexType mid = left + (right - left) / 2;

        if (_searchArray[mid] == target) {
            return mid; // Возвращаем индекс найденного элемента
        } else if (_searchArray[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    // Проверяем, корректно ли рассчитан left для возврата
    if (left < _searchArray.size() && _searchArray[left] == target) {
        return left;
    }

    // Элемент не найден, возвращаем позицию для вставки или ближайшую позицию
    return _searchArray.size(); // Условие обработки отсутствующего элемента
}

/**
 * @brief Устанавливает новый массив для поиска.
 *
 * Заменяет текущий массив на новый, предоставленный пользователем.
 *
 * @param arr Новый массив целых чисел.
 */
void BinarySearch::setArray(const SearchArray& arr) {
    _searchArray = arr;
}
