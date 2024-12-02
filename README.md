# Sorting-project
Lab 03 project in DSA: Study algorithms related to sorting techniques.

(Open Terminal in sorting-project folder)\
## Build for Windows: 

``` powershell
g++ SOURCE/Algorithms/source/*.cpp  SOURCE/Others/source/*.cpp -o bin/main.exe
```
## Build for MacOS: 

``` powershell
g++ SOURCE/Algorithms/source/*.cpp  SOURCE/Others/source/*.cpp -o bin/main
```
## Experiment
### Run Command
``` powershell
./bin/main.exe -experiment
```
### Change the size of arrays here

```cpp
int data_test[6] = {10000, 30000, 50000, 100000, 300000, 500000};
```

The ```EXPERIMENT``` flag is turned on, make the size reduced 1000 times

```cpp
#define EXPERIMENT

...code...

#ifdef EXPERIMENT
    for (int i = 0; i < 6; i++) {
        DATA_SIZE_TESTS[i] /= 1000;
    }
#endif
```

Turn off this flag, and re-build to sort in real size.

## Run

There are 5 commands to run this file

- Command 1: Run a sorting algorithm on the given input data

```
./bin/main.exe -a [Algorithm] [Input file] [Output parameter(s)]
```

For example

```sh
./bin/main.exe -a radix-sort input.txt -time
```

- Command 2: Run a sorting algorithm on the data generated automatically with specified size and order

```
./bin/main.exe -a [Algorithm] [Input size] [Input order] [Output parameter(s)]
```

For example

```sh
./bin/main.exe -a selection-sort 50 -rand -comp
```

- Command 3: Run a sorting algorithm on ALL data arrangements of a specified size

```
./bin/main.exe -a [Algorithm] [Input size] [Output parameter(s)]
```

For example

```sh
./bin/main.exe -a selection-sort 50 -both
```

- Command 4:  Run two sorting algorithms on the given input

```
./bin/main.exe -c [Algorithm 1] [Algorithm 2] [Input file]
```

For example

```sh
./bin/main.exe -c heap-sort merge-sort input.txt
```

- Command 5: Run two sorting algorithms on the data generated automatically

```
./bin/main.exe -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]
```

For example

```sh
./bin/main.exe -c quick-sort merge-sort 100000 -nsorted
```

### Input arguments

| Field               | Value       | Explain                                                       |
|---------------------|-------------|---------------------------------------------------------------|
| Mode                | -a          | Algorithm mode                                                |
|                     | -c          | Comparison mode                                               |
| Algorithm name      | bubble-sort | Lowercase, words are connected by "-"                         |
|                     | quick-sort  |                                                               |
| Input size          | 50          | any interger value, < 1e6                                     |
| Input order         | -rand       | randomized array                                              |
|                     | -nsorted    | nearly sorted array                                           |
|                     | -sorted     | sorted array                                                  |
|                     | -rev        | reversed sorted array                                         |
| Output parameter(s) | -time       | get running time                                              |
|                     | -comp       | get number of comparisons used in running time                |
|                     | -both       | get both values                                               |
| Input file          | input.txt   | any name. First line: array size n; Second line: n intergers |