#pragma once

#include "../../Others/header/helpFunctions.hpp"

#ifndef BINARY_INSERTION_SORT_HPP
#define BINARY_INSERTION_SORT_HPP

template<class T>
size_t binarySearch(std::vector<T>& array, T target, size_t low, size_t high);

template <class T>
void binaryInsertionSort (std::vector<T>& array);

template<class T>
size_t binarySearch(std::vector<T>& array, T target, size_t low, size_t high, size_t& count_comparison);

template <class T>
void binaryInsertionSort (std::vector<T>& array, size_t& count_comparison);

#endif // BINARYINSERTION_SORT_HPP