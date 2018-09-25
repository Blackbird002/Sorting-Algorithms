/*
Riad Shash (Ray)
Counting Sort C++ implementation
*/

#include <iostream>
void printArray(int array[], const int &arraySize);
void countingSort(int A[], const int &sizeA, const int &k);

int main(void){

    int ary1[10] = {2,5,3,0,2,3,0,3};
    std::cout<<"Counting Sort \n";
    printArray(ary1,8);
    countingSort(ary1,8, 5);
    printArray(ary1,8);

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
    A - Array A
    B - Array B
    sizeA - size of A
    sizeB - size of B
    k - range for 0 to k, for some integer k
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
    for(int j = sizeA-1; j > 0; j--){
        B[C[A[j]]-1] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }

    //Copies the sorted array back to A
    for(int i = 0; i < sizeA; i++)
        B[i] = A[i];
}
