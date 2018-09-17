/*
Riad Shash (Ray)
Quick Sort C++ implementation
*/

#include <iostream>

void swap(int &num1, int &num2);
void quickSort(int left, int right, int array[]);
void printArray(int array[], const int &arraySize);

int main(void){

    int ary1[10] = {9,4,2,5,7,8,1,0,6,3};
    std::cout<<"Quick Sort \n";
    std::cout<<"Array: { 9,4,2,5,7,8,1,0,6,3 } \n";
    quickSort(0,9,ary1);
    std::cout<<"After sorting (using Quick Sort): ";
    printArray(ary1,10);
    std::cout<<std::endl <<"Press ENTER to exit program.\n";
    std::cin.ignore();

    return 0;
}

//Swaps two given array elements
void swap(int &num1, int &num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void printArray(int array[], const int &arraySize){
    std::cout<<"{ ";
    for(int i = 0; i < arraySize; i++){
        std::cout<<array[i] <<" ";
    }
    std::cout<<"}";
}

//QuickSort sorting algorithm
void quickSort(int left, int right, int array[])
{
    int j,k;
    if (left < right){
        j = left;
        k = right + 1;
        do{
            do{
                j = j + 1;
            } while((array[j] < array[left]) && (j <= k));

            do{
                k = k - 1;
            } while((array[k] > array[left]) && (k >= 0));

            if (j < k){
                swap(array[j], array[k]);
            }
        } while(j <= k);

        swap(array[left], array[k]);
        quickSort(left, k-1, array);
        quickSort(k+1, right, array);
    }
}
