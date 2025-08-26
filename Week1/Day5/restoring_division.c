#include <stdio.h>
#include <stdint.h>

int main() {
    int dividend = 13;   // number to be divided (N)
    int divisor = 3;     // number that divides (D)

    int n = 4;
    int quotient = 0;
    int remainder = 0;

    for (int i = n - 1; i >= 0; i--) {
        // Left shift remainder by 1 and bring down next bit of dividend
        remainder = (remainder << 1) | ((dividend >> i) & 1);

        // Subtract divisor
        remainder = remainder - divisor;

        if (remainder < 0) {
            // Restore (undo subtraction)
            remainder = remainder + divisor;
            quotient = (quotient << 1) | 0;
        } else {
            quotient = (quotient << 1) | 1;
        }
    }

    printf("Dividend = %d, Divisor = %d\n", dividend, divisor);
    printf("Quotient = %d, Remainder = %d\n", quotient, remainder);

    return 0;
}

