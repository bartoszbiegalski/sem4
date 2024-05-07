#include <iostream>
#include "algorithms.cpp"

int main() {
    int number;
    std::cin >> number;

    int k;
    std::cin >> k;

    int n = number;
    int A[n];
    int B[n];
    for (int i = 0; i < n; i++) {
        std::cin >> number;
        A[i] = number;
        B[i] = A[i];
    }
    print(A, 0, n-1);
    std::cout<<k<<std::endl;
    std::cout<<binarySearch(A, 0, n-1, k)<<std::endl;

}