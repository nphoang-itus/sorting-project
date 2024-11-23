
#include "../header/flashSort.hpp"

template <class T>
void flashSort(std::vector<T> &arr, size_t &count_comparison) {
    count_comparison = 0; // Initialize comparison counter
    size_t n = arr.size();

    if (n <= 1) return; // Array is already sorted if it has 1 or no elements

    // Find the minimum and maximum elements in the array
    T min_val = arr[0], max_val = arr[0];
    size_t max_idx = 0;
    for (size_t i = 1; i < n; ++i) {
        ++count_comparison; // Increment comparison counter
        if (arr[i] < min_val) {
            min_val = arr[i];
        } else if (arr[i] > max_val) {
            max_val = arr[i];
            max_idx = i;
        }
    }

    // Calculate the number of classes (bins) and handle edge case
    if (max_val == min_val) return; // All elements are equal, no sorting needed
    size_t m = n / 2; // Number of classes (can be adjusted)
    std::vector<size_t> l(m, 0); // Classification array

    // Compute scaling factor
    double scaling_factor = static_cast<double>(m - 1) / (max_val - min_val);

    // Classify elements into classes
    for (size_t i = 0; i < n; ++i) {
        size_t class_idx = static_cast<size_t>(scaling_factor * (arr[i] - min_val));
        ++l[class_idx];
    }

    // Accumulate class counts to determine class boundaries
    for (size_t i = 1; i < m; ++i) {
        l[i] += l[i - 1];
    }

    // Perform the flash sorting
    size_t num_moved = 0;
    size_t current_class = 0;
    while (num_moved < n - 1) {
        while (current_class >= l[current_class]) {
            ++current_class; // Move to the next class
        }

        size_t pos = l[current_class] - 1;
        T temp = arr[pos];
        arr[pos] = arr[current_class];

        while (true) {
            size_t class_idx = static_cast<size_t>(scaling_factor * (temp - min_val));
            if (class_idx >= m) class_idx = m - 1; // Handle edge case
            pos = --l[class_idx];
            if (pos == current_class) break;
            std::swap(temp, arr[pos]);
            ++num_moved;
            ++count_comparison; // Increment comparison counter
        }
    }

    // Final sorting within each class using insertion sort logic
    for (size_t i = 1; i < n; ++i) {
        T key = arr[i];
        size_t j = i;
        while (j > 0 && arr[j - 1] > key) {
            ++count_comparison;
            arr[j] = arr[j - 1];
            --j;
        }
        if (j > 0) ++count_comparison;
        arr[j] = key;
    }
}

template <class T>
void flashSort(std::vector<T> &arr) {
    size_t n = arr.size();

    if (n <= 1) return; // Array is already sorted if it has 1 or no elements

    // Find the minimum and maximum elements in the array
    T min_val = arr[0], max_val = arr[0];
    size_t max_idx = 0;
    for (size_t i = 1; i < n; ++i) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        } else if (arr[i] > max_val) {
            max_val = arr[i];
            max_idx = i;
        }
    }

    // Calculate the number of classes (bins)
    if (max_val == min_val) return; // All elements are equal, no sorting needed
    size_t m = n / 2; // Number of classes (can be adjusted)
    std::vector<size_t> l(m, 0); // Classification array

    // Compute scaling factor
    double scaling_factor = static_cast<double>(m - 1) / (max_val - min_val);

    // Classify elements into classes
    for (size_t i = 0; i < n; ++i) {
        size_t class_idx = static_cast<size_t>(scaling_factor * (arr[i] - min_val));
        ++l[class_idx];
    }

    // Accumulate class counts to determine class boundaries
    for (size_t i = 1; i < m; ++i) {
        l[i] += l[i - 1];
    }

    // Perform the flash sorting
    size_t num_moved = 0;
    size_t current_class = 0;
    while (num_moved < n - 1) {
        while (current_class >= l[current_class]) {
            ++current_class; // Move to the next class
        }

        size_t pos = l[current_class] - 1;
        T temp = arr[pos];
        arr[pos] = arr[current_class];

        while (true) {
            size_t class_idx = static_cast<size_t>(scaling_factor * (temp - min_val));
            pos = --l[class_idx];
            if (pos == current_class) break;
            std::swap(temp, arr[pos]);
            ++num_moved;
        }
    }

    // Final sorting within each class
    for (size_t i = 1; i < n; ++i) {
        T key = arr[i];
        size_t j = i;
        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = key;
    }
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

