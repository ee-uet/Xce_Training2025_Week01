//#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint32_t quotient;
    uint32_t remainder;
} DivResult;

// Restoring Division Algorithm in C
DivResult restoring_divide(uint32_t dividend, uint32_t divisor) {
    DivResult result = {0, 0};
    
    uint32_t quotient = 0;
    uint32_t remainder = 0;  // This is the A register
    uint32_t temp_dividend = dividend;  // This is the Q register
    
    // Process 32 bits
    for (int i = 31; i >= 0; i--) {
        // Shift left AQ (remainder:temp_dividend) by 1 bit
        remainder = (remainder << 1) | ((temp_dividend >> 31) & 1);
        temp_dividend <<= 1;
        
        // Try subtraction
        if (remainder >= divisor) {
            remainder -= divisor;
            quotient |= (1U << i);  // Set bit i in quotient
        }
        // If remainder < divisor, do nothing (restoring not needed)
    }
    
    result.quotient = quotient;
    result.remainder = remainder;
    return result;
}

// Test function
int main() {
    
    // Test cases
    uint32_t test_cases[][2] = {
        {100, 7},
        {1000, 13},
        {0xFFFFFFFF, 2},
        {42, 1},
        {15, 3},
        {17, 5}
    };
    
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    /*
    for (int i = 0; i < num_tests; i++) {
        uint32_t dividend = test_cases[i][0];
        uint32_t divisor = test_cases[i][1];
        
        DivResult result = restoring_divide(dividend, divisor);
        
        
        printf("Divide %u by %u:\n", dividend, divisor);
        printf("  Quotient: %u\n", result.quotient);
        printf("  Remainder: %u\n", result.remainder);
        printf("  Verification: %u * %u + %u = %u\n", 
               result.quotient, divisor, result.remainder,
               result.quotient * divisor + result.remainder);
        printf("\n");
        
    }
    */
    return 0;
}
