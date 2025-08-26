#include <stdio.h>
#include <stdint.h>

int main() {
    uint32_t number = 0x12345678;
    uint8_t bit_position = 5;
    
    uint32_t set_result = number | (1 << bit_position);
    
    uint32_t clear_result = number & ~(1 << bit_position);
      
    uint32_t toggle_result = number ^ (1 << bit_position);
    
    uint8_t check_result = (number >> bit_position) & 1;
    
    printf("Original: 0x%08X\n", number);
    printf("Set bit %d: 0x%08X\n", bit_position, set_result);
    printf("Clear bit %d: 0x%08X\n", bit_position, clear_result);
    printf("Toggle bit %d: 0x%08X\n", bit_position, toggle_result);
    printf("Bit %d is: %d\n", bit_position, check_result);
    
    return 0;
}