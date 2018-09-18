/*
Riad Shash (Ray)
Selection Sort C++ implementation
*/

#include <iostream>

void swap(int &num1, int &num2);

void printArray(int array[], const int &arraySize);

int main(void){

    int ary1[10] = {9,4,2,5,7,8,1,0,6,3};
    std::cout<<"Selection Sort \n";
    std::cout<<"Array: { 9,4,2,5,7,8,1,0,6,3 } \n";
    
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



