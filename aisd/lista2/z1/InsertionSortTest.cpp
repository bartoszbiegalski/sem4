#include <iostream>
#include "algorithms.cpp"
int main() {
    int number;
    std::cin >> number;

    int n = number;
    int A[n];
    int B[n];
    for (int i = 0; i < n; i++) {
        std::cin >> number;
        A[i] = number;
        B[i] = A[i];
    }

    int swap = 0;
    int comp = 0;

    MySort *mySort;
    if (n < 40) {
        std::cout<<"Przed sortowaniem: \n";
        mySort->printArray(A, 0, n-1, n);
        std::cout<<"Sortowanie: \n";
        std::cout<<"Liczba porownan: "<<comp<<" liczba swapow: "<<swap<<std::endl;
        mySort->insertionSort(A, 0, n-1, n, swap, comp);
        std::cout<<"Przed sortowaniem: \n";
        mySort->printArray(B, 0, n-1, n);
        std::cout<<"Po sortowaniu: \n";
        mySort->printArray(A, 0, n-1, n);
        std::cout<<"Liczba porownan: "<<comp<<" liczba swapow: "<<swap<<std::endl;

    }
    else {
        mySort->insertionSort(A, 0, n-1, n, swap, comp);
        std::cout<<"Liczba porownan: "<<comp<<" liczba swapow: "<<swap<<std::endl;
    }

}