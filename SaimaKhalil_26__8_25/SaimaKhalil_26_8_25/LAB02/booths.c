#include <stdio.h>

// Function to perform arithmetic right shift
void arithmeticRightShift(int *A, int *Q, int *q0, int bits) {
    int mask = (1 << bits) - 1;

    int sign = (*A >> (bits - 1)) & 1; // save MSB of A
    int newQm1 = *Q & 1;               // save LSB of Q

    *Q = ((*A & 1) << (bits - 1)) | (*Q >> 1); // shift Q with A0
    *A = (sign << (bits - 1)) | (*A >> 1);     // shift A with sign extension

    *A &= mask;
    *Q &= mask;

    *q0 = newQm1; // update Q0
}

int main() {
    int bits = 8;   // 4-bit example
    int mask = (1 << bits) - 1;

    int M = 91 & mask;   // Multiplicand (in 4-bit two’s complement)
    int Q = -8 & mask;   // Multiplier   (in 4-bit two’s complement)
    int A = 0;
    int q0 = 0;
    int n = bits;

    printf("Initial: A=%d, Q=%d, M=%d\n", A, Q, M);

    while (n > 0) {
        int q1 = Q & 1;

        if (q1 == 0 && q0 == 1) {
            A = (A + M) & mask;  // restrict to spec bits
            printf("A = A + M => A=%d\n", A);
        } else if (q1 == 1 && q0 == 0) {
            A = (A - M) & mask;
            printf("A = A - M => A=%d\n", A);
        }

        arithmeticRightShift(&A, &q1, &q0, bits);
        printf("After ASR => A=%d, q1=%d, q0=%d\n", A, q1, q0);

        n--;
    }

    // Final result: concatenate A and Q (8-bit product)
    int result = (A << bits) | Q;
    // Convert result to signed 8-bit
    if (result & (1 << (2*bits - 1))) {
        result -= (1 << (2*bits));
    }

    printf("\nFinal Result: %d\n", result);
    return 0;
}   