// #include <stdio.h>

int main() {
    unsigned int dividend = 77;
    unsigned int divisor  = 7;
    unsigned int quotient = 0;
    unsigned int rem      = 0;

    // Perform division using shift-subtract method
    for (int i = 31; i >= 0; i--) {
        // Shift left remainder and bring in next dividend bit
        rem = (rem << 1) | ((dividend >> i) & 1);

        // Subtract divisor if possible
        if (rem >= divisor) {
            rem = rem - divisor;
            quotient = quotient | (1U << i);
        }
    }
    // printf("Quotient = %u\n", quotient);
    // printf("Remainder= %u\n", rem);

    return 0;
}
