#include <iostream>
#include <random>
#include <algorithm>

class AscendingGenerator {
private:
    int* A;
    int n;

public:

    AscendingGenerator(int n) {
        this->n = n;
    }

    void generate() {
        A = new int[n];
        std::random_device rd;
        std::mt19937 g(rd());
        std::uniform_int_distribution<int> distrib(1, 2*n - 1);
        std::uniform_int_distribution<int> random_number(1, 2*n - 1);

        for (int i = 1; i <= n; ++i) {
            A[i - 1] = distrib(g);
        }

        std::sort(A, A+n);

    }

    void printArray() {
        /// first element is always size of array
        std::cout<<n<<"\n";
        /// second will be random number to check if is in array
        std::random_device rd;
        std::mt19937 g(rd());
        std::uniform_int_distribution<int> random_number(1, 2*n - 1);
        std::cout<<random_number(g)<<std::endl;
        for (int i = 0; i < n; i++) {
            std::cout << A[i] << "\n";
        }
        std::cout << std::endl;
    }
};

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    AscendingGenerator *ascendingGenerator = new AscendingGenerator(n);
    ascendingGenerator->generate();
    ascendingGenerator->printArray();
    delete ascendingGenerator;
}
