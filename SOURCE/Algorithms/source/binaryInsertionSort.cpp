#include "../header/binaryInsertionSort.hpp"

template<class T>
size_t binarySearch(std::vector<T>& array, T target, size_t low, size_t high)   // thuật toán tìm kiếm nhị phân
{
    while(low < high)
    {
        size_t mid = (low + high) >> 1;
        if (target == array[mid])
        {
            return mid + 1;
        }
        if (target > array[mid])
        {
            low = mid + 1;
        }
        else 
        {
            high = mid;
        }
    }
    if (target >= array[low])
    {
        return low + 1;
    }
    else 
    {
        return low;
    }
}

template <class T>
void binaryInsertionSort(std::vector<T>& array) 
{
    T selected;
    size_t i;
    int location, j;
    size_t n = array.size();
    for (i = 1; i < n; i++)
    {
        j = i - 1;
        selected = array[i];
        location = binarySearch(array, selected, 0, j);     //sử dụng tìm kiếm nhị phân để tìm vị trí cần chèn
        while(j >= location)                                //tương tự như Insertion Sort
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = selected;
    }
}

template<class T>
size_t binarySearch(std::vector<T>& array, T target, size_t low, size_t high, size_t& count_comparison) //thuật toán tìm kiếm nhị phân
{
    while(++count_comparison && low < high)
    {
        size_t mid = (low + high) >> 1;
        if (++count_comparison && target == array[mid])
        {
            return mid + 1;
        }
        if (++count_comparison && target > array[mid])
        {
            low = mid + 1;
        }
        else 
        {
            high = mid;
        }
    }
    if (++count_comparison && target >= array[low])
    {
        return low + 1;
    }
    else 
    {
        return low;
    }
}

template <class T>
void binaryInsertionSort(std::vector<T>& array, size_t& count_comparison) 
{
    T selected;
    size_t i;
    int location, j;
    size_t n = array.size();
    for (i = 1; ++count_comparison && i < n; i++)
    {
        j = i - 1;
        selected = array[i];
        location = binarySearch(array, selected, 0, j, count_comparison);   //tìm kiếm nhị phân để tìm kiếm vị trí cần chèn
        while(++count_comparison && j >= location)                      //Tương tự InsertionSort
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = selected;
    }
}

// INSTANTIATION
//binaryInsertionSort
template size_t binarySearch(std::vector<int>&, int, size_t, size_t);
template void binaryInsertionSort (std::vector<int>&);

template size_t binarySearch(std::vector<long long>&, long long, size_t, size_t);
template void binaryInsertionSort (std::vector<long long>&);

template size_t binarySearch(std::vector<double>&, double, size_t, size_t);
template void binaryInsertionSort (std::vector<double>&);

template size_t binarySearch(std::vector<float>&, float, size_t, size_t);
template void binaryInsertionSort (std::vector<float>&);

template size_t binarySearch(std::vector<char>&, char, size_t, size_t);
template void binaryInsertionSort (std::vector<char>&);

//binaryInsertionSort with compare
template size_t binarySearch(std::vector<int>&, int, size_t, size_t, size_t&);
template void binaryInsertionSort (std::vector<int>&, size_t&);

template size_t binarySearch(std::vector<long long>&, long long, size_t, size_t, size_t&);
template void binaryInsertionSort (std::vector<long long>&, size_t&);

template size_t binarySearch(std::vector<double>&, double, size_t, size_t, size_t&);
template void binaryInsertionSort (std::vector<double>&, size_t&);

template size_t binarySearch(std::vector<float>&, float, size_t, size_t, size_t&);
template void binaryInsertionSort (std::vector<float>&, size_t&);

template size_t binarySearch(std::vector<char>&, char, size_t, size_t, size_t&);
template void binaryInsertionSort (std::vector<char>&, size_t&);