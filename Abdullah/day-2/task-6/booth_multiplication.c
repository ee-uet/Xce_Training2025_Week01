#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int add(int a, int b) {
    // TODO: Implement bitwise addition helper
    while (b!=0) {
      int carry = (a&b)<<1;
      a = a^b;
      b = carry;
    }
    return a;
}
// Performs arithmetic right shift on combined A (accumulator) and Q (multiplier)
void arithmatic_right_shifter(int *A, int *Q, int *Q1) {
    // Store least significant bit of Q as Q1 (previous bit for Booth's algorithm)
    *Q1 = *Q & 1;
    // Combine A and Q into a 64-bit value for shifting (A in high 32 bits, Q in low 32 bits)
    long long combined = ((long long)*A << 32) | (unsigned int)*Q;
    // Arithmetic right shift by 1, preserving sign bit
    combined >>= 1;
    // Extract high 32 bits back to A
    *A = (int)(combined >> 32);
    // Extract low 32 bits back to Q
    *Q = combined;
}

int twos_complement(int M){
      int num = M;
      num = ~num;
      num = num + 0x00000001;
      return num;
}

int booth_multiply(int multiplicand, int multiplier) {
    // TODO: Implement Booth's algorithm using shifting/adding
    int M = multiplicand;
    int Q = multiplier;
    int n_bits = 32;
    int A = 0;
    int Q1 = 0;

    for (int i = 0; i<n_bits; i++) {
      int Q0 = 1 & Q;
      if (Q0 == 0 && Q1 == 1) {
        A = add(M,A);
      }
      else if (Q0 == 1 && Q1 == 0) {
        int neg_M = twos_complement(M);
        A = add(A,neg_M);
      }
      arithmatic_right_shifter(&A,&Q,&Q1);
      }
    //return Q;
    return ((long long)A << 32) | (unsigned int)Q;
}

void test_booth() {
    int a, b;

    // Positive numbers
    a = 7; b = 3;
    printf("Test %d * %d = %d (Expected %d)\n", a, b, booth_multiply(a, b), a * b);

    // Negative * Positive
    a = -7; b = 3;
    printf("Test %d * %d = %d (Expected %d)\n", a, b, booth_multiply(a, b), a * b);

    // Positive * Negative
    a = 7; b = -3;
    printf("Test %d * %d = %d (Expected %d)\n", a, b, booth_multiply(a, b), a * b);

    // Negative * Negative
    a = -7; b = -3;
    printf("Test %d * %d = %d (Expected %d)\n", a, b, booth_multiply(a, b), a * b);

    // Multiplication by Zero
    a = 1234; b = 0;
    printf("Test %d * %d = %d (Expected %d)\n", a, b, booth_multiply(a, b), a * b);

    // Multiplication by One
    a = 999; b = 1;
    printf("Test %d * %d = %d (Expected %d)\n", a, b, booth_multiply(a, b), a * b);

    // Edge case: INT_MAX * 1
    a = INT_MAX; b = 1;
    printf("Test %d * %d = %d (Expected %d)\n", a, b, booth_multiply(a, b), a * b);

    // Edge case: INT_MIN * 1
    a = INT_MIN; b = 1;
    printf("Test %d * %d = %d (Expected %d)\n", a, b, booth_multiply(a, b), a * b);

    // Edge case: Overflow (note: result may overflow 32-bit int!)
    a = 50000; b = 50000;
    printf("Test %d * %d = %d (Expected %d, may overflow)\n", a, b, booth_multiply(a, b), a * b);
}

int main() {
    test_booth();
    return 0;
}