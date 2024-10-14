#include <BinarySearch.h>
#include <SimpleLogger.h>
#include <algorithm>  // Для std::sort

/**
 * @brief Конструктор класса BinarySearch.
 *
 * Инициализирует объект бинарного поиска и сохраняет переданный массив.
 *
 * @param arr Массив целых чисел для поиска.
 */
BinarySearch::BinarySearch(const IntArray& arr) : data(arr) {}

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
    IntArray sortedArray = data;
    std::sort(sortedArray.begin(), sortedArray.end());

    SimpleLogger::log("Starting binary search for value: " + std::to_string(target));

    IndexType left = 0;
    IndexType right = sortedArray.size();

    while (left + 1 < right) {
        IndexType mid = (left + right) / 2;

        SimpleLogger::log("Checking middle index: " + std::to_string(mid) +
                          ", value: " + std::to_string(sortedArray[mid]));

        if (sortedArray[mid] <= target) {
            left = mid;
        } else {
            right = mid;
        }
    }

    if (left < sortedArray.size() && sortedArray[left] == target) {
        SimpleLogger::log("Element found at index: " + std::to_string(left));
        return left;
    }

    SimpleLogger::log("Element not found.");
    return sortedArray.size();
}

/**
 * @brief Метод для установки нового массива.
 *
 * Заменяет текущий массив на новый, предоставленный пользователем.
 *
 * @param arr Новый массив целых чисел.
 */
void BinarySearch::setArray(const IntArray& arr) {
    data = arr;
}
