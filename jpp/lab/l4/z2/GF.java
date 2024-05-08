class Triple {
    public int x;
    public int y;
    public int d;
    public Triple(int x, int y, int d) {
        this.x = x;
        this.y = y;
        this.d = d;
    }
};

class GF {
    private int characteristic;
    private int value;

    public GF(int characteristic, int value) {
        this.characteristic = characteristic;
        while (value < 0) value+= this.characteristic;
        this.value = value % characteristic;
    }

    int getValue() {
        return value;
    }

    int getCharacteristic() {
        return characteristic;
    }

    @Override
    public String toString() {
        return "(" + characteristic + ", " + value + ")";
    }

    private Triple gcd_ext(int a, int b, int c) {
        Triple temp = new Triple(1, 0, a);
        if( b == 0 ) return temp;
        temp = gcd_ext(b, a % b, c);
        Triple output = new Triple(temp.y, temp.x - (a/b) * temp.y, temp.d);
        return output;
    }

    void add(GF a) throws GFCharacteristicException {
        if(a.characteristic != this.characteristic) {
            throw new GFCharacteristicException();
        }
        else {
            this.value = (value + a.getValue()) % characteristic;
            while (value < 0) value+=characteristic;
            this.value = this.value % characteristic;
        }
    }

    void sub(GF a) throws GFCharacteristicException {
        if(a.characteristic != this.characteristic) {
            throw new GFCharacteristicException();
        }
        else {
            this.value = (value - a.getValue()) % characteristic;
            while (value < 0) value+=characteristic;
            this.value = this.value % characteristic;
        }
    }

    void mul(GF a) throws GFCharacteristicException {
        if(a.characteristic != this.characteristic) {
            throw new GFCharacteristicException();
        }
        else {
            this.value = (value * a.getValue()) % characteristic;
            while (value < 0) value+=characteristic;
            this.value = this.value % characteristic;
        }
    }

    void div(GF a) throws GFCharacteristicException {
        if (a.characteristic != characteristic) {
            throw new GFCharacteristicException();
        } else {
            Triple triple = gcd_ext(a.value, characteristic, 1);
            this.value = (value * triple.x) % characteristic;
            while (value < 0) value+=characteristic;
            this.value = this.value % characteristic;
        }
    }


};

