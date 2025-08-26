#include <stdio.h>
#include <stdint.h>


void restoring_division(uint32_t dividend, uint32_t divisor, uint32_t *quotient, uint32_t *remainder) {
    uint64_t A = 0;          // Remainder (upper 32 bits)
    uint64_t Q = dividend;   // Dividend/Quotient (lower 32 bits)
    uint64_t M = divisor;    // Divisor
    
    int n = 32;
    
    for (int i = 0; i < n; i++) {
        
        A = (A << 1) | ((Q >> 31) & 1);  // Shift A left and bring in MSB of Q
        Q = Q << 1;                      // Shift Q left
        
        
        A = A - M;
        
        
        if (A & 0x80000000) {  // Check if bit 31 is set (negative)
            // Negative result: restore A and set Q0 = 0
            A = A + M;         // Restore A
            // Q0 remains 0 (from the left shift)
        } else {
            // Positive result: keep A and set Q0 = 1
            Q = Q | 1;         // Set LSB of Q to 1
        }
    }
    
    *quotient = Q;
    *remainder = A;
}

int main() {
    uint32_t dividend = 21;
    uint32_t divisor = 3;
    uint32_t quotient, remainder;
    
    restoring_division(dividend, divisor, &quotient, &remainder);
    printf("%u / %u = %u, remainder %u\n", dividend, divisor, quotient, remainder);
    
    return 0;
}