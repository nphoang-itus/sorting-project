#pragma once

#include "helpFunctions.hpp"
#include "dataGenerator.hpp"

#include "../../Algorithms/header/selectionSort.hpp"
#include "../../Algorithms/header/binaryInsertionSort.hpp"
#include "../../Algorithms/header/insertionSort.hpp"
#include "../../Algorithms/header/bubbleSort.hpp"
#include "../../Algorithms/header/shakerSort.hpp"
#include "../../Algorithms/header/shellSort.hpp"
#include "../../Algorithms/header/heapSort.hpp"
#include "../../Algorithms/header/mergeSort.hpp"
#include "../../Algorithms/header/quickSort.hpp"
#include "../../Algorithms/header/countingSort.hpp"
#include "../../Algorithms/header/radixSort.hpp"
#include "../../Algorithms/header/flashSort.hpp"

#ifndef SORT_EXPERIMENT_HPP
#define SORT_EXPERIMENT_HPP

#define NUMBER_DATA_ORDER 4 // 0: Random, 1: Sorted, 2: Reverse, 3: Nearly Sorted
#define NUMBER_SORT_ALGORITHM 12
#define SELECTION_SORT 0
#define INSERTION_SORT 1
#define BUBBLE_SORT 2
#define SHAKER_SORT 3
#define SHELL_SORT 4
#define HEAP_SORT 5
#define MERGE_SORT 6
#define QUICK_SORT 7
#define COUNTING_SORT 8
#define RADIX_SORT 9
#define FLASH_SORT 10
#define BINARY_INSERTION_SORT 11

class ResultOfSorting {
    public:
        std::chrono::duration<double, std::milli> running_time; // in milliseconds
        size_t count_comparison; // number of comparison
};

class SortExperiment {
    public:
        std::vector<std::vector<int>> arr;      // array of data to sort, we need to store 4 arrays for 4 data orders
        std::string file_name;
        int output_parameter;                   // 0: running time, 1: number of comparison, 2: both
        int input_size;                         // number of elements in the array
        int data_order_id;                      // 0: Random, 1: Sorted, 2: Reverse, 3: Nearly Sorted
        int algorithm_id[2];                    // for compare mode, we need to identify 2 algorithms
        bool is_algorithm_mode;                 // true: algorithm mode, false: compare mode
        bool is_input_from_file;                // for  command line 1 & 4
        bool is_running_all;                    // for command line 3
        std::vector<ResultOfSorting> results;   // store the result of sorting

        SortExperiment();
        ~SortExperiment();
        void runCompareMode();
        void runAlgorithmMode();
        void printResult();
};

void sort(std::vector<int> &arr, int algorithm_id, size_t &count_comparison);
void sort(std::vector<int> &arr, int algorithm_id, std::chrono::duration<double, std::milli> &running_time);
std::string getAlgorithmName(int algorithm_id);
int getAlgorithmID(std::string sort_name);

#endif