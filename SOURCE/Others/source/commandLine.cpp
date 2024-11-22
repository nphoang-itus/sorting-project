#include "../header/commandLine.hpp"
#include "../header/dataGenerator.hpp"
#include "../header/helpFunctions.hpp"
#include "../header/sortExperiment.hpp"

void executeWithCommandLine(SortExperiment &experiment, int &argc, char **&argv) {
    if (argc == 1) {
        return;
    }

    else if (!strcmp(argv[1], "-a")) {
        experiment.is_algorithm_mode = true;
    }
    else if (!strcmp(argv[1], "-c")) {
        experiment.is_algorithm_mode = false;
    }
    else {
        std::cout << "Invalid mode: only -a for algorithm mode and -c for compare mode\n";
        return;
    }

    if (experiment.is_algorithm_mode) {
        experiment.algorithm_id[0] = getAlgorithmID(argv[2]);
        experiment.is_input_from_file = !isNumber(argv[3]);

        if (experiment.is_input_from_file) {
            commandLine1(experiment, argc, argv);
        }

        else {
            experiment.input_size = atoi(argv[3]);
            experiment.is_running_all = isOutputParameterID(argv[4]);

            if (!experiment.is_running_all) {
                commandLine2(experiment, argc, argv);
            }

            else {
                commandLine3(experiment, argc, argv);
            }
        }
    }

    else {
        experiment.algorithm_id[0] = getAlgorithmID(argv[2]);
        experiment.algorithm_id[1] = getAlgorithmID(argv[3]);
        experiment.is_input_from_file = isNumber(argv[4]);

        if (experiment.is_input_from_file) {
            commandLine4(experiment, argc, argv);
        }

        else {
            commandLine5(experiment, argc, argv);
        }
    }

    if (experiment.is_algorithm_mode) {
        experiment.runAlgorithmMode();
    }

    else {
        experiment.runCompareMode();
    }

    experiment.printResult();
    return;
    
}

void commandLine1(SortExperiment &experiment, int &argc, char **&argv) {
    experiment.file_name = argv[3];
            
    if (!readData(experiment.arr[0], argv[3])) {
        exit(true);
    }

    experiment.output_parameter = getOutputParameterID(argv[4]);
}

void commandLine2(SortExperiment &experiment, int &argc, char **&argv) {
    experiment.data_order_id = getDataOrderID(argv[4]);
    experiment.output_parameter = getOutputParameterID(argv[5]);
    experiment.arr[0].resize(experiment.input_size);
    char file_name[] = "input.txt";

    generateData(experiment.arr[0], experiment.input_size, experiment.data_order_id);
    writeData(experiment.arr[0], file_name);
}

void commandLine3(SortExperiment &experiment, int &argc, char **&argv) {
    experiment.output_parameter = getOutputParameterID(argv[4]);

    for (int i = 0; i < NUMBER_SORT_ALGORITHM; i++) {
        experiment.arr[i].resize(experiment.input_size);
        generateData(experiment.arr[i], experiment.input_size, i);
        char file_name[] = "input_0.txt";
        file_name[6] = i + 1 + '0';
        writeData(experiment.arr[i], file_name);
    }
}

void commandLine4(SortExperiment &experiment, int &argc, char **&argv) {
    experiment.file_name = argv[4];

    if (!readData(experiment.arr[0], argv[4])) {
        exit(true);
    }
}

void commandLine5(SortExperiment &experiment, int &argc, char **&argv) {
    experiment.input_size = atoi(argv[4]);
    experiment.data_order_id = getDataOrderID(argv[5]);

    if (experiment.data_order_id == -1) {
        std::cout << "Invalid data order syntax!\n";
        std::cout << "Try: -rand, -sorted, -rev, -nsorted\n";
        return;
    }

    experiment.arr[0].resize(experiment.input_size);
    char file_name[] = "input.txt";
    generateData(experiment.arr[0], experiment.input_size, experiment.data_order_id);
    writeData(experiment.arr[0], file_name);
}