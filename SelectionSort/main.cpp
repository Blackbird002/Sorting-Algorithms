/*
Riad Shash (Ray)
Selection Sort C++ implementation
*/

#include <iostream>

void swap(int &num1, int &num2);
void selectionSort(int array[], const int &arraySize);
void printArray(int array[], const int &arraySize);

int main(void){

    int ary1[10] = {9,4,2,5,7,8,1,0,6,3};
    std::cout<<"Selection Sort \n";
    std::cout<<"Array: { 9,4,2,5,7,8,1,0,6,3 } \n";
    selectionSort(ary1,10);
    std::cout<<"After sorting (using Selection Sort): ";
    printArray(ary1,10);
    std::cin.ignore();

    return 0;
}

//Swaps two given array elements
void swap(int &num1, int &num2){
    double temp = num1;
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

//Selection Sort algorithm
void selectionSort(int array[], const int &arraySize){
    int k,j,small;
    if (arraySize > 0){
        for(k = 0; k< arraySize-1; k++){
            small = k;
            for(j = k+1; j < arraySize; j++){
                if(array[j] < array[small])
                    small = j;
            }
            if (k != small){
                swap(array[k],array[small]);
            }
        }
    }
}

