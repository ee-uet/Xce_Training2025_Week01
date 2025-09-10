//#include <stdio.h>
#include <stdint.h>

// Set a specific bit in a 32-bit number
uint32_t set_bit(uint32_t number, int bit_position) {
    if (bit_position < 0 || bit_position > 31) {
        return number;  // Invalid bit position, return unchanged
    }
    
    return number | (1U << bit_position);
}

// Clear a specific bit in a 32-bit number
uint32_t clear_bit(uint32_t number, int bit_position) {
    if (bit_position < 0 || bit_position > 31) {
        return number;  // Invalid bit position, return unchanged
    }
    
    return number & ~(1U << bit_position);
}

// Get the value of a specific bit
int get_bit(uint32_t number, int bit_position) {
    if (bit_position < 0 || bit_position > 31) {
        return -1;  // Invalid bit position
    }
    
    return (number >> bit_position) & 1;
}

// Toggle a specific bit
uint32_t toggle_bit(uint32_t number, int bit_position) {
    if (bit_position < 0 || bit_position > 31) {
        return number;  // Invalid bit position, return unchanged
    }
    
    return number ^ (1U << bit_position);
}
/*
// Helper function to print binary representation
void print_binary(uint32_t number) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (number >> i) & 1);
        if (i % 4 == 0 && i > 0) printf(" ");  // Space every 4 bits
    }
    printf("\n");
}
*/
/*
// Test function
int main() {
    printf("=== Bit Operations Test ===\n");
    
    uint32_t test_number = 0x12345678;
    printf("Original number: 0x%08X\n", test_number);
    printf("Binary: ");
    print_binary(test_number);
    printf("\n");
    
    //Test set_bit
    printf("Setting bit 4:\n");
    uint32_t result = set_bit(test_number, 4);
    printf("Result: 0x%08X\n", result);
    printf("Binary: ");
    print_binary(result);
    printf("Bit 4 value: %d\n\n", get_bit(result, 4));
    
    // Test clear_bit
    printf("Clearing bit 6 from the result:\n");
    result = clear_bit(result, 6);
    printf("Result: 0x%08X\n", result);
    printf("Binary: ");
    print_binary(result);
    printf("Bit 6 value: %d\n\n", get_bit(result, 6));
    
    // Test toggle_bit
    printf("Toggling bit 31:\n");
    result = toggle_bit(result, 31);
    printf("Result: 0x%08X\n", result);
    printf("Binary: ");
    print_binary(result);
    printf("Bit 31 value: %d\n\n", get_bit(result, 31));
    
    // Test multiple operations
    printf("=== Multiple Operations Test ===\n");
    uint32_t num = 0;
    printf("Starting with 0x%08X\n", num);
    
    // Set bits 0, 8, 16, 31
    int bits_to_set[] = {0, 8, 16, 31};
    for (int i = 0; i < 4; i++) {
        num = set_bit(num, bits_to_set[i]);
        printf("After setting bit %d: 0x%08X\n", bits_to_set[i], num);
    }
    
    // Clear bit 16
    num = clear_bit(num, 16);
    printf("After clearing bit 16: 0x%08X\n", num);
    
    printf("Final binary: ");
    print_binary(num);
    
    return 0;
}
*/
