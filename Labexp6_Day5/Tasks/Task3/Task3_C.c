#include <stdint.h>

// Global variables for division operation
volatile uint32_t dividend = 123456789;    // Test dividend value
volatile uint32_t divisor = 12345;         // Test divisor value
volatile uint32_t quotient = 0;            // Result: quotient storage
volatile uint32_t remainde_r = 0;           // Result: remainder storage (fixed typo)

// Non-restoring division algorithm for 32-bit unsigned integers
// Fixed function signature to accept volatile pointers
void non_restoring_div32(uint32_t dividend, uint32_t divisor, 
                         volatile uint32_t *quotient, volatile uint32_t *remainde_r) {
    uint32_t q = 0;        // Quotient accumulator
    int32_t r = 0;         // Remainder (signed to handle negative values)
    
    // Process each bit from MSB to LSB (31 down to 0)
    for (int i = 31; i >= 0; i--) {
        // Shift remainder left and bring down next dividend bit
        r = (r << 1) | ((dividend >> i) & 1);
        
        if (r >= 0) {
            // Remainder is non-negative: subtract divisor and set quotient bit
            r -= divisor;
            q = (q << 1) | 1;      // Set quotient bit to 1
        } else {
            // Remainder is negative: add divisor and clear quotient bit
            r += divisor;
            q = (q << 1) | 0;      // Set quotient bit to 0 (redundant but clear)
        }
    }
    
    // Final correction: ensure remainder is positive
    if (r < 0) r += divisor;
    
    // Store results in the provided memory locations
    *quotient = q;
    *remainde_r = r;
}

int main() {
    // Perform division: 123456789 ÷ 12345 = 10000 remainder 6789
    non_restoring_div32(dividend, divisor, &quotient, &remainde_r);
    
    while(1);   // Infinite loop to prevent program exit (bare-metal style)
}
