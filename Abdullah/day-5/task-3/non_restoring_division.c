void non_restoring_division(unsigned int dividend, unsigned int divisor, unsigned int *quotient, unsigned int *remainder) {

    
    unsigned int A = 0;             // Remainder register (accumulator)
    unsigned int Q = dividend;      // Quotient register (initially dividend)
    unsigned int M = divisor;       // Divisor register
    int n = 32;                     // Number of bits for 32-bit division
    
    for (int i = 0; i < n; i++) {

        if ((int)A < 0) {
            //--------------------Remainder is Negative: Add Divisor--
            A = (A << 1) | (Q >> 31);  // Shift A left, get MSB of Q
            A = A + M;                  // Add divisor (instead of subtract)
        } else {
            //--------------------Remainder is Non-negative: Subtract--
            A = (A << 1) | (Q >> 31);  // Shift A left, get MSB of Q  
            A = A - M;                  // Subtract divisor (normal case)
        }
        Q = Q << 1;                     // Shift quotient left by 1
        
        if ((int)A >= 0) {
            Q = Q | 1;                  // Set Q[0] = 1 (remainder non-negative)
        } else {
            Q = Q & ~1;                 // Set Q[0] = 0 (remainder negative)
        }
    }
    if ((int)A < 0) {
        *remainder = A + M;             // Correct negative remainder
    } else {
        *remainder = A;                 // Remainder is already correct
    }
    *quotient = Q;                      // Store final quotient
}

int main() {    
    unsigned int dividend = 13;         // Number to be divided
    unsigned int divisor = 3;           // Number to divide by
    unsigned int quotient, remainder;   // Results storage
-
    
    non_restoring_division(dividend, divisor, &quotient, &remainder);

    //----------------------######################---------------------
    //--------------------Output Results (Commented)----------------
    // Note: printf statements commented out for Spike compatibility
    
    /*
    printf("Non-Restoring Division of %u by %u:\n", dividend, divisor);
    printf("Quotient: %u\n", quotient);
    printf("Remainder: %u\n", remainder);
    */

    //----------------------######################---------------------
    //--------------------Verification-------------------------------
    // Manual verification: 13 ÷ 3 = 4 remainder 1
    // Check: 4 × 3 + 1 = 13 

    return 0;                           
}
