#include "../header/sortExperiment.hpp"
#include "../header/dataGenerator.hpp"

SortExperiment::SortExperiment() {
    arr.resize(NUMBER_SORT_ALGORITHM);
    results.resize(NUMBER_SORT_ALGORITHM);
}

SortExperiment::~SortExperiment() {
    int size = arr.size();

    for (int i = 0; i < size; i++) {
        arr[i].clear();
    }

    arr.clear();
    results.clear();
}

void SortExperiment::printResult() {
    if (is_algorithm_mode) {
        std::cout << "ALGORITHM MODE\n";
        std::cout << "Algorithm: " << getAlgorithmName(algorithm_id[0]) << '\n';

        if (is_input_from_file) {
            std::cout << "Input file: " << file_name << '\n';
        }

        std::cout << "Input size: " << input_size << '\n';

        int number_data_order = is_running_all ? NUMBER_DATA_ORDER : 1;

        for (int i = 0; i < number_data_order; i++) {
            if (!is_input_from_file) {
                std::cout << "Input order: " << getDataOrderName(i) << '\n';
            }

            std::cout << "------------------------------------\n";

            if (output_parameter == 3) {
                std::cout << "Running time: " << results[i].running_time.count() << " ms\n";
                std::cout << "Comparisons: " << results[i].count_comparison << '\n';
            }
            else if (output_parameter == 2) {
                std::cout << "Comparisons: " << results[i].count_comparison << '\n';
            }
            else {
                std::cout << "Running time: " << results[i].running_time.count() << " ms\n";
            }
        }
    }
    else {
        std::cout << "COMPARE MODE\n";
        std::cout << "Algorithm: " << getAlgorithmName(algorithm_id[0]) << " | " << getAlgorithmName(algorithm_id[1]) << '\n';

        if (is_input_from_file) {
            std::cout << "Input file: " << file_name << '\n';
        }

        std::cout << "Input size: " << input_size << '\n';
        
        if (!is_input_from_file) {
            std::cout << "Input order: " << getDataOrderName(data_order_id) << '\n';
        }

        std::cout << "---------------------------------------------\n";
        std::cout << "Running time: " << results[0].running_time.count() << " | " << results[1].running_time.count() << '\n';
        std::cout << "Comparisons: " << results[0].count_comparison << " | " << results[0].count_comparison << '\n';
    }

    return;
}

void SortExperiment::runCompareMode() {

}
        
void SortExperiment::runAlgorithmMode() {

}



void sort(std::vector<int> &arr, int algorithm_id, long long &count_comparison) {

}

void sort(std::vector<int> &arr, int algorithm_id, std::chrono::duration<double, std::milli> &running_time) {

}

std::string getAlgorithmName(int algorithm_id) {
    switch(algorithm_id) {
        case SELECTION_SORT:
            return "Selection Sort";
        case INSERTION_SORT:
            return "Insertion Sort";
        case BUBBLE_SORT:
            return "Bubble Sort";
        case SHAKER_SORT:
            return "Shaker Sort";
        case SHELL_SORT:
            return "Shell Sort";
        case HEAP_SORT:
            return "Heap Sort";
        case MERGE_SORT:
            return "Merge Sort";
        case QUICK_SORT:
            return "Quick Sort";
        case COUNTING_SORT:
            return "Counting Sort";
        case RADIX_SORT:
            return "Radix Sort";
        case FLASH_SORT:
            return "Flash Sort";
        case BINARY_INSERTION_SORT:
            return "Binary Insertion Sort";
        default:
            return "Unknown sort algorithm";
    }
}

int getAlgorithmID(std::string sort_name) {
    if (sort_name == "selection-sort") {
        return SELECTION_SORT;
    }
    
    else if (sort_name == "binary-insertion-sort") {
        return BINARY_INSERTION_SORT;
    }

    else if (sort_name == "insertion-sort") {
        return INSERTION_SORT;
    }
    
    else if (sort_name == "bubble-sort") {
        return BUBBLE_SORT;
    } 
    
    else if (sort_name == "shaker-sort") {
        return SHAKER_SORT;
    } 
    
    else if (sort_name == "shell-sort") {
        return SHELL_SORT;
    } 
    
    else if (sort_name == "heap-sort") {
        return HEAP_SORT;
    } 
    
    else if (sort_name == "merge-sort") {
        return MERGE_SORT;
    } 
    
    else if (sort_name == "quick-sort") {
        return QUICK_SORT;
    } 
    
    else if (sort_name == "counting-sort") {
        return COUNTING_SORT;
    } 
    
    else if (sort_name == "radix-sort") {
        return RADIX_SORT;
    } 
    
    else if (sort_name == "flash-sort") {
        return FLASH_SORT;
    } 
    
    return -1;
}