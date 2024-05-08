using System;

namespace GFNamespace {
    public class DHSetup<T> where T : GF{
        public T generator { get; }

        public DHSetup(T element) {
            this.generator = ~element;
        }


        public T power(T a, long b) {
            T result = default(T);
            if (a.Equals(default(T))) {
                result = generator;
            } else {
                result = (dynamic)generator.one();
            }
            while (b > 0) {
              if (b % 2 == 1) {
                  result = (T)((dynamic)result * a);
              }
                a = (T)((dynamic)a * a);
                b /= 2;
              }
            return result;
        }

        public long getRandomSecret() {
            Random rand = new Random();
            return rand.Next(0, generator.characteristic);
        }
    }
}
