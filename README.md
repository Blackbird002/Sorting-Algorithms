# Sorting-Algorithms
Various sorting algorithms that I have encountered in Computer Science

## Bubble Sort
The simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order (aka sinking sort).
<br>
**Time Complexity:** O(n^2) worst case

## Selection Sort
A sorting algorithm (aka in-place comparison sort). Algorithm divides the input into two parts: a sub-list of items already sorted and a sub-list of items remaining to be sorted.
It does not adapt to the data in any way. 
<br>
**Time Complexity:** O(n^2)

## Insertion Sort
A simple sorting algorithm that builds the final sorted array/list one item at a time. It's an efficient algorithm for sorting a small number of elements. Uses the **incremental approach**.
<br>
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
- Uses a loop invaraint
- Best case: array is **already sorted**
- Worst case: array is in **reverse order**
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

## Counting Sort
Uses supplied information about the range of numbers from 0 to k in the array. 
It determines for each element in the array x, the number of elements that are less than x.
It then uses that information to place the element x directly into position in array.
<br>
**Time Complexity:** O(n + k)

## Quick Sort
A partition/exchange sort with two "bins": A less than bin and a greater than bin.
Variable j starts left of the list/array. Variable k starts at the right.
Variable j and k are compared to the pivot.
Quicksort then recursively sorts the sub-arrays.
<br>
**Time Complexity:** O(nlog(n))
