#pragma once
#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

template <class T>
void quickSort(std::vector<T> &array);

template <class T>
void quickSort(std::vector<T> &array, size_t &count_comparison);

#endif // QUICK_SORT_HPP