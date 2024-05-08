#include <iostream>
#include "User.cpp"

int main () {

    GF first(101, 5);

    DHSetup<GF>dhSetup(first);

    User<GF> userA(dhSetup);
    User<GF> userB(dhSetup);

    std::cout << "Public Key User A: " << userA.getPublicKey() << std::endl;
    std::cout << "Public Key User B: " << userB.getPublicKey() << std::endl;

    userA.setKey(userB.getPublicKey());
    userB.setKey(userA.getPublicKey());

    GF message(101, 7);

    GF encryptedMessage = userA.encrypt(message);
    std::cout << "Encrypted Message: " << encryptedMessage << std::endl;

    GF decryptedMessage = userB.decrypt(encryptedMessage);
    std::cout << "Decrypted Message: " << decryptedMessage << std::endl;
}