#include <stdio.h>
#include <string.h>

int restoring_division(int Dividend, int Divisor, int *Quotient, int *remainder){

    int A = 0;              // Accumulator (remainder register)
    int Q = Dividend;       )
    int M = Divisor;        
    int n = 32;             
    
    for (int i = 1; i <= n; i++) {
        // Step 1: Shift left A,Q register pair by 1 bit
        A = (A<<1 | Q >> 31);  
        Q = Q<<1;              

        // Step 2: Subtract divisor from accumulator
        A = A-M;

        // Step 3: Check if result is negative (restore if needed)
        if ((int)A > 0) {
            // Result is negative, restore by adding divisor back
            A += M;             
            Q = Q & ~1;         
        }
        else{
            // Result is positive or zero, keep the subtraction
            Q = Q | 1;          // Set Q[0] = 1 (quotient bit is 1)
        }
    }

    // Store final results through pointer parameters
    *Quotient = Q;          
    *remainder = A;         
    
    return 0;               
}

int main() {
    // Test case setup
    int dividend = 13;      // Number to be divided
    int divisor = 3;        // Number to divide by
    int quotient, remainder; // Results storage

    // Perform restoring division
    restoring_division(dividend, divisor, &quotient, &remainder);
}

    