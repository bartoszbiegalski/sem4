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
	int characteristic;
    int value;
public:
	GF(int characteristic, int value) {
        this->characteristic = characteristic;
        while (value < 0) value+= this->characteristic;
        this->value = value % characteristic;
    }

    int getValue() {
        return value;
    }

    int getCharacteristic() {
        return characteristic;
    }
private:
    Triple gcd_ext(int a, int b, int c) {
        Triple temp(1, 0, a);
        if( b == 0 ) return temp;
        temp = gcd_ext(b, a % b, c);
        Triple output(temp.y, temp.x - (a/b) * temp.y, temp.d);
        return output;
}

public:
    ///Logical

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

    GF& operator=(const GF& b) const {
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

    GF operator/(const GF& b) const{
        if (characteristic != b.characteristic) {
            throw GFCharacteristicException();
        } else {
            Triple triple = gcd_ext(b.value, characteristic, 1);

            return GF(characteristic, ((value * (triple.x+characteristic)) + characteristic));
        }
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


};

