#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <time.h>
#include <stdlib.h>
#include <chrono>
#include <string>

#ifndef HELP_FUNCTIONS
#define HELP_FUNCTIONS

template <class T>
void swap(T &a, T &b);

int max(int array[], int n, size_t &count_comparison);
int max(int a, int b, size_t &count_comparison);
int max(int array[], int n);
int max(int a, int b);
int random(int l, int r);

bool readData(std::vector<int> &arr, std::string fileName);
bool writeData(std::vector<int> &arr, std::string fileName);
bool isNumber(char *str);
int getOutputParameterID(char *param_flag);
bool isOutputParameterID(char *param_flag);

#endif