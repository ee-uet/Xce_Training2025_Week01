#include <stdio.h>
#include <stdint.h>

// Bitwise addition 
int16_t sum(int16_t a, int16_t b) {
    while (b != 0) {
        uint16_t carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}

// Booth's multiplication
int32_t booth_multiply(int16_t M, int16_t Q) {
    int16_t A = 0;
    int Q_1 = 0;
    int n = 16;

    for (int i = 0; i < n; i++) {
        int Q0 = Q & 1;

        if (Q0 == 1 && Q_1 == 0)
            A = sum(A, -M);
        else if (Q0 == 0 && Q_1 == 1)
            A = sum(A, M);

        int new_Q1 = Q & 1;

        // Combine A and Q into 32-bit
        int32_t combined = ((int32_t)A << 16) | ((uint16_t)Q);
        combined >>= 1;  // arithmetic shift
        A = combined >> 16;
        Q = combined & 0xFFFF;

        Q_1 = new_Q1;
    }

    return ((int32_t)A << 16) | ((uint16_t)Q);
}

// Test
int main() {
    printf("5 * 3 = %d\n", booth_multiply(5, 3));
    printf("-4 * 6 = %d\n", booth_multiply(-4, 6));
     printf("-4 * 6 = %d\n", booth_multiply(4, -6));
    
     printf("-7 * -0 = %d\n", booth_multiply(-7, 0));
    return 0;
}
