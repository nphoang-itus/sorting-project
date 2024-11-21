#pragma once
#ifndef SHAKER_SORT_HPP
#define SHAKER_SORT_HPP
#include "../../myLibrary.hpp"
#include "../../Others/header/helpFunctions.hpp"

template<class T>
void shakerSort(std::vector<T>& array, int n);

template<class T>
void shakerSort(std::vector<T>& array, int n, long long& count_comparison);

#endif // SHAKER_SORT_HPP