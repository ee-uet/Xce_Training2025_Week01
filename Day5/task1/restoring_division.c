

int restoring_division(int Dividend, int Divisor, int *Quotient, int *remainder){
    int A = 0;
    int Q = Dividend;
    int M = Divisor;
    int n = 32;

    for (int i = 1; i <= n; i++) {
        A = (A<<1 | Q >> 31);  // A shifted left by 1 and Q right shfted by 31 to leave 1 index 
        Q = Q<<1;

        A = A-M;

        if ((int)A > 0) {
            A += M;
            Q = Q & ~1;
        }
        else{
            Q = Q | 1;
        }
    }
    *Quotient = Q;
    *remainder = A;
}


int main() {
    int dividend = 13;
    int divisor = 3;
    int quotient, remainder;

    restoring_division(dividend, divisor, &quotient, &remainder);
/*
    printf("Restoring Division of %u by %u:\n", dividend, divisor);
    printf("Quotient: %u\n", quotient);
    printf("Remainder: %u\n", remainder);
*/
    return 0;
}