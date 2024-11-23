#pragma once

#include "../../Others/header/helpFunctions.hpp"

#ifndef SHAKER_SORT_HPP
#define SHAKER_SORT_HPP

template<class T>
void shakerSort(std::vector<T>& array);

template<class T>
void shakerSort(std::vector<T>& array, long long& count_comparison);

#endif // SHAKER_SORT_HPP