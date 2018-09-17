/*
Riad Shash (Ray)
Insertion Sort C++ implementation
*/

#include <iostream>

void swap(int &num1, int &num2);
void insertionSort(int array[], const int &arraySize);
void printArray(int array[], const int &arraySize);

int main(void){

    //Needs an array +1 bigger than the size
    int ary1[10+1] = {9,4,2,5,7,8,1,0,6,3};
    std::cout<<"Insertion Sort \n";
    std::cout<<"Array: { 9,4,2,5,7,8,1,0,6,3 } \n";
    insertionSort(ary1,10);
    std::cout<<"After sorting (using Insertion Sort): ";
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

/*
Insertion Sort algorithm
Needs an array +1 bigger than the size
*/
void insertionSort(int array[], const int &arraySize)
{
    int j,save;
    for(int k = arraySize - 1; k >= 0; k--){
        j = k + 1;
        save = array[k];
        array[arraySize] = save;
        while (save > array[j]){
            array[j-1] = array[j];
            j = j + 1;
        }
        array[j-1] = save;
    }
}
