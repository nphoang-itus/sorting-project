#include "../header/quickSort.hpp"

template<class T>
int Partition(std::vector<T>& array, int low, int high, size_t& count_comparison)
{
    int mid = (low + high) >> 1;
    T pivot = array[mid];
    int index_pivot = mid;
    if (++count_comparison && pivot > array[low] && ++count_comparison && pivot > array[high])
    {
        if (++count_comparison && array[low] > array[high])
        {
            pivot = array[low];
            index_pivot = low;
        }
        else 
        {
            pivot = array[high];
            index_pivot = high;
        }
    }
    else 
    {
        if (++count_comparison && pivot < array[low] && ++count_comparison && pivot < array[high])
        {
            if (++count_comparison && array[low] < array[high])
            {
                pivot = array[low];
                index_pivot = low;
            }
            else 
            {
                pivot = array[high];
                index_pivot = high;
            }
        }
    }
    int i = low - 1;
    for (int j = low; ++count_comparison && j <= high - 1; j++)
    {
        if (++count_comparison && array[j] < pivot)
        {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[index_pivot]);
    return i + 1;
}

template<class T>
void impleQuickSort(std::vector<T>& array, int low, int high, size_t& count_comparison)
{
    if (++count_comparison && low < high)
    {
        int par = Partition(array, low, high, count_comparison);
        impleQuickSort(array, low, par - 1, count_comparison);
        impleQuickSort(array, par + 1, high, count_comparison);
    }
}

template<class T>
void quickSort(std::vector<T>& array, size_t& count_comparison) 
{
    impleQuickSort(array, 0, array.size() - 1, count_comparison);
}

template<class T>
int Partition(std::vector<T>& array, int low, int high)
{
    int mid = (low + high) >> 1;
    T pivot = array[mid];
    int index_pivot = mid;
    if (pivot > array[low] && pivot > array[high])
    {
        if (array[low] > array[high])
        {
            pivot = array[low];
            index_pivot = low;
        }
        else 
        {
            pivot = array[high];
            index_pivot = high;
        }
    }
    else 
    {
        if (pivot < array[low] && pivot < array[high])
        {
            if (array[low] < array[high])
            {
                pivot = array[low];
                index_pivot = low;
            }
            else 
            {
                pivot = array[high];
                index_pivot = high;
            }
        }
    }
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[index_pivot]);
    return i + 1;
}

template<class T>
void impleQuickSort(std::vector<T>& array, int low, int high)
{
    if (low < high)
    {
        int par = Partition(array, low, high);
        impleQuickSort(array, low, par - 1);
        impleQuickSort(array, par + 1, high);
    }
}

template<class T>
void quickSort(std::vector<T>& array) 
{
    impleQuickSort(array, 0, array.size() - 1);
}

// INSTANTIATION
//heapSort
template int Partition(std::vector<int>&, int, int);
template void impleQuickSort(std::vector<int>&, int, int);
template void quickSort(std::vector<int>&);

template int Partition(std::vector<long long>&, int, int);
template void impleQuickSort(std::vector<long long>&, int, int);
template void quickSort(std::vector<long long>&);

template int Partition(std::vector<double>&, int, int);
template void impleQuickSort(std::vector<double>&, int, int);
template void quickSort(std::vector<double>&);

template int Partition(std::vector<float>&, int, int);
template void impleQuickSort(std::vector<float>&, int, int);
template void quickSort(std::vector<float>&);

template int Partition(std::vector<char>&, int, int);
template void impleQuickSort(std::vector<char>&, int, int);
template void quickSort(std::vector<char>&);

//heapSort with compare
template int Partition(std::vector<int>&, int, int, size_t&);
template void impleQuickSort(std::vector<int>&, int, int, size_t&);
template void quickSort(std::vector<int>&, size_t&);

template int Partition(std::vector<long long>&, int, int, size_t&);
template void impleQuickSort(std::vector<long long>&, int, int, size_t&);
template void quickSort(std::vector<long long>&, size_t&);

template int Partition(std::vector<double>&, int, int, size_t&);
template void impleQuickSort(std::vector<double>&, int, int, size_t&);
template void quickSort(std::vector<double>&, size_t&);

template int Partition(std::vector<float>&, int, int, size_t&);
template void impleQuickSort(std::vector<float>&, int, int, size_t&);
template void quickSort(std::vector<float>&, size_t&);

template int Partition(std::vector<char>&, int, int, size_t&);
template void impleQuickSort(std::vector<char>&, int, int, size_t&);
template void quickSort(std::vector<char>&, size_t&);