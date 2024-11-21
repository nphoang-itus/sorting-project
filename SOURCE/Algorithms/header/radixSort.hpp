#pragma once
#ifndef RADIX_SORT_HPP
#define RADIX_SORT_HPP
#include "../../myLibrary.hpp"
#include "../../Others/header/helpFunctions.hpp"

template<class T>
T getMax(std::vector<T>& array, int n, long long& count_comparison);

template<class T>
void countSort(std::vector<T>& array, int n, int exp, long long& count_comparison);

template<class T>
void radixSort(std::vector<T>& array, int n, long long &count_comparison);

template<class T>
T getMax(std::vector<T>& array, int n);

template<class T>
void countSort(std::vector<T>& array, int n, int exp);

template<class T>
void radixSort(std::vector<T>& array, int n);

#endif // RADIX_SORT_HPP