#include <stdio.h>
#include <math.h>

int main() {
    int n;              // number of bits
    int M, Q;           // Divisor and Dividend
    int A = 0;          // Remainder i-e Accumulator
    
    printf("Enter Dividend Q: ");
    scanf("%d", &Q);
    printf("Enter Divisor M: ");
    scanf("%d", &M);
    printf("Enter number of bits n: ");
    scanf("%d", &n);

    int i;
    for (i = 0; i < n; i++) {
        // Step 1: Left shift AQ
        A = (A << 1) | ((Q >> (n - 1)) & 1);   // Shift left A and bring MSB of Q
        Q = Q << 1;                            // Shift left Q

        // Step 2: Perform operation depending on sign of A
        if (A >= 0) {
            A = A - M;   // A = A - M
        } else {
            A = A + M;   // A = A + M
        }

        // Step 3: Set Q0 depending on sign of A
        if (A >= 0) {
            Q = Q | 1;   // Q0 = 1
        } else {
            Q = Q & (~1); // Q0 = 0
        }
    }

    // Final correction if A < 0
    if (A < 0) {
        A = A + M;
    }

    printf("\nQuotient = %d", Q);
    printf("\nRemainder = %d\n", A);

    return 0;
}
