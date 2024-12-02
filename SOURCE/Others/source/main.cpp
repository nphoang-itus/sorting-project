#include "../header/commandLine.hpp"

void overview() { // This function is for testing the algorithms with different data sizes and data orders
    int DATA_SIZE_TESTS[6] = {10000, 30000, 50000, 100000, 300000, 500000};
    std::vector<int> arr;

    for (int dataOrderCode = 0; dataOrderCode < 1; dataOrderCode++) {
        std::string fileName = getDataOrderName(dataOrderCode) + ".csv";
        std::ofstream out(fileName);

        out << "Data order: " << getDataOrderName(dataOrderCode) << '\n';
        out << "Data size";

        std::cout << "Data order: " << getDataOrderName(dataOrderCode) << '\n';
        std::cout << "Data size";
        for (int size_idx = 0; size_idx < 6; size_idx++) {
            out << "," << DATA_SIZE_TESTS[size_idx] << ",,";
            std::cout << "," << DATA_SIZE_TESTS[size_idx] << ",,";
        }
        out << "\nResulting statics";
        std::cout << "\nResulting statics";
        for (int size_idx = 0; size_idx < 6; size_idx++) {
            out << ", Running time, Comparison";
            std::cout << ", Running time, Comparison";
        }
        out << "\n";
        std::cout << "\n";

        for (int algorithmID = 0; algorithmID < NUMBER_SORT_ALGORITHM; algorithmID++) {
            out << getAlgorithmName(algorithmID);
            std::cout << getAlgorithmName(algorithmID);
            for (int size_idx = 0; size_idx < 6; size_idx++) {
                int data_size = DATA_SIZE_TESTS[size_idx];
                arr.resize(data_size);
                generateData(arr, data_size, dataOrderCode);

                size_t comparisons = 0;
                std::chrono::duration<double, std::milli> running_time;

                std::vector<int> arr2 = arr;
                sort(arr2, algorithmID, running_time);

                arr2 = arr;
                sort(arr2, algorithmID, comparisons);

                out << ", " << running_time.count() << ", " << comparisons;
                std::cout << ", " << running_time.count() << ", " << comparisons;
            }
            out << "\n";
            std::cout << "\n";
        }
        out.close();
    }
}

int main(int argc, char **argv) {
    SortExperiment experiment;

    executeWithCommandLine(experiment, argc, argv);
    // overview();

    return 0;
}