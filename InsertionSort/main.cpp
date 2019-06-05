/*
Riad Shash (Ray)
Insertion Sort C++ implementation
*/

#include <iostream>
#include <cassert>

template <class T>
void insertionSort(T array[], const int& arraySize) {
	T key;
	int j, i;
	for (j = 1; j < arraySize; j++) {
		key = array[j];
		i = j - 1;
		while (i >= 0 && array[i] > key) {
			array[i + 1] = array[i];
			i--;
		}
		array[i + 1] = key;
	}
}

template <class T>
void test(int actual[], int expected[], const int& n)
{
	for (int i = 0; i < n; i++)
		assert(actual[i] == expected[i]);
	std::cout << "Test passed! \n";
}

int main(void) {
	int actual[10] = { 9,4,2,5,7,8,1,0,6,3 };
	int expected[10] = { 0,1,2,3,4,5,6,7,8,9 };
	std::cout << "Insertion Sort \n";
	insertionSort<int>(actual, 10);
	test<int>(actual, expected, 10);
	return 0;
}

/*
Insertion Sort algorithm
Needs an array +1 bigger than the size
void insertionSort(int array[], const int& arraySize){
	int j, save;
	for (int k = arraySize - 1; k >= 0; k--) {
		j = k + 1;
		save = array[k];
		array[arraySize] = save;
		while (save > array[j]) {
			array[j - 1] = array[j];
			j = j + 1;
		}
		array[j - 1] = save;
	}
}
*/

