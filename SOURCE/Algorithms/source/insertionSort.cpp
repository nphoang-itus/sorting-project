#include "../header/helpFunctions.hpp"
#include "../header/insertionSort.hpp"

template <class T>
void insertionSort(std::vector<T> &arr, long long &count_comparison) {
    count_comparison = 0; // Initialize comparison counter

    for (size_t i = 1; i < arr.size(); ++i) {
        T key = arr[i];
        size_t j = i;

        // Shift elements of arr[0..i-1] that are greater than key
        while (j > 0 && arr[j - 1] > key) {
            ++count_comparison; // Increment comparison counter
            arr[j] = arr[j - 1];
            --j;
        }
        if (j > 0) {
            ++count_comparison; // Increment comparison for the final check
        }
        arr[j] = key; // Place the key in its correct position
    }
}

template <class T>
void insertionSort(std::vector<T> &arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        T key = arr[i];
        size_t j = i;

        // Shift elements of arr[0..i-1] that are greater than key
        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = key; // Place the key in its correct position
    }
}


// INSTANTIATION
//selectionSort with Compare
template void insertionSort(std::vector<int>&, long long&);
template void insertionSort(std::vector<long long>&, long long&);
template void insertionSort(std::vector<float>&, long long&);
template void insertionSort(std::vector<double>&, long long&);
template void insertionSort(std::vector<char>&, long long&);

// selectionSort
template void insertionSort(std::vector<int>&);
template void insertionSort(std::vector<long long>&);
template void insertionSort(std::vector<float>&);
template void insertionSort(std::vector<double>&);
template void insertionSort(std::vector<char>&);

