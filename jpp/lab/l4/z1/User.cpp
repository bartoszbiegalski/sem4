#include "DHSetup.cpp"


class KeyInitializationException : public std::exception {
public:
    virtual const char* what() const noexcept {
        return "Key wasn't initialized!";
    }
};


template <typename T>
class User {
private:
    int secret;
    T key;
    DHSetup<T> dh;

public:
    User(DHSetup<T> dhSetup) : dh(dhSetup) {
       secret = dh.getRandomSecret();
    }

    T getPublicKey() {
        return dh.power(dh.getGenerator(), secret);
    }

    void setKey(T a) {
        key.setCharacteristic(a.getCharacteristic());
        key = dh.power(a, secret);
    }

    T encrypt(T m) {
        if (key.isInitialized() == false) {
            throw KeyInitializationException();
        }
        else return m * key;

    }

    T decrypt(T c) {
        if (key.isInitialized() == false) {
            throw KeyInitializationException();
        }
        else return c / key;
    }

};
