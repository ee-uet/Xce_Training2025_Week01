#include <stdio.h>
#include <stdint.h>

void nonRestoringDivision(uint32_t dividend, uint32_t divisor, uint32_t *quotient, uint32_t *remainder) {
    int32_t rem = 0;  // signed to allow negative values during iterations
    uint32_t q = 0;

    for (int i = 31; i >= 0; i--) {
        rem = (rem << 1) | ((dividend >> i) & 1);  // shift remainder left and bring down bit
        q <<= 1;

        if (rem >= 0) {
            rem = rem - divisor;
            if (rem >= 0)
                q |= 1;
        } else {
            rem = rem + divisor;
            if (rem >= 0)
                q |= 1;
        }
    }

    // If remainder is negative, correct it
    if (rem < 0)
        rem += divisor;

    *quotient = q;
    *remainder = (uint32_t)rem;
}

int main() {
    uint32_t dividend, divisor, quotient, remainder;

    printf("Enter Dividend: ");
    scanf("%u", &dividend);
    printf("Enter Divisor: ");
    scanf("%u", &divisor);

    nonRestoringDivision(dividend, divisor, &quotient, &remainder);

    printf("Quotient = %u, Remainder = %u\n", quotient, remainder);
    return 0;
}

