void non_restoring_division(unsigned int dividend, unsigned int divisor, unsigned int *quotient, unsigned int *remainder) {
    unsigned int A = 0;
    unsigned int Q = dividend;
    unsigned int M = divisor;
    int n = 32;
    for (int i = 0; i < n; i++) {
        if ((int)A < 0) {
            A = (A << 1) | (Q >> 31);
            A = A + M;
        } else {
            A = (A << 1) | (Q >> 31);
            A = A - M;
        }
        Q = Q << 1;
        if ((int)A >= 0) {
            Q = Q | 1;
        } else {
            Q = Q & ~1;
        }
    }
    if ((int)A < 0) {
        *remainder = A + M;
    } else {
        *remainder = A;
    }
    *quotient = Q;
}

int main() {
    unsigned int dividend = 13;
    unsigned int divisor = 3;
    unsigned int quotient, remainder;
    non_restoring_division(dividend, divisor, &quotient, &remainder);
    
    return 0;
}
