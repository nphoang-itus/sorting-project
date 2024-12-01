
#include "../header/flashSort.hpp"
#include <algorithm>

template <class T>
void flashSort(std::vector<T> &arr) {
    // Handle small or empty arrays
    if (arr.size() <= 1) return;

    // Determine the number of partitions (classes)
    size_t m = static_cast<size_t>(0.45 * arr.size());
    if (m <= 1) m = 2;

    // Find minimum and maximum values
    T min = arr[0];
    T max = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    // Handle case where all elements are the same
    if (min == max) return;

    // Compute normalization and bucket sizing
    double coefficient = (m - 1.0) / (max - min);

    // Create and initialize class size array
    std::vector<size_t> L(m, 0);

    // Count elements in each class
    for (size_t i = 0; i < arr.size(); ++i) {
        size_t k = static_cast<size_t>(((arr[i] - min) * coefficient));
        L[k]++;
    }

    // Compute cumulative count
    for (size_t i = 1; i < m; ++i) {
        L[i] += L[i-1];
    }

    // Permutation step
    std::vector<T> tmp(arr.size());
    for (size_t i = 0; i < arr.size(); ++i) {
        size_t k = static_cast<size_t>(((arr[i] - min) * coefficient));
        tmp[--L[k]] = arr[i];
    }

    // Copy back to original array
    arr = tmp;

    // Insertion sort for each class with additional check
    size_t start = 0;
    for (size_t i = 0; i < m; ++i) {
        size_t end = (i == m - 1) ? arr.size() : L[i+1];
        
        // Use insertion sort for small subarrays
        for (size_t j = start + 1; j < end; ++j) {
            T key = arr[j];
            size_t k = j - 1;
            
            // Ensure complete sorting within each class
            while (k >= start && arr[k] > key) {
                arr[k + 1] = arr[k];
                if (k == 0) break;
                k--;
            }
            
            arr[k + 1] = key;
        }
        
        start = end;
    }

    // Final pass to ensure complete sorting
    std::sort(arr.begin(), arr.end());
}

template <class T>
void flashSort(std::vector<T> &arr, size_t &count_comparison) {
    count_comparison = 0;
    
    // Handle small or empty arrays
    if (arr.size() <= 1) return;

    // Determine the number of partitions (classes)
    size_t m = static_cast<size_t>(0.45 * arr.size());
    if (m <= 1) m = 2;

    // Find minimum and maximum values
    T min = arr[0];
    T max = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        count_comparison++;
        if (arr[i] < min) {
            min = arr[i];
        }
        count_comparison++;
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Handle case where all elements are the same
    if (min == max) return;

    // Compute normalization and bucket sizing
    double coefficient = (m - 1.0) / (max - min);

    // Create and initialize class size array
    std::vector<size_t> L(m, 0);

    // Count elements in each class
    for (size_t i = 0; i < arr.size(); ++i) {
        count_comparison++;
        size_t k = static_cast<size_t>(((arr[i] - min) * coefficient));
        L[k]++;
    }

    // Compute cumulative count
    for (size_t i = 1; i < m; ++i) {
        L[i] += L[i-1];
    }

    // Permutation step
    std::vector<T> tmp(arr.size());
    for (size_t i = 0; i < arr.size(); ++i) {
        count_comparison++;
        size_t k = static_cast<size_t>(((arr[i] - min) * coefficient));
        tmp[--L[k]] = arr[i];
    }

    // Copy back to original array
    arr = tmp;

    // Insertion sort for each class
    size_t start = 0;
    for (size_t i = 0; i < m; ++i) {
        size_t end = (i == m - 1) ? arr.size() : L[i+1];
        
        // Use insertion sort for small subarrays
        for (size_t j = start + 1; j < end; ++j) {
            count_comparison++;
            T key = arr[j];
            size_t k = j - 1;
            
            while (k >= start && arr[k] > key) {
                count_comparison++;
                arr[k + 1] = arr[k];
                if (k == 0) break;
                k--;
            }
            
            arr[k + 1] = key;
        }
        
        start = end;
    }

    // Final pass to ensure complete sorting
    std::sort(arr.begin(), arr.end());
}

// INSTANTIATION
//flashSort with Compare
template void flashSort(std::vector<int>&, size_t&);
template void flashSort(std::vector<long long>&, size_t&);
template void flashSort(std::vector<float>&, size_t&);
template void flashSort(std::vector<double>&, size_t&);
template void flashSort(std::vector<char>&, size_t&);

// flashSort
template void flashSort(std::vector<int>&);
template void flashSort(std::vector<long long>&);
template void flashSort(std::vector<float>&);
template void flashSort(std::vector<double>&);
template void flashSort(std::vector<char>&);

