#include <iostream>
#include <random>

class Triple {
public:
    unsigned long long int x;
    unsigned long long int y;
    unsigned long long int d;

    Triple() {

    }

    Triple(unsigned long long int x, unsigned long long int y, unsigned long long int d) {
        this->x = x;
        this->y = y;
        this->d = d;
    }
};

class Pair {
private:
    unsigned long long int first;
    unsigned long long int second;
public:
    Pair() {}

    Pair(unsigned long long int first, unsigned long long int second) {
        this->first = first;
        this->second = second;
    };
    unsigned long long int getFirst() {
        return this->first;
    }
    unsigned long long int getSecond() {
        return this->second;
    }

    void setFirst(unsigned long long int firstValue) {
        this->first = firstValue;
    }

    void setSecond(unsigned long long int secondValue) {
        this->second = secondValue;
    }
};

unsigned long long int gcd(unsigned long long int a, unsigned long long int b) {
    if(b > a) {
        unsigned long long int temp = a;
        a = b;
        b = temp;
    }
    if(b == 0) return a;
    else return gcd(b, a % b);
}

Triple gcdExt(unsigned long long int a, unsigned long long int b, unsigned long long int c) {

    Triple temp;
    unsigned long long int nwd = gcd(a, b);
    if (c % nwd != 0) {
        temp.x = a;
        temp.y = b;
        temp.d = -1;
        return temp;
    }

    temp.x = 1;
    temp.y = 0;
    temp.d = a;
    if( b == 0 ) return temp;
    temp = gcdExt(b, a % b, c);
    Triple output(temp.y, temp.x - (a/b) * temp.y, temp.d);
    return output;
}

class RSA {
private:
    unsigned long long int p;
    unsigned long long int q;
    unsigned long long int n;
    unsigned long long int phi;
    unsigned long long int e;
    unsigned long long int d;
    Pair sk;
    Pair pk;

    void setN(unsigned long long int p, unsigned long long int q) {
        this->n = p * q;
    }

    void setPhi(unsigned long long int p, unsigned long long int q) {
        this->phi = (p-1)*(q-1);
    }

    void pickE(unsigned long long int e) {
        this->e = 0;

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<unsigned long long int> dis(2, this->phi);
        do {
            this->e = dis(gen);
        } while ((this->e >= this->phi) || (gcd(this->phi, this->e) != 1));
    }

    bool isPrime(unsigned long long int n, int k = 5) {
        if (n <= 1 || n == 4) return false;
        if (n <= 3) return true;

        unsigned long long int d = n - 1;
        while (d % 2 == 0) d /= 2;

        for (int i = 0; i < k; ++i) {
            unsigned long long int a = 2 + rand() % (n - 4);
            unsigned long long int x = power(a, d, n);
            if (x == 1 || x == n - 1) continue;

            bool prime = false;
            while (d != n - 1) {
                x = (x * x) % n;
                d *= 2;

                if (x == 1) return false;
                if (x == n - 1) {
                    prime = true;
                    break;
                }
            }

            if (!prime) return false;
        }

        return true;
    }

    unsigned long long int power(unsigned long long int x, unsigned long long int y, unsigned long long int p) {
        unsigned long long int res = 1;

        x = x % p;
        while (y > 0) {
            if (y & 1) res = (res * x) % p;
            y = y >> 1;
            x = (x * x) % p;
        }
        return res;
    }

    void checkStartParameters(unsigned long long int p, unsigned long long int q) noexcept(false) {
        if (isPrime(p) == false || isPrime(q) == false) {
            throw std::runtime_error("P and q are not prime!");
        }
    }

    void setD(unsigned long long int e, unsigned long long int phi) {
        Triple triple = gcdExt(e, phi, 1);
        this->d = triple.x % phi;
        //if (d < 0) d += this->phi;
    }

    void setKeys() {
        this->pk.setFirst(this->n);
        this->pk.setSecond(this->e);


        this->sk.setFirst(this->n);
        this->sk.setSecond(this->d);
    }

public:
    RSA() {

    }

    RSA(unsigned long long int p, unsigned long long int q) {
        this->p = p;
        this->q = q;
        checkStartParameters(this->p, this->q);
        setN(this->p, this->q);
        setPhi(this->p, this->q);
        pickE(this->n);
        setD(this->e, this->phi);
        setKeys();
    }

    Pair getSk() {
        return this->sk;
    }

    Pair getPk() {
        return this->pk;
    }


    void printKeys() {
        std::cout<<"pk: ("<< this->pk.getFirst()<<", "<< this->pk.getSecond()<<")\n";
        std::cout<<"sk: ("<< this->sk.getFirst()<<", "<< this->sk.getSecond()<<")\n";
    }
};