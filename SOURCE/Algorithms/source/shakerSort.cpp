#include "../header/shakerSort.hpp"

template<class T>
void shakerSort(std::vector<T>& array, long long &count_comparison) 
{
    //cài đặt hàm shakerSort
    int start = 0;                          //biến giữ vị trí biên trái
    int End = array.size() - 1;                        //biến giữ vị trí biên phải
    while (++count_comparison && start <= End)                     //Tương tự với Bubble Sort nhưng chạy từ cả 2 phía chưa được sắp xếp
    {
        for (int i = start; ++count_comparison && i < End; i++)    //Chạy từ bên trái đẩy phần tử lớn nhất lên trên cùng của vị trí chưa được sắp xếp
        {
            if (++count_comparison && array[i] > array[i + 1])
            {
                swap<T>(array[i], array[i + 1]);
            }
        }
        End--;
        for (int i = End - 1; ++count_comparison && i >= start; i--) //Chạy từ bên phải đẩy phần tử thấp nhất xuống dưới cùng của vị trí chưa được sắp xếp
        {
            if (++count_comparison && array[i] > array[i + 1])
            {
                swap<T>(array[i], array[i + 1]);
            }
        }
        start++;
    }
}

template<class T>
void shakerSort(std::vector<T>& array) {
    //cài đặt hàm shakerSort
    int start = 0;                          //Biến giữ vị trí biên trái
    int End = array.size() - 1;                        //Biến giữ vị trí biên phải
    while (start <= End)                     //Tương tự với Bubble Sort nhưng chạy từ cả 2 phía chưa được sắp xếp
    {
        for (int i = start; i < End; i++)    //Chạy từ bên trái đẩy phần tử lớn nhất lên trên cùng của vị trí chưa được sắp xếp
        {
            if (array[i] > array[i + 1])
            {
                swap<T>(array[i], array[i + 1]);
            }
        }
        End--;
        for (int i = End - 1; i >= start; i--) //Chạy từ bên phải đẩy phần tử thấp nhất xuống dưới cùng của vị trí chưa được sắp xếp
        {
            if (array[i] > array[i + 1])
            {
                swap<T>(array[i], array[i + 1]);
            }
        }
        start++;
    }
}

// INSTANTIATION
//shakerSort
template void shakerSort(std::vector<int>&);
template void shakerSort(std::vector<long long>&);
template void shakerSort(std::vector<double>&);
template void shakerSort(std::vector<float>&);
template void shakerSort(std::vector<char>&);

//shakerSort with compare
template void shakerSort(std::vector<int>&, long long&);
template void shakerSort(std::vector<long long>&, long long&);
template void shakerSort(std::vector<double>&, long long&);
template void shakerSort(std::vector<float>&, long long&);
template void shakerSort(std::vector<char>&, long long&);