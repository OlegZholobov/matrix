#include "getNumberOfOrderedRows.hpp"

bool isOrderedArray(int* arr, size_t n){
    for(size_t i = 1; i < n; ++i){
        if(arr[i - 1] >= arr[i]) return false;
    }
    return true;
}

size_t getNumberOfOrderedRows(int **matrix, size_t m, size_t n) {
    size_t count = 0;
    for(size_t i = 0; i < m; ++i){
        if(isOrderedArray(matrix[i], n)){
            ++count;
        }
    }
    return count;
}
