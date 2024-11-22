#pragma once
#ifndef DATA_GENERATOR_HPP
#define DATA_GENERATOR_HPP

#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>

template <class T>
void generateRandomData(std::vector<int> &arr, int n);
void generateSortedData(std::vector<int> &arr, int n);
void generateReverseData(std::vector<int> &arr, int n);
void generateData(std::vector<int> &arr, int n, int dataType);
std::string getDataOrderName(int data_order_id);
int getDataOrderID(char agr_flag[]);

#endif