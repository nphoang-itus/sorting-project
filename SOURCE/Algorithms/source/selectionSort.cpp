#include "../../Others/header/helpFunctions.hpp"
#include "../header/selectionSort.hpp"

template <class T>
void selectionSort(std::vector<T>& array) {
    for (size_t i = 0; i < array.size() - 1; ++i) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < array.size(); ++j) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        swap<T>(array[i], array[minIndex]);
    }
}

template <class T>
void selectionSort(std::vector<T> array, size_t &countComparison) {
    countComparison = 0;
    for (size_t i = 0; ++countComparison && i < array.size() - 1; ++i) {
        size_t minIndex = i;
        for (size_t j = i + 1; ++countComparison && j < array.size(); ++j) {
            if (++countComparison && array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        swap<T>(array[i], array[minIndex]);
    }
}

// INSTANTIATION
// selectionSort
template void selectionSort(std::vector<int>&);
template void selectionSort(std::vector<long long>&);
template void selectionSort(std::vector<float>&);
template void selectionSort(std::vector<double>&);
template void selectionSort(std::vector<char>&);

//selectionSort with Compare
template void selectionSort(std::vector<int>, size_t&);
template void selectionSort(std::vector<long long>, size_t&);
template void selectionSort(std::vector<float>, size_t&);
template void selectionSort(std::vector<double>, size_t&);
template void selectionSort(std::vector<char>, size_t&);