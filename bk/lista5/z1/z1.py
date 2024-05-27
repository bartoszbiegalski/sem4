import sys
import random
import string
import base64

def generate_random_ascii_string():
    length = random.randint(30, 50)
    ascii_characters = string.ascii_letters + string.digits + string.punctuation
    random_string = ''.join(random.choice(ascii_characters) for _ in range(length))
    return random_string

def KSA(K):
    n = len(K)
    j = 0
    T = [K[i % n] for i in range(256)]
    S = list(range(256))
    for i in range(256):
        j = (j + S[i] + T[i]) % 256
        S[i], S[j] = S[j], S[i]
    return S

def PRGA(S, m):
    i = 0
    j = 0
    KS = [0] * m
    for b in range(m):
        i = (i + 1) % 256
        j = (j + S[i]) % 256
        S[i], S[j] = S[j], S[i]
        KS[b] = S[(S[i] + S[j]) % 256]
    return KS

def RC4(key, data):
    S = KSA(key)
    #print(f"key : {S}")
    keystream = PRGA(S, len(data))
    return bytes([c ^ k for c, k in zip(data, keystream)])

def bits_to_string_array(bit_string):
    bit_groups = textwrap.wrap(bit_string, 8)
    return bit_groups

def main(key):
    for i in range(5):
        message = generate_random_ascii_string()
        print(f"Original Message: {message}")
        m
        essage1_bit_groups = bits_to_string_array(message1_bits)


        key_bytes = key.encode('latin-1')
        message_bytes = message.encode('latin-1')

        encrypted_message = RC4(key_bytes, message_bytes)
        encrypted_message_base64 = base64.b64encode(encrypted_message).decode('ascii')
        print(f"Encrypted Message (base64): {encrypted_message_base64}")

        decrypted_message_bytes = RC4(key_bytes, encrypted_message)
        decrypted_message = decrypted_message_bytes.decode('latin-1')
        print(f"Decrypted Message: {decrypted_message}")




if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python3 script.py <key>")
    else:
        main(sys.argv[1])
