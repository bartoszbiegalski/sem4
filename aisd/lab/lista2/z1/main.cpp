#include <iostream>
#include "algorithms.cpp"
int main() {
    int number;
    std::cin >> number;

    int n = number;
    int A[n];
    int B[n];
    int C[n];
    for (int i = 0; i < n; i++) {
        std::cin >> number;
        A[i] = number;
        B[i] = A[i];
        C[i] = A[i];
    }

    int swap = 0;
    int comp = 0;

    MySort *mySort;
    if(n<30) mySort->printArray(A, 0, n-1, n);
    mySort->DualPivotQuickSort(A, 0, n-1, n, swap, comp);
    if(n<30) mySort->printArray(A, 0, n-1, n);
    std::cout<<"swap: "<<swap<<" comp:"<<comp<<std::endl;
    return 0;
}
