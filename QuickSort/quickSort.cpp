/*
Riad Shash (Ray)
Bubble Sort C++ implementation
*/

#include <iostream>
#include <cassert>
#include <random>
#include <chrono>
#include <algorithm>
#include <iomanip>

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
	for (int i = 0; i < n; i++) {
		assert(actual[i] == expected[i]);	
	}
}

template <class T>
void swap(T& num1, T& num2) {
	T temp = num1;
	num1 = num2;
	num2 = temp;
}

template <class T>
int Partition(T A[], int p, int r){
    T x = A[r];
    int i = p - 1;
    for(int j = p; j <= r-1; j++){
        if(A[j] < x){
            i++;
            swap<T>(A[i],A[j]);
        }
    }
    swap<T>(A[i+1],A[r]);
    return (i + 1);
}

/*
	p - low index of array (C++ -> 0)
	r - high index of array (C++ -> n-1)
*/
template <class T>
void QuickSort(T A[], int p, int r) {
	if(p < r){
        int q = Partition<T>(A,p,r);
        QuickSort<T>(A,p,q-1);
        QuickSort<T>(A,q+1,r);
    }
}

void testQuickSortCase1() {
	int actual[10] = { 9,4,2,5,7,8,1,0,6,3 };
	int expected[10] = { 0,1,2,3,4,5,6,7,8,9 };
	QuickSort<int>(actual, 0, 9);

	//Checks if array contents are exactly in the same order
	compareArray<int>(actual, expected, 10);
	std::cout << "Quick Sort Case 1 passed!\n";
}

void testQuickSortCase2() {
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
	QuickSort<double>(actual,0,MaxNum-1);

	//Expected Array is sorted here
	int n = sizeof(expected) / sizeof(expected[0]);
	std::sort(expected, expected + n);

	//printArray(expected, MaxNum);
	//std::cout<<std::endl;
	//printArray(actual, MaxNum);

	//Checks if array contents are exactly in the same order
	compareArray<double>(actual, expected, MaxNum);
	std::cout << "Quick Sort Case 2 passed!\n";
}

int main(void) {
	std::cout << std::fixed;
    std::cout << std::setprecision(2);

	std::cout << "QuickSort \n";
	testQuickSortCase1();
	testQuickSortCase2();
	return 0;
}