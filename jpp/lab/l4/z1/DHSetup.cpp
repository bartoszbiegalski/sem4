#include <random>
#include "GF.cpp"


template <typename T>
class DHSetup {
private:
    T generator;
public:
    DHSetup(T element) : generator(element){
        generator = ~element; /// random generator from element's group
    }
    T getGenerator() {
       return generator;
    }
    T power(T a, unsigned long b) {
        T result = generator.one();
        while (b > 0) {
            if (b % 2 == 1) {
                result *= a;
            }
            a *= a;
            b /= 2;
        }
        return result;
    }
    unsigned long getRandomSecret() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution dist(0, generator.getCharacteristic()-1);
        return dist(gen);
    }


};