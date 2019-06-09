/*
Riad Shash (Ray)
Bubble Sort C++ implementation
*/

#include <iostream>
#include <cassert>
#include <random>
#include <chrono>
#include <algorithm>

//The number of random numbers to generate...
const int MaxNum = 10000;

template <class T>
void printArray(T array[], const int& arraySize) {
	std::cout << "{ ";
	for (int i = 0; i < arraySize; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << "}";
}

template <class T>
void compareArray(T actual[], T expected[], const int& n) {
	for (int i = 0; i < n; i++)
		assert(actual[i] == expected[i]);
}

template <class T>
void swap(T& num1, T& num2) {
	T temp = num1;
	num1 = num2;
	num2 = temp;
}

/*
	//Previous version of Bubble Sort that I had...

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
*/

template <class T>
void bubbleSort(T array[], const int& arraySize) {
	int i, j;
	for (i = 0; i < arraySize - 1; i++) {
		for(j = arraySize - 1; j > i; j--) {
			if (array[j] < array[j - 1])
				swap(array[j], array[j - 1]);
		}
	}
}

void testBubbleSortCase1() {
	int actual[10] = { 9,4,2,5,7,8,1,0,6,3 };
	int expected[10] = { 0,1,2,3,4,5,6,7,8,9 };
	bubbleSort<int>(actual, 10);

	//Checks if array contents are exactly in the same order
	compareArray<int>(actual, expected, 10);
	std::cout << "Bubble Sort Case 1 passed!\n";
}

void testBubbleSortCase2() {
	double randomNum = 0;
	double actual[MaxNum];
	double expected[MaxNum];

	//Generates a seed based on elapsed time since Coordinated Universal Time (UTC) 
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	//Uses the 32 - bit Mersenne Twister Random Number Engine
	std::mt19937 randomEngine(seed);
	std::uniform_real_distribution<double> myDistribution(-100000, 100000);

	for (int i = 0; i < MaxNum; i++)
	{
		randomNum = myDistribution(randomEngine);
		actual[i] = randomNum;
		expected[i] = randomNum;
	}
	//Actual array is sorted here
	bubbleSort<double>(actual, MaxNum);

	//Expected Array is sorted here
	int n = sizeof(expected) / sizeof(expected[0]);
	std::sort(expected, expected + n);

	//Checks if array contents are exactly in the same order
	compareArray<double>(actual, expected, MaxNum);
	std::cout << "Bubble Sort Case 2 passed!\n";
}

int main(void) {
	std::cout << "Bubble Sort \n";
	testBubbleSortCase1();
	testBubbleSortCase2();
	return 0;
}