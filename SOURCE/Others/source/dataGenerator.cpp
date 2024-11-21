#include "../header/dataGenerator.hpp"
#include "../header/helpFunctions.hpp"

//-------------------------------------------------

// This function generates a random array
void generateRandomData(int a[], int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % n;
	}
}

// This function generates a sorted array (ascending order)
void generateSortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}

// This function generates a reverse-sorted array (descending order)
void generateReverseData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}

// This function generates a nearly-sorted array
void generateNearlySortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}

	srand((unsigned int) time(NULL));
	
	for (int i = 0; i < 10; i ++)
	{
		int r1 = rand() % n;
		int r2 = rand() % n;
		swap(a[r1], a[r2]);
	}
}

void generateData(int a[], int n, int dataType)
{
	switch (dataType)
	{
	case 0:	
		generateRandomData(a, n);
		break;
	case 1:	
		generateSortedData(a, n);
		break;
	case 2:	
		generateReverseData(a, n);
		break;
	case 3:	
		generateNearlySortedData(a, n);
		break;
	default:
		std::cout << "Error: unknown data type!\n";
	}
}

std::string getDataOrderName(int data_order_id) {
    switch (data_order_id) {
        case 0:
            return "Randomized data";
        case 1:
            return "Sorted data";
        case 2:
            return "Reverse sorted data";
        case 3:
            return "Nearly sorted data";
        default:
            return "Unknown data order";
    }
}

int getDataOrderID(char agr_flag[]) {

    if (!strcmp(agr_flag, "-rand")) return 0;
    else if (!strcmp(agr_flag, "-sorted")) return 1;
    else if (!strcmp(agr_flag, "-rev")) return 2;
    else if (!strcmp(agr_flag, "-nsorted")) return 3;

    return -1;
}