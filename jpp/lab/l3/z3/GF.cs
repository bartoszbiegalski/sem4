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

   private static Triple gcd_ext(int a, int b, int c) {
       Triple temp = new Triple(1, 0, a);
       if( b == 0 ) return temp;
       temp = gcd_ext(b, a % b, c);
       Triple output = new Triple(temp.y, temp.x - (a/b) * temp.y, temp.d);
       return output;
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
  }
}
