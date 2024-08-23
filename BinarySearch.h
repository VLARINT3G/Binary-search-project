#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <vector>
#include <cstdint>

using SearchArray = std::vector<int32_t>;
using IndexType = std::size_t;
using ValueType = int32_t;

class BinarySearch {
public:
    explicit BinarySearch(const SearchArray& arr);
    IndexType search(ValueType target);
    void setArray(const SearchArray& arr);

private:
    SearchArray searchArray_;
};

#endif  // BINARY_SEARCH_H
