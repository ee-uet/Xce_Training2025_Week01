#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// ======================= Final Task: Booth's Multiplication =======================

int twos_complement(int b){
    b = ~b;
    b = b + 0x00000001;
    return b;
}

int add(int a, int b) {
    // TODO: Implement bitwise addition helper
    int carry = 0;
    while(b != 0){
        carry = (unsigned)(a&b) << 1;
        a = a ^ b;
        b = carry;
    }
    return a;
}

long long booth_multiply(int multiplicand, int multiplier) {
    // TODO: Implement Booth's algorithm using shifting/adding
    int A   = 0;
    int n   = 32;
    int M   = multiplicand;
    int Q   = multiplier;
    int Q_1 = 0;
    int Q_0 = 0;

    for(int i = 0;i < n;i++){
        Q_0 = Q & 1;
        if(Q_0 == 1 && Q_1 == 0){
            A = add(A,twos_complement(M));
        }
        else if(Q_0 == 0 && Q_1 == 1){
            A = add(A,M);
        }

        Q_1 = Q & 1;
        Q = (A & 1) << 31 | (unsigned)Q >> 1;
        A = A >> 1;

    }
   
    long long result = ((long long) A << 32) | (unsigned)(Q);
    return (result);
}

void test_booth() {
    // TODO: Write test cases for booth_multiply
    // Include positive, negative, zero, overflow cases
    //printf("Using BOOTH Multiplier: %lld\n",result);

    
    printf(" 5 *  3 = %lld (expected %d)\n", booth_multiply(5, 3),5*3);
    printf("-5 *  3 = %lld (expected %d)\n", booth_multiply(-5, 3),-5*3);
    printf(" 5 * -3 = %lld (expected %d)\n", booth_multiply(5, -3),5*-3);
    printf("-5 * -3 = %lld (expected %d)\n", booth_multiply(-5, -3),-5*-3);
    printf(" 0 *  7 = %lld (expected %d)\n", booth_multiply(0, 7),0*7);
    printf(" -7 *  0 = %lld (expected %d)\n", booth_multiply(7, 0),-7*0);
    printf(" 1 * 123 = %lld (expected %d)\n", booth_multiply(1, 123),1*123);
    printf("INT_MAX * 1 = %lld (expected %d)\n", booth_multiply(INT_MAX, 1), 1*INT_MAX);
    printf("INT_MIN * 1 = %lld (expected %d)\n", booth_multiply(INT_MIN, 1), 1*INT_MIN);

}


// ======================= Main =======================
int main() {
    
    // --- Final Task ---
    test_booth();

    return 0;
}
