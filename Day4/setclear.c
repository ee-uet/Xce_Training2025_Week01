#include <stdint.h>

// Function to set or clear a bit in a 32-bit number
int main() {
    volatile uint32_t number = 0x49527510;
    volatile uint32_t k = 5;
    volatile uint32_t mask = 1 << k;

    volatile uint32_t set_result = number | mask;
    volatile uint32_t clear_result = number & ~mask;

    return set_result + clear_result;  
}

