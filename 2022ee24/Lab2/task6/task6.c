// ======================= Booth's Multiplication =======================
#include <stdio.h>
#include <stdint.h>

int add(int a, int b) {
    while (b != 0) {
        int carry = a & b;   // Calculate carry bits
        a = a ^ b;          // Calculate sum without carry
        b = carry << 1;     // Shift carry to next position
    }
    return a;
}

int shift(int* ptrA, int* ptrQ, int Q_lsb) {
    int Qm1 = Q_lsb;     // Store current Q_lsb as Qm1 for next iteration
    int A_lsb = *ptrA & 1; // Get LSB of A
    *ptrA = *ptrA >> 1;  // Arithmetic right shift A (preserves sign)
    *ptrQ = (uint32_t)*ptrQ >> 1; // Logical right shift Q
    if (A_lsb) {
        *ptrQ |= (1U << 31); // Set MSB of Q if A_lsb is 1
    }
    return Qm1;
}

long int booth_multiply(int multiplicand, int multiplier) {
    int A = 0;           // Accumulator
    int M = multiplier;  // Multiplier
    int Q = multiplicand;// Multiplicand
    int n = 32;          // Number of bits
    int Qm1 = 0;         // Previous LSB of Q

    for (int i = 0; i < n; i++) {
        int Q_lsb = Q & 1; // Get LSB of Q
        if (Q_lsb == 0 && Qm1 == 1) {
            A = add(A, M); // Add M to A
        } else if (Q_lsb == 1 && Qm1 == 0) {
            // Subtract M by adding two's complement of M
            A = add(A, add(~M, 1)); // A - M = A + (-M) = A + (~M + 1)
        }
        Qm1 = shift(&A, &Q, Q_lsb); // Shift A and Q, update Qm1
    }

    // Combine A and Q into 64-bit result with proper sign extension
    int64_t result = ((int64_t)A << 32) | ((uint32_t)Q & 0xFFFFFFFF);
    return result;
}

void test()
{
    int a;
    int b;
    while(1)
    {
        printf("Enter integer1: ");
        scanf("%d",&a);
        printf("Enter integer2: ");
        scanf("%d",&b);
        printf("%d x %d = %ld\n",a,b,booth_multiply(a,b));
    }
}

void test_booth() {
    // Test case 1: Positive numbers
    printf("Test 1: 5 * 3\n");
    if (booth_multiply(5, 3) == 15) {
        printf("Passed: 5 * 3 = 15\n");
    } else {
        printf("Failed: 5 * 3, expected 15, got %ld\n", booth_multiply(5, 3));
    }

    // Test case 2: Negative multiplicand
    printf("Test 2: -5 * 3\n");
    if (booth_multiply(-5, 3) == -15) {
        printf("Passed: -5 * 3 = -15\n");
    } else {
        printf("Failed: -5 * 3, expected -15, got %ld\n", booth_multiply(-5, 3));
    }

    // Test case 3: Negative multiplier
    printf("Test 3: 5 * -3\n");
    if (booth_multiply(5, -3) == -15) {
        printf("Passed: 5 * -3 = -15\n");
    } else {
        printf("Failed: 5 * -3, expected -15, got %ld\n", booth_multiply(5, -3));
    }

    // Test case 4: Both negative
    printf("Test 4: -5 * -3\n");
    if (booth_multiply(-5, -3) == 15) {
        printf("Passed: -5 * -3 = 15\n");
    } else {
        printf("Failed: -5 * -3, expected 15, got %ld\n", booth_multiply(-5, -3));
    }

    // Test case 5: Multiplication by zero
    printf("Test 5: 42 * 0\n");
    if (booth_multiply(42, 0) == 0) {
        printf("Passed: 42 * 0 = 0\n");
    } else {
        printf("Failed: 42 * 0, expected 0, got %ld\n", booth_multiply(42, 0));
    }

    // Test case 6: Zero multiplicand
    printf("Test 6: 0 * 42\n");
    if (booth_multiply(0, 42) == 0) {
        printf("Passed: 0 * 42 = 0\n");
    } else {
        printf("Failed: 0 * 42, expected 0, got %ld\n", booth_multiply(0, 42));
    }

    // Test case 7: Multiplication by 1
    printf("Test 7: 123 * 1\n");
    if (booth_multiply(123, 1) == 123) {
        printf("Passed: 123 * 1 = 123\n");
    } else {
        printf("Failed: 123 * 1, expected 123, got %ld\n", booth_multiply(123, 1));
    }

    // Test case 8: Multiplication by -1
    printf("Test 8: 123 * -1\n");
    if (booth_multiply(123, -1) == -123) {
        printf("Passed: 123 * -1 = -123\n");
    } else {
        printf("Failed: 123 * -1, expected -123, got %ld\n", booth_multiply(123, -1));
    }

    // Test case 9: Edge case - Large positive numbers
    printf("Test 9: 46340 * 46340\n");
    if (booth_multiply(46340, 46340) == 2147395600LL) {
        printf("Passed: 46340 * 46340 = 2147395600\n");
    } else {
        printf("Failed: 46340 * 46340, expected 2147395600, got %ld\n", booth_multiply(46340, 46340));
    }

    // Test case 10: Edge case - Negative and positive
    printf("Test 10: -46340 * 46340\n");
    if (booth_multiply(-46340, 46340) == -2147395600LL) {
        printf("Passed: -46340 * 46340 = -2147395600\n");
    } else {
        printf("Failed: -46340 * 46340, expected -2147395600, got %ld\n", booth_multiply(-46340, 46340));
    }

    // Test case 11: Edge case - INT32_MAX * 1
    printf("Test 11: INT32_MAX * 1\n");
    if (booth_multiply(INT32_MAX, 1) == (long int)INT32_MAX) {
        printf("Passed: INT32_MAX * 1 = %ld\n", (long int)INT32_MAX);
    } else {
        printf("Failed: INT32_MAX * 1, expected %ld, got %ld\n", (long int)INT32_MAX, booth_multiply(INT32_MAX, 1));
    }

    // Test case 12: Edge case - INT32_MIN * 1
    printf("Test 12: INT32_MIN * 1\n");
    if (booth_multiply(INT32_MIN, 1) == (long int)INT32_MIN) {
        printf("Passed: INT32_MIN * 1 = %ld\n", (long int)INT32_MIN);
    } else {
        printf("Failed: INT32_MIN * 1, expected %ld, got %ld\n", (long int)INT32_MIN, booth_multiply(INT32_MIN, 1));
    }

    printf("All test cases completed!\n");
}


int main()
{
    test_booth();
    //printf("%d\n",add(INT32_MIN,1));
    //test();
    return 0;
}