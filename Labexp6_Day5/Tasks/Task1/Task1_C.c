#include <stdio.h>
#include <stdint.h>

int main() {
    int dividend = 13;
    int divisor = 3;

    int quotient = 0;
    int remainder = 0;

    // Number of bits (assuming 32-bit dividend)
    int n = 32;

    remainder = 0;
    quotient = dividend;

    for (int i = 0; i < n; i++) {
        // Left shift (remainder, quotient)
        remainder = (remainder << 1) | ((quotient >> (n - 1)) & 1);
        quotient <<= 1;

        // Subtract divisor
        remainder = remainder - divisor;

        if (remainder < 0) {
            // Restore remainder
            remainder = remainder + divisor;
            // Set quotient bit = 0
            quotient = quotient & (~1);
        } else {
            // Set quotient bit = 1
            quotient = quotient | 1;
        }
    }

    printf("Dividend = %d, Divisor = %d\n", dividend, divisor);
    printf("Quotient = %d, Remainder = %d\n", quotient, remainder);

    return 0;
}