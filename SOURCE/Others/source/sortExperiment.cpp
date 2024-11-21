#include "../header/sortExperiment.hpp"

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

