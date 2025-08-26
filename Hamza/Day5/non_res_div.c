#include <stdio.h>

unsigned int non_restoring_division(unsigned int dividend, unsigned int divisor, unsigned int *remainder) {
    unsigned int quotient = 0;
    unsigned int current_remainder = 0;

    for (int i = 0; i < 32; i++) {
        current_remainder <<= 1;
        quotient <<= 1;
        current_remainder |= (dividend >> (31 - i)) & 1;
        
        if ((long long)current_remainder < 0) { // CHeck sign
            current_remainder = (current_remainder << 1) + divisor;
        } else {
            current_remainder = (current_remainder << 1) - divisor;
        }
        
        if ((long long)current_remainder >= 0) {
            quotient |= 1;
        }
    }
    
    if ((long long)current_remainder < 0) {
        current_remainder += divisor;}
    *remainder = current_remainder;
    return quotient;
}
int main() {
    unsigned int dividend = 100;
    unsigned int divisor = 10;
    unsigned int remainder;
    unsigned int quotient = non_restoring_division(dividend, divisor, &remainder);
    printf("Quotient: %u, Remainder: %u\n", quotient, remainder);
    return 0;}
