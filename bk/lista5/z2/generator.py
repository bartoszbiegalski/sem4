import sys
import base64

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
    keystream = PRGA(S, len(data))
    return bytes([c ^ k for c, k in zip(data, keystream)])

def bytes_to_bits(byte_data):
    return ' '.join(f'{byte:08b}' for byte in byte_data)

def main(key, message):
    key_bytes = key.encode('latin-1')
    message_bytes = message.encode('latin-1')

    encrypted_message = RC4(key_bytes, message_bytes)
    encrypted_message_base64 = base64.b64encode(encrypted_message).decode('ascii')
    print(encrypted_message_base64)

if __name__ == "__main__":
    main(sys.argv[1], sys.argv[2])
