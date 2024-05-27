import random
import sympy
import sys

def generateKeys( p, q ):
    n = p * q
    phi = (p - 1) * (q - 1)

    e = random.randint(2, phi - 1)
    while sympy.gcd(e, phi) != 1:
        e = random.randint(2, phi - 1)

    d = sympy.mod_inverse(e, phi)
    public_key = (n, e)
    private_key = (n, d)
    
    return private_key, public_key

def crack(n, e1, d1):
    t = d1[1] * e1[1] - 1 
    kphi = t
    while (t % 2 == 0):
        t = t // 2

    a = 2
    while (True):
        k = t
        while k < kphi:
            x = pow(a, k, n)
            if x != 1 and x != (n - 1) and x ** 2 % n == 1:
                r = sympy.gcd(x - 1, n)
                return n // r
            k *= 2
        a += 2

 

def main():
    pa = int(sys.argv[1])
    qa = int(sys.argv[2])

    if not sympy.isprime(pa) or not sympy.isprime(qa):
        print("p oraz q muszą być liczbami pierwszymi.")
        return

    skA, pkA = generateKeys(pa, qa)
    skB, pkB = generateKeys(pa, qa)

    print("skA: ", skA)
    print("pkA: ", pkA)
    print("skB:", skB)
    print("pkB: ", pkB)

    cracked_n = crack(pkA[0], pkA, skA)

    dA = sympy.mod_inverse(pkA[1], (pa - 1) * (qa - 1))
    cracked_private_key = (pkA[0], dA)
    print("Odkryty klucz prywatny dla osoby A:", cracked_private_key)


if __name__ == "__main__":
    main()
