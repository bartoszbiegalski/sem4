#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>

#include "algorithms.cpp"

int main() {
    int number;
    std::cin >> number;

    int k = 0;
    
    std::cin >> k; 

    int n = number;
    int A[n];
    int B[n];
    int C[n];
    for (int i = 0; i < n; i++) {
        std::cin >> number;
        A[i] = number;
        B[i] = A[i];
       
    }
    int comp = 0;
    
   
    std::cout<<"looking for number: "<<k<<std::endl;
    
    print(A, 0, n-1); 
   
    std::cout<<binarySearch(A, 0, n-1,  k, comp)<<std::endl;
    
   
    
    
    
    return 0;
}
