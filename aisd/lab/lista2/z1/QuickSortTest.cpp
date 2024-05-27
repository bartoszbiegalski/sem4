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
        if(n<30) mySort->printArray(A, 0, n-1, n);
        std::cout<<"Sortowanie: \n";
        mySort->quicksort(A, 0, n-1, n, swap, comp);
        std::cout<<"Przed sortowaniem: \n";
        if(n<30) mySort->printArray(B, 0, n-1,  n);
        std::cout<<"Po sortowaniu: \n";
        if(n<30) ySort->printArray(A, 0, n-1, n);
        std::cout<<"Liczba porownan: "<<comp<<" liczba swapow: "<<swap<<std::endl;

    }
    else {
        mySort->quicksort(A, 0, n-1, n, swap, comp);
        std::cout<<"Liczba porownan: "<<comp<<" liczba swapow: "<<swap<<std::endl;
    }

}