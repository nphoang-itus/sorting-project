#include "../header/heapSort.hpp"

template<class T>
void heapify(std::vector<T>& array, int n, int i, long long& count_comparison)
{
    //cài đặt hàm heapify của heapSort
    int largest = i;                                    //giả sử cho node cha là lớn nhất
    int left = 2 * i + 1;
    if (++count_comparison && left < n && ++count_comparison && array[largest] < array[left])           //tìm node con lớn nhất mà lớn hơn node cha
    {
        largest = left;
    }
    if (++count_comparison && left + 1 < n && ++count_comparison && array[largest] < array[left + 1])
    {
        largest = left + 1;
    }
    if (++count_comparison && largest != i)                                   //nếu node cha không phải lớn nhất thì đổi chỗ sao cho node cha lớn nhất
    {
        swap(array[i], array[largest]);
        heapify(array, n, largest);                       //đệ quy xuống node con ở dưới để node con ở dưới lớn nhất
    }
}

template<class T>
void heapSort(std::vector<T>& array, int n, long long &count_comparison) 
{
    //cài đặt hàm heapSort
    for (int i = n / 2 - 1; ++count_comparison && i >= 0; i--)                //bắt đầu từ n / 2 - 1 vì đó là phần tử cuối cùng có con
    {
        heapify(array, n, i);                             //Xây dựng max heap
    }
    for (int i = n - 1; ++count_comparison && i > 0; i--)
    {
        swap(array[0], array[i]);                           //đổi chỗ phần tử lớn nhất với phần tử phải cùng mà chưa được sắp xếp
        heapify(array, i, 0);                             //heapify tiếp mảng với số phần tử còn lại bắt đầu từ gốc
    }
}

template<class T>
void heapify(std::vector<T>& arr, int n, int i)
{
    //cài đặt hàm heapify của heapSort
    int largest = i;                                    //giả sử cho node cha là lớn nhất
    int left = 2 * i + 1;
    if (left < n && arr[largest] < arr[left])           //tìm node con lớn nhất mà lớn hơn node cha
    {
        largest = left;
    }
    if (left + 1 < n && arr[largest] < arr[left + 1])
    {
        largest = left + 1;
    }
    if (largest != i)                                   //nếu node cha không phải lớn nhất thì đổi chỗ sao cho node cha lớn nhất
    {
        Swap(arr[i], arr[largest]);
        heapify(arr, n, largest);                       //đệ quy xuống node con ở dưới để node con ở dưới lớn nhất
    }
}

template<class T>
void heapSort(std::vector<T>& arr, int n)
{
    //cài đặt hàm heapSort
    for (int i = n / 2 - 1; i >= 0; i--)                //bắt đầu từ n / 2 - 1 vì đó là phần tử cuối cùng có con
    {
        heapify(arr, n, i);                             //Xây dựng max heap
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);                           //đổi chỗ phần tử lớn nhất với phần tử phải cùng mà chưa được sắp xếp
        heapify(arr, i, 0);                             //heapify tiếp mảng với số phần tử còn lại bắt đầu từ gốc
    }
}

// INSTANTIATION
//heapSort
template void heapify(std::vector<int>&, int, int);
template void heapSort(std::vector<int>&, int);

template void heapify(std::vector<long long>&, int, int);
template void heapSort(std::vector<long long>&, int);

template void heapify(std::vector<double>&, int, int);
template void heapSort(std::vector<double>&, int);

template void heapify(std::vector<float>&, int, int);
template void heapSort(std::vector<float>&, int);

template void heapify(std::vector<char>&, int, int);
template void heapSort(std::vector<char>&, int);

//heapSort with compare
template void heapify(std::vector<int>&, int, int, long long&);
template void heapSort(std::vector<int>&, int, long long&);

template void heapify(std::vector<long long>&, int, int, long long&);
template void heapSort(std::vector<long long>&, int, long long&);

template void heapify(std::vector<double>&, int, int, long long&);
template void heapSort(std::vector<double>&, int, long long&);

template void heapify(std::vector<float>&, int, int, long long&);
template void heapSort(std::vector<float>&, int, long long&);

template void heapify(std::vector<char>&, int, int, long long&);
template void heapSort(std::vector<char>&, int, long long&);