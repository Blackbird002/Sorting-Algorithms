# Sorting-Algorithms
Various sorting algorithms that I have encountered in Computer Science

## Terminology:
- **Loop Invariant**: any condition or value of any variable that must be true before and after each iteration of any loop
1. **Initialization**: It is true prior to the first iteration of the loop
2. **Maintenance**: If it is true before an iteration of the loop, it remains true before the next iteration
3. **Termination**: When the loop terminates, the invariant gives us a useful property that helps show the correctless of the algorithm
- **In place sort**: rearranges the numbers/objects within the array


## Bubble Sort
The simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.
It is very popular (easy to remember), but inefficient.

Algorithm (Introduction to Algorithms 3rd Edition - Cormen, Leiserson, Rivest, Stein):

```
BubbleSort(A)
  for i = 1 to A.length - 1
    for j = A.length downto i + 1
      if A[j] < A[j-1]
        exchange A[j] with A[j-1]
```

**Time Complexity:** O(n^2) worst case

## Selection Sort
A sorting algorithm (aka in-place comparison sort). Algorithm divides the input into two parts: a sub-list of items already sorted and a sub-list of items remaining to be sorted.
It does not adapt to the data in any way. 
<br>
**Time Complexity:** O(n^2)

## Insertion Sort
A simple sorting algorithm that builds the final sorted array/list one item at a time. It's an efficient algorithm for sorting a small number of elements. Uses the **incremental approach**. Since we have a sorted subarray A[1...j-1], we insert a single element A[j] into the proper place which results in the sorted subarray A[1..j].

Algorithm (Introduction to Algorithms 3rd Edition - Cormen, Leiserson, Rivest, Stein):
```
Insertion-Sort(A)
  for j = 2 to A.length
    key = A[j];
    i = j - 1
    while i > 0 and A[i] > key
      A[i + 1] = A[i]
      i = i - 1
    A[i + 1] = key
```
- Algorithm of choice if data is **nearly sorted**
- Uses a **loop invariant**: At the start of each iteration of the for loop, the subarray A[1..j-1] consists of the elements originally in A[1..j-1], but it's sorted.
- Best case: array is **already sorted**
- Worst case: array is in **reverse order**
- **In place** sort
- Time Complexity: **O(n^2)** worst case

## Merge Sort
Sort that follows the **divide-and-conquer approach:**
1. **Divide**: Devides n-element sequence to be sorted into 2 subsequences of n/2
2. **Conquer**: Sorts the two subsequences recursively using merge sort
3. **Combine**: Merges the two sorted subsequences

Algorithm (Introduction to Algorithms 3rd Edition - Cormen, Leiserson, Rivest, Stein):
```
Merge(A,p,q,r)
  n1 = q - p + 1
  n2 = r - q
  let L[1..n1 + 1] and R1[1..n2 + 1] be new arrays
  for i = 1 to n1
    L[i] = A[p + i - 1]
  for j = 1 to n2
    R[j] = A[q + j]
  L[n1 + 1] = sentinel
  L[n2 + 2] = sentinel
  i = 1
  j = 1
  for k = p to r
    if L[i] <= R[j]
      A[k] = L[i]
      i = i + 1
    else
      A[k] = R[j]
      j = j + 1
```

```
MergeSort(A,p,r)
  if p < r
    q = floor((p + r)/2)
    MergeSort(A,p,q)
    MergeSort(A,q+1,r)
    Merge(A,p,q,r);
```
- Since it's recursive, we need to use a **recurrence equation** to describe running time of a problem of size n 
- Running Time: **O(n lg n)**

![Recursive Tree](/Docs/Images/mergeSortRecTree.jpg)

## Counting Sort
Uses supplied information about the range of numbers from 0 to k in the array. 
It determines for each element in the array x, the number of elements that are less than x.
It then uses that information to place the element x directly into position in array.
<br>
**Time Complexity:** O(n + k)

## Quick Sort
Sort that follows the **divide-and-conquer approach:**
1. **Divide**: Partition the array A[p..r] into two subarrays A[p..q-1] and A[q+1..r] such that each element of A[p..q-1] is 
less than or equal to A[q], which is, in turn, less than or equal to each element of A[q+1..r]. 
2. **Conquer**: Sort the two subarrays A[p..q-1] and A[q+1..r] by recursive calls to quicksort
3. **Combine**: Because subarrays are already sorted, no further work is needed to combine them: entire array A[p..r] is now sorted

Algorithm (Introduction to Algorithms 3rd Edition - Cormen, Leiserson, Rivest, Stein):
```
/* p --> Starting index
 r --> Ending index */
QuickSort(A,p,r)
  if p < r
    q = Partition(A,p,r)
    QuickSort(A,p,q-1)
    QuickSort(A,q+1,r)
```
Initial call is QuckSort(A,1,A.length)

Partition rearanges the subarray A[p..r] in place.
```
Partition(A,p,r)
  x = A[r]
  i = p - 1
  for j = p to r - 1
    if A[j] <= x
      i = i + 1
      exchange A[i] with A[j]
  exchange A[i + 1] with A[r]
  return i + 1
```