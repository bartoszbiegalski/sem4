using System;

namespace GFNamespace {
        public class User<T> where T : GF {
        private long secret;
        private U key;
        private DHSetup<T> dh;

        public User(T dhSetup) {
            dh = dhSetup;
            secret = dh.getRandomSecret();
        }

        public U getPublicKey() {
            return dh.power(dh.generator, secret);
        }

        public void setKey(U a) {
            key = dh.power(a, secret);
        }

        public U encrypt(U m) {
            if (key == null) {
                throw new Exception("Key not set.");
            }
            return dh.power(m, secret);
        }

        public U decrypt(U c) {
            if (key == null) {
                throw new Exception("Key not set.");
            }
            return dh.power(c, secret);
        }
    }
}
