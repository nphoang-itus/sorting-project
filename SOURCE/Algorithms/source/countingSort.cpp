#include "../header/countingSort.hpp"

template <class T>
void countingSort(std::vector<T> &array) {
    std::memset(cnt, 0, sizeof(cnt));
    int maxValue = INT_MIN;

    for (int i = 0; i < array.size(); ++i) {
        cnt[array[i]]++;
        maxValue = max(maxValue, array[i]);
    }

    int idx = 0;
    for (int i = 0; i <= maxValue; ++i) {
        for (; cnt[i]; --cnt[i], l++) {
            array[l] = i;
        }
    }
}

template <class T>
void countingSort(std::vector<T> &array, long long &count_comparison) {
    count_comparison = 0;

    std::memset(cnt, 0, sizeof(cnt));
    int maxValue = INT_MIN;

    for (int i = 0; ++count_comparison && i < array.size(); ++i) {
        cnt[array[i]]++;
        maxValue = max(maxValue, array[i], count_comparison);
    }

    int idx = 0;
    for (int i = 0; ++count_comparison && i <= maxValue; ++i) {
        for (; ++count_comparison && cnt[i]; --cnt[i], l++) {
            array[l] = i;
        }
    }
}

// INSTANTIATION
// Counting Sort
template void countingSort(std::vector<int>&);
template void countingSort(std::vector<long long>&);
template void countingSort(std::vector<float>&);
template void countingSort(std::vector<double>&);

// Counting Sort with Com
template void countingSort(std::vector<int>&, long long&);
template void countingSort(std::vector<long long>&, long long&);
template void countingSort(std::vector<float>&, long long&);
template void countingSort(std::vector<double>&, long long&);