#pragma once

#include "../../Others/header/helpFunctions.hpp"

#ifndef HEAP_SORT_HPP
#define HEAP_SORT_HPP

template<class T>
void heapify(std::vector<T>& array, int n, int i, long long& count_comparison);

template<class T>
void heapSort(std::vector<T>& array, int n, long long& count_comparison);

template<class T>
void heapify(std::vector<T>& array, int n, int i);

template<class T>
void heapSort(std::vector<T>& array, int n);

#endif // HEAP_SORT_HPP