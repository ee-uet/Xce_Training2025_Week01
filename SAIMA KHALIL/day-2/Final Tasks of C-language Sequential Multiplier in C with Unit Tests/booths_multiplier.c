#include <stdio.h>

void arithmeticRightShift(int *A, int *Q, int *q0, int bits) {
    int mask = (1 << bits) - 1;

    int sign = (*A >> (bits - 1)) & 1; // save MSB of A
    int newQm1 = *Q & 1;               // save LSB of Q

    *Q = ((*A & 1) << (bits - 1)) | (*Q >> 1); // shift Q right and append LSB of A to MSB of Q
    *A = (sign << (bits - 1)) | (*A >> 1);     // shift A with sign extension

    *A &= mask;
    *Q &= mask;

    *q0 = newQm1; // update Q0 (it's LSB of Q)
}

int main() {
    int bits = 8;    
    int mask = (1 << bits) - 1; //creating mask i-e will yield no.of 1's equal to no.of bits

    // restricting to spec bits
    int M = 91 & mask;   // Multiplicand  
    int Q = -8 & mask;   // Multiplier    
    int A = 0;
    int q0 = 0;
    int n = bits;

    printf(" A=%d, Q=%d, M=%d\n", A, Q, M);

    while (n > 0) {
        int q1 = Q & 1; //extracting last bit of Q

        if (q1 == 0 && q0 == 1) {
            A = (A + M) & mask;  // restricting to spec bits
            printf("Updated A = A + M  is : %d\n", A);
        } else if (q1 == 1 && q0 == 0) {
            A = (A - M) & mask;
            printf("Updated A = A - M is : %d\n", A);
        }

        arithmeticRightShift(&A, &q1, &q0, bits);
        printf("After ASR : A=%d, q1=%d, q0=%d\n", A, q1, q0);

        n--;
    }

   
    int result = (A << bits) | Q; // concatenating A and Q  
  
    if (result & (1 << (2*bits - 1))) {
        result -= (1 << (2*bits));
    } // convert result to signed i-e if msb(sign bit )= 1 , it means the number is negative, then convert it into 2’s complement form to get the correct signed value.
    printf("\nFinal Result: %d\n", result);
    return 0;
}   
