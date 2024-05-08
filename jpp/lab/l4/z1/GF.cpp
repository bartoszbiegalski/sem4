#include <gmp.h>

class Triple {
public:
    int x;
    int y;
    int d;
    Triple(int x, int y, int d) : x(x), y(y), d(d) {}
};

class GFInvalidValueException : public std::exception {
public:
    virtual const char* what() const noexcept {
        return "Invalid value!";
    }
};

class GFCharacteristicException : public std::exception {
public:
    virtual const char* what() const noexcept {
        return "Inappropriate characteristic!";
    }
};

class GF {

private:
    bool initialize = false;
	int characteristic;
    int value;
    std::vector<int> primes;
public:
    GF() : characteristic(0), value(0) {}

    GF(int characteristic, int value) {
        this->initialize = true;
        this->characteristic = characteristic;
        while (value < 0) value += this->characteristic;
        this->value = value % characteristic;
        setPrimes();
    }

    int getValue() {
        return value;
    }

    void setCharacteristic(int characteristic) {
        this->characteristic = characteristic;
        while (value < 0) value += this->characteristic;
        this->value = value % characteristic;
    }

    int getCharacteristic() {
        return characteristic;
    }

    void printPrimes() {
        for (int i = 0; i < this->primes.size(); i++) {
            std::cout<<this->primes[i]<<std::endl;
        }
    }
private:
    void setPrimes() {
        mpz_t n;
        mpz_init(n);
        mpz_t char_mpz;
        mpz_init(char_mpz);
        mpz_set_ui(char_mpz, characteristic);

        mpz_t half;
        mpz_init(half);
        mpz_sub_ui(half, char_mpz, 1);
        mpz_fdiv_q_ui(half, half, 2);

        mpz_t i;
        mpz_init_set_ui(i, 2);
        for (; mpz_cmp(i, half) <= 0; mpz_add_ui(i, i, 1)) {
            int is_prime = mpz_probab_prime_p(i, 25);
            if (is_prime) {
                int next_prime = mpz_get_ui(i);
                if((characteristic - 1) % next_prime == 0) this->primes.push_back(next_prime);
            }
        }
        mpz_clear(n);
        mpz_clear(half);
        mpz_clear(i);
    }

    Triple gcd_ext(int a, int b, int c) {
        Triple temp(1, 0, a);
        if( b == 0 ) return temp;
        temp = gcd_ext(b, a % b, c);
        Triple output(temp.y, temp.x - (a/b) * temp.y, temp.d);
        return output;
    }

    bool is_generator(GF &element) {
        GF one(characteristic, 1);
        for(int i = 0; i < primes.size(); i++) {
            int pow = (characteristic - 1) / primes[i];
            if ((element^pow) == one) return false;
        }
        return true;
    }
public:
    ///Logical

    GF one() {
        return GF(characteristic, 1);
    }

    bool operator==(const GF& b) {
        if (characteristic != b.characteristic) {
            throw GFCharacteristicException();
        } else {
            if (b.value == value) return true;
            else return false;
        }
    }

    bool operator!=(const GF& b) {
        if (characteristic != b.characteristic) {
            throw GFCharacteristicException();
        } else {
            if (b.value == value) return false;
            else return true;
        }
    }

    bool operator<=(const GF& b) {
        if (characteristic != b.characteristic) {
            throw GFCharacteristicException();
        } else {
            if (value <= b.value) return true;
            else return false;
        }
    }

    bool operator>=(const GF& b) {
        if (characteristic != b.characteristic) {
            throw GFCharacteristicException();
        } else {
            if (value >= b.value) return true;
            else return false;
        }
    }

    bool operator<(const GF& b) {
        if (characteristic != b.characteristic) {
            throw GFCharacteristicException();
        } else {
            if (value >= b.value) return false;
            else return true;
        }
    }

    bool operator>(const GF& b) {
        if (characteristic != b.characteristic) {
            throw GFCharacteristicException();
        } else {
            if (value <= b.value) return false;
            else return true;
        }
    }
    ////Algebraic

    GF& operator=(const GF& b) {
        this->initialize = true;
        if (characteristic != b.characteristic) {
            throw GFCharacteristicException();
        }
        value = b.value;
        return *this;
    }

    GF operator-() const{
        return GF(characteristic,characteristic-value % characteristic);
    }

    GF operator+(const GF& b) const{
        if (characteristic != b.characteristic) {
            throw GFCharacteristicException();
        }
        else return GF(characteristic, (value + b.value)%characteristic);
    }

    GF operator-(const GF& b) const {
        if (characteristic != b.characteristic) {
            throw GFCharacteristicException();
        }
        int result = (value - b.value) % characteristic;
        if (result < 0) {
            result += characteristic;
        }
        return GF(characteristic, result);
    }

    GF operator*(const GF& b) const{
        if (characteristic != b.characteristic) {
            throw GFCharacteristicException();
        } else return GF(characteristic, (value * b.value) % characteristic);
    }

    GF operator/(const GF& b) {
        if (characteristic != b.characteristic) {
            throw GFCharacteristicException();
        } else {
            Triple triple = gcd_ext(b.value, characteristic, 1);

            return GF(characteristic, ((value * (triple.x+characteristic)) + characteristic));
        }
    }

    GF operator~() { /// special operator for assigning to the value a random generator from it's group
        return getRandomGenerator();
    }

    GF operator^(int exponent) const {
        GF result = GF(characteristic, 1);
        for (int i = 0; i < exponent; ++i) {
            result *= *this;
        }
        return result;
    }

    //// Assign

    GF& operator+=(const GF& b) {
        if (characteristic != b.characteristic) {
            throw GFCharacteristicException();
        }
        *this = *this + b;
        return *this;
    }

    GF& operator-=(const GF& b) {
        if (characteristic != b.characteristic) {
            throw GFCharacteristicException();
        }
        *this = *this - b;
        return *this;
    }

    GF& operator*=(const GF& b) {
        if (characteristic != b.characteristic) {
            throw GFCharacteristicException();
        }
        *this = *this * b;
        return *this;
    }

    GF& operator/=(const GF& b) {
        if (characteristic != b.characteristic) {
            throw GFCharacteristicException();
        }
        *this = *this / b;
        return *this;
    }

    //// streams

    friend std::ostream& operator<<(std::ostream& os, const GF& b) {
        os << "(" << b.characteristic << ", " << b.value << ")";
        return os;
    }

    friend GF& operator<<(GF& b, int val) {

        b = GF(b.characteristic, val);
        return b;
    }


    GF getRandomGenerator() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution dist(2, characteristic-1);

        GF temp(characteristic, dist(gen));

        while (is_generator(temp) == 0) {
            temp = GF(characteristic, dist(gen));
        }
        return temp;
    }

    bool isInitialized() {
        return initialize;
    }
};

