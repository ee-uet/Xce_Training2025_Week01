#include <stdio.h>
#include <stdint.h>

int main() {
    int n;              // number of bits
    unsigned int M, Q;  // M = divisor, Q = dividend
    unsigned int A = 0; // accumulator

    printf("Enter dividend: ");
    scanf("%u", &Q);

    printf("Enter divisor: ");
    scanf("%u", &M);

    n = sizeof(unsigned int) * 8; // number of bits (e.g., 32-bit)

    for (int i = 0; i < n; i++) {
        // Step 1: Left shift A and Q together
        A = (A << 1) | ((Q >> (n - 1)) & 1);  //dividend Q ka sabse leftmost bit (MSB) nikalna.
        Q = Q << 1;

        // Step 2: Subtract divisor
        A = A - M;

        if ((int)A < 0) {
            // Restore
            A = A + M;
            Q = Q & ~1;   // Q[0] = 0
        } else {
            Q = Q | 1;    // Q[0] = 1
        }
    }

    printf("Quotient = %u\n", Q);
    printf("Remainder = %u\n", A);

    return 0;
}
