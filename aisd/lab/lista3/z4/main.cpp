#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>

#include "algorithms.cpp"

int main() {
    std::cout << std::fixed;


    std::chrono::duration<double> time1 = std::chrono::duration<double>::zero();

    for (int i = 1000; i <= 100000; i += 1000) {
        std::random_device rd;
        std::mt19937 g(rd());
        std::uniform_int_distribution<int> distrib(1, 2 * i - 1);
        std::uniform_int_distribution<int> k_distrib(0, i - 1);

        int *A = new int[i];

        int sum_comp = 0;

        for (int j = 0; j < 50; j++) {
            for (int k = 0; k < i; k++) {
                A[k] = distrib(g);
            }

            int element = k_distrib(g);


            std::sort(A, A + i);
            auto start = std::chrono::high_resolution_clock::now();
            binarySearch(A, 0, i, element, comp);
            auto end = std::chrono::high_resolution_clock::now();
            time1 += end - start;
        }


        std::cout<< time1.count() << std::endl;

        delete[] A; // Zwolnienie zaalokowanej pamięci
    }

    return 0;
}