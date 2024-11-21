#include "../header/bubbleSort.hpp"

void bubbleSort(int arr[], int n, long long &count_comparison) {
    count_comparison = 0;
    bool swapped = false;

    // loop through the array
    for (int i = 0; ++count_comparison && (i < n - 1); i++) {
        swapped = false;
        // Bring the largest element to the end
        for (int j = 0; ++count_comparison && (j < n - i - 1); j++) {
            if (++count_comparison && (arr[j] > arr[j + 1])) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
 
        // If no two elements were swapped by inner loop, then break
        if (++count_comparison && (swapped == false))
            break;
    }
}

void bubbleSort(int arr[], int n) {
    bool swapped = false;

    // loop through the array
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        // Bring the largest element to the end
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
 
        // If no two elements were swapped by inner loop, then break
        if (swapped == false)
            break;
    }
}