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
    IndexType right = _searchArray.size();  // Полуинтервал [left, right)

    // Основной цикл поиска
    while (left + 1 < right) {  // Пока разница больше 1
        IndexType mid = (left + right) / 2;

        if (_searchArray[mid] <= target) {
            left = mid;  // Отсекаем правую часть
        } else {
            right = mid;  // Отсекаем левую часть
        }
    }

    // Проверяем, найден ли элемент в left
    if (left < _searchArray.size() && _searchArray[left] == target) {
        return left;
    }

    // Если элемент не найден, возвращаем размер массива
    return _searchArray.size();
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
