#include <stdio.h>

int main() {
    unsigned int dividend = 13;   // Q
    unsigned int divisor  = 3;    // M
    int A = 0;                    // accumulator / remainder
    unsigned int Q = dividend;    // quotient register (initially dividend)
    int n = 4;                    // number of bits (same as dividend size)

    for (int i = 0; i < n; i++) {
        // shift left A and Q together
        int msbQ = (Q >> (n - 1)) & 1;   // take out MSB of Q
        A = (A << 1) | msbQ;
        Q = Q << 1;

        // subtract divisor
        A = A - divisor;

        // check if result is negative
        if (A < 0) {
            A = A + divisor;     // restore A
        } else {
            Q = Q | 1;           // set Q0 = 1
        }
    }

    // mask quotient to correct bit-width
    unsigned int quotient = Q & ((1 << n) - 1);

    printf("Quotient = %u\n", quotient);
    printf("Remainder = %d\n", A);

    return 0;
}
