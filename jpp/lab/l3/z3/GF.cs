using System;


namespace GFNamespace {
  public class GFInvalidValueException : Exception {
    public GFInvalidValueException() {
      Console.WriteLine("Invalid value inserted!");
    }
  }

  public class GFCharacteristicException : Exception {
    public GFCharacteristicException() {
      Console.WriteLine("Wrong characteristic!");
    }
  }

  public class GF {
    private int characteristic {get;}
    private int value {get;}

    public GF(int characteristic, int value) {
      this.characteristic = characteristic;
      while (value < 0) value+= this.characteristic;
      this.value = value % characteristic;
    }

    public override string ToString() {
       return $"({characteristic},{value})";
   }

    public static bool operator ==(GF a, GF b) {
        if (a.characteristic != b.characteristic) {
            throw new GFCharacteristicException();
        } else {
            if (a.value == b.value) return true;
            else return false;
        }
    }

    public static bool operator !=(GF a, GF b) {
        if (a.characteristic != b.characteristic) {
            throw new GFCharacteristicException();
        } else {
            if (a.value == b.value) return false;
            else return true;
        }
    }

    public static bool operator <=(GF a, GF b) {
        if (a.characteristic != b.characteristic) {
            throw new GFCharacteristicException();
        } else {
            if (a.value <= b.value) return true;
            else return false;
        }
    }

    public static bool operator >=(GF a, GF b)  {
        if (a.characteristic != b.characteristic) {
            throw new GFCharacteristicException();
        } else {
            if (a.value >= b.value) return true;
            else return false;
        }
    }

    public static bool operator <(GF a, GF b)  {
        if (a.characteristic != b.characteristic) {
            throw new GFCharacteristicException();
        } else {
            if (a.value >= b.value) return false;
            else return true;
        }
    }

    public static bool operator >(GF a, GF b) {
        if (a.characteristic != b.characteristic) {
            throw new GFCharacteristicException();
        } else {
            if (a.value <= b.value) return false;
            else return true;
        }
    }
    ////Algebraic
    /*
    public static GF& operator =(const GF& b) {
        if (characteristic != b.characteristic) {
            throw GFCharacteristicException();
        }
        value = b.value;
        return *this;
    }

    public static GF& operator-() {
        return GF(characteristic,characteristic-value % characteristic);
    }

    GF operator+(const GF& b) {
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

    GF operator*(const GF& b) {
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


  */
  }
}
