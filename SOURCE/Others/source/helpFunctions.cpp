#include "../header/helpFunctions.hpp"
#include "../header/dataGenerator.hpp"

template <class T>
void swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

int max(int array[], int n, long long &count_comparison) {
	int max_idx = 0;

	for (int i = 1; ++count_comparison && (i < n); i++)
		if (++count_comparison && (array[max_idx] < array[i]))
			max_idx = i;

	return array[max_idx];
}

int max(int a, int b, long long &count_comparison) {
	count_comparison++;

	return (a > b) ? a : b;
}

int max(int array[], int n) {
	int max_idx = 0;

	for (int i = 1; i < n; i++)
		if (array[max_idx] < array[i])
			max_idx = i;

	return array[max_idx];
}

int max(int a, int b) {
	return (a > b) ? a : b;
}

int random(int l, int r) {
    srand((unsigned int)time(nullptr));
	int ran = rand();
	
	return 1ll * ran % (r - l + 1) + l;
}
bool readData(std::vector<int> &arr, char *fileName) {
    if (!arr.empty()) {
        arr.clear();
    }
    
	std::fstream fin(fileName, std::ios::in);

    if (!fin) {
        std::cout << "Error: File not found\n";
        return false;
    }

	int size; fin >> size;
	arr.resize(size);

    for (int i = 0; i < size; i++) {
        fin >> arr[i];
    }

    fin.close();

    return true;
}

bool writeData(std::vector<int> &arr, char *fileName) {
    std::fstream fout(fileName, std::ios::out);

    if (!fout) {
        std::cout << "Error: File not found\n";
        return false;
    }

	int size = arr.size();
	fout << size << '\n';

    for (int i = 0; i < size; i++) {
        fout << arr[i] << ' ';
    }

	fout.close();

    return true;
}

bool is_number(char *str) {
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        if (str[i] < '0' || str[i] > '9') return false;
    }

    return true;
}

int getOutputParameterID(char *param_flag) {
    if (!strcmp(param_flag, "-time")) return 1;
    if (!strcmp(param_flag, "-comp")) return 2;
    if (!strcmp(param_flag, "-both")) return 3;
    return -1;
}

bool isOutputParameterID(char *param_flag) {
    if (getOutputParameterID(param_flag) == -1) {
        return false;
    }
    return true;
}

bool isNumber(char *str) {
	int len = strlen(str);

    for (int i = 0; i < len; i++) {
        if (str[i] < '0' || str[i] > '9') return false;
    }
	
    return true;
}


template void swap(int&, int&);
template void swap(long long&, long long&);
template void swap(float&, float&);
template void swap(double&, double&);
template void swap(char&, char&);