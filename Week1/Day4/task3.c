#include <stdint.h>

int main() {
    uint32_t dividend = 77;
    uint32_t divisor  = 7;
    uint32_t quotient = 0;
    uint32_t rem      = 0;

    for (int i = 31; i >= 0; i--) {
        // Shift left remainder and bring in next dividend bit
        rem = (rem << 1) | ((dividend >> i) & 1);

        // Subtract divisor if possible
        if (rem >= divisor) {
            rem = rem - divisor;
            quotient = quotient | (1U << i);
        }
        // If rem < divisor, do nothing (non-restoring for unsigned)
    }

    // Store results in memory-mapped registers (optional for FPGA)
    volatile uint32_t *q = (uint32_t*)0x80000000;
    volatile uint32_t *r = (uint32_t*)0x80000004;
    *q = quotient;
    *r = rem;

    return 0;
}
