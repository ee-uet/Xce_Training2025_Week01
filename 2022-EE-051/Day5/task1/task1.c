// #include <stdio.h>

int main() {
    unsigned int dividend = 77, divisor = 7;
    unsigned int quotient = 0, rem = 0;  
    
    // Loop through each bit of dividend starting from MSB (bit 31) down to LSB (bit 0)
    for (int i = 31; i >= 0; i--) {
        // Left shift remainder to make space for the next bit
        rem = rem << 1;

        // Bring down the current bit of dividend into remainde
        if ((dividend >> i) & 1) {
            rem = rem | 1;   // Add '1' at LSB if current bit is set
        }

        // If remainder is greater or equal to divisor, perform subtraction
        if (rem >= divisor) {
            rem = rem - divisor;  // Subtract divisor from remainder
            quotient = quotient | (1U << i);   // Set the current quotient bit
        }
    }

    // printf("\nFinal Result:\n");
    // printf("Quotient = %u, Remainder = %u\n", quotient, rem);

    return 0;
}
