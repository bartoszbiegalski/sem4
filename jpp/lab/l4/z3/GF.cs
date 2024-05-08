using System;
using System.Collections;

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

  public class Triple {
      public int x;
      public int y;
      public int d;
      public Triple(int x, int y, int d) {
          this.x = x;
          this.y = y;
          this.d = d;
      }
  };

  public class GF {

    public int characteristic {get;}
    public int value {get;}
    public ArrayList primes = new ArrayList();

    public GF(int characteristic, int value) {
      this.characteristic = characteristic;
      while (value < 0) value+= this.characteristic;
      this.value = value % characteristic;
      setPrimes();
    }

    public override string ToString() {
       return $"({characteristic},{value})";
   }

   private static Triple gcd_ext(int a, int b, int c) {
       Triple temp = new Triple(1, 0, a);
       if( b == 0 ) return temp;
       temp = gcd_ext(b, a % b, c);
       Triple output = new Triple(temp.y, temp.x - (a/b) * temp.y, temp.d);
       return output;
   }

   private void setPrimes() {
     for(int i = 2; i < Math.Sqrt(characteristic); i++) {
       if ((characteristic - 1) % i == 0)  {
         primes.Add(i);
       }
     }
   }

   public bool is_generator(GF element) {
           for(int i = 0; i < primes.Count; i++) {
              int div = (int)primes[i];
              int pow = (characteristic - 1) / div;
              if ((element^pow) == element.one()) return false;
           }
           return true;
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

    public GF negate() {
        return new GF(characteristic,characteristic-value % characteristic);
    }

    public static GF operator +(GF a, GF b) {
        if (a.characteristic != b.characteristic) {
            throw new GFCharacteristicException();
        }
        else return new GF(a.characteristic, (a.value + b.value)%a.characteristic);
    }

    public static GF operator -(GF a, GF b) {
        if (a.characteristic != b.characteristic) {
            throw new GFCharacteristicException();
        }
        else return new GF(a.characteristic, (a.value - b.value)%a.characteristic);
    }


    public static GF operator *(GF a, GF b) {
        if (a.characteristic != b.characteristic) {
            throw new GFCharacteristicException();
        }
        else return new GF(a.characteristic, (a.value * b.value)%a.characteristic);
    }

    public static GF operator /(GF a, GF b) {
        if (a.characteristic != b.characteristic) {
            throw new GFCharacteristicException();
        } else {
            Triple triple = gcd_ext(b.value, a.characteristic, 1);

            return new GF(a.characteristic, ((a.value * (triple.x+a.characteristic)) + a.characteristic));
        }
    }

    public static GF operator ^(GF a, int exponent) {
        GF result = a.one();
        for (int i = 0; i < exponent; ++i) {
            result = result*a;
        }
        return result;
    }

    private GF getRandomGenerator() {
      Random rand = new Random();
      int randomNumber = rand.Next(0, characteristic - 1);

      GF temp = new GF(characteristic, randomNumber);
      while (is_generator(temp) == true) {
        temp = new GF(characteristic, rand.Next(0, characteristic - 1));

      }
      return temp;
    }

    public static GF operator~(GF a) {
            return getRandomGenerator();
    }


    public GF one() {
        return new GF(this.characteristic, 1);
    }
  }
}
