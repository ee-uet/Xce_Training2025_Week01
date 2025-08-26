#include <stdint.h>

uint32_t bit_modify(uint32_t num, uint32_t pos, int op) {
    uint32_t mask = 1u << pos;
    if (op == 1)       // set
        num |= mask;
    else                // clear
        num &= ~mask;
    return num;
}

int main() {
    uint32_t num = 0x12345678;
    uint32_t pos = 5;
    int op = 1;  // 1=set, 0=clear

    uint32_t result = bit_modify(num, pos, op);

    // Return the result in a0 register (standard RISC-V exit)
    return result;
}
