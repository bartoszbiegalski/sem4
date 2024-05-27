#include <iostream>
#include "RSABreaker.cpp"


int main(int argc, char *argv[]) {
    unsigned long long int p1 = atoi(argv[1]);
    unsigned long long int q1 = atoi(argv[2]);

    RSA A(p1, q1);

    RSA B(p1, q1);
    std::cout<<"A: ";
    A.printKeys();
    std::cout<<"B: ";
    B.printKeys();

    RSABreaker hacker(A, B.getPk());
    hacker.printCrackedKey();

    return 0;
}
