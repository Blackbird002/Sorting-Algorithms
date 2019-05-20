# Sorting-Algorithms
Various sorting algorithms that I have encountered in Computer Science

## BubbleSort
The simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order (aka sinking sort).
<br>
**Time Complexity:** O(n^2) worst case

## SelectionSort
A sorting algorithm (aka in-place comparison sort). Algorithm divides the input into two parts: a sub-list of items already sorted and a sub-list of items remaining to be sorted.
It does not adapt to the data in any way. 
<br>
**Time Complexity:** O(n^2)

## InsertionSort
A simple sorting algorithm that builds the final sorted array/list one item at a time.
- Algorithm of choice if data is **nearly sorted**
<br>
**Time Complexity:** O(n^2) worst case

## CountingSort
Uses supplied information about the range of numbers from 0 to k in the array. 
It determines for each element in the array x, the number of elements that are less than x.
It then uses that information to place the element x directly into position in array.
<br>
**Time Complexity:** O(n + k)

## QuickSort
A partition/exchange sort with two "bins": A less than bin and a greater than bin.
Variable j starts left of the list/array. Variable k starts at the right.
Variable j and k are compared to the pivot.
Quicksort then recursively sorts the sub-arrays.
<br>
**Time Complexity:** O(nlog(n))
