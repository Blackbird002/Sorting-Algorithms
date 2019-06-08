/*
Riad Shash (Ray)
Bubble Sort C++ implementation
*/

#include <iostream>
#include <cassert>

template <class T>
void compareArray(int actual[], int expected[], const int& n) {
	for (int i = 0; i < n; i++)
		assert(actual[i] == expected[i]);
}

template <class T>
void swap(T& num1, T& num2) {
	T temp = num1;
	num1 = num2;
	num2 = temp;
}

template <class T>
void bubbleSort(T array[], const int& arraySize) {
	int i, j;
	for (i = 0; i < arraySize - 1; i++) {
		for (j = 0; j < arraySize - 1; j++) {
			if (array[j] > array[j + 1])
				swap(array[j], array[j + 1]);
		}
	}
}

void testBubbleSort() {
	int actual[10] = { 9,4,2,5,7,8,1,0,6,3 };
	int expected[10] = { 0,1,2,3,4,5,6,7,8,9 };
	bubbleSort<int>(actual, 10);
	compareArray<int>(actual, expected, 10);
	std::cout << "Bubble Sort Test passed!\n";
}

int main(void) {
	std::cout << "Bubble Sort \n";
	testBubbleSort();
	return 0;
}