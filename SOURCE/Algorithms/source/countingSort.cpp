#include "../header/countingSort.hpp"

template<class T>
void countingSort(std::vector<T>& array)
{
    T Max = 0;
    size_t n = array.size();
    for (size_t i = 0; i < n; i++)
    {
        if (array[i] > Max)
        {
            Max = array[i];
        }
    }
    std::vector<T> frequency(Max + 1, 0);
    for (size_t i = 0; i < n; i++)
    {
        frequency[array[i]]++;
    }
    for (size_t i = 1; i <= Max; i++)
    {
        frequency[i] += frequency[i - 1];
    }
    std::vector<T> temp(n);
    for (int i = n - 1; i >= 0; i--)
    {
        temp[frequency[array[i]] - 1] = array[i];
        frequency[array[i]]--;
    }

    array = temp;
}

template<class T>
void countingSort(std::vector<T>& array, size_t& count_comparison)
{
    T Max = 0;
    size_t n = array.size();
    for (size_t i = 0; ++count_comparison && i < n; i++)
    {
        if (++count_comparison && array[i] > Max)
        {
            Max = array[i];
        }
    }
    std::vector<T> frequency(Max + 1, 0);
    for (size_t i = 0; ++count_comparison && i < n; i++)
    {
        frequency[array[i]]++;
    }
    for (size_t i = 1; i <= Max; i++)
    {
        frequency[i] += frequency[i - 1];
    }
    std::vector<T> temp(n);
    for (int i = n - 1; ++count_comparison && i >= 0; i--)
    {
        temp[frequency[array[i]] - 1] = array[i];
        frequency[array[i]]--;
    }
    array = temp;
}

// INSTANTIATION
//heapSort
template void countingSort(std::vector<int>&);

template void countingSort(std::vector<long long>&);

//heapSort with compare
template void countingSort(std::vector<int>&, size_t&);

template void countingSort(std::vector<long long>&, size_t&);