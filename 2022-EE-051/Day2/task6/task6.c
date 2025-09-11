#include <stdio.h>

// Booth Multiplication
int add(int a, int b) {
    // Implement bitwise addition helper
	while (b != 0) {
        int carry = a & b;  // find common set bits 
        a = a ^ b;          // sum of bits without carry
        b = carry << 1;     // shift carry to left by 1
    }
    return a;
}

long long booth_multiply(int multiplicand, int multiplier) {
    long long A = 0;                 // high 32 bits
    long long M = multiplicand;      // multiplicand (sign-extended)
    unsigned int Q = multiplier;     // multiplier (low 32 bits, unsigned for shifts)
    int Q_1 = 0;

    for (int i = 0; i < 32; i++) {
        int Q0 = Q & 1;

        // Add or subtract based on (Q0, Q-1)
        if (Q0 == 1 && Q_1 == 0) {
            A -= M;
        } else if (Q0 == 0 && Q_1 == 1) {
            A += M;
        }

        // Save LSB of A
        int lsbA = A & 1;

        // Shift right arithmetic: A >> 1 keeps sign
        A >>= 1;

        // Shift Q right, insert lsbA into MSB
        Q = (Q >> 1) | ((unsigned)lsbA << 31);

        // Update Q-1
        Q_1 = Q0;
    }

    // Combine 64-bit product
    long long result = (A << 32) | (Q & 0xFFFFFFFFLL);
    return result;
}

void test_booth() {
    printf("7 * 5 = %lld\n", booth_multiply(7, 5));
    printf("-7 * 5 = %lld\n", booth_multiply(-7, 5));
    printf("-7 * 0 = %lld\n", booth_multiply(-7, 0));
    printf("5 * 0 = %lld\n", booth_multiply(5, 0));
    printf("-5 * -6 = %lld\n", booth_multiply(-5, -6));
    printf("123456 * -654321 = %lld\n", booth_multiply(123456, -654321));
}

int main() {
    test_booth();
    return 0;
}