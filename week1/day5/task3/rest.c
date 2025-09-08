// file: rest.c
void non_restoring_division(unsigned int dividend, unsigned int divisor, unsigned int *quotient, unsigned int *remainder) {
    unsigned int A = 0; 
    unsigned int Q = dividend; 
    unsigned int M = divisor; 
    int n = 32; 
    for (int i = 0; i < n; i++) {
        // Shift A left and bring in MSB of Q
        if ((int)A < 0) {
            A = (A << 1) | (Q >> 31);
            A = A + M;        // if previous A was negative: A = (A << 1)|msb(Q) + M
        } else {
            A = (A << 1) | (Q >> 31);
            A = A - M;        // if previous A was non-negative: A = (A << 1)|msb(Q) - M
        }

        Q = Q << 1;

        // Set or clear LSB of Q depending on sign of A
        if ((int)A >= 0) {
            Q = Q | 1;
        } else {
            Q = Q & ~1;
        }
    }

    // Final remainder adjustment if A < 0
    if ((int)A < 0) {
        *remainder = A + M;
    } else {
        *remainder = A;
    }
    *quotient = Q;
}

int main() {
    unsigned int dividend = 14;
    unsigned int divisor = 3;
    unsigned int quotient, remainder;
    non_restoring_division(dividend, divisor, &quotient, &remainder);

    volatile int *tohost = (int *)0x80001000;  // HTIF location for Spike proxy
    *tohost = 1;
    return 0;
}

