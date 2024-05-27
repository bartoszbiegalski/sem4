import sys
import textwrap

def bits_to_string_array(bit_string):
    bit_groups = textwrap.wrap(bit_string, 8)
    return bit_groups

def string_to_bits(s):
    return ''.join(f'{ord(c):08b}' for c in s)
def longest_common_substring(A, B):
    m, n = len(A), len(B)
    dp = [[0] * (n + 1) for _ in range(m + 1)]

    longest_length = 0
    end_index_A = 0

    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if A[i - 1] == B[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
                if dp[i][j] > longest_length:
                    longest_length = dp[i][j]
                    end_index_A = i
            else:
                dp[i][j] = 0

    start_index_A = end_index_A - longest_length
    longest_common_substring = A[start_index_A:end_index_A]

    return longest_common_substring


def RC4_check(message1_bits, message2_bits):
    byte = 0
    min_length = min(len(message1_bits), len(message2_bits))
    #print(len(message1_bits), len(message2_bits),len(longest_common_substring(message1_bits, message2_bits)))
    #print(byte, "bytes are the same")
    if longest_common_substring(message1_bits)


def main(message1, message2):
    message1_bits = string_to_bits(message1)
    message2_bits = string_to_bits(message2)



    message1_bit_groups = bits_to_string_array(message1_bits)
    message2_bit_groups = bits_to_string_array(message2_bits)

    print(message1_bit_groups)
    print(message2_bit_groups)

    RC4_check(message1_bit_groups, message2_bit_groups)

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python script.py <message1> <message2>")
    else:
        main(sys.argv[1], sys.argv[2])
