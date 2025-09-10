#include <stdio.h>

int main() {
    unsigned int dividend = 11;   // Q
    unsigned int divisor  = 3;    // M
    int A = 0;                    // A = 0 
    unsigned int Q = dividend;    // Q = Dividend
    int n = 32;                   // number of bits


    while (n > 0) {
    
        if (A < 0) {
            int msbQ = (Q >> 31) & 1;   // take MSB of Q
            A = (A << 1) | msbQ;
            Q = Q << 1;
            A = A + divisor;
        } else {
            int msbQ = (Q >> 31) & 1;
            A = (A << 1) | msbQ;
            Q = Q << 1;
            A = A - divisor;
        }

        if (A < 0) {
            Q = Q & (~1);
        } else {
            Q = Q | 1;
        }

        n--;
    }
    if (A < 0) {
        A = A + divisor;
    }

    // results
    printf("Dividend = %u, Divisor = %u\n", dividend, divisor);
    printf("Quotient = %u\n", Q);
    printf("Remainder = %d\n", A);

    return 0;
}
