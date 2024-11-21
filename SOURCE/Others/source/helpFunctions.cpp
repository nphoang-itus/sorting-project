#include "../header/helpFunctions.hpp"
#include <time.h>
#include <stdlib.h>

template <class T>
void swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

int max(int array[], int n, long long &countComparison) {
	int max_idx = 0;

	for (int i = 1; ++countComparison && (i < n); i++)
		if (++countComparison && (array[max_idx] < array[i]))
			max_idx = i;

	return array[max_idx];
}

int max(int a, int b, long long &countComparison) {
	countComparison++;

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

template void swap(int&, int&);
template void swap(long long&, long long&);
template void swap(float&, float&);
template void swap(double&, double&);
template void swap(char&, char&);