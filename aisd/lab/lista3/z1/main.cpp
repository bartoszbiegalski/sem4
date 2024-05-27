#include <iostream>
#include "algorithms.cpp"

int main() {

    int number;

    std::cin >> number;
    int n = number;

    int k;
    std::cin >> k;

    int A[n];
    int B[n];
    for (int i = 0; i < n; i++) {
       std::cin >> number;
       A[i] = number;
       B[i] = number;
    }

    int swap = 0;
    int comp = 0;

    int result = RandomizedSelect(B, 0, n-1, k, swap, comp);
    std::cout<<swap<<" "<<comp<<std::endl;

    if(number < 50) {
        std::cout<<"search position: "<<k<<std::endl;
        print(B, 0, n-1);
        print(A, 0, n-1);
        InsertionSort(A, 0, n-1, swap, comp);
        print(A, 0, n-1);
        std::cout<<"Result: "<<result<<std::endl;
    }
}