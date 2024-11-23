#include "Others/header/commandLine.hpp"

int main(int argc, char **argv) {
    SortExperiment experiment;

    executeWithCommandLine(experiment, argc, argv);

    return 0;
}