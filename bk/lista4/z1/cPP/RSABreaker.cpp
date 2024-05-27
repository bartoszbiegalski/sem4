#include "RSA.cpp"
#include <unistd.h>

class RSABreaker {
private:
    RSA A;
    Pair pkB;

    unsigned long long int fastFact(unsigned long long int a, unsigned long long int n, unsigned long long int modulo) {
        unsigned long long int result = 1;
        a = a % modulo;

        while (n > 0) {
            if (n % 2 == 1) {
                result = (result * a) % modulo;
            }
            n = n >> 1;
            a = (a * a) % modulo;
        }

        return result;
    }


    Pair crack() {
        unsigned long long int p = 0;
        unsigned long long int q = 0;

        unsigned long long int kphi = A.getSk().getSecond() * A.getPk().getSecond() - 1;
        unsigned long long int t = kphi;

        while (t % 2 == 0) {
            t /= 2;
        }

        unsigned long long int a = 2;
        unsigned long long int n = this->A.getSk().getFirst();

        while (a < 100) {
            unsigned long long int k = t;
            while (k < kphi) {
                unsigned long long int x = fastFact(a, k, n) % n;

                if (x != 1 && x != (n-1) && ((x*x) % n == 1)) {
                    p = gcd(x-1, n);
                    q = n / p;
                    return Pair(p, q);
                }
                k = k * 2;
            }
            a = a + 2;
        }

        if (p == 0) {
            std::cerr << "Nie udało się znaleźć odpowiednich wartości p i q." << std::endl;
        } else {
            q = n / p;
        }

        return Pair(p, q);
    }

public:
    RSABreaker(RSA A, Pair pkB) {
        this->A = A;
        this->pkB = pkB;
    }

    void printCrackedKey() {
        Pair skB = crack();
        std::cout<<"("<<skB.getFirst()<<", "<<skB.getSecond()<<")\n";
    }
};
