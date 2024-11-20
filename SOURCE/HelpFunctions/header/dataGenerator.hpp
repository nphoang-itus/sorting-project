#pragma once
#ifndef DATA_GENERATOR_HPP
#define DATA_GENERATOR_HPP

#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>

using namespace std;

template <class T>
void Swap(T &a, T &b);
void generateRandomData(int a[], int n);
void generateSortedData(int a[], int n);
void generateReverseData(int a[], int n);
void generateData(int a[], int n, int dataType);

#endif