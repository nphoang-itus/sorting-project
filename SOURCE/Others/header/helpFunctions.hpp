#pragma once
#ifndef HELP_FUNCTIONS
#define HELP_FUNCTIONS

#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>

void swap(int &a, int &b);
int max(int array[], int n, long long &count_comparison);
int max(int a, int b, long long &count_comparison);
int max(int array[], int n);
int max(int a, int b);
int random(int l, int r);

bool readData(std::vector<int> &arr, char *fileName);
bool writeData(std::vector<int> &arr, char *fileName);
bool isNumber(char *str);
int getOutputParameterID(char *param_flag);
bool isOutputParameterID(char *param_flag);

#endif