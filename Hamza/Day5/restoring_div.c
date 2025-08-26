#include <stdio.h>

unsigned int restoring_division(unsigned int dividend, unsigned int divisor, unsigned int *remainder) {
    unsigned int quotient = 0;
    unsigned int current_remainder = dividend;

    for (int i = 0; i < 32; i++) {
        // sshift left
        current_remainder <<= 1;
        quotient <<= 1;

        // trial subtraction
        if (current_remainder >= divisor) {
            current_remainder -= divisor;
            quotient |= 1;
        }
    }
    
    *remainder = current_remainder;
    return quotient;
}

int main() {
    unsigned int dividend = 100;
    unsigned int divisor = 10;
    unsigned int remainder;
    unsigned int quotient = restoring_division(dividend, divisor, &remainder);
    
    printf("Quotient: %u, Remainder: %u\n", quotient, remainder);
    
    return 0;
}
