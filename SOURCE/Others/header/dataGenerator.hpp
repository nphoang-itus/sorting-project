#pragma once
#ifndef DATA_GENERATOR_HPP
#define DATA_GENERATOR_HPP

#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <string>

template <class T>
void generateRandomData(int a[], int n);
void generateSortedData(int a[], int n);
void generateReverseData(int a[], int n);
void generateData(int a[], int n, int dataType);
std::string getDataOrderName(int data_order_id);
int getDataOrderID(char agr_flag[]);

#endif