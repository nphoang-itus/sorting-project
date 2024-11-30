#pragma once
#ifndef COUNTING_SORT_HPP
#define COUNTING_SORT_HPP

#include <string.h>
#include <limits.h>
#include "../../Others/header/helpFunctions.hpp"

static const int MAX_VAL = 10000001;
extern int cnt[MAX_VAL];

template <class T>
void countingSort(std::vector<T> &array);

template <class T>
void countingSort(std::vector<T> &array, size_t &count_comparison);


#endif // COUNTING_SORT_HPP