/*
Riad Shash (Ray)
Merge Sort C++
*/

#include <iostream>
#include <cassert>
#include <cmath>

template <class T>
void printArray(T array[], const int& arraySize) {
	std::cout << "{ ";
	for (int i = 0; i < arraySize; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << "}";
}


template <class T>
void compareArray(int actual[], int expected[], const int& n) {
	for (int i = 0; i < n; i++)
		assert(actual[i] == expected[i]);
}

/*
	Axiliary function in Merge Sort
	p,q,r are indices into the array (int)
	sentinelVal is the value that is greater than all the elements
 */
template <class T>
void merge(T array[], int p, int q, int r, T sentinelVal) {
	int n1 = q - p + 1;
	int n2 = r - q;
	//std::cout << "n1 = " << n1 << " n2 = " << n2 << std::endl;
	T *L = new T[n1 + 1];
	T *R = new T[n2 + 1];
	for (int i = 0; i < n1; i++)
		L[i] = array[p + i];
	for (int j = 1; j <= n2; j++)
		R[j-1] = array[q + j];
	L[n1] = sentinelVal;
	R[n2] = sentinelVal;
	//printArray<T>(L, n1 + 1);
	//printArray<T>(R, n2 + 1);
	int i = 0;
	int j = 0;
	for (int k = p; k <= r; k++) {
		if (L[i] <= R[j]) {
			array[k] = L[i];
			i++;
		}
		else {
			array[k] = R[j];
			j++;
		}
	}
	delete[] L;
	delete[] R;
}

template <class T>
void mergeSort(T array[], int p, int r, T sentinelVal) {
	if (p < r) {
		int q = floor((p + r) / 2);
		mergeSort<T>(array, p, q, sentinelVal);
		mergeSort<T>(array, q+ 1, r, sentinelVal);
		merge<T>(array, p, q, r, sentinelVal);
	}
}

void testMerge() {
	int actArray[8] = { 2,4,5,7,1,2,3,6 };
	int expArray[8] = { 1,2,2,3,4,5,6,7 };
	merge<int>(actArray, 0, 3, 7, 1000);
	compareArray<int>(actArray, expArray, 8);
	std::cout << "Merge Test passed!\n";
}

void testMergeSort() {
	int actual[10] = { 9,4,2,5,7,8,1,0,6,3 };
	int expected[10] = { 0,1,2,3,4,5,6,7,8,9 };
	mergeSort<int>(actual, 0, 9, 10000);
	compareArray<int>(actual, expected, 10);
	std::cout << "Merge Sort Test passed!\n";
}

int main(void) {
	std::cout << "Merge Sort \n";
	testMerge();
	testMergeSort();
	return 0;
}