#include <stdio.h>
#include <stdint.h>
#include <limits.h>


int64_t add64(int64_t a, int64_t b) {
    int64_t carry;
    while (b != 0) {
        carry = a & b;             
        a = a ^ b;                 
        b = (uint64_t)carry << 1;  // carry shifted into position
    }
    return a;
}

/* two's complement in 64-bit space */
int64_t two_complement64(int64_t M) {
    return (~M) + 1;
}


long long booth_multiply(int multiplicand, int multiplier) {
    int64_t M = (int64_t)multiplicand;   
    int64_t Q = (int64_t)multiplier;     
    int64_t AC = 0;                      
    int Q_minus1 = 0;                    
    const int n = 32;

    for (int i = 0; i < n; i++) {
        int Q0 = (int)(Q & 1);           // least-significant bit of Q

        if (Q0 == 1 && Q_minus1 == 0) {
            int64_t comp_M = two_complement64(M);
            AC = add64(AC, comp_M);     // AC = AC - M
        } else if (Q0 == 0 && Q_minus1 == 1) {
            AC = add64(AC, M);          // AC = AC + M
        }

        // Update Q-1 for next iteration ) 
        Q_minus1 = (int)(Q & 1);

        // Form combined AC:Q in 128-bit, arithmetic-right-shift by 1,
           
        __int128 combined = (__int128)AC << 32;
        combined |= (__int128)((uint32_t)Q);

        combined >>= 1;                // arithmetic right shift by 1

        AC = (int64_t)(combined >> 32);
        Q = (int64_t)(combined & 0xFFFFFFFF);
    }

    // Combine final AC (upper 32 bits) and Q (lower 32 bits) into 64-bit result.
       
    int64_t result = (AC << 32) | (int64_t)((uint32_t)Q);
    return (long long)result;
}

/* Unit tests covering positive, negative, zero, and edge cases */
void test_booth() {
    long long res;

    res = booth_multiply(6, 3);
    printf("6 * 3 = %lld (expected 18)\n", res);

    res = booth_multiply(-6, 3);
    printf("-6 * 3 = %lld (expected -18)\n", res);

    res = booth_multiply(6, -3);
    printf("6 * -3 = %lld (expected -18)\n", res);

    res = booth_multiply(-6, -3);
    printf("-6 * -3 = %lld (expected 18)\n", res);

    res = booth_multiply(0, 12345);
    printf("0 * 12345 = %lld (expected 0)\n", res);

    res = booth_multiply(67890, 0);
    printf("67890 * 0 = %lld (expected 0)\n", res);

    res = booth_multiply(0, 0);
    printf("0 * 0 = %lld (expected 0)\n", res);

    res = booth_multiply(123, 1);
    printf("123 * 1 = %lld (expected 123)\n", res);

    res = booth_multiply(-123, 1);
    printf("-123 * 1 = %lld (expected -123)\n", res);

    res = booth_multiply(123, -1);
    printf("123 * -1 = %lld (expected -123)\n", res);

    res = booth_multiply(-123, -1);
    printf("-123 * -1 = %lld (expected 123)\n", res);

    res = booth_multiply(INT_MAX, 1);
    printf("INT_MAX * 1 = %lld (expected %d)\n", res, INT_MAX);

    res = booth_multiply(INT_MIN, 1);
    printf("INT_MIN * 1 = %lld (expected %d)\n", res, INT_MIN);

    res = booth_multiply(INT_MAX, INT_MAX);
    printf("INT_MAX * INT_MAX = %lld (expected %lld)\n", res, (long long)INT_MAX * INT_MAX);
}

int main() {
    test_booth();
    return 0;
}

