#include <iostream>
#include <random>
#include <algorithm>

class RandomGenerator {
private:
    int* A;
    int n;

public:

    RandomGenerator(int n) {
        this->n = n;
    }

    void generate() {
        A = new int[n];
        std::random_device rd;
        std::mt19937 g(rd());
        std::uniform_int_distribution<int> distrib(1, 2*n - 1);

        for (int i = 1; i <= n; ++i) {
            A[i - 1] = distrib(g);
        }
    }

    void printArray() {
        /// first element is always size of array
        std::cout<<n<<"\n";
        for (int i = 0; i < n; i++) {
            std::cout << A[i] << "\n";
        }
        std::cout << std::endl;
    }
};

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    RandomGenerator *randomGenerator = new RandomGenerator(n);
    randomGenerator->generate();
    randomGenerator->printArray();
    delete randomGenerator;
}
