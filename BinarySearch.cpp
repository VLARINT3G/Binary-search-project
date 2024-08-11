#include "BinarySearch.h"

int BinarySearch::search(int target) {
    int left = 0;
    int right = search_array.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (target <= search_array[mid]) {
            right = mid; // сужаем правую границу до mid
        } else {
            left = mid;  // сужаем левую границу до mid
        }
    }

    // После выхода из цикла left и right будут равны и указывать на один элемент.
    if (search_array[left] == target) {
        return left;
    }

    return left; // Элемент не найден, возвращаем индекс для возможной вставки
}
