

void restoring_division(unsigned int dividend, unsigned int divisor, 
                       unsigned int *quotient, unsigned int *remainder) {
    unsigned int A = 0; 
    unsigned int Q = dividend; 
    unsigned int M = divisor; 
    int n = 32; 
    
    for (int i = 0; i < n; i++) {
       
        A = (A << 1) | (Q >> 31);
        Q = Q << 1;
        
        A = A - M;
        
        if ((int)A < 0) {
        
            A = A + M;
            Q = Q & ~1;
        } else {
            Q = Q | 1;
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
    volatile int *tohost = (int *)0x80001000;
    *tohost = 1;
    
    return 0;
}