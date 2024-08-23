#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "BinarySearch.h"

int main() {
    std::srand(static_cast<unsigned>(std::time(0)));

    const IndexType n = 10;
    SearchArray mainArr(n);
    for (IndexType i = 0; i < n; ++i) {
        mainArr[i] = std::rand() % 100;
    }

    std::cout << "Original vector: ";
    for (ValueType num : mainArr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::sort(mainArr.begin(), mainArr.end());

    std::cout << "Sorted vector: ";
    for (ValueType num : mainArr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    ValueType userTarget;
    std::cout << "Type down a digit for search: ";
    std::cin >> userTarget;

    BinarySearch binarySearch(mainArr);
    IndexType result = binarySearch.search(userTarget);

    if (result < mainArr.size() && mainArr[result] == userTarget) {
        std::cout << "Your element is in "
                  << result + 1 << "-th place" << std::endl;
    } else {
        std::cout << "Your element is not found. It could be placed at position "
                  << result + 1 << std::endl;
    }

    return 0;
}
