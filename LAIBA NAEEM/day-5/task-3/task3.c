#include <stdio.h>

int main() {
    unsigned int dividend, divisor;
    unsigned int A = 0, Q, M;
    int i;

    printf("Enter dividend:\n");
    scanf("%u", &dividend);
    printf("Enter divisor:\n");
    scanf("%u", &divisor);

    Q = dividend;
    M = divisor;

    for (i = 0; i < 32; i++) {
        A = (A << 1) | (Q >> 31);  // bring MSB of Q to LSB of A
        Q = Q << 1;

        if ((int)A >= 0)
            A = A - M;
        else
            A = A + M;

        if ((int)A >= 0)
            Q = Q | 1;
    }

    if ((int)A < 0)
        A = A + M;

    printf("Quotient = %u\n", Q);
    printf("Remainder = %u\n", A);

    return 0;
}
