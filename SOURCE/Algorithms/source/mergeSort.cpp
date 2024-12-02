#include "../header/mergeSort.hpp"

template<class T>
void Merge(std::vector<T>& array, size_t left, size_t mid, size_t right, size_t& count_comparison) {
    size_t n1 = mid - left + 1;
    size_t n2 = right - mid;
    std::vector<T> arrayL(n1), arrayR(n2);
    for (size_t i = 0; ++count_comparison && i < n1; i++) {
        arrayL[i] = array[i + left];
    }
    for (size_t i = 0; ++count_comparison && i < n2; i++) {
        arrayR[i] = array[i + mid + 1];
    }

    size_t i = 0, j = 0;
    size_t k = left;
    
    while(++count_comparison && i < n1 && ++count_comparison && j < n2) {
        if (++count_comparison && arrayL[i] <= arrayR[j]) {
            array[k] = arrayL[i];
            i++;
        }

        else {
            array[k] = arrayR[j];
            j++;
        }

        k++;
    }

    while(++count_comparison && i < n1) {
        array[k] = arrayL[i];
        k++;
        i++;
    }

    while(++count_comparison && j < n2) {
        array[k] = arrayR[j];
        k++;
        j++;
    }
}

template<class T>
void impleMergeSort(std::vector<T>& array, size_t left, size_t right, size_t& count_comparison) {
    if (++count_comparison && left >= right) {
        return;
    }

    size_t mid = (left + right) >> 1;
    
    impleMergeSort(array, left, mid, count_comparison);
    impleMergeSort(array, mid + 1, right, count_comparison);
    Merge(array, left, mid, right, count_comparison);
}

template<class T>
void mergeSort(std::vector<T>& array, size_t& count_comparison) {

    impleMergeSort(array, 0, array.size() - 1, count_comparison);

}

template<class T>
void Merge(std::vector<T>& array, size_t left, size_t mid, size_t right) {
    size_t n1 = mid - left + 1;
    size_t n2 = right - mid;
    std::vector<T> arrayL(n1), arrayR(n2);

    for (size_t i = 0; i < n1; i++) {
        arrayL[i] = array[i + left];
    }

    for (size_t i = 0; i < n2; i++) {
        arrayR[i] = array[i + mid + 1];
    }

    size_t i = 0, j = 0;
    size_t k = left;
    
    while(i < n1 && j < n2) {
        if (arrayL[i] <= arrayR[j]) {
            array[k] = arrayL[i];
            i++;
        }

        else {
            array[k] = arrayR[j];
            j++;
        }

        k++;
    }

    while(i < n1) {
        array[k] = arrayL[i];
        k++;
        i++;
    }

    while(j < n2) {
        array[k] = arrayR[j];
        k++;
        j++;
    }
}

template<class T>
void impleMergeSort(std::vector<T>& array, size_t left, size_t right) {
    if (left >= right) {
        return;
    }

    size_t mid = (left + right) >> 1;
    
    impleMergeSort(array, left, mid);
    impleMergeSort(array, mid + 1, right);
    Merge(array, left, mid, right);
}

template<class T>
void mergeSort(std::vector<T>& array) {
    impleMergeSort(array, 0, array.size() - 1);
}

// INSTANTIATION
//mergeSort
template void Merge(std::vector<int>&, size_t, size_t, size_t);
template void impleMergeSort(std::vector<int>&, size_t, size_t);
template void mergeSort(std::vector<int>&);

template void Merge(std::vector<long long>&, size_t, size_t, size_t);
template void impleMergeSort(std::vector<long long>&, size_t, size_t);
template void mergeSort(std::vector<long long>&);

template void Merge(std::vector<double>&, size_t, size_t, size_t);
template void impleMergeSort(std::vector<double>&, size_t, size_t);
template void mergeSort(std::vector<double>&);

template void Merge(std::vector<float>&, size_t, size_t, size_t);
template void impleMergeSort(std::vector<float>&, size_t, size_t);
template void mergeSort(std::vector<float>&);

template void Merge(std::vector<char>&, size_t, size_t, size_t);
template void impleMergeSort(std::vector<char>&, size_t, size_t);
template void mergeSort(std::vector<char>&);

//heapSort with compare
template void Merge(std::vector<int>&, size_t, size_t, size_t, size_t&);
template void impleMergeSort(std::vector<int>&, size_t, size_t, size_t&);
template void mergeSort(std::vector<int>&, size_t&);

template void Merge(std::vector<long long>&, size_t, size_t, size_t, size_t&);
template void impleMergeSort(std::vector<long long>&, size_t, size_t, size_t&);
template void mergeSort(std::vector<long long>&, size_t&);

template void Merge(std::vector<double>&, size_t, size_t, size_t, size_t&);
template void impleMergeSort(std::vector<double>&, size_t, size_t, size_t&);
template void mergeSort(std::vector<double>&, size_t&);

template void Merge(std::vector<float>&, size_t, size_t, size_t, size_t&);
template void impleMergeSort(std::vector<float>&, size_t, size_t, size_t&);
template void mergeSort(std::vector<float>&, size_t&);

template void Merge(std::vector<char>&, size_t, size_t, size_t, size_t&);
template void impleMergeSort(std::vector<char>&, size_t, size_t, size_t&);
template void mergeSort(std::vector<char>&, size_t&);