import java.util.*;

public class Main {
    public static void main(String[] args) throws GFCharacteristicException {
        GF first = new GF(11, 5);
        GF second = new GF(11, 3);
        System.out.println(first.getValue()+ " " + second.getValue());
        first.add(second);
        System.out.println(first.getValue());

        first = new GF(11, 5);
        second = new GF(11, 3);
        System.out.println(first.getValue()+ " " + second.getValue());
        first.sub(second);
        System.out.println(first.getValue());

        first = new GF(11, 8);
        second = new GF(11, 5);
        System.out.println(first.getValue()+ " " + second.getValue());
        first.div(second);
        System.out.println(first.getValue());
    }
}