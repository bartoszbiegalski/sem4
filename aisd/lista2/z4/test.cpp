#include <iostream>
#include "algorithms.cpp"

void generate(int *numbers, int N);

int main() {
    for (int i = 1000; i <= 50000; i+=1000) {
        double swapSum = 0;
        double compSum = 0;
        for (int j = 0; j <= 100; j++) {
            int* numbers = new int[i];
            generate(numbers, i);
            MySort *mySort;
            int swap = 0;
            int comp = 0;
            mySort->DualPivotQuickSort(numbers, 0, i-1, i, swap, comp);
            swapSum+=swap;
            compSum+=comp;
        }
        std::cout<<swapSum/(double)i<<" "<<compSum/(double)i<<std::endl;
    }

}

void generate(int *numbers, int N) {
    for (int i = 1; i <= N; ++i) {
        numbers[i - 1] = i;
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(numbers, numbers + N, g);
}
