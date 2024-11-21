#pragma once
#ifndef COMMAND_LINE_HPP
#define COMMAND_LINE_HPP

#include "sortExperiment.hpp"

void executeWithCommandLine(SortExperiment &experiment, int &argv, char **&argc);
void commandLine1(SortExperiment &experiment, int &argv, char **&argc);
void commandLine2(SortExperiment &experiment, int &argv, char **&argc);
void commandLine3(SortExperiment &experiment, int &argv, char **&argc);
void commandLine4(SortExperiment &experiment, int &argv, char **&argc);
void commandLine5(SortExperiment &experiment, int &argv, char **&argc);

#endif