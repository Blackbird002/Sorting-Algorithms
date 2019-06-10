/*
Riad Shash (Ray)
Insertion Sort C++ implementation
*/

#include <iostream>
#include <cassert>
#include <random>
#include <chrono>
#include <algorithm>

//The number of random numbers to generate...
const int MaxNum = 10000;

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
void compareArray(T actual[], T expected[], const int& n) {
	for (int i = 0; i < n; i++)
		assert(actual[i] == expected[i]);
}

void testInsertionSortCase1(){
	int actual[10] = { 9,4,2,5,7,8,1,0,6,3 };
	int expected[10] = { 0,1,2,3,4,5,6,7,8,9 };
	insertionSort<int>(actual, 10);
	compareArray<int>(actual, expected, 10);
	std::cout << "Insertion Sort Case 1 passed!\n";
}

void testInsertionSortCase2() {
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
	insertionSort<double>(actual, MaxNum);

	//Expected Array is sorted here
	int n = sizeof(expected) / sizeof(expected[0]);
	std::sort(expected, expected + n);

	//Checks if array contents are exactly in the same order
	compareArray<double>(actual, expected, MaxNum);
	std::cout << "Insertion Sort Case 2 passed!\n";
}


int main(void) {
	std::cout << "Insertion Sort \n";
	testInsertionSortCase1();
	testInsertionSortCase2();
	return 0;
}

/*
//Previous insertion sort that I had...

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

