#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include <vector>

class BinarySearch {
private:
    std::vector<int> search_array;

public:
    
    BinarySearch(const std::vector<int>& arr) : search_array(arr) {}

   
    int search(int target);

   
    void setArray(const std::vector<int>& arr) {
        search_array = arr;
    }
};

#endif // BINARYSEARCH_H