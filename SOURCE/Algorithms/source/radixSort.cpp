#include "../header/radixSort.hpp"

template<class T>
T getMax(std::vector<T>& array, size_t& count_comparison)
{
    //cài đặt lấy giá trị lớn nhất (hoặc số có nhiều chữ số nhất) của radixSort
    T mx = array[0];
    size_t n = array.size();
    for (size_t i = 1; ++count_comparison && i < n; i++)
    {
        if (++count_comparison && array[i] > mx)
        {
            mx = array[i];
        }
    }
    return mx;
}

template<class T>
void countSort(std::vector<T>& array, size_t exp, size_t& count_comparison)
{
    //cài đặt hàm sắp xếp theo từng cơ số của từng chữ số trong radixSort
    size_t n = array.size();
    std::vector<T> output(n);                      //tạo một mảng tạm để lưu trữ sau khi sắp xếp theo cơ số
    int i;
    size_t cnt[10] = { 0 };                       //đếm số lần xuất hiện của từng chữ số trong cơ số 10
    for (i = 0; ++count_comparison && i < n; i++)
    {
        cnt[(array[i] / exp) % 10]++;
    }
    for (i = 1; ++count_comparison && i < 10; i++)
    {
        cnt[i] += cnt[i - 1];                   //Cộng dồn mảng đếm để có được vị trí cuối cùng với mỗi cơ số hiện tại
    }
    for (i = n - 1; ++count_comparison && i >= 0; i--)
    {
        output[cnt[(array[i] / exp) % 10] - 1] = array[i];  //Duyệt ngược mảng ban đầu để có được vị trí đúng của mảng so với mảng cộng dồn tần suất
        cnt[(array[i] / exp) % 10]--;
    }
    for (i = 0; ++count_comparison && i < n; i++)
    {
        array[i] = output[i];                      //Copy từ mảng mới về mảng ban đầu
    }
}

template<class T>
void radixSort(std::vector<T>& array, size_t& count_comparison) 
{
    //cài đặt radixSort
    size_t soChuSo = (size_t)getMax(array, count_comparison);
    for (size_t exp = 1; ++count_comparison && soChuSo / exp > 0; exp *= 10)
    {
        countSort(array, exp, count_comparison);                  //Thực hiện các chữ số từ phải cùng qua trái
    }
}

template<class T>
T getMax(std::vector<T>& array)
{
    //cài đặt lấy giá trị lớn nhất (hoặc số có nhiều chữ số nhất) của radixSort
    T mx = array[0];
    size_t n = array.size();
    for (size_t i = 1; i < n; i++)
    {
        if (array[i] > mx)
        {
            mx = array[i];
        }
    }
    return mx;
}

template<class T>
void countSort(std::vector<T>& array, size_t exp)
{
    //cài đặt hàm sắp xếp theo từng cơ số của từng chữ số trong radixSort
    size_t n = array.size();
    std::vector<T> output(n);                      //tạo một mảng tạm để lưu trữ sau khi sắp xếp theo cơ số
    int i;
    size_t cnt[10] = { 0 };                       //đếm số lần xuất hiện của từng chữ số trong cơ số 10
    for (i = 0; i < n; i++)
    {
        cnt[(array[i] / exp) % 10]++;
    }
    for (i = 1; i < 10; i++)
    {
        cnt[i] += cnt[i - 1];                   //Cộng dồn mảng đếm để có được vị trí cuối cùng với mỗi cơ số hiện tại
    }
    for (i = n - 1; i >= 0; i--)
    {
        output[cnt[(array[i] / exp) % 10] - 1] = array[i];  //Duyệt ngược mảng ban đầu để có được vị trí đúng của mảng so với mảng cộng dồn tần suất
        cnt[(array[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
    {
        array[i] = output[i];                      //Copy từ mảng mới về mảng ban đầu
    }
}

template<class T>
void radixSort(std::vector<T>& array)
{
    //cài đặt radixSort
    size_t soChuSo = (size_t)getMax(array);
    for (size_t exp = 1; soChuSo / exp > 0; exp *= 10)
    {
        countSort(array, exp);                  //Thực hiện các chữ số từ phải cùng qua trái
    }
}

// INSTANTIATION
//radixSort
template int getMax(std::vector<int>&);
template void countSort(std::vector<int>&, size_t);
template void radixSort(std::vector<int>&);

template long long getMax(std::vector<long long>&);
template void countSort(std::vector<long long>&, size_t);
template void radixSort(std::vector<long long>&);

//radixSort with compare
template int getMax(std::vector<int>&, size_t&);
template void countSort(std::vector<int>&, size_t, size_t&);
template void radixSort(std::vector<int>&, size_t&);

template long long getMax(std::vector<long long>&, size_t&);
template void countSort(std::vector<long long>&, size_t, size_t&);
template void radixSort(std::vector<long long>&, size_t&);