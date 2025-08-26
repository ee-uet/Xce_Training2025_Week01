#include <stdio.h>
#include <stdint.h>

int main() {
    uint32_t num = 0x12345678;  // Example number
    int bitpos = 5;             // Bit position (0–31)
    int choice = 1;             // 1 = Set bit, 0 = Clear bit
    uint32_t result;

    if (choice == 1) {
        // Set bit
        result = num | (1U << bitpos);
    } else {
        // Clear bit
        result = num & ~(1U << bitpos);
    }

    printf("Original: 0x%08X\n", num);
    printf("Modified: 0x%08X\n", result);

    return 0;
}

