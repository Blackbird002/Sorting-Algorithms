/*
Riad Shash (Ray)
Counting Sort C++ implementation
*/

#include <iostream>
void printArray(int array[], const int &arraySize);
void countingSort(int A[], const int &sizeA, const int &k);

int main(void){

    int arraySize = 12;
    int ary1[arraySize] = {55,23,14,5,38,17,36,99,51,74,64,31};
    std::cout<<"Counting Sort \n";
    std::cout<<"Before: " <<std::endl;
    printArray(ary1,arraySize);
    countingSort(ary1,arraySize, 99);
    std::cout<<std::endl;
    std::cout<<"After: " <<std::endl;
    printArray(ary1,arraySize);

    //Wait for user to press enter
    std::cin.ignore();

    return 0;
}

//Prints the array to the screen
void printArray(int array[], const int &arraySize){
    std::cout<<"{ ";
    for(int i = 0; i < arraySize; i++){
        std::cout<<array[i] <<" ";
    }
    std::cout<<"}";
}

/*
    A - Array A (the array we send to function)
    B - Array B (we build this array)
    sizeA - size of A
    k - range from 0 to k, for some integer k
*/
void countingSort(int A[], const int &sizeA, const int &k){
    //Create array C of size k
    //K needs 1 more due to 0 index
    int C[k+1] = {0};

    //Creare array B of size A
    int B[sizeA] = {0};

    for(int j = 0; j < sizeA; j++)
        C[A[j]] = C[A[j]] + 1;
    //C[i] now has the number of elements eqaul to i

    for(int i = 1; i < k+1; i++)
        C[i] = C[i] + C[i - 1];
    //C[i] now has the # of elements that are less than or equal to i

    /*
    A[j] == X
    C[X] == Y
    B[Y - 1] = X

    C[X] = C[x] - 1
    */
    for(int j = sizeA-1; j >= 0; j--){
        B[C[A[j]]-1] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }

    //Copies the sorted array back to A
    for(int i = 0; i < sizeA; i++)
        A[i] = B[i];
}
