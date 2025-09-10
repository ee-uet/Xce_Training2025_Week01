// file: division.c
#include <stdio.h>

/* Restoring division in C (keeps A, Q, M as 32-bit unsigned) */
void restoring_division(unsigned int dividend, unsigned int divisor, 
                       unsigned int *quotient, unsigned int *remainder) {
    unsigned int A = 0; 
    unsigned int Q = dividend; 
    unsigned int M = divisor; 
    int n = 32; 
    
    for (int i = 0; i < n; i++) {
        // Left-shift A and bring MSB of Q into LSB of A
        A = (A << 1) | (Q >> 31);
        Q = Q << 1;
        
        // Try subtracting M from A
        A = A - M;
        
        // If A treated as signed is negative, restore A and set Q LSB to 0
        if ((int)A < 0) {
            A = A + M;
            Q = Q & ~1;   // clear LSB
        } else {
            Q = Q | 1;    // set LSB
        }
    }
    
    *quotient = Q;
    *remainder = A;
}

int main() {
    unsigned int dividend = 13;
    unsigned int divisor = 3;
    unsigned int quotient, remainder;
    
    restoring_division(dividend, divisor, &quotient, &remainder);

    // signal to host (Spike proxy) that program finished
    volatile int *tohost = (int *)0x80001000;
    *tohost = 1;
    
    return 0;
}

