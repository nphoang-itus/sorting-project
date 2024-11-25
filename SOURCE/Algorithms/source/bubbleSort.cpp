#include "../header/bubbleSort.hpp"

template <class T>
void bubbleSort(std::vector<T> &arr, size_t &count_comparison) {
    count_comparison = 0;
    bool swapped = false;

    // loop through the array
    for (int i = 0; ++count_comparison && (i < arr.size() - 1); i++) {
        swapped = false;
        // Bring the largest element to the end
        for (int j = 0; ++count_comparison && (j < arr.size() - i - 1); j++) {
            if (++count_comparison && (arr[j] > arr[j + 1])) {
                // swap(arr[j], arr[j + 1]);
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
 
        // If no two elements were swapped by inner loop, then break
        if (++count_comparison && (swapped == false))
            break;
    }
}

template <class T>
void bubbleSort(std::vector<T> &arr) {
    bool swapped = false;

    // loop through the array
    for (int i = 0; i < arr.size() - 1; i++) {
        swapped = false;
        // Bring the largest element to the end
        for (int j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap(arr[j], arr[j + 1]);
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
 
        // If no two elements were swapped by inner loop, then break
        if (swapped == false)
            break;
    }
}

template void bubbleSort(std::vector<int>&, size_t&);
template void bubbleSort(std::vector<long long>&, size_t&);
template void bubbleSort(std::vector<float>&, size_t&);
template void bubbleSort(std::vector<double>&, size_t&);
template void bubbleSort(std::vector<char>&, size_t&);

template void bubbleSort(std::vector<int>&);
template void bubbleSort(std::vector<long long>&);
template void bubbleSort(std::vector<float>&);
template void bubbleSort(std::vector<double>&);
template void bubbleSort(std::vector<char>&);